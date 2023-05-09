/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 07:35:48 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/02/17 05:03:37 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	free_lst(t_stack *lst)
{
	t_stack		*current;
	t_stack		*temp;

	current = lst;
	while (current != NULL)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
}

t_stack	*ft_lstlast(t_stack *lst)
{
	if (lst)
	{
		while (lst->next != NULL)
			lst = lst->next;
	}	
	return (lst);
}

int	ft_lstsize(t_stack *lst)
{
	int		size;
	t_stack	*ok;

	ok = lst;
	size = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		size++;
	}
	lst = ok;
	return (size);
}

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*tmp;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	tmp = *lst;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
}
