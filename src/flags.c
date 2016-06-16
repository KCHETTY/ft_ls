/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnovan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 08:43:31 by arnovan-          #+#    #+#             */
/*   Updated: 2016/06/16 09:33:50 by kchetty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		flag_ls(t_DIR dir)
{
	dir.dir = opendir(".");

	if (dir.dir == NULL)
		dir_error();

	while ((dir.strdir = readdir(dir.dir)) != NULL)
	{
		if (dir.strdir->d_name[0] != '.')
		{
			write(1, dir.strdir->d_name, dir.strdir->d_namlen);
			write(1, "\n", 1);
		}
	}
	closedir(dir.dir);
	return (0);
}

void	flag_a(t_DIR dir, t_flag_a **first)
{
	t_flag_a	*current;
	dir.dir = opendir(".");

	//move to seperate erroe file
	if (dir.dir == NULL)
		dir_error();

	while ((dir.strdir = readdir(dir.dir)) != NULL)
	{
		if (*first == NULL)
		{
			*first  = (t_flag_a *)malloc(sizeof(t_flag_a));
			current = *first;
		}
		current->name = dir.strdir->d_name;
		//printf("%s ", current->name);
		current->len = dir.strdir->d_namlen;
		//printf("%d\n", current->len);
		current->next = (t_flag_a *)malloc(sizeof(t_flag_a));
		current = current->next;
	}
	current->next = NULL;
	closedir(dir.dir);
	free(current);
}

//void	flag_l()
//{


//}


