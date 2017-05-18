/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamidi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 15:13:34 by bhamidi           #+#    #+#             */
/*   Updated: 2017/03/16 12:56:15 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*ptr;

	ptr = NULL;
	if (!(ptr = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		ptr->content_size = 0;
		ptr->content = NULL;
	}
	else
	{
		if (!(ptr->content = malloc(sizeof(*ptr->content) * content_size)))
			return (NULL);
		ptr->content = ft_memcpy(ptr->content, content, content_size);
		ptr->content_size = content_size;
	}
	ptr->next = NULL;
	return (ptr);
}
