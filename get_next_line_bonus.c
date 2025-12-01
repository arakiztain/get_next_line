/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakiztain <arakiztain@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 13:15:51 by arakiztain        #+#    #+#             */
/*   Updated: 2025/10/28 13:46:39 by arakiztain       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*stash[1024];
	char		*buffer;
	char		*line;
	int			bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes = 1;
	while (!is_line(stash[fd]) && bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
			return (free(stash[fd]), stash[fd] = NULL, free(buffer), NULL);
		buffer[bytes] = '\0';
		stash[fd] = str_join(stash[fd], buffer);
	}
	line = extract_line(stash[fd]);
	stash[fd] = save_remainder(stash[fd]);
	free(buffer);
	return (line);
}

/* #include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line_bonus.h"

int main(void)
{
    int     fd1;
    int     fd2;
    char    *line1;
    char    *line2;

    fd1 = open("test2.txt", O_RDONLY);
    fd2 = open("test3.txt", O_RDONLY);
    if (fd1 < 0 || fd2 < 0)
        return (perror("open"), 1);

    printf("Leyendo alternamente entre fd1 y fd2:\n\n");

    while (1)
    {
        line1 = get_next_line(fd1);
        line2 = get_next_line(fd2);

        if (!line1 && !line2)
            break;

        if (line1)
        {
            printf("fd1: %s", line1);
            free(line1);
        }
        if (line2)
        {
            printf("fd2: %s", line2);
            free(line2);
        }
    }

    close(fd1);
    close(fd2);
    return (0);
} */