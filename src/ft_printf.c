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

#include "../ft_printf.h"

static void init_true(const char *text, va_list args, t_guide *guide);
static void init_false(t_guide *guide);

int	ft_printf(const char *text, ...)
{
	va_list	args;
	t_guide	*guide;
	int ret;

	guide = (t_guide *)malloc(sizeof(t_guide));
	guide->i = 0;
	guide->len = 0;
	init_false(guide);
	va_start(args, text);
	while(text[guide->i] != '\0')
	{
		if (text[guide->i] == '%')
		{
			guide->i++;
			init_true(text, args, guide);
		}
		else
		{
			//write (1, text[guide->i], 1);
			ft_putchar_fd(text[guide->i], 1);
			guide->i++;
			guide->len++;
		}
	}
	ret = guide->len;
	va_end(args);
	free (guide);
	return (ret);
}

static void init_false(t_guide *guide)
{
	guide->dot = 0;
	guide->precision = 0;
	guide->pzero = 0;
	guide->pspace = 0;
	guide->width = 0;
	guide->f_minus = 0;
	guide->f_zero = 0;
	guide->f_zerop = 0;
}

static void init_true(const char *text, va_list args, t_guide *guide)
{
	char c;

	check_flags(text, guide);
	if (text[guide->i] == 'c')
		print_char(args, guide);
	else if (text[guide->i] == 's')
		print_string(args, guide);
	else if (text[guide->i] == 'd' || text[guide->i] == 'i' || text[guide->i] == 'u')
	{
		c = guide->i;
		print_diu(args, guide);
	}
	else if (text[guide->i] == 'x' || text[guide->i] == 'X')
	{
		c = guide->i;
		print_x(args, guide, c);
	}
	else if (text[guide->i] == 'p')
		print_p(args, guide);
	else
	{
		ft_putchar_fd('%', 1);
		//!guide->i--;
		guide->len++;
	}
	guide->i++;
	init_false(guide);
}
