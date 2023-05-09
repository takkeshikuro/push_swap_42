/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_for_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 10:09:33 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/02/17 05:02:52 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	value_left_in_chunk(t_stack **a, int chunk_size)
{
	int		i;
	t_stack	*tmp;

	tmp = *a;
	i = 0;
	while (tmp)
	{
		if (tmp->index <= chunk_size)
			i++;
		tmp = tmp->next;
	}
	return (i);
}

int	find_max(t_stack *stack)
{
	int	max;

	max = stack->nbr;
	while (stack)
	{
		if (max < stack->nbr)
			max = stack->nbr;
		stack = stack->next;
	}
	return (max);
}

int	find_min(t_stack *stack)
{
	int	min;

	min = stack->nbr;
	while (stack != NULL)
	{
		if (min > stack->nbr)
			min = stack->nbr;
		stack = stack->next;
	}
	return (min);
}

int	get_pos(t_stack **a, int nbr)
{
	int		pos;
	t_stack	*tmp;

	tmp = *a;
	pos = 0;
	while (tmp)
	{
		if (tmp->nbr == nbr)
			return (pos);
		pos++;
		tmp = tmp->next;
	}
	return (0);
}
