/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolau <lnicolau@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 04:50:41 by lnicolau          #+#    #+#             */
/*   Updated: 2024/05/26 04:50:41 by lnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
int first_index_valid(char *str)
{
    int index;
    while(str[index] == ' ' || str[index] == '\t'
         || str[index] == '\v' || str[index] == '\r')
        index++;
    return (index);
}