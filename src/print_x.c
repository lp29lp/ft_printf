/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 21:41:23 by lpaulo-d          #+#    #+#             */
/*   Updated: 2021/07/16 21:41:23 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static char	coprih(unsigned int num,char c);
static void	flags_x(va_list args, t_guide *guide, unsigned int size);
static int	check_size(unsigned int num);

void	print_x(va_list args, t_guide *guide, char c)
{
	unsigned int num;
	unsigned int size;
	char conv;

	num = va_arg(args, unsigned int);
	size = check_size(num);
	flags_x(args, guide, size);
	if (guide->f_minus == 0)
		while (guide->pspace-- > 0)
			ft_putchar_fd(' ', 1);
	if ((guide->f_zero == 1) || (!guide->f_zero) || (guide->precision > size))
	{
		while (guide->pzero-- > 0)
			ft_putchar_fd('0', 1);
		coprih(num, c);
		if (guide->f_minus == 1)
			while (guide->pspace-- > 0)
				ft_putchar_fd(' ', 1);
	}
}

static char	coprih(unsigned int num,char c)
{
	unsigned int base;
	char *info_base;

	base = 16;
	if (c == 'x')
	{
		info_base = "0123456789abcdef";
		if (num / base > 0)
			coprih(num / base, c);
		ft_putchar_fd(info_base[num % base], 1);
	}
	else
	{
		info_base = "0123456789ABCDEF";
		if (num /= base > 0)
			coprih(num / base, c);
		ft_putchar_fd(info_base[num % base], 1);
	}
}

static void	flags_x(va_list args, t_guide *guide, unsigned int size)
{
	if (guide->precision > 1 && guide->width > 1)
	{
		if (guide->width > guide->precision && guide->precision > size)
		{
			guide->pzero = guide->precision - size;
			guide->pspace = guide->width - guide->pzero;
		}
		else if (guide->width < guide->precision && guide->precision > size)
			guide->pzero = guide->precision - size;
		guide->len += size + guide->pzero + guide->pspace;

	}
	if (guide->width > size && guide->f_zero == 1)
		guide->pzero = guide->width - size;
	else
		guide->pzero = 0;
	if (guide->width > size && guide->f_zero == 0)
		guide->pspace = guide->width - size;
	guide->len += size + guide->pzero + guide->pspace;
}

static int	check_size(unsigned int num)
{
	unsigned int size;

	size = 0;
	if (num == 1)
		return (1);
	while (num >= 1)
	{
		num/= 16;
		size++;
	}
	return (size);
}
