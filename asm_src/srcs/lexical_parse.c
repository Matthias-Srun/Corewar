/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexical_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamidi <bhamidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 22:01:34 by bhamidi           #+#    #+#             */
/*   Updated: 2017/03/23 15:49:41 by bhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int		get_str(char *str)
{
	int		i;
	char	*tmp;

	tmp = NULL;
	i = -1;
	while (str[++i] != '\0')
		if (str[i + 1] == ' ' || str[i + 1] == '\0')
			break ;
	tmp = ft_strnew(sizeof(char) * i);
	ft_strncpy(tmp, str, i + 1);
	i = get_op_tab(tmp);
	ft_strdel(&tmp);
	return (i);
}

char	*match_str(char *str)
{
	int		i;
	char	*dst;

	dst = NULL;
	i = -1;
	while (str[++i] != '\0')
		if (str[i] == LABEL_CHAR && !get_str(str + i + 1)
				&& str[i - 1] != DIRECT_CHAR)
		{
			dst = ft_strnew(sizeof(char) * ft_strlen(str) + 1);
			ft_strncpy(dst, str, i + 1);
			ft_strcat(dst, " ");
			ft_strcat(dst, str + i + 1);
			ft_strdel(&str);
			return (dst);
		}
	return (str);
}

int		verif_sepa(char *str)
{
	char	**tab;
	int		i;

	i = -1;
	if (!(tab = ft_space(str)))
		return (1);
	if (!ft_strcmp(NAME_CMD_STRING, tab[0])
			|| !ft_strcmp(COMMENT_CMD_STRING, tab[0]))
		return (free_tab(&tab) - 1);
	if (ft_strchr(tab[0], SEPARATOR_CHAR))
		return (free_tab(&tab));
	while (tab[++i] != 0)
		if (i > 0)
		{
			if (tab[i][0] == ',' &&
					tab[i - 1][ft_strlen(tab[i - 1]) - 1] == ',')
				return (free_tab(&tab));
		}
	if (tab[i - 1][ft_strlen(tab[i - 1]) - 1] == ',')
		return (free_tab(&tab));
	if (i > 2)
		if (tab[1][0] == SEPARATOR_CHAR)
			return (free_tab(&tab));
	return (free_tab(&tab) - 1);
}

char	**get_tab(char *str, int line, t_stable **head)
{
	char	**tab;
	int		i;
	int		n;

	i = -1;
	if (!(n = 0) && verif_sepa(str))
	{
		free_str_head(head, &str);
		print_error_lexical(line);
	}
	if (!(tab = ft_white(str)))
		return (0);
	if (!ft_strcmp(NAME_CMD_STRING, tab[0])
			|| !ft_strcmp(COMMENT_CMD_STRING, tab[0]))
		return (tab);
	while (tab[++i] != 0)
		if (get_num(tab[i]) != -1)
			n++;
	if (n > 1 || verif_nb_separator(get_occurs(str, ','), tab, str))
	{
		free_str_tab_stab(&str, &tab, head);
		print_error_lexical(line);
	}
	return (tab);
}

int		lexical_parse(t_stable **head, int fd)
{
	char	*str;
	int		i;
	char	**tab;

	i = 0;
	str = NULL;
	while (!(tab = NULL) && get_next_line(fd, &str) > 0)
	{
		if ((++i) && str)
		{
			clean_comment(str);
			if (ft_strlen(str))
				if ((tab = get_tab(str, i, head)))
					if (fill_stable(tab, head, str, i))
					{
						free_str_tab_stab(&str, &tab, head);
						print_error_lexical(i);
					}
		}
		free_str_tab(&str, &tab);
	}
	close(fd);
	return (0);
}
