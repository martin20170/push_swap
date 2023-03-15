/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mphilip <mphilip@student.42lyon.fr >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:35:43 by mphilip           #+#    #+#             */
/*   Updated: 2023/03/15 13:40:14 by mphilip          ###   ########.fr       */
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
	int	i;

	i = 0;
	while (i < size)
	{
		ft_lstadd_back(stack, ft_lstnew(&index_tab[i]));
		i++;
	}
}

int	*content_of_id(t_list *stack, int id)
{
	int	i;

	i = 0;
	while (i < id)
	{
		stack = stack->next;
		i++;
	}
	return (stack->content);
}

void	del(void *ptr)
{
	(void)ptr;
}

int		split_stack(t_list **stack_from, t_list **stack_to, char name, int mod)
{
	int	len;
	int	pivot;

	len = 0;
	pivot = *(int*)(ft_lstlast(*stack_from)->content);
	while (*(int*)((*stack_from)->content) != pivot)
	{
		if (*(int*)((*stack_from)->content) < pivot)
		{
			ft_push(stack_from, stack_to, name);
			len++;
		}
		else
			ft_rotate(stack_from, name);
	}
	if (mod == 1)
	{
		ft_reverse_rotate(stack_from, name);
		ft_swap(*stack_from, name);
		while (mod < ft_lstsize(*stack_from) - 1)
		{
			ft_reverse_rotate(stack_from, name);
			mod++;
		}
	}
	return (len);
}

void	sort_stack(t_list **stack, char name)
{
	int			size;
	int			len_stack;
	static int 	count_b = 0;
	t_list		*tempo = NULL;

	if (count_b > 0)
		len_stack = split_stack(stack, &tempo, name, 1);
	else
		len_stack = split_stack(stack, &tempo, name, 0);
	size = ft_lstsize(*stack);

	ft_printf("\n\nTEST A\n\n");

	if (len_stack > 2)
	{
		ft_printf("\n\nTEST B\n\n");
		if (name == 'a')
			sort_stack(&tempo, name+1);
		else
		{
			count_b++;
			sort_stack(&tempo, name-1);
		}
	}
	else if (size > 2)
	{
		ft_printf("\n\nTEST C\n\n");
		sort_stack(stack, name);
	}
	if (len_stack == 2)
	{
		ft_printf("\n\nTEST DfEF\n\n");
		if (*(int*)(tempo->content) < *(int*)(tempo->next->content))
			ft_swap(tempo, name);
	}
	else if (size == 2)
	{
		ft_printf("\n\nTEST D\n\n");
		if (*(int*)((*stack)->content) > *(int*)((*stack)->next->content))
			ft_swap(*stack, name);
	}

	while (len_stack > 0)
	{
		ft_printf("\n\nTEST E\n\n");
		if (name == 'a')
			ft_push(&tempo, stack, name+1);
		else
		{
			count_b++;
			ft_push(&tempo, stack, name-1);
		}
		len_stack--;
	}
}

int	main(int argc, char **argv)
{
	int		*tab;
	t_list	*stack_a = NULL;
	t_list	*stack_b = NULL;

	tab = index_tab(argc - 1, argv + 1);
	fill_stack(&stack_a, tab, argc - 1);

	split_stack(&stack_a, &stack_b, 'a', 0);

	sort_stack(&stack_b, 'b');

	ft_printf("\n\n\n");
		for (int i = 0; i < argc - 1; i++)
			ft_printf("tab %d : %d\n", i, tab[i]);
		ft_printf("\n\n\n");

			printf("\n\n\n");
		for (int i = 0; i < ft_lstsize(stack_a); i++)
			ft_printf("satck_a %d : %d\n", i, *content_of_id(stack_a, i));
		printf("\n\n\n");

		printf("\n\n\n");
		for (int i = 0; i < ft_lstsize(stack_b); i++)
			ft_printf("satck_b %d : %d\n", i, *content_of_id(stack_b, i));
		printf("\n\n\n");



	ft_lstclear(&stack_a, &del);
	ft_lstclear(&stack_b, &del);
	free (tab);

	return (0);
}



