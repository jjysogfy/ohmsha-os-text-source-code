#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int fd[2];
    pipe(fd);

    pid_t p = fork();
    if (p == 0) {
        close(fd[1]);  // writeはclose

        char buf;
        while (read(fd[0], &buf, 1) > 0) {
            printf("child: %c\n", buf);
        }

        close(fd[0]);
        _exit(0);
    } else {
        close(fd[0]);

        write(fd[1], "hello", 5);
        close(fd[1]);
        waitpid(p, NULL, 0);
    }
}
