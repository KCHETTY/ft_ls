/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchetty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 08:51:14 by kchetty           #+#    #+#             */
/*   Updated: 2016/06/14 08:13:55 by kchetty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	process_args(char **argv, t_args *flags);

int		flag_ls(t_DIR dir)
{
	dir.dir = opendir(".");

	if (dir.dir == NULL)
	{
		write(1, "ERROR -> NO DIRECTORY", 21);
		return (2);
	}

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
	{
		write(1, "ERROR -> NO DIRECTORY", 21);
	}


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

void	read_files(t_args flags, t_DIR dir)
{
	t_flag_a	*first = NULL;

	if ((flags.flag_a == 1) && (flags.flag_l == 0))
		flag_a(dir, &first);
	//if (flags.flag_l == 1)
	//	flag_l();
	//if (flags.flag_r == 1)
		//flag_r(dir);	
	while (first)
	{
		write(1, first->name, first->len);
		write(1, "\n", 1);
		first = first->next;
	}
}

int		main(int argc, char **argv)
{
	t_args		flags;
	t_DIR		dir;

	if (argc == 1)
		flag_ls(dir);
	if (argc > 1)
	{
		process_args(argv, &flags);
		read_files(flags, dir);
	}

		printf("R: %d\n", flags.flag_R);
		printf("r: %d\n", flags.flag_r);
		printf("a: %d\n", flags.flag_a);
		printf("l: %d\n", flags.flag_l);
		printf("t: %d\n", flags.flag_t);
	return (0);		
}

void	process_args(char **argv, t_args *flags)
{
	int		i;
	int		j;

	i = 1;
	while (argv[i] != NULL)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			//printf("%c\n", argv[i][j]);
			if (argv[i][j] == 'R')
				flags->flag_R = 1;
			if (argv[i][j] == 'r')
				flags->flag_r = 1;
			if (argv[i][j] == 'a')
				flags->flag_a = 1;
			if (argv[i][j] == 'l')
				flags->flag_l = 1;
			if (argv[i][j] == 't')
				flags->flag_t = 1;
			j++;
		}
		i++;
	}
}
