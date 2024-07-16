/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohurteb <yohurteb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 16:14:05 by yohurteb          #+#    #+#             */
/*   Updated: 2024/07/16 17:55:30 by yohurteb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

typedef struct s_data 
{
	pthread_mutex_t	key;
	pthread_mutex_t	key2;
	char			*str;
	char			*str2;
} 	t_data;

void	*func1(void *arg)
{
	t_data	*data = (t_data *)arg;

	pthread_mutex_lock(&data->key);
	fprintf(stderr, "in fct1 : %s\n", data->str);
	usleep(1000000);
	fprintf(stderr, "OOH\n");
	pthread_mutex_unlock(&data->key);
	
}

void	*func2(void *arg)
{
	t_data	*data = (t_data *)arg;

	pthread_mutex_lock(&data->key2);
	fprintf(stderr, "in fct2 : %s\n", data->str2);
	pthread_mutex_unlock(&data->key2);
	pthread_exit(data);
}

#include <stdio.h>
#include <string.h>
int	main()
{
	t_data			data;
	t_data			data2;
	pthread_t		t1;
	pthread_t		t2;
	data.str = strdup("salut");
	data2.str2 = strdup("yo");

	pthread_mutex_init(&data.key, NULL);
	pthread_mutex_init(&data2.key, NULL);
	pthread_create(&t1, NULL, func1, &data);
	pthread_create(&t2, NULL, func2, &data2);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	pthread_mutex_destroy(&data.key);
	pthread_mutex_destroy(&data2.key);
	return (0);
}
