/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohurteb <yohurteb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 16:13:07 by yohurteb          #+#    #+#             */
/*   Updated: 2024/07/24 13:17:51 by yohurteb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# define ERROR_ARG 0
# define MAX_PHILO 200

typedef pthread_mutex_t mutex;

typedef struct timeval timeval;

typedef	struct s_data
{
	int			dead_flag;
	mutex		dead_lock;
	mutex		eat_lock;
	mutex		write_lock;
	mutex		*forks;
	timeval		start;
	long		set_t_die;
	long		set_t_eat;
	long		set_t_sleep;
	int			nb_philo;
	int			nb_eat;
	int			one_time;
}	t_data;

typedef struct s_philo
{
	pthread_t	thread;
	int			num;
	int			eating;
	long		last_eat;
	long		start_time;
	size_t		time_to_die;
	size_t		time_to_eat;
	size_t		time_to_sleep;
	mutex		*l_fork;
	mutex		*r_fork;
	mutex		*dead_lock;
	mutex		*eat_lock;
	mutex		*write_lock;
	t_data		*data;
}	t_philo;

int		check_args(int ac, char **av, t_data *data);

long	ft_atoi(const char *str);

void	error(int code_error);

void	init_data(t_data *data, mutex *forks);

void	init_forks(t_data *data);

void	init_philo(t_philo *philos, t_data *data);

int		make_threads(t_philo *philos, t_data *data);

void	if_stop(t_data *data, t_philo *philos);

void	*routine(void *philo);

void	free_all(t_philo *philos);

long	give_time(t_data *data);

int		ft_usleep(size_t milliseconds, t_data *data);

void	print_status(t_philo *philo, char *str, long time);

#endif