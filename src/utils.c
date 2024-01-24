/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:05:14 by cchabeau          #+#    #+#             */
/*   Updated: 2024/01/24 09:14:51 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

static int	ft_isspace(char c)
{
	if (c == 32)
		return (1);
	if (c >= 9 && c <= 13)
		return (1);
	return (0);
}

long int	ft_atoi(const char *str)
{
	int			sign;
	long int	result;

	sign = 1;
	result = 0;
	while (ft_isspace(*str) == 1)
		str++;
	if (*str == 45 || *str == 43)
	{
		if (*str == 45)
			sign *= -1;
		str++;
	}
	while (*str >= 48 && *str <= 57)
	{
		result = (result * 10) + (*str - 48);
		str++;
		if ((result * sign) < INT_MIN || (result * sign) > INT_MAX)
			return (result * sign);
	}
	return (result * sign);
}

uint64_t	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * (uint64_t)1000) + (time.tv_usec / 1000));
}
void	ft_usleep(uint64_t time)
{
	uint64_t start;
	start = get_time();
	while((get_time() - start) < time)
		usleep(500);
}