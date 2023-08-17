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

static int	value_is_overflow(unsigned long value, int num, int sign)
{
	unsigned long	cutoff;
	int				cutlim;

	cutoff = ft_is_overflow(sign);
	cutlim = cutoff % 10;
	cutoff /= 10;
	if (value > cutoff || (value == cutoff && num > cutlim))
		return (1);
	else
		return (0);
}

static int	is_ok(size_t nptr_len, int sign, char *nptr)
{
	unsigned long	value;
	size_t			i;
	int				num;

	value = 0;
	i = 0;
	while (i < nptr_len)
	{
		num = *nptr++ - '0';
		if (!(0 <= num && num <= 9))
			return (0);
		if (value_is_overflow(value, num, sign))
			return (0);
		value = value * 10 + num;
		i++;
	}
	return (1);
}

int	is_int(char *nptr)
{
	int				sign;
	size_t			nptr_len;

	sign = ft_has_sign(*nptr);
	nptr_len = ft_strlen(nptr);
	if (*nptr == '+' || *nptr == '-')
	{
		nptr_len--;
		nptr++;
	}
	if (nptr_len == 0)
		return (0);
	if (is_ok(nptr_len, sign, nptr))
		return (1);
	return (0);
}
