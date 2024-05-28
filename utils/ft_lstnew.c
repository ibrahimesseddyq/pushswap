/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibes-sed <ibes-sed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 00:14:48 by ibes-sed          #+#    #+#             */
/*   Updated: 2024/05/28 02:56:11 by ibes-sed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../pushswap.h"

t_list	*ft_lstnew(int content)
{
	t_list	*index;

	index = (t_list *)malloc(sizeof(t_list));
	if (!index)
		return (NULL);
	index -> content = content;
	index -> next = NULL;
	return (index);
}
