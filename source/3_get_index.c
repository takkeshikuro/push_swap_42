/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_get_index.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 10:23:16 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/02/17 05:37:20 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	*sort_int_tab(int *tab, int size)
{
	int	swap;
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (tab[i] > tab[i + 1])
		{
			swap = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = swap;
			i = 0;
		}
		else
			i++;
	}
	return (tab);
}

void	get_exact_index(t_stack **stack, int *tab, int size)
{
	t_stack	*tmp;
	int		i;

	tmp = *stack;
	i = 0;
	while (tmp != NULL)
	{
		while (i < size)
		{
			if (tmp->nbr == tab[i])
			{
				tmp->index = i;
				i = 0;
				break ;
			}
			i++;
		}
		tmp = tmp->next;
	}
}

void	get_index(t_stack **stack)
{
	t_stack	*tmp;
	int		*tab;
	int		i;
	int		size;

	tmp = *stack;
	size = ft_lstsize(*stack);
	tab = malloc(sizeof(t_stack) * size);
	if (!tab)
	{
		free_lst(*stack);
		end_error();
	}
	i = 0;
	while (tmp != NULL)
	{
		tab[i] = tmp->nbr;
		i++;
		tmp = tmp->next;
	}
	tab = sort_int_tab(tab, size);
	get_exact_index(stack, tab, size);
	free(tab);
}
