/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 22:00:55 by kmira             #+#    #+#             */
/*   Updated: 2019/08/04 23:26:17 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "default.h"

char	*spaceship_sprite(void)
{
	return (" c>\n>*\n [=)\n>*\n c>");
}

int		*spaceship_attributes(void)
{
	int *sprite_attribute;

	sprite_attribute = malloc(sizeof(int) * (19));
	sprite_attribute[0] = COLOR_PAIR(0);
	sprite_attribute[1] = COLOR_PAIR(0);
	sprite_attribute[2] = COLOR_PAIR(6) | A_BOLD;
	sprite_attribute[3] = COLOR_PAIR(0);
	sprite_attribute[4] = COLOR_PAIR(4);
	sprite_attribute[5] = COLOR_PAIR(0);
	sprite_attribute[6] = COLOR_PAIR(0);
	sprite_attribute[7] = COLOR_PAIR(0);
	sprite_attribute[8] = COLOR_PAIR(0);
	sprite_attribute[9] = COLOR_PAIR(7) | A_BOLD;
	sprite_attribute[10] = COLOR_PAIR(0);
	sprite_attribute[11] = COLOR_PAIR(0);
	sprite_attribute[12] = COLOR_PAIR(4);
	sprite_attribute[13] = COLOR_PAIR(0);
	sprite_attribute[14] = COLOR_PAIR(0);
	sprite_attribute[15] = COLOR_PAIR(0);
	sprite_attribute[16] = COLOR_PAIR(0);
	sprite_attribute[17] = COLOR_PAIR(6) | A_BOLD;
	sprite_attribute[18] = COLOR_PAIR(0);
	sprite_attribute[19] = COLOR_PAIR(0);
	return (sprite_attribute);
}

char	*enemy01_sprite(void)
{
	return (" /\n<+\n o\n<+\n \\");
}

int		*enemy01_attributes(void)
{
	int	*sprite_attribute;

	sprite_attribute = malloc(sizeof(int) * (15));
	sprite_attribute[0] = COLOR_PAIR(0);
	sprite_attribute[1] = COLOR_PAIR(4);
	sprite_attribute[2] = COLOR_PAIR(0);
	sprite_attribute[3] = COLOR_PAIR(6) | A_BOLD;
	sprite_attribute[4] = COLOR_PAIR(12);
	sprite_attribute[5] = COLOR_PAIR(0);
	sprite_attribute[6] = COLOR_PAIR(0);
	sprite_attribute[7] = COLOR_PAIR(0);
	sprite_attribute[8] = COLOR_PAIR(0);
	sprite_attribute[9] = COLOR_PAIR(6) | A_BOLD;
	sprite_attribute[10] = COLOR_PAIR(12);
	sprite_attribute[11] = COLOR_PAIR(0);
	sprite_attribute[12] = COLOR_PAIR(0);
	sprite_attribute[13] = COLOR_PAIR(4);
	sprite_attribute[14] = COLOR_PAIR(0);
	return (sprite_attribute);
}
