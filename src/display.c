/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchetty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/16 11:08:21 by kchetty           #+#    #+#             */
/*   Updated: 2016/06/16 11:32:15 by kchetty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	display(t_flag_a **first)
{
	while (first)
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
}
