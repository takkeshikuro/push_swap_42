/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 11:25:00 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/02/17 05:00:02 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*ft_new_value(int value, t_stack *lst)
{
	t_stack	*new_value;

	new_value = malloc(sizeof (t_stack));
	if (!new_value)
	{
		free_lst(lst);
		end_error();
	}
	new_value->nbr = value;
	new_value->next = NULL;
	return (new_value);
}

t_stack	*put_into_list(char **tab, t_stack *lst, int start)
{	
	int		i;
	int		value;

	i = start;
	while (tab[i])
	{
		if (start == 0)
			value = ft_atoi_w_tab(tab[i], lst, tab);
		else if (start == 1)
			value = ft_atoi_w_av(tab[i], lst);
		ft_lstadd_back(&lst, ft_new_value(value, lst));
		i++;
	}
	return (lst);
}

t_stack	*ft_process(int ac, char **av)
{
	t_stack	*list;
	char	**tab;

	list = NULL;
	if (ac == 2)
	{
		tab = ft_split(av[1], ' ');
		if (!tab)
			end_error();
		if (!check_arg(tab, 0))
		{
			free_tab_char(tab);
			end_error();
		}
		list = put_into_list(tab, list, 0);
		free_tab_char(tab);
	}
	else
	{
		if (!check_arg(av, 1))
			end_error();
		list = put_into_list(av, list, 1);
	}
	return (list);
}

int	main(int ac, char **av)
{
	t_stack	*stack;
	int		size;

	if (ac < 2)
		exit (1);
	stack = ft_process(ac, av);
	size = ft_lstsize(stack);
	if (!stack || !checkdup(stack))
	{
		free_lst(stack);
		end_error();
	}
	if (size == 2 && !check_if_sorted(&stack))
	{
		ft_sa(&stack);
		free_lst(stack);
	}
	else if (size > 2 && !check_if_sorted(&stack))
	{	
		get_index(&stack);
		ft_sort(&stack, size);
	}
	else if (check_if_sorted(&stack))
		free_lst(stack);
	return (0);
}
