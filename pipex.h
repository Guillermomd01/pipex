#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <errno.h>
# include <fcntl.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>

char	*found_path(char **envp,char **cmd1_parsed);
void	pipex(char *infile, char *cmd1, char *cmd2, char *outfile, char **envp);

#endif
