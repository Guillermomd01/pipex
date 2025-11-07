#ifndef PIPEX_H
# define PIPEX_H

# include "ft_libft/libft.h"
# include <unistd.h>
# include <errno.h>
# include <fcntl.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
#include <sys/wait.h>

char	*found_path(char **envp,char **cmd1_parsed);
void	create_first_child(char *infile, int fd[2], char *cmd, char **envp);
void	create_second_child(char *outfile, int fd[2], char *cmd2, char **envp);
void	redirection_close(int fd_in, int fd[2]);
void	pipex(char *infile, char *cmd1, char *cmd2, char *outfile, char **envp);

#endif
