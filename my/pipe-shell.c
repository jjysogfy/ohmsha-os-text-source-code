#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

#include <stdio.h>

int main() {
    int fd[2];
    pipe(fd);

    pid_t pid1 = fork();

    if (pid1 == 0) {
        close(fd[0]);

        dup2(fd[1], STDOUT_FILENO);
        close(fd[1]);
        execlp("ls", "ls", NULL);
    }

    pid_t pid2 = fork();

    if (pid2 == 0) {
        close(fd[1]);

        dup2(fd[0], STDIN_FILENO);
        close(fd[0]);
        execlp("grep", "grep", ".c", NULL);
    }

    close(fd[0]);
    close(fd[1]);

    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);
    fprintf(stderr, "[INFO] succeed\n");
}
