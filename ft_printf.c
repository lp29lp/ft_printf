/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 15:33:45 by lpaulo-d          #+#    #+#             */
/*   Updated: 2021/07/01 15:33:45 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void init_false(t_guide *guide)
{
	guide->dot = 0;
	guide->precision = 0;
	guide->pzero = 0;
	guide->pspace = 0;
	guide->width = 0;
	guide->f_minus = 0;
	guide->f_zero = 0;
}

static void init_true(const char *text, va_list args, t_guide *guide)
{
	char c;

	check_flags(text, args, guide);
	//! conferindo as letras apos a conclusao das flags
	if (tex[guide->i] == 'c')
		print_char(agrs, guide);
	if (tex[guide->i] == 's')
		print_string(args, guide)
	if (text[guide->i] == 'd' || text[guide->i] == 'i' || text[guide->i] == 'u')
	{
		c = guide->i;
		print_int(args, guide, c);
	}
	if (text[guide->i] == 'x' || text[guide->i] == 'X')
	{
		c = guide->i;
		print_x(args, guide, c);
	}
}

int	ft_printf(const char *text, ...)
{
	va_list	args;
	t_list	guide;

	guide.i = 0;
	guide.len = 0;
	init_false(&guide);
	va_start(args, text);
	while(text[guide.i] != '\0')
	{
		if (text[guide.i] == '%')
		{
			guide.i++;
			init_true(text, args, &guide);
		}
		else
		{
			write (1, text[guide.i], 1);
			guide.i++;
			guide.len++;
		}
	}
	va_end(args);
	return (guide.len);
}