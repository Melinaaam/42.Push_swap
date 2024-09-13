/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melinamotylewski <melinamotylewski@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 10:46:51 by memotyle          #+#    #+#             */
/*   Updated: 2024/07/31 12:08:51 by melinamotyl      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*vérifie si c est un unsigned char sur 7 bits,
entrant dans le jeu de caractères ASCII.
*/
int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}
// #include <stdio.h>
// int	main()
// {
// 	int	c;

// 	c = 1;
// 	printf("%d\n", ft_isascii(c));
// 	return(0);
// }
