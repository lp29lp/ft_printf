/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 16:39:48 by lpaulo-d          #+#    #+#             */
/*   Updated: 2021/07/19 19:59:21 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int main()
{
    printf(" original %d\n", printf("|%d|", -101));
    printf(" euzinha %d\n", ft_printf("|%d|", -101));
    printf("\n");
    printf(" original %d\n", printf("|%d|", 101));
    printf(" euzinha %d\n", ft_printf("|%d|", 101));
    printf("\n");
    //printf(" euzinha %d\n", ft_printf("|%0 1d|", 0));
    //printf(" original %d\n", printf("|%0 1d|", 0));
    //printf("\n");
    //printf(" euzinha %d\n", ft_printf("|%0 1.0d|", 0));
    //printf(" original %d\n", printf("|%0 1.0d|", 0));
    //printf("\n");
    //printf(" original %d\n", printf("|%0+1d", 0));
    //printf(" euzinha %d\n", ft_printf("|%0+1d", 0));
    //printf("\n");
    //printf(" euzinha %d\n", ft_printf("|%0+1.d|", 0));
    //printf(" original %d\n", printf("|%0+1.d|", 0));
    //printf("\n");
    //printf(" euzinha %d\n", ft_printf("|%-+1.0d|", 0));
    //printf(" original %d\n", printf("|%-+1.0d|", 0));
    return 0;
}