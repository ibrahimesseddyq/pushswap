/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibes-sed <ibes-sed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 00:14:06 by ibes-sed          #+#    #+#             */
/*   Updated: 2024/06/02 23:43:52 by ibes-sed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


t_list	*ft_lstlast(t_list *lst)
{
	t_list	*start;
	int		i;

	if (lst == NULL)
		return (NULL);
	start = lst;
	i = 0;
	while (start -> next != NULL)
	{
		start = start -> next;
		i++;
	}
	return (start);
}
