/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminadzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 20:01:30 by aminadzh          #+#    #+#             */
/*   Updated: 2018/01/25 20:08:07 by aminadzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"
# include <fcntl.h>

# define BUFF_SIZE 1
# define STACK_STR ((t_stack *)(*stack)->content)->str
# define STACK_DESC ((t_stack *)(*stack)->content)->desc

typedef struct	s_stack
{
	char		*str;
	int			desc;
}				t_stack;

int				get_next_line(const int fd, char **line);

#endif
