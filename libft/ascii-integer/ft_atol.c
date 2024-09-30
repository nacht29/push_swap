/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachan <yachan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:56:30 by yachan            #+#    #+#             */
/*   Updated: 2024/09/30 17:56:49 by yachan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
converts string to long
accept whitespaces and 1 sign (+) (-) before digits
*/

long	ft_atol(const char *num)
{
	int		op;
	long	results;

	op = 1;
	results = 0;
	while (*num == ' ' || (*num >= 9 && *num <= 13))
		num++;
	if (*num == '+' || *num == '-')
	{
		if (*num == '-')
			op = -1;
		num++;
	}
	while (*num >= '0' && *num <= '9')
	{
		results = results * 10 + (*num - '0');
		num++;
	}
	return (results * op);
}
