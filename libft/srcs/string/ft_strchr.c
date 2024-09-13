/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melinamotylewski <melinamotylewski@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 15:08:10 by memotyle          #+#    #+#             */
/*   Updated: 2024/07/31 12:11:45 by melinamotyl      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
cherche a partir du debut
La fonction strchr() renvoie un pointeur
sur la première occurrence du caractère c
dans la chaîne s.
Elle cherche le caractere c jusqu'au caract final \0 pas au dela
renvoit un pointeur sur le caractère correspondant ou NULL
*/

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)//on cherche si 's'='c'
		{
			return ((char *)s);//si oui on retourne depuis cette trouvaille
		}
		s++;//sinon on continu de chercher dans s
	}
	if ((char)c == '\0')//si c est le caract \0
	{
		return ((char *)s);//retourne s
	}
	return (NULL);
}

// #include <stdio.h>
// int	main()
// {
// 	char	s[] = "Hello";
// 	printf("%s\n", ft_strchr(s, '\0'));
// 	return (0);
// }
