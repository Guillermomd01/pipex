#include "pipex.h"

char	*found_path(char **envp,char **cmd1_parsed)
{
	char	*ruta_prueba;
	char	**path;
	int 	i;
	char	*temp;

	i = 0;
	while(envp[i] && !ft_strnstr(envp[i], "PATH=", 5))
		i++;
		if (envp[i] == NULL )
			return(NULL);
	path = ft_split(ft_strchr(envp[i],'=') + 1, ':');
	i = 0;
	temp = ft_strjoin("/",cmd1_parsed[0]);
	while(path[i] != NULL)
	{
		ruta_prueba = ft_strjoin(path[i], temp);
		if (access(ruta_prueba, X_OK) == -1)
		{
			free(ruta_prueba);
			i++;
		}
		else
			return (free(temp), free_aux(path), free(path), ruta_prueba);
	}
	return (free(temp), free_aux(path), free(path), NULL);
}

void	free_aux(char **str)
{
	int	i;
	
	i = 0;
	while(str[i])
	{
		free(str[i]);
		i++;
	}
}
void	pipex(char *infile, char *cmd1, char *cmd2, char *outfile, char **envp)
{
	int	pid1;
	int	pid2;
	int	fd[2];
	int	status;
	int exit_code;

	if (pipe(fd) == -1)
	{
		perror ("pipe");
		exit (1);
	}
	pid1 = fork();
	if (pid1 == -1)
	{
		perror ("fork");
		exit (1);
	}
	else if (pid1 == 0)
		create_first_child(infile, fd, cmd1, envp);
	else
	{
		pid2 = fork();
		if (pid2 == -1)
		{
			perror ("fork");
			exit (1);
		}
		else if (pid2 == 0)
			create_second_child(outfile, fd, cmd2, envp);
		close(fd[0]);
		close(fd[1]);
		waitpid(pid1, NULL, 0);
		waitpid(pid2, &status, 0);
		if (WIFEXITED(status))
			exit_code = WEXITSTATUS(status);
		else 
			exit_code = 128 + WTERMSIG(status);
		exit(exit_code);
	}
}
char	*verify_exe(char **cmd_parsed)
{
	if(access(cmd_parsed[0], F_OK) == -1)
		return (NULL);
	if(access(cmd_parsed[0], X_OK) == -1)
	{
		ft_putstr_fd(cmd_parsed[0], 2);
		ft_putendl_fd(": Permission denied", 2);
		exit(126);
	}
	return(ft_strdup(cmd_parsed[0]));

}
void	create_second_child(char *outfile, int fd[2], char *cmd2, char **envp)
{
	int		fd_out;
	char	**cmd2_parsed;
	char	*path;

	if (dup2(fd[0], 0) == -1)
	{
		perror("dup2");
		exit(1);
	}
	fd_out = open(outfile, O_CREAT | O_TRUNC | O_WRONLY, 0644);
	if(fd_out == -1)
	{
		perror("open");
		exit(1);
	}
	redirection_close_outfile(fd_out, fd);
	cmd2_parsed = ft_split(cmd2, ' ');
	if (!(ft_strchr(cmd2_parsed[0], '/')))
	{
		path = found_path(envp, cmd2_parsed);
		if (!path)
		{
			ft_putstr_fd(cmd2_parsed[0], 2);
			ft_putendl_fd(": command not found", 2);
			exit (127);
		}
	}
	else
		path = verify_exe(cmd2_parsed);
	execve(path, cmd2_parsed, envp);
	free_aux (cmd2_parsed);
	free (cmd2_parsed);
	if (errno == EACCES || errno == EISDIR)
	{
		ft_putstr_fd(cmd2_parsed[0], 2);
		ft_putendl_fd(": Permission denied", 2);
		exit(126);
	}
	else if (errno == ENOENT)
	{
		ft_putstr_fd(cmd2_parsed[0], 2);
		ft_putendl_fd(": command not found", 2);
		exit (127);
	}
	else
		{
		ft_putstr_fd(cmd2_parsed[0], 2);
		ft_putendl_fd(": command not found", 2);
		exit (127);
		}
}
void	redirection_close_outfile(int fd_out, int fd[2])
{
	if (dup2(fd_out, 1) == -1)
		perror("dup2");
	close(fd[0]);
	close(fd[1]);
	close (fd_out);
}
void	create_first_child(char *infile, int fd[2], char *cmd1, char **envp)
{
	int		fd_in;
	char	**cmd1_parsed;
	char	*path;

	fd_in = open(infile, O_RDONLY);
	if (fd_in == -1)
	{
		perror("open");
		exit (1);
	}
	redirection_close_infile(fd_in, fd);
	cmd1_parsed = ft_split(cmd1,' '); //parsear con split para poder usar execve
	if (!(ft_strchr(cmd1_parsed[0], '/')))
	{
		path = found_path(envp, cmd1_parsed);//sacar path de envp
		if (!path)
		{
			ft_putstr_fd(cmd1_parsed[0], 2);
			ft_putendl_fd(": command not found", 2);
			exit (127);
		}
	}
	else
		path = verify_exe(cmd1_parsed);
	execve(path, cmd1_parsed, envp);
	free_aux (cmd1_parsed);
	free (cmd1_parsed);
	if (errno == EACCES || errno == EISDIR)
	{
		ft_putstr_fd(cmd1_parsed[0], 2);
		ft_putendl_fd(": Permission denied", 2);
		exit(126);
	}
	else if (errno == ENOENT)
	{
		ft_putstr_fd(cmd1_parsed[0], 2);
		ft_putendl_fd(": command not found", 2);
		exit (127);
	}
	else
		{
		ft_putstr_fd(cmd1_parsed[0], 2);
		ft_putendl_fd(": command not found", 2);
		exit (127);
		}
}
void	redirection_close_infile(int fd_in, int fd[2])
{
	if (dup2(fd_in, 0) == -1)//redirigir a infile y out y cerrar los que ya no usamos
		perror("dup2");
	close(fd_in);
	close(fd[0]);
	if (dup2(fd[1], 1) == -1)
		perror("dup2");
	close(fd[1]);
}
int	main(int argc, char **argv, char **envp)
{
	if (argc != 5)
	{
		ft_putstr_fd("Usage: ./pipex infile cmd1 cmd2 outfile\n", 2);
		return (1);
	}
	pipex(argv[1],argv[2],argv[3], argv[4], envp);
	return (0);
}
