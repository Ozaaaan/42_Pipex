/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozdemir <ozdemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:04:07 by ozdemir           #+#    #+#             */
/*   Updated: 2023/12/20 16:41:51 by ozdemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	open_file(char *file, int nb)
{
	if (nb == 1)
	{
		if (access(file, F_OK))
			exit_error("Fichier inexistant");
		return (open(file, O_RDONLY));
	}
	else
		return (open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644));
}

int	ft_str_chr(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	if (str[i] == c)
		return (i);
	return (-1);
}

int	ft_str_ncmp(char *s1, char *s2, int n)
{
	int	i;

	i = 0;
	while (i < n - 1 && s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

char	*path_join(char *path, char *bin)
{
	char	*joined;
	int		i;
	int		j;

	joined = malloc(sizeof(char) * (ft_str_chr(path, 0) + ft_str_chr(bin, 0)
				+ 2));
	i = 0;
	j = 0;
	while (path[j])
	{
		joined[i] = path[j];
		i++;
		j++;
	}
	joined[i] = '/';
	i++;
	j = 0;
	while (bin[j])
	{
		joined[i] = bin[j];
		i++;
		j++;
	}
	joined[i] = 0;
	return (joined);
}
