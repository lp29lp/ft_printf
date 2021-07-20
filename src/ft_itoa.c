/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 19:33:19 by lpaulo-d          #+#    #+#             */
/*   Updated: 2021/07/19 21:54:20 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_itoa(int n)
{
	int			sign;
	int			size;
	char		*conv;
	long int	nn;

	sign = n < 0;
	nn = n;
	if (sign > 0)
		nn = -nn;
	size = 1;
	while (n / 10 != 0 && size++)
		n /= 10;
	conv = malloc(sizeof(char) * (size + sign + 1));
	if (!conv)
		return (NULL);
	conv[size + sign] = '\0';
	while (size-- != 0)
	{
		conv[size + sign] = nn % 10 + '0';
		nn /= 10;
	}
	if (sign > 0)
		conv[0] = '-';
	return (conv);
}
