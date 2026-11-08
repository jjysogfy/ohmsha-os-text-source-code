#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>

int main(void)
{
    const char *name = "/my_shm";
    size_t size = 4096;

    int fd = shm_open(name, O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
    if (fd == -1) {
        perror("shm_open");
        return 1;
    }

    if (ftruncate(fd, size) == -1) {
        perror("ftruncate");
        return 1;
    }

    char *p = mmap(NULL, size,
                   PROT_READ | PROT_WRITE,
                   MAP_SHARED,
                   fd, 0);

    if (p == MAP_FAILED) {
        perror("mmap");
        return 1;
    }

    printf("mapped address: %p\n", p);
    printf("current contents: \"%s\"\n", p);

    printf("Enter text: ");
    fgets(p, size, stdin);

    printf("stored: \"%s\"\n", p);

    munmap(p, size);
    close(fd);

    return 0;
}
