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

#include "../ft_printf.h"

static void	flags_int(t_guide *guide, int size);
static int check_sign(int num, t_guide *guide, const char *text);

void	print_diu(const char *text, va_list args, t_guide *guide)
{
	int num = 0;
	unsigned int unum = 0;
	int size = 0;;
	char *src;
	int count = 0;

	src = NULL;
	if (text[guide->i] == 'd' || text[guide->i] == 'i')
		num = va_arg(args, int);
	else
		unum = va_arg(args, unsigned int);
	if ((num < 0 && text[guide->i] == 'd') || (num < 0 && text[guide->i] == 'i'))
	{
		num = check_sign(num, guide, text);
		if (guide->width > 0)
			guide->width -= 1;
	}
	if (text[guide->i] == 'd' || text[guide->i] == 'i')
		src = ft_itoa(num);
	if (text[guide->i] == 'u' && unum != 0)
		src = ft_utoa(unum);
	if (unum != 0 || num != 0)
		size = ft_strlen(src);
	if (size == 0)
	{
		ft_putchar_fd('0', 1);
		guide->len += 1;
		guide->precision -= 1;
		guide->width -= 1;
	}
	flags_int(guide, size);
	if (guide->f_minus == 0)
		while (guide->pspace-- > 0)
			ft_putchar_fd(' ', 1);
	if ((guide->f_zero == 1) || (!guide->f_zero) || (guide->precision > size))
	{
		while (guide->pzero-- > 0)
			ft_putchar_fd('0', 1);
		if (guide->sign == 1)
			ft_putchar_fd('-', 1);
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
	if (guide->precision > size)
	{
		if (guide->width > guide->precision && guide->precision > size)
		{
			guide->pzero = guide->precision - size;
			guide->pspace = guide->width - guide->precision;
		}
		else if (guide->width < guide->precision && guide->precision > size)
			guide->pzero = guide->precision - size;
		//if (guide->precision > 0)
		//	guide->pspace = guide->precision - size;
		guide->len += size + guide->pzero + guide->pspace;
		return ;
	}
	if (guide->width > size && guide->f_zero == 1)
		guide->pzero = guide->width - size;
	if (guide->width > size && guide->f_zero == 0)
		guide->pspace = guide->width - size;
	guide->len += size + guide->pzero + guide->pspace;
}

static int check_sign(int num, t_guide *guide, const char *text)
{
	if (text[guide->i] == 'd' || text[guide->i] == 'i')
	{
		guide->sign = 1;
		guide->len += 1;
		return (num * -1);
	}
	if (text[guide->i] == 'u')
		return (num * -1);
	else
		return (num);
}
