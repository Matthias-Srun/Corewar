/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 15:54:59 by msrun             #+#    #+#             */
/*   Updated: 2017/03/15 16:20:20 by msrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

extern t_joueur	**g_list_joueurs;
extern t_process	*g_list_process;

void			aff_live_p(SDL_Surface *ecran, TTF_Font *police, int i)
{
	char		*value;
	SDL_Surface	*text;
	SDL_Rect	position;
	SDL_Rect	rect;
	SDL_Color	white;

	if (g_list_joueurs[i]->last_live == 0)
	{
		sdl_color_init(&white);
		rect = rect_noir(200, 25, 1500, 450 + ((i * 2) * 25));
		SDL_FillRect(ecran, &rect, SDL_MapRGB(ecran->format, 255, 255, 255));
		text = TTF_RenderText_Blended(police, "Last live player", white);
		position.x = 1500;
		position.y = 450 + ((i * 2) * 25);
		SDL_BlitSurface(text, NULL, ecran, &position);
		if (!(value = ft_itoa_base_signed((int)g_list_joueurs[i]->num_joueur,
						10, 0)))
			quit_clean(1);
		text = TTF_RenderText_Blended(police, value, white);
		free(value);
		position.x = 1600;
		SDL_BlitSurface(text, NULL, ecran, &position);
		SDL_FreeSurface(text);
	}
}

void			afficher_live(SDL_Surface *ecran, TTF_Font *police, int i)
{
	SDL_Surface		*text;
	char			*value;
	SDL_Color		white;
	SDL_Rect		position;
	SDL_Rect		rect;

	while (g_list_joueurs[++i])
	{
		sdl_color_init(&white);
		aff_live_p(ecran, police, i);
		rect = rect_noir(200, 25, 1500, 475 + ((i * 2) * 25));
		SDL_FillRect(ecran, &rect, SDL_MapRGB(ecran->format, 255, 255, 255));
		if (!(value = ft_itoa_base(g_list_joueurs[i]->last_live, 10, 0)))
			quit_clean(1);
		text = TTF_RenderText_Blended(police, value, white);
		position.x = 1500;
		position.y = 475 + ((i * 2) * 25);
		SDL_BlitSurface(text, NULL, ecran, &position);
		SDL_FreeSurface(text);
		free(value);
	}
}

unsigned int	ft_nb_mlist(void)
{
	t_process		*tmp;
	unsigned int	i;

	i = 0;
	tmp = g_list_process;
	while (tmp)
	{
		++i;
		tmp = tmp->next;
	}
	return (i);
}

void			afficher_proc(SDL_Surface *ecran, TTF_Font *police)
{
	SDL_Surface		*text;
	char			*value;
	SDL_Color		white;
	SDL_Rect		position;
	SDL_Rect		rect;

	sdl_color_init(&white);
	rect = rect_noir(200, 25, 1500, 350);
	SDL_FillRect(ecran, &rect, SDL_MapRGB(ecran->format, 255, 255, 255));
	if (!(value = ft_itoa_base(ft_nb_mlist(), 10, 0)))
		quit_clean(1);
	text = TTF_RenderText_Blended(police, "Nb process:", white);
	position.x = 1500;
	position.y = 350;
	SDL_BlitSurface(text, NULL, ecran, &position);
	SDL_FreeSurface(text);
	text = TTF_RenderText_Blended(police, value, white);
	position.x = 1580;
	SDL_BlitSurface(text, NULL, ecran, &position);
	SDL_FreeSurface(text);
	free(value);
}
