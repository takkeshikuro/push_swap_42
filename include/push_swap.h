/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 06:56:43 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/02/17 05:42:58 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				nbr;
	int				index;
	struct s_stack	*next;
}					t_stack;

//main.c (1)
t_stack	*ft_new_value(int value, t_stack *lst);
t_stack	*put_into_list(char **tab, t_stack *lst, int start);
t_stack	*ft_process(int ac, char **av);

//check_things.c (2)
int		check_if_sorted(t_stack **lst);
int		checkdup(t_stack *a);
int		check_arg(char **tab, int start);

//get_index.c (3)
int		*sort_int_tab(int *tab, int size);
void	get_exact_index(t_stack **stack, int *tab, int size);
void	get_index(t_stack **stack);

//ft_sort.c (4)
void	rotate_min(t_stack **a, int min);
void	sort_3_value(t_stack **a);
void	sort_5_value(t_stack **a, t_stack **b);
void	ft_sort(t_stack **stack, int size);

//big_sort.c (5)
int		pos_from_start(t_stack **a, int chunk_size);
int		pos_from_end(t_stack **a, int chunk_size);
void	push_to_b(t_stack **a, t_stack **b, int chunk_size);
void	push_to_a(t_stack **a, t_stack **b);
void	big_sort(t_stack **a, t_stack **b);

// rules_1.c (6)
void	ft_index(t_stack **a);
void	ft_sa(t_stack **a);
void	ft_sb(t_stack **b);
void	ft_pa(t_stack **a, t_stack **b);
void	ft_pb(t_stack **a, t_stack **b);

// rules_2.c
void	ft_ra(t_stack **a);
void	ft_rb(t_stack **b);
void	ft_rra(t_stack **a);
void	ft_rrb(t_stack **b);

//ending.c; (7)
void	free_tab_char(char **tab);
void	end_error(void);

//utils_1.c (a)
int		ft_atoi_w_av(const char *str, t_stack *lst);
int		ft_atoi_w_tab(const char *str, t_stack *lst, char **tab_to_free);
int		ft_isdigit(char c);
int		ft_issign(char c);
int		ft_strlen(const char *str);

//utils_2.c (a.1)
void	ft_putendl_fd(char *s, int fd);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);

//utils_4_algo.c (d)
int		value_left_in_chunk(t_stack **a, int chunk_size);
int		find_max(t_stack *stack);
int		find_min(t_stack *stack);
int		get_pos(t_stack **a, int min);

//utils_ft_split.c (c)
char	**ft_split(char const *s, char c);

//utils_lst.c (b)
void	free_lst(t_stack *lst);
t_stack	*ft_lstlast(t_stack *lst);
int		ft_lstsize(t_stack *lst);
void	ft_lstadd_back(t_stack **lst, t_stack *new);

#endif
