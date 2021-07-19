/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 15:34:31 by lpaulo-d          #+#    #+#             */
/*   Updated: 2021/07/01 15:34:31 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_guide
{
	int	i;
	int	len;
	int	dot;
	int	precision;
	int	pzero;
	int	pspace;
	int	width;
	int	f_minus;
	int	f_zero;
	int	f_zerop;
}	t_guide;

char	*ft_itoa(int n);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
int		ft_isdigit(int c);
size_t	ft_strlen(const char *s);
int		ft_printf(const char *text, ...);
void	check_flags(const char *text, va_list args, t_guide *guide);
void	print_char(va_list args, t_guide *guide);
void	print_diu(va_list args, t_guide *guide, char c);
void	print_p(va_list args, t_guide *guide);
void	print_porcent(va_list args, t_guide *guide);
void	print_string(va_list args, t_guide *guide);
void	print_x(va_list args, t_guide *guide, char c);

#endif
