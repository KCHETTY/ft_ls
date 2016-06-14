/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchetty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 09:03:32 by kchetty           #+#    #+#             */
/*   Updated: 2016/06/13 14:15:51 by kchetty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <unistd.h>
# include <time.h>
# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_arguments
{
	int			flag_R;
	int			flag_r;
	int			flag_a;
	int			flag_l;
	int			flag_t;
}	t_args;

typedef struct s_DIR
{
	DIR				*dir;
	struct dirent	*strdir;
}	t_DIR;

typedef struct s_flag_a
{
	char	*name;
	int		len;
	struct s_flag_a *next;
}	t_flag_a;

#endif
