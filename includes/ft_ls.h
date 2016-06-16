/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchetty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 09:03:32 by kchetty           #+#    #+#             */
/*   Updated: 2016/06/16 11:29:20 by kchetty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"

# include <unistd.h>
# include <time.h>
# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <stdlib.h>
# include <stdio.h>
# include <pwd.h>
# include <grp.h>

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
	struct stat		buf;
	struct passwd	*pwd;
	struct group	*grp;
}	t_DIR;

typedef struct s_flag_a
{
	char	*name;
	int		len;
	struct s_flag_a *next;
}	t_flag_a;

typedef struct s_flag_l
{
	char			*perno;
	unsigned short	link;
	char		 	*user;
	char		 	*group;
	int				byte;
	char	*date;
	char	*mdno;
	char 	*time;
	char	*name;
	struct s_flag_l *next;
}	t_flag_l;

void
int		dir_error(void);
int		flag_ls(t_DIR dir);
void	flag_a(t_DIR dir, t_flag_a **first);
void	flag_l(t_DIR dir, t_args flags);
void	read_files(t_args flags, t_DIR dir);

#endif
