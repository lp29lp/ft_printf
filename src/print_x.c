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

static void	coprih(unsigned int num,const char *text, t_guide *guide);
static void	flags_x(t_guide *guide, int size);
static int	check_size(unsigned int num);

void	print_x(va_list args, t_guide *guide, const char *text)
{
	unsigned int num;
	int size;

	num = va_arg(args, unsigned int);
	size = check_size(num);
	if (size == 0 && guide->dot == 0)
	{
		ft_putchar_fd('0', 1);
		guide->len += 1;
		guide->precision -= 1;
		guide->width -= 1;
	}
	flags_x(guide, size);
	if (guide->f_minus == 0)
		while (guide->pspace-- > 0)
			ft_putchar_fd(' ', 1);
	if ((guide->f_zero == 1) || (!guide->f_zero) || (guide->precision > size))
	{
		while (guide->pzero-- > 0)
			ft_putchar_fd('0', 1);
		if (size > 0)
			coprih(num, text, guide);
		if (guide->f_minus == 1)
			while (guide->pspace-- > 0)
				ft_putchar_fd(' ', 1);
	}
}

static void	coprih(unsigned int num, const char *text, t_guide *guide)
{
	unsigned int base;
	char *info_base;

	base = 16;
	if (text[guide->i] == 'x')
	{
		info_base = "0123456789abcdef";
		if (num / base > 0)
			coprih(num / base, text, guide);
		ft_putchar_fd(info_base[num % base], 1);
	}
	else
	{
		info_base = "0123456789ABCDEF";
		if (num / base > 0)
			coprih(num / base, text, guide);
		ft_putchar_fd(info_base[num % base], 1);
	}
}

static void	flags_x(t_guide *guide, int size)
{
	if (guide->precision > size && guide->precision != guide->width)
	{
		if (guide->width > guide->precision && guide->precision > size)
		{
			guide->pzero = guide->precision - size;
			guide->pspace = guide->width - guide->precision;
		}
		else if (guide->width < guide->precision && guide->precision > size)
			guide->pzero = guide->precision - size;
		guide->len += size + guide->pzero + guide->pspace;
		return ;
	}
	if (guide->width > size && size == 0 && guide->precision == 0)
	{
		guide->pspace = guide->width -size;
		guide->len += guide->pspace;
		return ;
	}
	if (guide->width > size && guide->f_zero == 1)
		guide->pzero = guide->width - size;
	if (guide->width > size && guide->f_zero == 0 && guide->width != guide->precision)
	{
		guide->pspace = guide->width - size;
		guide->len += size + guide->pzero + guide->pspace;
		return ;
	}
	guide->len += size + guide->pzero + guide->pspace;
	if (guide->width == guide->precision && guide->width > 0 && guide->precision > 0)
	{
		guide->pzero = guide->width - size;
		guide->len += guide->pzero;
		return ;
	}
}

static int	check_size(unsigned int num)
{
	int size;

	size = 0;

	while (num >= 1)
	{
		num/= 16;
		size++;
	}
	return (size);
}
