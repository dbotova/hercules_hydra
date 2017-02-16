#ifndef HYDRA_DAEMON_H
# define HYDRA_DAEMON_H
# include <sys/resource.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/wait.h>
# include <signal.h>
# include <stdlib.h>
# include <sys/socket.h>
# include <arpa/inet.h>
# include <string.h>
# define BUF_SIZE 2000

void					daemonize(const char *cmd);

#endif