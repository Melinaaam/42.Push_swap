/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memotyle <memotyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 13:54:53 by memotyle          #+#    #+#             */
/*   Updated: 2024/09/27 17:20:14 by memotyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*stemp;
	int		len;
	int		i;

	i = 0;
	if (!s1)
		s1 = "";
	if (s2[0] == '\0')
		return (NULL);
	len = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	stemp = (char *)malloc(sizeof(char) * (len + 1));
	// if (!stemp)
	// {
	// 	if (s1)
	// 		free (s1);
	// 	if (s2)
	// 		free (s2);
	// 	exit (EXIT_FAILURE);
	// }
	while (*s1 && s1)
		stemp[i++] = *s1++;
	while (*s2 && s2)
		stemp[i++] = *s2++;
	stemp[i] = '\0';
	return (stemp);
}
