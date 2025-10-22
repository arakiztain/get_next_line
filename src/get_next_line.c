#include "../include/get_next_line.h"

int	line_len(char *str)
{
	int	i;
	char	del;

	i = 0;
	del = '\n';
	while (str[i])
	{
		if (str[i] == del)
			break;
		i++;
	}
	return (i);
}

int	is_line(char *str)
{
	int	i;
	char	del;

	i = 0;
	del = '\n';
	while (str[i])
	{
		if (str[i] == del)
			return (1);
		i++;
	}
	return (0);
}

char	*cpy_buffer(char *str)
{
	static char	*line;
	// static

}

char	*get_next_line(int fd)
{
	static char	buffer[1024];
	static int	bytes;
	static int	i = 0;
    
	while (bytes = read(fd, buffer, 10))
	{
		if (bytes <= 0)
			return NULL;
		buffer[bytes] = '\0';
		printf("buffer %s\n", buffer);
	}


	bytes = read(fd, buffer, 10);
	if (bytes <= 0)
		return NULL;
	while (!is_line(buffer))
	{
		
	}

/* 	buffer[bytes] = '\0';
	printf("buffer %s", buffer); */

	return (buffer);
}

int	main(void)
{
	int fd = open("../fitx.txt", O_RDONLY);

	if (fd == -1)
		return (1);
	get_next_line(fd);
	/* get_next_line(fd);
	get_next_line(fd); */
	// printf("%s", get_next_line(3));
	close (fd);
	return (0);
}