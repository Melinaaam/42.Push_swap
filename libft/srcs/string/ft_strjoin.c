/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melinamotylewski <melinamotylewski@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 13:54:53 by memotyle          #+#    #+#             */
/*   Updated: 2024/09/25 18:29:11 by melinamotyl      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*stemp;
	int		len1;
	int		len2;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen((char *)s1);
	len2 = ft_strlen((char *)s2);
	stemp = malloc(sizeof(char) * (len1 + len2 + 1));
	if (!stemp)
		return (NULL);
	ft_memcpy(stemp, s1, len1);
	ft_memcpy(stemp + len1, s2, len2);
	stemp[len1 + len2] = '\0';
	return (stemp);
}
