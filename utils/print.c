/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohurteb <yohurteb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:12:33 by yohurteb          #+#    #+#             */
/*   Updated: 2024/07/22 16:54:30 by yohurteb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_status(t_philo *philo, char *str, long time)
{
	pthread_mutex_lock(&philo->write_lock);
	printf("%zu %d %s\n", time, philo->num, str);
	pthread_mutex_unlock(&philo->write_lock);
}
