/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younko <younko@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 13:49:33 by younko            #+#    #+#             */
/*   Updated: 2023/03/01 22:32:29 by younko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs.h"

char	*new_line(char *line)
{
	char	*new;

	if (line != NULL)
		free(line);
	new = malloc(sizeof(char));
	if (new == NULL)
		return (NULL);
	new[0] = '\0';
	return (new);
}
