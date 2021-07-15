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

typedef struct s_guide
{
	int	i;//! not init// contador/movimento de casa
	int len;//!not init
	int	dot;
	int precision;
	int pzero;
	int pspace;
	int width;
	int f_minus;
	int f_zero;
}	t_guide;
