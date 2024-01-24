/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 21:40:56 by cchabeau          #+#    #+#             */
/*   Updated: 2024/01/24 14:35:17 by cchabeau         ###   ########.fr       */
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

void	eat(t_settings *set, int pos)
{
	take_fork(set, pos, set->philosophers[pos].lfork_id);
	take_fork(set, pos, set->philosophers[pos].rfork_id);
	set->philosophers[pos].last_meal = get_time();
	set->philosophers[pos].status = EAT;
	print(set, pos);
	set->philosophers[pos].weight++;
	ft_usleep(set->time_to_eat);
	pthread_mutex_unlock(&set->forks[set->philosophers[pos].lfork_id]);
	pthread_mutex_unlock(&set->forks[set->philosophers[pos].rfork_id]);
}
