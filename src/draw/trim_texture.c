/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 13:38:59 by ndelhota          #+#    #+#             */
/*   Updated: 2025/05/26 13:44:52 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	trim_texture(char **s)
{
	char	*new_string;

	new_string = ft_strtrim(*s, " ");
	free(*s);
	*s = new_string;
}
