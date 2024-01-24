/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 21:40:56 by cchabeau          #+#    #+#             */
/*   Updated: 2024/01/24 11:44:19 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

static void	take_fork(t_settings *settings, int pos, int id)
{
		pthread_mutex_lock(&(settings->forks[id]));
		if (settings->philosophers[pos].status != FORK)
			settings->philosophers[pos].status = FORK;
		print(settings, pos);
}

void	eat(t_settings *settings, int pos)
{
	take_fork(settings, pos, settings->philosophers[pos].lfork_id);
	take_fork(settings, pos, settings->philosophers[pos].rfork_id);
	settings->philosophers[pos].status = EAT;
	print(settings, pos);
	settings->philosophers[pos].last_meal = get_time();
	settings->philosophers[pos].weight++;
	ft_usleep(settings->time_to_eat);
	pthread_mutex_unlock(&settings->forks[settings->philosophers[pos].rfork_id]);
	pthread_mutex_unlock(&settings->forks[settings->philosophers[pos].lfork_id]);
}
