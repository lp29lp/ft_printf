/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 18:25:09 by lpaulo-d          #+#    #+#             */
/*   Updated: 2021/07/15 18:25:09 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	flags_int(t_list *guide, unsigned long int len)
{
	if (guide->precision > 1 && guide->width > 1)
	{
		if (guide->width > guide->precision && guide->precision > len)
		{
			guide->pzero = guide->precision - len;
			guide->pspaces = guide->width - pzero;
		}
		else if (guide->width < guide->precision && guide->precision > len)
			guide->pzero = guide->precision - len;
		guide->count += len + guide->pzero + guide->pspaces;

	}
	if (guide->width > len && guide->f_zero == 1)
		guide->pzero = guide->width - len;
	else
		guide->pzero = 0;
	if (guide->width > len && guide->f_zero == 0)
		guide->pspaces = guide->width - len;
	guide->count += len + guide->pzero + guide->pspaces;
}

unsigned long int check_sign(va_list *guide, unsigned long int num, char c)
{
	if (num < 0 && c == 'd' || c == 'i')
	{
		write(1, '-', 1);
		num *= -1;
		return (num)
	}
	//?if (num < 0 && c == 'u')
	//?	return (void);
}

void	print_diu(va_list args, t_list *guide, char c)
{
	unsigned long int num;
	unsigned long int size;
	char src;

	num = va_arg(args, int);
	num = check_sign(guide, num, c)
	src = ft_itoa(num);
	size = ft_strlen(src);
	flags_int(guide, size);
	if (guide->f_minus == 0)
		while (guide->pspaces-- > 0)
			ft_putchar_fd(' ', 1);
	if ((guide->f_zero == 1) || (!guide->f_zero) || (guide->precision > size))
	{
		while (guide->pzero-- > 0)
			ft_putchar_fd('0', 1);
		while (size-- > 0)
		{
			ft_putchar_fd(*src, 1);
			src++;
		}
		if (guide->f_minus == 1)
			while (guide->pspaces-- > 0)
				ft_putchar_fd(' ', 1);
	}
}
