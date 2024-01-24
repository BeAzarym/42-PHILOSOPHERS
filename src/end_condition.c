/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_condition.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 09:31:09 by cchabeau          #+#    #+#             */
/*   Updated: 2024/01/24 13:58:41 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	death_checking(t_settings *set)
{
	int	i;

	while (!set->sated)
	{
		i = -1;
		while (++i < set->nb_philo)
		{
			if ((get_time()
					- set->philosophers[i].last_meal) > set->time_to_die
				&& set->philosophers[i].status != EAT)
			{
				set->philosophers[i].status = DIED;
				print(set, i);
				set->is_alive = 0;
				break ;
			}
			usleep(100);
		}
		if (set->is_alive == 0)
			break ;
		sated_checking(set);
	}
}

void	sated_checking(t_settings *settings)
{
	int	i;

	i = 0;
	while (settings->limits != -1 && i < settings->nb_philo
		&& settings->philosophers[i].weight >= settings->limits)
		i++;
	if (i == settings->nb_philo)
		settings->sated = 1;
}
