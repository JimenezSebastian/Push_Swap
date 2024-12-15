/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almejia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:34:57 by almejia-          #+#    #+#             */
/*   Updated: 2024/12/12 15:35:02 by almejia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

const char	*isspaces(const char *str)
{
	int	p;

	p = 0;
	while (str[p] == ' ' || (str[p] >= '\t' && str[p] <= '\r'))
		++p;
	return (str + p);
}

int	signos(const char *str)
{
	int	minus;
	int	plus;
	int	sign;

	minus = 0;
	plus = 0;
	sign = 1;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			++minus;
		if (*str == '+')
			++plus;
		++str;
	}
	if ((minus > 1 || plus > 1) || (minus == 1 && plus == 1))
		return (0);
	if (minus == 1)
		sign = -1;
	return (sign);
}

int	ft_atoi(const char *str)
{
	int			r;
	int			sign;
	long long	n;

	n = 0;
	str = isspaces(str);
	sign = signos(str);
	while (*str == '+' || *str == '-')
		++str;
	while (*str >= '0' && *str <= '9')
		n = n * 10 + (*(str++) - '0');
	(void)sign;
	if (n < INT_MIN || n > INT_MAX)
		return (0);
	n *= sign;
	r = (int)n;
	return (r);
}
/*
int main()
{
	printf("%i", ft_atoi("-2147483648"));
	return (0);
}
*/
