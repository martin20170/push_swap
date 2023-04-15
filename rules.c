/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mphilip <mphilip@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 14:40:04 by mphilip           #+#    #+#             */
/*   Updated: 2023/04/10 21:07:50 by mphilip          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list *stack, char name)
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

void	push(t_list **stack_from, t_list **stack_to, char name)
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
		if (name == 'a')
			ft_printf("p%c\n", name + 1);
		else
			ft_printf("p%c\n", name - 1);
	}
}

void	rotate(t_list **stack, char name)
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

void	reverse_rotate(t_list **stack, char name)
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
