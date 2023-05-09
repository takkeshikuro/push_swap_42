/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 07:33:09 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/02/17 05:09:11 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_issign(char c)
{
	if (c == '+' || c == '-')
		return (1);
	return (0);
}

int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi_w_tab(const char *str, t_stack *lst, char **tab_to_free)
{
	int				sign;
	long long int	result;

	result = 0;
	sign = 1;
	while (*str == ' ' || (*str > 9 && *str < 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str)
	{
		result = result * 10 + (*str - 48);
		str++;
	}
	if ((sign * result) > 2147483647 || (sign * result) < -2147483648)
	{
		free_lst(lst);
		free_tab_char(tab_to_free);
		end_error();
	}
	return (sign * result);
}

int	ft_atoi_w_av(const char *str, t_stack *lst)
{
	int				sign;
	long long int	result;

	result = 0;
	sign = 1;
	while (*str == ' ' || (*str > 9 && *str < 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str)
	{
		result = result * 10 + (*str - 48);
		str++;
	}
	if ((sign * result) > 2147483647 || (sign * result) < -2147483648)
	{
		free_lst(lst);
		end_error();
	}
	return (sign * result);
}
