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

char	boladao(unsigned int num,char *base)
{
	size_t base;

	base = ft_strlen(info_base);
	if (num / base > 0)
		boladao(num / base);
	ft_putchar_fd(info_base[num % base], fd);
}


void	print_x(va_list args, t_list *guide)
{
	unsigned long int num;
	
	num = (unsigned long int)va_arg(args, int);
	
}