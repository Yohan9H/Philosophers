/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_break.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohurteb <yohurteb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 11:07:30 by yohurteb          #+#    #+#             */
/*   Updated: 2024/07/26 11:23:00 by yohurteb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_break(t_philo *philo)
{
	if (if_dead(philo) == -1 || if_eat_finish(philo) == -1)
	{
		print_status(philo, "", give_time(philo->data));
		return (-1);
	}
	return (0);
}
