/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 22:00:55 by kmira             #+#    #+#             */
/*   Updated: 2019/08/05 00:38:29 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "default.h"

char	*spaceship_sprite(void)
{
	static char *spaceship_char_sprite;

	if (spaceship_char_sprite != 0)
		return (spaceship_char_sprite);
	else
		spaceship_char_sprite = " c>\n>*\n [=)\n>*\n c>";
	return (spaceship_char_sprite);
}

int		*spaceship_attributes(void)
{
	static int *spaceship_attribute;

	if (spaceship_attribute != 0)
		return (spaceship_attribute);
	spaceship_attribute = malloc(sizeof(*spaceship_attribute) * (19));
	spaceship_attribute[0] = COLOR_PAIR(0);
	spaceship_attribute[1] = COLOR_PAIR(0);
	spaceship_attribute[2] = COLOR_PAIR(6) | A_BOLD;
	spaceship_attribute[3] = COLOR_PAIR(0);
	spaceship_attribute[4] = COLOR_PAIR(4);
	spaceship_attribute[5] = COLOR_PAIR(0);
	spaceship_attribute[6] = COLOR_PAIR(0);
	spaceship_attribute[7] = COLOR_PAIR(0);
	spaceship_attribute[8] = COLOR_PAIR(0);
	spaceship_attribute[9] = COLOR_PAIR(7) | A_BOLD;
	spaceship_attribute[10] = COLOR_PAIR(0);
	spaceship_attribute[11] = COLOR_PAIR(0);
	spaceship_attribute[12] = COLOR_PAIR(4);
	spaceship_attribute[13] = COLOR_PAIR(0);
	spaceship_attribute[14] = COLOR_PAIR(0);
	spaceship_attribute[15] = COLOR_PAIR(0);
	spaceship_attribute[16] = COLOR_PAIR(0);
	spaceship_attribute[17] = COLOR_PAIR(6) | A_BOLD;
	spaceship_attribute[18] = COLOR_PAIR(0);
	spaceship_attribute[19] = COLOR_PAIR(0);
	return (spaceship_attribute);
}

char	*enemy01_sprite(void)
{
	static char *enemy01_char_sprite;

	if (enemy01_char_sprite != 0)
		return (enemy01_char_sprite);
	else
		enemy01_char_sprite = " /\n<+\n o\n<+\n \\";
	return (enemy01_char_sprite);
}

int		*enemy01_attributes(void)
{
	static int	*enemy01_attribute;

	if (enemy01_attribute != 0)
		return (enemy01_attribute);
	enemy01_attribute = malloc(sizeof(*enemy01_attribute) * (15));
	enemy01_attribute[0] = COLOR_PAIR(0);
	enemy01_attribute[1] = COLOR_PAIR(4);
	enemy01_attribute[2] = COLOR_PAIR(0);
	enemy01_attribute[3] = COLOR_PAIR(6) | A_BOLD;
	enemy01_attribute[4] = COLOR_PAIR(12);
	enemy01_attribute[5] = COLOR_PAIR(0);
	enemy01_attribute[6] = COLOR_PAIR(0);
	enemy01_attribute[7] = COLOR_PAIR(0);
	enemy01_attribute[8] = COLOR_PAIR(0);
	enemy01_attribute[9] = COLOR_PAIR(6) | A_BOLD;
	enemy01_attribute[10] = COLOR_PAIR(12);
	enemy01_attribute[11] = COLOR_PAIR(0);
	enemy01_attribute[12] = COLOR_PAIR(0);
	enemy01_attribute[13] = COLOR_PAIR(4);
	enemy01_attribute[14] = COLOR_PAIR(0);
	return (enemy01_attribute);
}

char	*bullet_sprite(void)
{
	static char *bullet_sprite;

	if (bullet_sprite != 0)
		return (bullet_sprite);
	else
		bullet_sprite = ">";
	return (bullet_sprite);
}

int		*bullet_attribute(void)
{
	static int	*bullet_attribute;

	if (bullet_attribute != 0)
		return (bullet_attribute);
	bullet_attribute = malloc(sizeof(*bullet_attribute) * (1));
	bullet_attribute[0] = COLOR_PAIR(6) | A_BOLD;
	return (bullet_attribute);
}
