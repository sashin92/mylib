/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 17:35:29 by sashin            #+#    #+#             */
/*   Updated: 2021/04/19 16:45:28 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
** ft_strdup() duplicate s1 to new string.
*/

char	*ft_strdup(const char *s1)
{
	char		*s2;
	size_t		length;
	size_t		idx;

	length = 0;
	while (s1[length])
		++length;
	if (!(s2 = (char *)malloc((length + 1) * sizeof(char))))
		return (NULL);
	idx = 0;
	while (s1[idx])
	{
		s2[idx] = s1[idx];
		++idx;
	}
	s2[idx] = '\0';
	return (s2);
}
