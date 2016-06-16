/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_l.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchetty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 09:50:12 by kchetty           #+#    #+#             */
/*   Updated: 2016/06/16 11:34:00 by kchetty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char	*ft_format(char *str)
{
	int i;
	int j;
	char *format = NULL;

	format = (char *)malloc(sizeof(char) * 13);
	i = 0;
	j = 4;
	while (j >= 4 && j <= 15)
	{
		format[i++] = str[j++];
	}
	format[i++] = '\0';
	return(format);
}

char	*ft_getpermissions(struct stat *f_stat)
{
	char	*str = NULL;

	str = (char *)malloc(sizeof(char) * 10);
	str[0] = (S_ISDIR(f_stat->st_mode)) ? 'd' : '-';
	str[1] = (f_stat->st_mode & S_IRUSR) ? 'r' : '-';
	str[2] = (f_stat->st_mode & S_IWUSR) ? 'w' : '-';
	str[3] = (f_stat->st_mode & S_IXUSR) ? 'x' : '-';
	str[4] = (f_stat->st_mode & S_IRGRP) ? 'r' : '-';
	str[5] = (f_stat->st_mode & S_IWGRP) ? 'w' : '-';
	str[6] = (f_stat->st_mode & S_IXGRP) ? 'x' : '-';
	str[7] = (f_stat->st_mode & S_IROTH) ? 'r' : '-';
	str[8] = (f_stat->st_mode & S_IWOTH) ? 'w' : '-';
	str[9] = (f_stat->st_mode & S_IXOTH) ? 'x' : '-';
	str[10] = '\0';
	return (str);
}


void	flag_l(t_DIR ref, t_args flags)
{
	time_t		*mtime;
	ref.dir = opendir(".");
	t_flag_l	*first = NULL;
	t_flag_l	*node;

	if (flags.flag_a == 1)
	{	
		while ((ref.strdir = readdir(ref.dir)) != NULL)
		{
			stat(ref.strdir->d_name, &ref.buf);
			ref.pwd         = getpwuid(ref.buf.st_uid);
			ref.grp         = getgrgid(ref.buf.st_gid);
			mtime = &ref.buf.st_mtimespec.tv_sec;
			if (first == NULL)
			{
				first = (t_flag_l *)malloc(sizeof(t_flag_l));	
				node = first;
			}
			node->perno		= ft_getpermissions(&ref.buf);
			node->link		= ref.buf.st_nlink;
			//ref.pwd			= getpwuid(ref.buf.st_uid);
			node->user		= ref.pwd->pw_name;
			//ref.grp			= getgrgid(ref.buf.st_gid);
			node->group		= ref.grp->gr_name;
			node->byte		= ref.buf.st_size;    
			node->time		= ft_format(ctime(mtime));
			node->name		= ref.strdir->d_name;
			node->next		= (t_flag_l *)malloc(sizeof(t_flag_l));
			node			= node->next;
		}
		node->next = NULL;
	}

	closedir(ref.dir);
/*
 * while (first)
	{
		if ((first->user != NULL) && (first->link != 0))
		{
			ft_putstr(first->perno);
			ft_putnbr(first->link);
			ft_putstr(first->user);
			ft_putstr(first->group);
			ft_putnbr(first->byte);
			ft_putstr(first->time);
			ft_putstr(first->name);
			write(1, "\n", 1);

			//printf("\n\nfilename: %s\n filesize: %i\n 
			//permision: %u\n link: %u\n user: %s\n group: %s\n time: %s\n", 
			//first->name, first->byte, first->perno, 
			//first->link, first->user, first->group, first->time) ;
		}
		first = first->next;
	}
*/
	//free(node);
}

