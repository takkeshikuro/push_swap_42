/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_ft_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:57:36 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/02/17 05:01:16 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rotate_min(t_stack **a, int min)
{
	int	pos;

	pos = get_pos(a, min);
	if (pos <= (ft_lstsize(*a) / 2))
	{
		while ((*a)->nbr != min)
			ft_ra(a);
	}
	else if (pos > (ft_lstsize(*a) / 2))
	{
		while ((*a)->nbr != min)
			ft_rra(a);
	}
}

void	sort_3_value(t_stack **a)
{
	int		min;
	int		max;

	min = find_min(*a);
	max = find_max(*a);
	while (!check_if_sorted(a))
	{
		if ((*a)->nbr == min)
		{
			ft_sa(a);
			ft_ra(a);
			break ;
		}
		if ((*a)->nbr > (*a)->next->nbr)
			ft_sa(a);
		if ((*a)->next->nbr == max)
			ft_rra(a);
	}	
}

void	sort_5_value(t_stack **a, t_stack **b)
{
	int	min;

	while (ft_lstsize(*a) > 3)
	{
		min = find_min(*a);
		rotate_min(a, min);
		ft_pb(a, b);
	}
	sort_3_value(a);
	while (ft_lstsize(*b) > 0)
		ft_pa(a, b);
}

void	ft_sort(t_stack **stack, int size)
{
	t_stack		*a;
	t_stack		*b;

	a = *stack;
	b = NULL;
	if (size <= 3)
		sort_3_value(&a);
	else if (size <= 5)
		sort_5_value(&a, &b);
	else
		big_sort(&a, &b);
	free_lst(a);
}
