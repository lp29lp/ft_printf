/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 14:44:15 by lpaulo-d          #+#    #+#             */
/*   Updated: 2021/07/06 14:44:15 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void flags_string(int len, t_list *guide)
{
	if (guide->precision > 0 && guide->precision < len)
		len = guide->precision;
	else if (guide->dot == 1 && guide->precision == 0)
		len = 0;
	if (guide-> width > len && guide->f_zero == 1)
		guide->pzero = guide->width - len;
	else
		guide->pzero = 0;
	if (guide->width > len && guide->f_zero == 0)
		guide->pspaces = guide->width - len;
	guide->count += len + guide-> zero + guide->spaces; 
	return (len);
}

void print_string(va_list args, t_list *guide)
{
	char	*src;
	int		len;

	src = va_arg(args, char*);
	len = flags_string(ft_strlen(scr), guide);
	if (guide->f_minus == 0)
		while (guide->spaces-- > 0)
			ft_putchar_fd(' ', 1);
	if (guide->f_zero == 1)
		while (guide->zero-- > 0)
			ft_putchar_fd('0', 1);
	while (len-- > 0)
	{
		ft_putchar_fd(src, 1);
		src++;
	}
	if (guide->f_minus == 1)
		while (guide->spaces-- > 0)
			ft_putchar_fd(' ', 1);
}
