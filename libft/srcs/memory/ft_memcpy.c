/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melinamotylewski <melinamotylewski@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 16:20:51 by memotyle          #+#    #+#             */
/*   Updated: 2024/09/25 18:19:49 by melinamotyl      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*sd;
	unsigned char	*sc;
	size_t			i;

	sd = (unsigned char *)dest;
	sc = (unsigned char *)src;
	i = 0;
	if ((!sd || !sc))
		return (NULL);
	while (i < n)
	{
		((char *)sd)[i] = ((char *)sc)[i];
		i++;
	}
	return (sd);
}
