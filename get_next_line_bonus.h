/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakiztain <arakiztain@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 10:55:33 by arakiztain        #+#    #+#             */
/*   Updated: 2025/11/10 13:00:12 by arakiztain       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	int				fd;
	char			*content;
	struct s_list	*next;
}			t_list;
char	*get_next_line(int fd);
int		ft_str_len(char *str);
int		is_line(char *str);
char	*str_join(char *s1, char *s2);
char	*extract_line(char *stash);
char	*save_remainder(char *stash);

#endif