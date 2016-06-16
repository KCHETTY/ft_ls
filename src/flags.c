/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnovan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 08:43:31 by arnovan-          #+#    #+#             */
/*   Updated: 2016/06/16 15:59:00 by kchetty          ###   ########.fr       */
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

void	flag_r(t_flag_a **first_a, t_flag_l **first_l)
{
	if (*first_a != NULL)
	{
		t_flag_a	*current;
		t_flag_a	*prev;
		t_flag_a	*next;
		current = *first_a;
		prev = NULL;
		while (current)
		{
			next = current->next;
			current->next = prev;
			prev = current;
			current = next;
		}
		*first_a = prev;
	}
	if (*first_l != NULL)
	{
		t_flag_l    *current;
		t_flag_l    *prev;
		t_flag_l    *next;
		current = *first_l;
		prev = NULL;
		while (current)
		{
			next = current->next;
			current->next = prev;
			prev = current;
			current = next;
		}
		*first_l = prev;
	}
}
