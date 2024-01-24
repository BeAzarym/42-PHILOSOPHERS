/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 21:42:03 by cchabeau          #+#    #+#             */
/*   Updated: 2024/01/24 12:34:43 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void print(t_settings *settings, int pos)
{
	time_t t;

	t = settings->start;
	pthread_mutex_lock(&settings->talking);
if (settings->is_alive)
{

	if (settings->philosophers[pos].status == FORK)
		printf("%li %d %s\n", get_time() - t, pos, M_FORK);
	else if (settings->philosophers[pos].status == EAT)
		printf("%li %d %s\n", get_time() - t, pos, M_EAT);
	else if (settings->philosophers[pos].status == SLEEP)
		printf("%li %d %s\n", get_time() - t, pos, M_SLEEP);
	else if (settings->philosophers[pos].status == THINK)
		printf("%li %d %s\n", get_time() - t, pos, M_THINK);
	else if (settings->philosophers[pos].status == DIED)
		printf("%li %d %s\n", get_time() - t, pos, M_DIED);
}	
	pthread_mutex_unlock(&settings->talking);
}