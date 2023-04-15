/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sorts.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mphilip <mphilip@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 20:59:03 by mphilip           #+#    #+#             */
/*   Updated: 2023/04/10 21:09:45 by mphilip          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_sort(t_list **stack_a, t_list **stack_b)
{
	t_list	*head_a;
	int		i;
	int		j;
	int		size;
	int		max_bits;

	i = 0;
	head_a = *stack_a;
	size = ft_lstsize(head_a);
	max_bits = get_max_bits(stack_a);
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			head_a = *stack_a;
			if (((*(int *)(head_a->content) >> i) & 1) == 1)
				rotate(stack_a, 'a');
			else
				push(stack_a, stack_b, 'a');
		}
		while (ft_lstsize(*stack_b) != 0)
			push(stack_b, stack_a, 'b');
		i++;
	}
}

void	sort_two(t_list *stack)
{
	if (*(int *)((stack)->content) == 2)
		swap(stack, 'a');
}

void	sort_three(t_list **stack)
{
	if (*(int *)((*stack)->content) == 1)
	{
		reverse_rotate(stack, 'a');
		swap(*stack, 'a');
	}
	else if (*(int *)((*stack)->content) == 2)
	{
		if (*(int *)((*stack)->next->content) == 3)
			reverse_rotate(stack, 'a');
		else
			swap(*stack, 'a');
	}
	else if (*(int *)((*stack)->content) == 3)
	{
		if (*(int *)((*stack)->next->content) == 1)
			rotate(stack, 'a');
		else
		{
			rotate(stack, 'a');
			swap(*stack, 'a');
		}
	}
}

void	sort_four(t_list **stack_a, t_list **stack_b)
{
	while (ft_lstsize(*stack_b) != 1)
	{
		if (*(int *)((*stack_a)->content) == 4)
			push(stack_a, stack_b, 'a');
		else
			rotate(stack_a, 'a');
	}
	sort_three(stack_a);
	push(stack_b, stack_a, 'b');
	rotate(stack_a, 'a');
}

void	sort_five(t_list **stack_a, t_list **stack_b)
{
	while (ft_lstsize(*stack_b) != 2)
	{
		if (*(int *)((*stack_a)->content) == 4 || \
			*(int *)((*stack_a)->content) == 5)
			push(stack_a, stack_b, 'a');
		else
			rotate(stack_a, 'a');
	}
	sort_three(stack_a);
	if (*(int *)((*stack_b)->content) == 5)
		swap(*stack_b, 'b');
	push(stack_b, stack_a, 'b');
	rotate(stack_a, 'a');
	push(stack_b, stack_a, 'b');
	rotate(stack_a, 'a');
}
