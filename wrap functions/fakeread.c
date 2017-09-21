#include <stdio.h>
#include <sys/types.h>
#include <dlfcn.h>


static ssize_t (*__real_read)(int fd, void *buf, size_t count);

__attribute__((constructor)) static void init_wraps()
{
    __real_read = dlsym(RTLD_NEXT, "read");
}


ssize_t read(int fd, void *buf, size_t count)
{
    int nread = __real_read(fd, buf, count);
    printf("wrapped read: %d bytes read\n", nread);
    
    return nread;
}
