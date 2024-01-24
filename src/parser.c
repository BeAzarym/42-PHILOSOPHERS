/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:02:46 by cchabeau          #+#    #+#             */
/*   Updated: 2024/01/24 12:59:48 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	check_arg(int argc, char **argv)
{
	int		i;
	long	tmp;

	i = 1;
	while (i < argc)
	{
		tmp = ft_atoi(argv[i]);
		if ((tmp < INT_MIN || tmp > INT_MAX) || tmp <= 0)
			return (0);
		i++;
	}
	return (1);
}
