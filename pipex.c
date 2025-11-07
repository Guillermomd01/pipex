#include "PIPEX_H"
# include <unistd.h>
# include <errno.h>
# include <fcntl.h>

char	*found_path(char **envp,char **cmd1_parsed)
{
	char	*ruta_prueba;
	char	**path;
	int i;
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
		{
			free(temp);
			path = NULL;
			free(path);
			return (ruta_prueba);
		}
	}
	free(temp);
	free(path);
	return (NULL);
}

void	pipex(char *infile, char *cmd1, char *cmd2, char *outfile, char **envp)
{
	int		i;
	int		id;
	int		fd[2];
	int		fd_in;
	int		fd_out;
	char	**cmd1_parsed;
	char	**cmd2_parsed;
	char	*path;
	i = 0;
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
	{
		//hijo
		fd_in = open(infile, O_RDONLY);
		if (fd_in == -1)
		{
			perror("problem whit first fd");
			exit (1);
		}
		//redirigir a infile y out y cerrar los que ya no usamos
		if (dup2(fd_in, 0) == -1)
			perror("dup2");
		close(fd_in);
		close(fd[0]);
		if (dup2(fd[1], 1) == -1)
			perror("dup2");
		close(fd[1]);
		
		//parsear con split para poder usar execve
		cmd1_parsed = ft_split(cmd1,' ');
		//sacar path de envp
		path = found_path(envp, cmd1_parsed);
		if (!path)
			{
				perror("command not found");
				exit (127);
			}
		execve(path, cmd1_parsed, envp);
		perror("command not found");
		exit(127);
		
	}
	else
	//este es el padre
	{
		id = fork();
		if (id == -1)
		{
			perror ("not child");
			exit (1);
		}
		else if (id == 0)
		{
			// creamos hijo2
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
		close(fd[0]);
		close(fd[1]);
		wait(NULL);
		wait(NULL);
	}
}