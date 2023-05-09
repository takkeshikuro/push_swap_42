/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_check_things.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 07:39:17 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/02/17 05:38:36 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	check_if_sorted(t_stack **lst)
{
	t_stack		*tmp;

	tmp = *lst;
	while (tmp->next != NULL)
	{
		if (tmp->nbr > tmp->next->nbr)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	checkdup(t_stack *a)
{
	t_stack		*tmp;
	t_stack		*tmp2;

	tmp = a;
	while (tmp->next != NULL)
	{
		tmp2 = tmp->next;
		while (tmp2)
		{
			if (tmp2->nbr == tmp->nbr)
				return (0);
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
	return (1);
}

int	check_arg(char **tab, int start)
{
	int		i;
	int		j;

	i = start;
	while (tab[i])
	{
		j = -1;
		while (tab[i][++j])
		{
			if (j == 0)
			{
				if (!ft_issign(tab[i][j]) && !ft_isdigit(tab[i][j]))
					return (0);
				if (ft_issign(tab[i][j]) && !ft_isdigit(tab[i][j + 1]))
					return (0);
				if (!tab[i][j + 1])
					break ;
				j++;
			}
			if (!ft_isdigit(tab[i][j]))
				return (0);
		}
		i++;
	}
	return (1);
}
