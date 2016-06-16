/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnovan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 08:56:06 by arnovan-          #+#    #+#             */
/*   Updated: 2016/06/16 16:03:30 by kchetty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	read_files(t_args flags, t_DIR dir)
{
	t_flag_a	*first_a = NULL;
	t_flag_l	*first_l = NULL;

	if ((flags.flag_a == 1) && (flags.flag_l == 0))
		flag_a(dir, &first_a);
	if (flags.flag_l == 1)
		flag_l(dir, flags, &first_l);
	if (flags.flag_r == 1)
		flag_r(&first_a, &first_l);
	ft_display(first_a, first_l);



	//if (flags.flag_r == 1)
	//flag_r(dir);	
/*	while (first_a)
	{
		write(1, first_a->name, first_a->len);
		write(1, "\n", 1);
		first_a = first_a->next;
	}

	while (first_l)
	{
		if ((first_l->user != NULL) && (first_l->link != 0))
		{
			ft_putstr(first_l->perno);
			ft_putnbr(first_l->link);
			ft_putstr(first_l->user);
			ft_putstr(first_l->group);
			ft_putnbr(first_l->byte);
			ft_putstr(first_l->time);
			ft_putstr(first_l->name);
			write(1, "\n", 1);

			//printf("\n\nfilename: %s\n filesize: %i\n 
			//permision: %u\n link: %u\n user: %s\n group: %s\n time: %s\n", 
			//first->name, first->byte, first->perno, 
			//first->link, first->user, first->group, first->time) ;
		}
		first_l = first_l->next;
	}*/

}
