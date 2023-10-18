/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 12:20:08 by cchabeau          #+#    #+#             */
/*   Updated: 2023/10/18 14:38:16 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
#define PHILOSOPHERS_H

# include <limits.h>
# include <stdio.h>

# define ERR_COUNT_ARG "[ERROR] >> Invalid number of argument\n"
# define ERR_INVALID_ARG "[ERROR] >> Invalid argument\n"

long int ft_atoi(const char *str);
int check_arg(int argc, char **argv);
int ft_error(char *error_code);

#endif