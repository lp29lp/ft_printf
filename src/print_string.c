/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 14:44:15 by lpaulo-d          #+#    #+#             */
/*   Updated: 2021/07/06 14:44:15 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void flags_string(int len, t_list *guide)
{
	if (guide->precision > 0 && guide->precision < len)//!precision
		len = guide->precision; //imprime o tamanho da precição
	else if (guide->dot == 1 && guide->precision == 0)
		len = 0; //imprime nulo
	if (guide-> width > len && guide->f_zero == 1)//!trata os zeros
		guide->zero = guide->width - len;//se tem 0 e width maior q o tamanho preenche com 0 os primeiros campos
	else
		guide->zero = 0;//se a opção acima nao for true o zero(quantidade de zero) tem q ser 0 no fim ele nao consegue preencher os campos pq n tem tamanho suficiente
	if (guide->width > len && guide->f_zero == 0)//!spaces
		guide->spaces = guide->width - len;
	guide->count += len + guide-> zero + guide->spaces; 
	return (len);
}

void print_string(va_list args, t_list *guide)
{
	char	*src;
	int		len;

	src = va_arg(args, char *);
	len = flags_string(ft_strlen(scr, guide));
	if (guide->f_minus == 0)
		while (guide->spaces-- > 0)
			ft_putchar_fd(' ', 1);
	if (guide->f_zero == 1)
		while (guide->zero-- > 0)
			ft_putchar_fd('0', 1);
	while (len-- > 0)
	{
		ft_putchar_fd(src, 1);
		src++;
	}
	if (guide->f_minus == 1)
		while (guide->spaces-- > 0)
			ft_putchar_fd(' ', 1);
}