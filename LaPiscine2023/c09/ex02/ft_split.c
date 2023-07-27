/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younko <younko@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 09:47:51 by younko            #+#    #+#             */
/*   Updated: 2023/03/01 15:57:55 by younko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_in_sep(char c, char *sep)
{
	int	i;

	i = -1;
	while (sep[++i] != '\0')
		if (sep[i] == c)
			return (1);
	return (0);
}

int	cal_len(char *str, char *sep)
{
	int	i;
	int	len;

	len = 0;
	i = -1;
	while (str[++i] != '\0')
		if (is_in_sep(str[i], sep) == 0)
			len++;
	return (len);
}

int	cal_cnt(char *str, char *sep)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (str[i] != '\0')
	{
		while (is_in_sep(str[i], sep) && str[i] != '\0')
			i++;
		if (is_in_sep(str[i], sep) == 0 && str[i] != '\0')
			cnt++;
		while (is_in_sep(str[i], sep) == 0 && str[i] != '\0')
			i++;
	}
	return (cnt);
}

char	**ft_split(char *str, char *charset)
{
	char	**words;
	int		cnt;
	int		j;
	int		i;

	cnt = cal_cnt(str, charset);
	words = (char **)malloc(sizeof(char *) * (cnt + 1));
	words[cnt] = 0;
	if (cnt == 0)
		return (words);
	i = 0;
	cnt = 0;
	while (str[i] != '\0' && cnt < cal_cnt(str, charset))
	{
		while (is_in_sep(str[i], charset) && str[i] != '\0')
			i++;
		words[cnt] = malloc(sizeof(char) * (cal_len(str + i, charset) + 1));
		j = 0;
		while (is_in_sep(str[i], charset) == 0 && str[i] != '\0')
			words[cnt][j++] = str[i++];
		words[cnt][j] = '\0';
		cnt++;
	}
	return (words);
}
