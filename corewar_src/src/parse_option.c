/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_option.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 19:13:57 by bandre            #+#    #+#             */
/*   Updated: 2017/03/14 23:01:30 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void			parse_dump(int *dump, int *visu, int argc, char **argv)
{
	int i;

	i = 1;
	*dump = -1;
	*visu = -1;
	while (i < argc)
	{
		if (ft_strcmp("-dump", argv[i]) == 0)
		{
			i++;
			if (i < argc && ft_is_number(argv[i]) && *dump == -1)
			{
				if (ft_strlen(argv[i]) >= 14 ||
						ft_atoi(argv[i]) < 0 || ft_atoi(argv[i]) > INT_MAX)
					quit_clean(2);
				else
					*dump = ft_atoi(argv[i]);
			}
			else
				quit_clean(2);
		}
		if (ft_strcmp("-v", argv[i]) == 0)
			*visu = 1;
		i++;
	}
}

static void		init(t_parse *joueurs)
{
	int i;

	i = 0;
	while (i < 4)
	{
		joueurs[i].num = 0;
		joueurs[i].fichier = NULL;
		i++;
	}
}

static int		value_player(int value, t_parse *joueurs)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (joueurs[i].num == value)
			return (value_player(value - 1, joueurs));
		i++;
	}
	return (value);
}

void			par_extend(int *ptr[2], t_parse *joueurs,
		int argc, char **argv)
{
	if (ft_strcmp("-dump", argv[*ptr[0]]) == 0)
		*ptr[0] += 1;
	else if (ft_strcmp("-v", argv[*ptr[0]]) == 0)
		*ptr[0] = *ptr[0] + 1 - 1;
	else if (ft_strcmp("-n", argv[*ptr[0]]) == 0)
	{
		(*ptr[0])++;
		if (*ptr[0] + 1 < argc && ft_is_number(argv[*ptr[0]]))
		{
			joueurs[*ptr[1]].num = value_player(ft_atoi(argv[*ptr[0]]),
					joueurs);
			joueurs[*ptr[1]].fichier = argv[*ptr[0] + 1];
			(*ptr[1])++;
			(*ptr[0])++;
		}
		else
			quit_clean(2);
	}
	else
	{
		joueurs[*ptr[1]].fichier = argv[*ptr[0]];
		(*ptr[1])++;
	}
}

t_parse			*parse_number(int *dump, int *visu, int argc, char **argv)
{
	int			i;
	t_parse		*joueurs;
	int			tab;
	int			*ptr[2];

	tab = 0;
	i = 0;
	ptr[0] = &i;
	ptr[1] = &tab;
	if (!(joueurs = (t_parse*)malloc(sizeof(t_parse) * 4)))
		quit_clean(1);
	init(joueurs);
	parse_dump(dump, visu, argc, argv);
	while ((++i) < argc)
		par_extend(ptr, joueurs, argc, argv);
	i = 0;
	while (i < 4)
	{
		if (joueurs[i].num == 0)
			joueurs[i].num = value_player(-1, joueurs);
		i++;
	}
	if (tab == 0 || tab > 4)
		quit_clean(2);
	return (joueurs);
}
