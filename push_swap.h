/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mphilip <mphilip@student.42lyon.fr >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:43:02 by mphilip           #+#    #+#             */
/*   Updated: 2023/03/14 12:59:43 by mphilip          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

/* --- RULES --- */

void	ft_swap(t_list *stack, char name);
void	ft_rotate(t_list **stack, char name);
void	ft_reverse_rotate(t_list **stack, char name);
void	ft_ss(t_list *stack_a, t_list *stack_b);
void	ft_rr(t_list **stack_a, t_list **stack_b);
void	ft_rrr(t_list **stack_a, t_list **stack_b);
void	ft_push(t_list **stack_from, t_list **stack_to, char name);
int		nb_larger(int *tab, int id, int size);
int		*index_tab(int size, char **input);
void	fill_stack(t_list **stack, int *index_tab, int size);
int		*content_of_id(t_list *stack, int id);
void	del(void *ptr);
int		split_stack(t_list **stack_from, t_list **stack_to, char name, int mod);
void	sort_stack(t_list **stack, char name);

#endif
