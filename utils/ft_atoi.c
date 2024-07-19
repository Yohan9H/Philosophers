/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohurteb <yohurteb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 11:02:11 by yohan.h           #+#    #+#             */
/*   Updated: 2024/07/18 10:56:41 by yohurteb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	verif_signe(const char *str, size_t *i)
{
	int	sgn;

	sgn = 1;
	if (str[*i] == '+' || str[*i] == '-')
	{
		if (str[*i] == '-')
			return (-1);
		*i = *i + 1;
	}
	return (sgn);
}

int	check_not_digit(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		i++;
	}
	return (0);
}

size_t	ft_atoi(const char *str)
{
	size_t	i;
	int		signe;
	size_t	res;

	i = 0;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;

	signe = verif_signe(str, &i);
	if (signe == -1)
		return (-1);
	if (check_not_digit(&str[i]) == -1)
		return (-1);
	while (str[i] >= '0' && str[i] <= '9' && str[i])
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * signe);
}
