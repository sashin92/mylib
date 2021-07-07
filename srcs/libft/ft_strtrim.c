/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 10:11:54 by sashin            #+#    #+#             */
/*   Updated: 2021/07/07 12:01:22 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
** ft_strtrim() allocates and returns a copy of 's1' with the characters
** specified in 'set' removed from the beginning and the end of the string.
** return the trimmed string.  NULL if the allocation fails.
*/

static int	strtrim_isset(char const c, char const *set)
{
	int			idx;

	idx = 0;
	while (set[idx])
	{
		if (c == set[idx])
			return (1);
		++idx;
	}
	return (0);
}

static char	*strtrim_alloc(char const *s1, int begin, int end)
{
	char		*s2;
	int			idx;

	idx = 0;
	if (end < begin)
	{
		s2 = (char *)malloc(sizeof(char));
		if (!s2)
			return (NULL);
		*s2 = 0;
		return (s2);
	}
	s2 = (char *)malloc((end - begin + 2) * sizeof(char));
	if (!s2)
		return (NULL);
	while (idx < end - begin + 1)
	{
		s2[idx] = s1[begin + idx];
		++idx;
	}
	s2[idx] = '\0';
	return (s2);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int			begin;
	int			end;
	char		*s2;

	begin = 0;
	end = 0;
	while (s1[end])
		++end;
	end = end - 1;
	while (strtrim_isset(s1[begin], set))
		++begin;
	while (strtrim_isset(s1[end], set) && (end >= begin))
		--end;
	s2 = strtrim_alloc(s1, begin, end);
	if (!s2)
		return (NULL);
	return (s2);
}
