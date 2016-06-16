/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnovan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 08:46:43 by arnovan-          #+#    #+#             */
/*   Updated: 2016/06/14 09:01:05 by arnovan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		dir_error(void)
{
		write(1, "No such file or directory", 21);
		return (2);
}


/*
void	ft_malloc_error(void)
{
		ft_putstr("Encountered a malloc error\n");
			exit(1);
}

void	ft_arg_error(void)
{
		ft_putstr("Invalid map file\n");
			ft_putstr("Usage ./fdf 42.fdf\n");
				exit(1);	
}

void	ft_file_error(void)
{
		ft_putstr("Error opening file\n");
			exit(1);
}

*/
