/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 18:45:56 by bandre            #+#    #+#             */
/*   Updated: 2017/03/15 16:57:52 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "../../libsdl/include/SDL/SDL_ttf.h"
# include "../../libsdl/include/SDL/SDL.h"
# include "../libft/libft/libft.h"
# include "corewar_msrun.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct	s_parse
{
	int			num;
	char		*fichier;
}				t_parse;

typedef struct	s_option
{
	int			dump;
	int			visu;
	int			total_cycles;
}				t_option;

int				recup_param(t_parse *num_joueurs, SDL_Surface
		*ecran, t_option option);
void			quit_clean(int error);
int				test_valide(int fd, int num_joueur);
t_joueur		*new_t_joueur(char *name, char *cri, int num);
t_process		*new_t_process(int r1, int nb_joueurs, t_process *next,
		t_process *previous);
void			print_memory(void);
int				boucle_principal(SDL_Surface *ecran,
		TTF_Font *police, t_option option);
int				show_winner(SDL_Surface *ecran, TTF_Font *police,
		t_option option);
t_parse			*parse_number(int *dump, int *visu, int argc, char **argv);
void			affichage(SDL_Surface *ecran, TTF_Font *police, int cycles);

void			color_change(int pc, int nb, SDL_Surface *ecran,
		int num_joueur);
void			afficher_cycles(SDL_Surface *ecran, TTF_Font *police,
		int cycles);
void			ft_check_op(t_process *proc);
void			affichage_mem_change(SDL_Surface *ecran, TTF_Font *police,
				int num_joueur, int pc);
void			sdl_color_init(SDL_Color *color);
void			blit_text(SDL_Surface *ecran, SDL_Surface *text, int pc);

void			gestion_cycles(int *cycles, t_option option, int *cycles_to_die,
		int *checks);
int				gestion_event(t_option option, int cycles,
		SDL_Surface *ecran, TTF_Font *police);

void			test_live(void);
int				count_live(void);
void			afficher_live(SDL_Surface *ecran, TTF_Font *police, int i);
SDL_Rect		rect_noir(int w, int h, int x, int y);
void			afficher_live(SDL_Surface *ecran, TTF_Font *police, int i);
void			afficher_proc(SDL_Surface *ecran, TTF_Font *police);

#endif
