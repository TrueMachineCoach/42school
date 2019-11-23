/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandrow <bandrow@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 17:23:15 by bandrow           #+#    #+#             */
/*   Updated: 2019/09/09 15:46:19 by bandrow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static	int		isupper(int c)
{
	unsigned char letter;

	letter = (char)c;
	return (c >= 'A' && c <= 'Z');
}

static	int		islower(int c)
{
	unsigned char letter;

	letter = (char)c;
	return (c >= 'a' && c <= 'z');
}

int				ft_isalpha(int c)
{
	return (isupper(c) || islower(c));
}
