/* ************************************************************************** */
/*	                                                                          */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smihata <smihata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 11:22:45 by smihata           #+#    #+#             */
/*   Updated: 2023/08/12 11:26:32 by smihata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static unsigned long	ft_is_overflow(int sign)
{
	if (sign < 0)
		return (LONG_MIN);
	else
		return (LONG_MAX);
}

static int	ft_has_sign(char c)
{
	if (c == '-')
		return (-1);
	else
		return (1);
}
int	is_int(char *nptr)
{
	int				sign;
	unsigned long	cutoff;
	int				cutlim;
	int				num;
	unsigned long	value;
	size_t			nptr_len;
	size_t			i;

	sign = ft_has_sign(*nptr);
	nptr_len = ft_strlen(nptr);
	if (*nptr == '+' || *nptr == '-')
	{
		nptr_len--;
		nptr++;
	}
	cutoff = ft_is_overflow(sign);
	cutlim = cutoff % 10;
	cutoff /= 10;
	value = 0;
	i = 0;
	while (i < nptr_len)
	{
		num = *nptr++ - '0';
		if (!(0 <= num && num <= 9))
			return (0);
		if (value > cutoff || (value == cutoff && num > cutlim))
			return (0);
		value = value * 10 + num;
		i++;
	}
	return (1);
}
