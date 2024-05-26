/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolau <lnicolau@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:55:37 by lnicolau          #+#    #+#             */
/*   Updated: 2024/03/26 14:47:39 by lnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// de una string apenas encuentre una coincidencia te devuelve el resto
#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i] != (char)c && str[i] != '\0')
		i++;
	if (str[i] == (char)c)
		return ((char *)&str[i]);
	return (0);
}
