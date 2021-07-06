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

static void init_false(t_guide guide)
{
	guide.i = 0;
}

static void init_true(const char *text, va_list args, t_guide *guide)
{
	check_flags(format, args, guide);
	if (tex[guide->i] == 'c')
		print_char(agrs, guide);
	if (tex[guide->i] == 's')
		print_strinh(args, guide)
	
}

int ft_printf(const char *text, ...)
{
	t_guide	guide;
	va_list	args;

	//!iniciar o guide check()
	////initguide(&guide);
	va_start(args, text);
	while(text[guide.i] != '\0')
	{
		if (text[guide.i] == '%')
		{
			guide.i++;
			init(text, args, &guide)//?arrumar
		}
		else
		{
			write (1, text[guide.i], 1);
			guide.i++;
			guide.len++;
		}
	}
	va_end(args);
}