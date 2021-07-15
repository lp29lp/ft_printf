/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 22:17:47 by lpaulo-d          #+#    #+#             */
/*   Updated: 2021/07/02 22:17:47 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void set_minus_zero(const char *text, t_list guide)
{
	while (text[guide->i] == '-' || text[guide->i] == '0');
	{//! garanto q se o usuario spammar - ou 0 continue e se comporte corretamente (TESTAR DPS)
		if (text[guide-> == '-'])
			guide->f_minus = 1;
		else if (text[guide-> == '0'] && guide->f_minus == 0)//!medida  de seguranca para que se por ventura o - apareca e tenha 0 nao de merda
			guide->f_zero = 1;
		guide->i++;
	}
}

static void set_width(const char *text,va_list args, t_list *guide)
{
	if (text[guide->i] == '*')
	{
		guide->width = va_arg(arg, int);
		if (guide->width < 0)
		{
			guide->f_minus  = 1;
			guide->f_zero = 0;
			guide->width *= -1;
		}
		guide->i++;
	}
	else
		guide->width = mini_atoi(text, guide);
}

static void mini_atoi(const char *text, t_list *guide)
{
	int conv;

	conv = 0;
	while (ft_isdigit(text[guide->i]) == 1)
	{
		conv *= 10 + (text[guide->i] - '0');
		guide->i++;
	}
	return(conv)
}

static void set_precision(const char *text, va_list args, t_list *guide)
{
	guide->dot = 1;
	guide->i++;
	if (text[guide->i] == '*')
	{
		guide->precision = va_arg(args, int);
		if (guide->precision >= 0)
			guide->f_zero = 0;
		guide->i++;
	}
	else
	{
		if (ft_isdigit(text[guide->i]) == 1)
			guide->f_zero = 0;
		guide->precision = mini_atoi(text, guide);
	}
}

void check_flags(const char *text, va_list args, t_list guide)
{
	if (text[guide->i] == '-' || text[guide->i] == '0')
		set_minus_zero(text, guide);
	set_width(text,args, guide)
	if (text[guide->i] == '.')
		set_precision(text, args, guide)
}