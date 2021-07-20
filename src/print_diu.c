/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 18:25:09 by lpaulo-d          #+#    #+#             */
/*   Updated: 2021/07/19 16:22:35 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	flags_int(t_guide *guide, int size);
static int check_sign(const char *text, t_guide *guide, int num);

void	print_diu(const char *text, va_list args, t_guide *guide)
{
	int num;
	int size;
	char *src;
	int count = 0;

	num = va_arg(args, int);
	num = check_sign(text, guide, num);
	src = ft_itoa(num);
	if (src == NULL)
		return ;
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
			write(1, &src[count++], 1);
		if (guide->f_minus == 1)
			while (guide->pspace-- > 0)
				ft_putchar_fd(' ', 1);
	}
	free (src);
}

static void	flags_int(t_guide *guide, int size)
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

static int check_sign(const char *text, t_guide *guide, int num)
{
	if ((num < 0 && text[guide->i] == 'd') || (num < 0 && text[guide->i] == 'i'))
	{
		ft_putchar_fd('-', 1);
		num *= -1;
		guide->len += 1;
		return (num);
	}
	else if (num < 0)
	{
		num *= -1;
		return (num);
	}
	else
		return (num);
}
