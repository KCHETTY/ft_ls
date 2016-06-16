/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchetty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 08:51:14 by kchetty           #+#    #+#             */
/*   Updated: 2016/06/16 10:20:03 by kchetty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

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
