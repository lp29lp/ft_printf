/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 21:24:08 by lpaulo-d          #+#    #+#             */
/*   Updated: 2021/07/02 21:24:08 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void print_char(va_list arg, t_list guide)
{
	char c;
	//!organizacao
	//?iniciar os else na struct
	c = va_arg(arg, char);//!int?
	if( (guide->width > 1 && guide ->f_zero == 1))//!pq maior q 1
		guide->pzero = guide->width - 1;//!pq menos 1 
		//*aqui ja sei o tanto de zero q deve ser posto de acordo com o tamnho de width
	else
		guide->pzero = 0;//*ja sei que nao tem zero assim nao imprime os zeros, so da os espaços do width
	if (guide->width > 1 && guide->pzero == 0)//*imprime espacos pq n tem zero e pzero n tem valor
		guide->pspace = guide->width - 1;//*quantidade de espacos a ser impresso
	else
		guide->pspace = 0;//*se pzero recebeu valor de width n tem espacos a ser impresso somente 0 inves de espacos
	guide->len += guide->width;
	//!impressao
	if (guide->f_minus == 0)
		while (guide->pzero-- > 0)
			ft_putchar_fd('0', 1);
	ft_putchar_fd(c, 1);
	if (guide->f_minus == 1) //*se for '-' o '0' é anulado entao imprime espacos
		while (guide->pspace > 0)//!salvo espaço para o conteudo de 'c'
			ft_putchar_fd(' ', 1);
}