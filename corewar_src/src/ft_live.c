/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 12:12:05 by msrun             #+#    #+#             */
/*   Updated: 2017/03/15 18:18:31 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

extern unsigned char	*g_memory;
t_joueur				**g_list_joueurs;

unsigned int	ft_live2(int pos)
{
	unsigned int nb;

	nb = g_memory[ft_pc(pos)] * 256 * 256 * 256;
	nb += g_memory[ft_pc(pos + 1)] * 256 * 256;
	nb += g_memory[ft_pc(pos + 2)] * 256;
	nb += g_memory[ft_pc(pos + 3)];
	return (nb);
}

int				ft_live(t_process *proc)
{
	unsigned int	i;
	unsigned int	j;
	char			nb[4];

	++(proc->live);
	i = ft_live2(ft_pc(proc->pc + 1));
	j = -1;
	while (g_list_joueurs[++j])
	{
		if (i == (unsigned int)g_list_joueurs[j]->num_joueur)
		{
			++(g_list_joueurs[j]->nb_live);
			g_list_joueurs[j]->last_live = proc->act_cycle;
			break ;
		}
	}
	proc->pc = ft_pc(proc->pc + 5);
	ft_check_op(proc);
	return (-1);
}
