#include "get_next_line.h"

int ft_str_len(char *str)
{
    int i;

	i = 0;
    if (!str)
        return (0);
    while (str[i])
        i++;
    return (i);
}

int is_line(char *str)
{
    int i;

	i = 0;
    if (!str)
        return (0);
    while (str[i])
    {
        if (str[i] == '\n')
            return (1);
        i++;
    }
    return (0);
}

char    *str_join(char *s1, char *s2)
{
    int len1;
    int len2;
    char    *new_str;
    int i;
    int j;

	len1 = ft_str_len(s1);
	len2 = ft_str_len(s2);
	i = 0;
	j = 0;
    if (!s2 || len2 == 0)
        return (s1);
    new_str = malloc(len1 + len2 + 1);
    if (!new_str)
    {
        if (s1)
            free(s1);
        return (NULL);
    }
    while (s1 && s1[i])
    {
        new_str[i] = s1[i];
        i++;
    }
    while (s2[j])
        new_str[i++] = s2[j++];
    new_str[i] = '\0';
    if (s1)
        free(s1);
    return (new_str);
}

char    *extract_line(char *stash)
{
    int	i;
    char    *line;

	i = 0;
    if (!stash || !stash[0])
        return (NULL);
    while (stash[i] && stash[i] != '\n')
        i++;
    if (stash[i] == '\n')
        i++;
    line = malloc(i + 1);
    if (!line)
        return (NULL);
    i = 0;
    while (stash[i] && stash[i] != '\0' && stash[i] != '\n')
    {
        line[i] = stash[i];
        i++;
    }
    if (stash[i] == '\n')
        line[i++] = '\n';
    line[i] = '\0';
    return (line);
}

char    *save_remainder(char *stash)
{
    int len_line;
    int len_total;
    char    *new_stash;
    int i;

	len_line = 0;
	i = 0;
    if (!stash || !stash[0])
        return (NULL);
    while (stash[len_line] && stash[len_line] != '\n')
        len_line++;
    if (stash[len_line] == '\n')
        len_line++;
    len_total = ft_str_len(stash);
    if (len_line >= len_total)
    {
        free(stash);
        return (NULL);
    }
    new_stash = malloc(len_total - len_line + 1);
    if (!new_stash)
    {
        free(stash);
        return (NULL);
    }
    while (stash[len_line + i])
    {
        new_stash[i] = stash[len_line + i];
        i++;
    }
    new_stash[i] = '\0';
    free(stash);
    return (new_stash);
}