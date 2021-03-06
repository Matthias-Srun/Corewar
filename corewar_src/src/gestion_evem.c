/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_evem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 01:45:43 by bandre            #+#    #+#             */
/*   Updated: 2017/03/15 17:53:04 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int				gestion_event(t_option option, int cycles,
		SDL_Surface *ecran, TTF_Font *police)
{
	SDL_Event	event;

	if (option.visu == 1)
	{
		if (cycles % 10 == 0)
		{
			afficher_cycles(ecran, police, cycles);
			afficher_live(ecran, police, -1);
			afficher_proc(ecran, police);
			SDL_Flip(ecran);
		}
		SDL_PollEvent(&event);
		if (event.type == SDL_QUIT)
			return (0);
	}
	return (1);
}

void			gestion_cycles(int *cycles, t_option option, int *cycles_to_die,
		int *checks)
{
	if (*cycles == 0 && !count_live())
		(*checks)++;
	if ((*checks > 10 || count_live()) && *cycles == 0)
	{
		(*cycles_to_die) -= CYCLE_DELTA;
		*cycles = (*cycles_to_die);
		*checks = 0;
		test_live();
	}
	else if (*cycles == 0)
	{
		test_live();
		*cycles = *cycles_to_die;
	}
}
