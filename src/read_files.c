/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnovan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 08:56:06 by arnovan-          #+#    #+#             */
/*   Updated: 2016/06/16 11:16:49 by kchetty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	read_files(t_args flags, t_DIR dir)
{
	t_flag_a	*first = NULL;

	if ((flags.flag_a == 1) && (flags.flag_l == 0))
		flag_a(dir, &first);
	if (flags.flag_l == 1)
		flag_l(dir, flags);
	//if (flags.flag_r == 1)
		//flag_r(dir);	
/*	while (first)
	{
		write(1, first->name, first->len);
		write(1, "\n", 1);
		first = first->next;
	}*/
}
