/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 13:30:13 by bandre            #+#    #+#             */
/*   Updated: 2017/03/15 16:54:13 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

extern unsigned char		*g_memory;

void	print_memory(void)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 128)
	{
		j = 0;
		while (j < 32)
		{
			ft_printf("%02hhx ", g_memory[i * 32 + j]);
			j++;
		}
		ft_putendl("");
		i++;
	}
	quit_clean(5);
}
