/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_checks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mphilip <mphilip@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 20:57:21 by mphilip           #+#    #+#             */
/*   Updated: 2023/04/11 13:51:39 by mphilip          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list *stack)
{
	t_list	*ptr;
	int		value;

	ptr = stack;
	value = *(int *)(ptr->content);
	ptr = ptr->next;
	while (ptr)
	{
		if (value > *(int *)(ptr->content))
			return (0);
		value = *(int *)(ptr->content);
		ptr = ptr->next;
	}
	return (1);
}

int	is_digits(char **str, int limit, int i)
{
	int	j;

	while (i < limit)
	{
		j = 0;
		while (str[i][j])
		{
			if (ft_isdigit(str[i][j]) == 0)
			{
				if (!(str[i][j] == '-' && j == 0 && ft_strlen(str[i]) != 1))
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	have_duplicates(char **str, int limit, int i)
{
	int	j;
	int	memo;

	while (i < limit)
	{
		j = i;
		memo = ft_atoi(str[i]);
		while (j < limit)
		{
			if (ft_atoi(str[j]) == memo && j != i)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	error_check(char **str, int limit, int i, char **tab)
{
	long	num;

	if (is_digits(str, limit, i) == 0 || have_duplicates(str, limit, i) == 1)
	{
		ft_printf("Error\n");
		free_split(tab);
		return (1);
	}
	while (i < limit)
	{
		num = ft_atoi(str[i]);
		if (num < -2147483648 || num > 2147483647)
		{
			ft_printf("Error\n");
			free_split(tab);
			return (1);
		}
		i++;
	}
	return (0);
}
