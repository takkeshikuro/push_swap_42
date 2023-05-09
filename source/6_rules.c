/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_rules.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 12:02:08 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/02/11 09:48:31 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_index(t_stack **stack)
{
	int	tmp;

	if (*stack == NULL)
		return ;
	tmp = (*stack)->index;
	(*stack)->index = (*stack)->next->index;
	(*stack)->next->index = tmp;
}

void	ft_sa(t_stack **a)
{
	int	tmp;

	if (*a == NULL)
		return ;
	ft_index(a);
	tmp = (*a)->nbr;
	(*a)->nbr = (*a)->next->nbr;
	(*a)->next->nbr = tmp;
	ft_putendl_fd("sa", 1);
}

void	ft_sb(t_stack **b)
{
	int	tmp;

	if (*b == NULL)
		return ;
	ft_index(b);
	tmp = (*b)->nbr;
	(*b)->nbr = (*b)->next->nbr;
	(*b)->next->nbr = tmp;
	ft_putendl_fd("sb", 1);
}

void	ft_pa(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (!*b)
		return ;
	tmp = *a;
	*a = *b;
	*b = (*b)->next;
	(*a)->next = tmp;
	ft_putendl_fd("pa", 1);
}

void	ft_pb(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (!*a)
		return ;
	tmp = *b;
	*b = *a;
	*a = (*a)->next;
	(*b)->next = tmp;
	ft_putendl_fd("pb", 1);
}
