/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pgcd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandrow <bandrow@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 14:06:52 by bandrow           #+#    #+#             */
/*   Updated: 2019/09/17 14:19:16 by bandrow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int		ft_pgcd(unsigned int a, unsigned int b)
{
	while (a != 0 && b != 0)
	{
		if (a > b)
			a = a % b;
		else
			b = b % a;
	}
	return (a + b);
}
