/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melinamotylewski <melinamotylewski@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 11:31:43 by memotyle          #+#    #+#             */
/*   Updated: 2024/09/25 17:41:53 by melinamotyl      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
