/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 13:06:01 by msrun             #+#    #+#             */
/*   Updated: 2017/03/23 15:45:53 by bhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include <unistd.h>

extern unsigned char	*g_memory;

int	ft_aff(t_process *proc)
{
	unsigned char	c;

	if (g_memory[ft_pc(proc->pc + 2)] < 17 && g_memory[ft_pc(proc->pc + 2)] &&
			g_memory[ft_pc(proc->pc + 1)] == 64)
	{
		c = proc->registre[g_memory[(ft_pc(proc->pc + 2))] - 1][3];
		write(1, &c, 1);
		proc->pc = ft_pc(proc->pc + 3);
	}
	else
		proc->pc = ft_pc(proc->pc + 2);
	ft_check_op(proc);
	return (-1);
}
