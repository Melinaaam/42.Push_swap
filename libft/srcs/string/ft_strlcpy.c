/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melina <melina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 13:45:43 by memotyle          #+#    #+#             */
/*   Updated: 2024/08/13 14:49:37 by melina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
copie jusuqu'a size -1 caracteres de la chaine src vers dest
et garanti qu'elle termine toujours par '\0'
evite debordement de memoire
retourne nb total de caracteres de src
*/

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	if ((dest == NULL) || (src == NULL))
		return (0);
	i = 0;
	while(src[i])
		i++;
	if (n == 0)
		return (i);
	while (*src && --n)
		*dest++ = *src++;
	*dest = '\0'; 
	return (i);
}

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	src[15] = "Hola que tal ?";
	char	dest[13];

	printf("La chaine src : %s ", src);
	printf("est composee de %zu caractere.\n",ft_strlcpy(dest, src, 2));
	printf("Voici a quoi ressemble maintenant dest : %s", dest);
	return (0);
}
*/
