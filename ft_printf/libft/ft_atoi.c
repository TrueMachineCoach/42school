/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandrow <bandrow@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 18:46:00 by bandrow           #+#    #+#             */
/*   Updated: 2019/09/16 11:32:18 by bandrow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static	int		issapce(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r')
		return (1);
	return (0);
}

int				ft_atoi(const char *str)
{
	int						i;
	int						is_neg;
	unsigned long long int	result;

	i = 0;
	while (issapce(str[i]))
		i++;
	is_neg = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			is_neg = -1;
		i++;
	}
	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += (str[i++] - '0');
	}
	if (result > 9223372036854775808ULL && is_neg == -1)
		return (0);
	if (result > 9223372036854775807ULL && is_neg == 1)
		return (-1);
	return ((int)(result * is_neg));
}
