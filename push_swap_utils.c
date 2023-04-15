/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mphilip <mphilip@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:42:51 by mphilip           #+#    #+#             */
/*   Updated: 2023/04/11 13:19:34 by mphilip          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	nb_larger(int *tab, int id, int size)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (i < size)
	{
		if (tab[i] > tab[id])
			result++;
		i++;
	}
	return (result);
}

int	*index_tab(int size, char **input)
{
	int	i;
	int	*tab;
	int	*result;

	i = 0;
	tab = malloc(sizeof(int) * size);
	result = malloc(sizeof(int) * size);
	if (!tab || !result)
		return (NULL);
	while (i < size)
	{
		tab[i] = ft_atoi(input[i]);
		i++;
	}
	i = 0;
	while (i < size)
	{
		result[i] = size - nb_larger(tab, i, size);
		i++;
	}
	free(tab);
	return (result);
}

void	fill_stack(t_list **stack, int *index_tab, int size)
{
	int		i;
	t_list	*ptr;

	i = 0;
	ptr = *stack;
	while (i < size)
	{
		ft_lstadd_back(stack, ft_lstnew(&index_tab[i]));
		i++;
	}
	i = 0;
	while (ptr)
	{
		ptr->id = i;
		ptr = ptr->next;
		i++;
	}
}

int	get_max_bits(t_list **stack)
{
	t_list	*head;
	int		max;
	int		max_bits;

	head = *stack;
	max = *(int *)(head->content);
	max_bits = 0;
	while (head)
	{
		if (*(int *)(head->content) > max)
			max = *(int *)(head->content);
		head = head->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	sort_short(t_list **stack_a, t_list **stack_b, int argc)
{
	if (is_sorted(*stack_a) == 0)
	{
		if (argc == 2)
			sort_two(*stack_a);
		else if (argc == 3)
			sort_three(stack_a);
		else if (argc == 4)
			sort_four(stack_a, stack_b);
		else if (argc == 5)
			sort_five(stack_a, stack_b);
	}
}
