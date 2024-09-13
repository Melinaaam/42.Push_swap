/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melina <melina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 11:31:43 by memotyle          #+#    #+#             */
/*   Updated: 2024/08/16 15:27:15 by melina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// size_t	ft_strlen(const char *s)
// {
// 	size_t	i;

// 	i = 0;
// 	if (!s)
// 		return (i);
// 	while (s[i])
// 		i++;
// 	return (i);
// }

// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	char	*joined;
// 	char	*temp;

// 	joined = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
// 	if (joined == NULL)
// 		return (NULL);
// 	temp = joined;
// 	while (*s1)
// 		*temp++ = *s1++;
// 	while (*s2)
// 		*temp++ = *s2++;
// 	*temp = '\0';
// 	return (joined);
// }

// char	*ft_strchr(const char *str, int c)
// {
// 	char	*chr;

// 	if (!str || !*str)
// 		return (NULL);
// 	chr = (char *)str;
// 	while (*chr && (unsigned char)*chr != (unsigned char)c)
// 		chr++;
// 	if ((unsigned char)*chr == (unsigned char)c)
// 		return (chr);
// 	else
// 		return (NULL);
// }

// size_t	ft_strlcpy(char *dest, const char *src, size_t n)
// {
// 	size_t	i;

// 	i = 0;
// 	while (src[i])
// 		i++;
// 	if (n == 0)
// 		return (i);
// 	while (--n && *src)
// 		*dest++ = *src++;
// 	*dest = '\0';
// 	return (i);
// }

char	*ft_strdup_gnl(char *s)
{
	size_t	i;
	size_t	size;
	char	*dup;

	i = 0;
	size = ft_strlen(s);
	dup = malloc(sizeof(char) * size + 1);
	if (dup == NULL)
		return (NULL);
	while (i < size)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
