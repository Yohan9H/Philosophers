/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohurteb <yohurteb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 16:13:07 by yohurteb          #+#    #+#             */
/*   Updated: 2024/07/16 18:45:53 by yohurteb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>

typedef struct s_philo // peut etre rajouter une var pour think
{
	pthread_t		thread;
	size_t			start_time;
	int				num;
	int				eating;
	int				nb_eat; //av[5]
	size_t			last_eat;
	size_t			time_to_die; //av[2]
	size_t			time_to_eat; //av[3]
	size_t			time_to_sleep; //av[4]
	int				nb_philo; //av[1]
	int				*dead;
	pthread_mutex_t	*h_fork;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*dead_fork;
	pthread_mutex_t	*eat_fork;
	pthread_mutex_t	*write_fork;
}	t_philo;

typedef	struct s_data
{
	int				dead_flag;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	eat_lock;
	pthread_mutex_t	write_lock;
	pthread_mutex_t	*tab_forks;
	t_philo			*philos;
}	t_data;

#endif