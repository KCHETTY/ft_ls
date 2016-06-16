/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchetty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/16 11:08:21 by kchetty           #+#    #+#             */
/*   Updated: 2016/06/16 12:37:35 by kchetty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_display(t_flag_a *first_a, t_flag_l *first_l)
{
	if (first_a != NULL)
	{
		while (first_a)
		{
			write(1, first_a->name, first_a->len);
			write(1, "\n", 1);
			first_a = first_a->next;
		}
	}
	else if (first_l != NULL)
	{
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
		}
	}
}
