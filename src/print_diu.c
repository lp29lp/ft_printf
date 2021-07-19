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

#include "../ft_printf.h"

static void	flags_int(t_guide *guide, unsigned long int size);
static int check_sign(t_guide *guide, unsigned long int num, char c);

void	print_diu(va_list args, t_guide *guide, char c)
{
	unsigned long int num;
	unsigned long int size;
	char *src;

	num = va_arg(args, int);
	num = check_sign(guide, num, c);
	src = ft_itoa(num);
	size = ft_strlen(src);
	flags_int(guide, size);
	if (guide->f_minus == 0)
		while (guide->pspace-- > 0)
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
			while (guide->pspace-- > 0)
				ft_putchar_fd(' ', 1);
	}
}

static void	flags_int(t_guide *guide, unsigned long int size)
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

static int check_sign(t_guide *guide, unsigned long int num, char c)
{
	//if (num < 0 && c == 'd' || c == 'i')
	ft_putchar_fd('-', 1);
	num *= -1;
	return (num);
	guide->len += 1;

	//?if (num < 0 && c == 'u')
	//?	return (void);
}
