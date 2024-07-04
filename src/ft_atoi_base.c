/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 16:20:40 by jyap              #+#    #+#             */
/*   Updated: 2024/05/14 17:06:15 by jyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (base[i] != '\0')
	{
		j = 0;
		while (j < i)
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		if (base[i] == '+' || base[i] == '-')
			return (0);
		else if (base[i] == 32 || (base[i] >= 9 && base[i] <= 13))
			return (0);
		i++;
	}
	if (i < 2)
		return (0);
	return (i);
}

int	base_index(char *base, char c)
{
	int	index;

	index = 0;
	while (base[index])
	{
		if (base[index] == c)
			return (index);
		index++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	result;
	int	base_len;

	result = 0;
	base_len = check_base(base);
	if (base_len == 0)
		return (0);
	while (*str)
	{
		if (ft_isalpha(*str))
			*str = ft_toupper(*str);
		if (base_index(base, *str) == -1)
			return (result);
		result = (result * base_len) + (base_index(base, *str));
		str++;
	}
	return (result);
}
