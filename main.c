/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 18:08:43 by albaud            #+#    #+#             */
/*   Updated: 2024/01/05 19:55:12 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct	s_tree
{
	char			*content;
	struct s_tree	*left;
	struct s_tree	*right;
}				t_tree;

int	file_len(char *file)
{
	int		fd;
	int		len;
	char	c;

	len = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		printf("Error opening file %s\n", file);
		return (1);
	}
	while (read(fd, &c, 1))
		len++;
	close(fd);
	return (len);
}

char	*file_to_str(char *file)
{
	int		fd;
	int		len;
	char	*str;

	len = file_len(file);
	str = malloc(sizeof(char) * (len + 1));
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		printf("Error opening file %s\n", file);
		return (NULL);
	}
	read(fd, str, len);
	str[len] = '\0';
	close(fd);
	return (str);
}


int main(int argc, char **argv)
{
	char	*file = argv[1];
	char	*str;
	t_tree	*tree;

	str = file_to_str(file);

	printf("%s\n", str);
}