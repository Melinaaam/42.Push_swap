/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melinamotylewski <melinamotylewski@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:40:13 by memotyle          #+#    #+#             */
/*   Updated: 2024/07/31 12:08:57 by melinamotyl      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//vérifie s'il s'agit d'un caractère imprimable, y compris l'espace.
int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
// #include <stdio.h>
// int	main()
// {
// 	int	c;

// 	c = '\n';
// 	printf("%d\n", ft_isprint(c));
// 	return(0);
// }
