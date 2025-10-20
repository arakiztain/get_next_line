#include "../include/get_next_line.h"

int count_n(char *str)
{
    //Zenbatu zenbet caracter dauz /n-arte read(fd, buffer, r) apurka apurka irakurtzeko
}

char    *get_next_line(int fd)
{
    static char    buffer[100];
    static  int bytes;
    static  int i = 0;
    
    bytes = read(fd, buffer + i, 100 - i);
    if (bytes <= 0)
        return NULL;
    buffer[bytes + i] = '\0';
    printf("%i", buffer[i]);
    while (buffer[i + 1])
    {
        if (buffer[i] == '\n')
            break;
            write(1, &buffer[i], 1);
        i++;
    }
    //printf("%i\n", i);
    write(1, "\n", 1);
    return (buffer);
}

int main(void)
{
    int fd = open("../fitx.txt", O_RDONLY);

    if (fd == -1)
        return (1);
    get_next_line(fd);
    get_next_line(fd);
    get_next_line(fd);
    // printf("%s", get_next_line(3));
    close (fd);
    return (0);
}