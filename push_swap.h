/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mphilip <mphilip@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:43:02 by mphilip           #+#    #+#             */
/*   Updated: 2023/04/11 13:51:07 by mphilip          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

void	del(void *ptr);
void	free_split(char **tab);
void	sort_two(t_list *stack);
void	sort_three(t_list **stack);
void	swap(t_list *stack, char name);
void	rotate(t_list **stack, char name);
void	reverse_rotate(t_list **stack, char name);
void	sort_four(t_list **stack_a, t_list **stack_b);
void	sort_five(t_list **stack_a, t_list **stack_b);
void	radix_sort(t_list **stack_a, t_list **stack_b);
void	fill_stack(t_list **stack, int *index_tab, int size);
void	push(t_list **stack_from, t_list **stack_to, char name);
void	sort_short(t_list **stack_a, t_list **stack_b, int argc);

int		tablen(char **tab);
int		is_sorted(t_list *stack);
int		get_max_bits(t_list **stack);
int		nb_larger(int *tab, int id, int size);
int		is_digits(char **str, int len, int i);
int		error_check(char **str, int limit, int i, char **tab);
int		have_duplicates(char **str, int len, int i);
int		string_stack(char **argv, t_list **stack_a, t_list **stack_b);

int		*index_tab(int size, char **input);

#endif
