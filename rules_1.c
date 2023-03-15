/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mphilip <mphilip@student.42lyon.fr >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 14:40:04 by mphilip           #+#    #+#             */
/*   Updated: 2023/03/09 17:29:46 by mphilip          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_list *stack, char name)
{
	void	*memo;

	if (ft_lstsize(stack) > 1)
	{
		memo = stack->content;
		stack->content = stack->next->content;
		stack->next->content = memo;
		if (name)
			ft_printf("s%c\n", name);
	}
}

void	ft_ss(t_list *stack_a, t_list *stack_b)
{
	ft_swap(stack_a, 0);
	ft_swap(stack_b, 0);
	ft_printf("ss\n");
}

void	ft_push(t_list **stack_from, t_list **stack_to, char name)
{
	t_list	*memo;

	if (stack_from)
	{
		memo = (*(stack_from))->next;
		if (!stack_to)
			*stack_to = ft_lstnew((*stack_from)->content);
		else
			ft_lstadd_front(stack_to, ft_lstnew((*stack_from)->content));
		free(*stack_from);
		*stack_from = memo;
		ft_printf("p%c\n", name);
	}
}

void	ft_rotate(t_list **stack, char name)
{
	t_list	*memo;

	if (ft_lstsize(*stack) > 1)
	{
		memo = (*stack)->next;
		ft_lstadd_back(stack, ft_lstnew((*stack)->content));
		free(*stack);
		*stack = memo;
		if (name)
			ft_printf("r%c\n", name);
	}
}

void	ft_rr(t_list **stack_a, t_list **stack_b)
{
	ft_rotate(stack_a, 0);
	ft_rotate(stack_b, 0);
	ft_printf("rr\n");
}

void	ft_reverse_rotate(t_list **stack, char name)
{
	t_list	*last;
	t_list	*bef_last;
	int		size;

	size = ft_lstsize(*stack);
	bef_last = *stack;
	if (size > 1)
	{
		last = ft_lstlast(*stack);
		while (size > 2)
		{
			bef_last = bef_last->next;
			size--;
		}
		ft_lstadd_front(stack, ft_lstnew(last->content));
		free(last);
		bef_last->next = NULL;
		if (name)
			ft_printf("rr%c\n", name);
	}
}

void	ft_rrr(t_list **stack_a, t_list **stack_b)
{
	ft_reverse_rotate(stack_a, 0);
	ft_reverse_rotate(stack_b, 0);
	ft_printf("rrr\n");
}
