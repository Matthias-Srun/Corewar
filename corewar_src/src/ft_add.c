/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 12:23:08 by msrun             #+#    #+#             */
/*   Updated: 2017/03/15 17:42:48 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

extern unsigned char	*g_memory;

static void	ft_add_it(unsigned char *tab1, unsigned char *tab2,
		unsigned char *tab3)
{
	long int	nb1;
	long int	nb2;
	int			i;

	i = -1;
	nb1 = 0;
	nb2 = 0;
	while (++i < 4)
	{
		nb1 += nb1 * 255 + tab1[i];
		nb2 += nb2 * 255 + tab2[i];
	}
	nb1 = (nb1 + nb2) % 4294967296;
	i = -1;
	while (++i < 4)
	{
		tab3[3 - i] = nb1 % 256;
		nb1 /= 256;
	}
}

int			ft_add(t_process *proc)
{
	if (g_memory[ft_pc(proc->pc + 1)] == 84)
	{
		if (g_memory[ft_pc(proc->pc + 2)] < 17 && g_memory[ft_pc(proc->pc + 2)]
	&& g_memory[ft_pc(proc->pc + 3)] < 17 && g_memory[ft_pc(proc->pc + 3)] &&
		g_memory[ft_pc(proc->pc + 4)] < 17 && g_memory[ft_pc(proc->pc + 4)])
			ft_add_it(proc->registre[g_memory[ft_pc(proc->pc + 2)] - 1],
			proc->registre[g_memory[ft_pc(proc->pc + 3)] - 1],
			proc->registre[g_memory[ft_pc(proc->pc + 4)] - 1]);
		proc->carry =
	(ft_dir_uint(proc->registre[g_memory[ft_pc(proc->pc + 5)] - 1])) ? 0 : 1;
		proc->pc = ft_pc(proc->pc + 5);
	}
	else
		proc->pc = ft_pc(proc->pc + 2);
	ft_check_op(proc);
	return (-1);
}
