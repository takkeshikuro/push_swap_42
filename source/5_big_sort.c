/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_big_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 10:49:54 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/02/17 05:01:41 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	pos_from_start(t_stack **a, int chunk_size)
{
	int		comp;
	t_stack	*tmp;

	tmp = *a;
	comp = 0;
	while (tmp)
	{
		if (tmp->index <= chunk_size)
			return (comp);
		comp++;
		tmp = tmp->next;
	}
	return (0);
}

int	pos_from_end(t_stack **a, int chunk_size)
{
	int		comp;
	t_stack	*tmp;

	tmp = *a;
	comp = 0;
	while (tmp)
	{
		if (tmp->index <= chunk_size)
			comp = 0;
		tmp = tmp->next;
		comp++;
	}
	return (comp);
}

void	push_to_b(t_stack **a, t_stack **b, int chunk_size)
{
	while (*a)
	{
		while (value_left_in_chunk(a, chunk_size))
		{
			if (pos_from_start(a, chunk_size) <= pos_from_end(a, chunk_size))
				ft_ra(a);
			else
				ft_rra(a);
			if ((*a)->index <= chunk_size)
			{
				ft_pb(a, b);
				if ((*b)->index > chunk_size / 2)
					ft_rb(b);
			}
		}
		get_index(a);
	}
}

void	push_to_a(t_stack **a, t_stack **b)
{
	int	size;

	while (*b)
	{
		size = ft_lstsize(*b);
		while ((*b)->nbr != find_max(*b))
		{
			if (get_pos(b, find_max(*b)) < (size / 2))
				ft_rb(b);
			else
				ft_rrb(b);
		}
		ft_pa(a, b);
	}
}

void	big_sort(t_stack **a, t_stack **b)
{
	int	size;
	int	nbr_of_chunk;
	int	chunk_size;

	size = ft_lstsize(*a);
	if (size)
	{
		if (size <= 200)
			nbr_of_chunk = 5;
		else
			nbr_of_chunk = 10;
	}
	chunk_size = size / nbr_of_chunk;
	push_to_b(a, b, chunk_size);
	push_to_a(a, b);
}
