#include "hydra_daemon.h"

void	daemonize(const char *cmd) 
{ 
    int                 i;
    //int fd0, fd1, fd2; 
    pid_t               pid; 
    struct sigaction    sa; 
    
    //umask(0); 
    /* 
     * Become a session leader to lose controlling 
TTY. 
     */ 
    if ((pid = fork()) < 0) 
        perror("%s: can't fork"); 
    else if (pid != 0)
        exit(0); 
    setsid(); 
    /* 
     * Ensure future opens won't allocate controlli
ng TTYs. 
     */ 
    sa.sa_handler = SIG_IGN; 
    sigemptyset(&sa.sa_mask); 
    sa.sa_flags = 0; 
    if (sigaction(SIGHUP, &sa, NULL) < 0) 
        perror("%s: can't ignore SIGHUP"); 
    if ((pid = fork()) < 0) 
        perror("%s: can't fork"); 
    else if (pid != 0) 
        exit(0); 
    /* 
     * Change the current working directory to the 
root so 
     * we won't prevent file systems from being unm
ounted. 
     */ 
    // if (chdir("/") < 0) 
    //     err_quit("%s: can't change directory to /"); 
    /* 
     * Attach file descriptors 0, 1, and 2 to /dev/
null. 
     */ 
    // fd0 = open("/dev/null", O_RDWR); 
    // fd1 = dup(0); 
    // fd2 = dup(0); 
}                