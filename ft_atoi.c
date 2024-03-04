/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkokorev <mkokorev@student.42berlin.d>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 14:39:33 by mkokorev          #+#    #+#             */
/*   Updated: 2023/11/24 16:47:19 by mkokorev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_spaceskip(const char *nptr)
{
	int	i;

	i = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
	{
		i++;
	}
	return ((char *)&nptr[i]);
}

int	ft_atoi(const char *nptr)
{
	long	i;
	long	integer;

	i = 0;
	nptr = ft_spaceskip(nptr);
	if (nptr[i] == '-' || nptr[i] == '+')
		i++;
	if (ft_isdigit (nptr[i]) == 0)
		return (0);
	integer = nptr[i] - 48;
	while (nptr[i + 1] != '\0' && ft_isdigit((int)nptr[i + 1]))
	{
		if (nptr[i] >= '0' && nptr[i] <= '9')
			integer = integer * 10 + nptr[i + 1] - 48;
		else
			return (0);
		i++;
	}
	if (*nptr == '-')
		integer = -1 * integer;
	if (nptr[i] == ' ')
		return (0);
	return (integer);
}

/*
#include "libft.h"
#include <string.h>
#include <stddef.h>

int	main(void)
{
printf("atoi:\n");
	printf("%d\n", ft_atoi("- 42"));
	printf("%d\n\n", atoi("- 42"));
}
*/
