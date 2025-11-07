#include "pipex.h"

char	*found_path(char **envp,char **cmd1_parsed)
{
	char	*ruta_prueba;
	char	**path;
	int 	i;
	char	*temp;

	i = 0;
	while(!ft_strnstr(envp[i], "PATH=", 5))
		i++;
	path = ft_split(ft_strchr(envp[i],'=') + 1, ':');
	i = 0;
	temp = ft_strjoin("/",cmd1_parsed[0]);
	while(path[i] != NULL)
	{
		ruta_prueba = ft_strjoin(path[i], temp);
		if (access(ruta_prueba, X_OK) == -1)
		{
			i++;
			free(ruta_prueba);
		}
		else
			return (free(temp), free(path), ruta_prueba);
	}
	return (free(temp), free(path), NULL);
}

void	pipex(char *infile, char *cmd1, char *cmd2, char *outfile, char **envp)
{
	int		id;
	int		fd[2];
	
	if (pipe(fd) == -1)
	{
		perror ("pipe");
		exit (1);
	}
	id = fork();
	if (id == -1)
	{
		perror ("not child");
		exit (1);
	}
	else if (id == 0)
		create_first_child(infile, fd, cmd1, envp);
	else
	{
		id = fork();
		if (id == -1)
		{
			perror ("not child");
			exit (1);
		}
		else if (id == 0)
			create_second_child(outfile, fd, cmd2, envp);
		close(fd[0]);
		close(fd[1]);
		wait(NULL);
		wait(NULL);
	}
}

void	create_second_child(char *outfile, int fd[2], char *cmd2, char **envp)
{
	int		fd_out;
	char	**cmd2_parsed;
	char	*path;

	if (dup2(fd[0], 0) == -1)
				perror("dup2");
	fd_out = open(outfile, O_CREAT | O_TRUNC | O_WRONLY, 0644);
	if (dup2(fd_out, 1) == -1)
		perror("dup2");
	close(fd[0]);
	close(fd[1]);
	close (fd_out);
	cmd2_parsed = ft_split(cmd2, ' ');
	path = found_path(envp, cmd2_parsed);
	if (!path)
	{
		perror("command not found");
		exit (127);
	}
	execve(path, cmd2_parsed, envp);
	perror("command not found");
	exit (127);
}
void	create_first_child(char *infile, int fd[2], char *cmd1, char **envp)
{
	int		fd_in;
	char	**cmd1_parsed;
	char	*path;

	fd_in = open(infile, O_RDONLY);
	if (fd_in == -1)
	{
		perror("problem with first fd");
		exit (1);
	}
	redirection_close(fd_in, fd);
	cmd1_parsed = ft_split(cmd1,' '); //parsear con split para poder usar execve
	path = found_path(envp, cmd1_parsed);//sacar path de envp
	if (!path)
		{
			perror("command not found");
			exit (127);
		}
	execve(path, cmd1_parsed, envp);
	perror("command not found");
	exit(127);
}
void	redirection_close(int fd_in, int fd[2])
{
	if (dup2(fd_in, 0) == -1)//redirigir a infile y out y cerrar los que ya no usamos
		perror("dup2");
	close(fd_in);
	close(fd[0]);
	if (dup2(fd[1], 1) == -1)
		perror("dup2");
	close(fd[1]);
	return ;
}
#include "pipex.h"

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
