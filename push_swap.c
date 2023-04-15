/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mphilip <mphilip@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:35:43 by mphilip           #+#    #+#             */
/*   Updated: 2023/04/11 13:52:13 by mphilip          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	del(void *ptr)
{
	(void)ptr;
}

int	tablen(char **tab)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (tab[i])
	{
		len++;
		i++;
	}
	return (len);
}

void	free_split(char **tab)
{
	int	len;
	int	i;

	len = tablen(tab);
	i = 0;
	while (i < len)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	string_stack(char **argv, t_list **stack_a, t_list **stack_b)
{
	char	**spl;
	int		*tab;

	spl = ft_split(argv[1], ' ');
	if (!spl)
		return (0);
	if (error_check(spl, tablen(spl), 0, spl) == 0)
	{
		tab = index_tab(tablen(spl), spl);
		fill_stack(stack_a, tab, tablen(spl));
		sort_short(stack_a, stack_b, tablen(spl));
		if (is_sorted(*stack_a) == 0)
			radix_sort(stack_a, stack_b);
		ft_lstclear(stack_a, &del);
		ft_lstclear(stack_b, &del);
		free(tab);
		free_split(spl);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int		*tab;
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 2)
	{
		if (string_stack(argv, &stack_a, &stack_b) == 0)
			return (0);
	}
	else if (argc > 2 && error_check(argv, argc, 1, NULL) == 0)
	{
		tab = index_tab(argc - 1, argv + 1);
		fill_stack(&stack_a, tab, argc - 1);
		sort_short(&stack_a, &stack_b, argc - 1);
		if (is_sorted(stack_a) == 0)
			radix_sort(&stack_a, &stack_b);
		ft_lstclear(&stack_a, &del);
		ft_lstclear(&stack_b, &del);
		free(tab);
	}
	return (0);
}
