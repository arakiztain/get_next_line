#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

char    *get_next_line(int fd);
int ft_str_len(char *str);
int is_line(char *str);
char    *str_join(char *s1, char *s2);
char    *extract_line(char *stash);
char    *save_remainder(char *stash);

#endif