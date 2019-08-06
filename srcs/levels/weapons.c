/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapons.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 19:02:12 by kmira             #+#    #+#             */
/*   Updated: 2019/08/06 00:07:00 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "default.h"

/*
** Spawns two '>' bullets
*/

void			spawn_bullet01(t_sprite *sprites, int row, int col)
{
	int i;

	i = 0;
	while (sprites[i].sprite != NULL)
		i++;
	sprites[i].sprite = bullet01_sprite();
	sprites[i].sprite_attribute = bullet01_attribute();
	sprites[i].screen_x = col + 2;
	sprites[i].screen_y = row;
	while (sprites[i].sprite != NULL)
		i++;
	sprites[i].sprite = bullet01_sprite();
	sprites[i].sprite_attribute = bullet01_attribute();
	sprites[i].screen_x = col + 2;
	sprites[i].screen_y = row + 4;
	return ;
}

/*
** Spawns two '*' bullets
*/

void			spawn_bullet02(t_sprite *sprites, int row, int col)
{
	int i;

	i = 0;
	while (sprites[i].sprite != NULL)
		i++;
	sprites[i].sprite = bullet02_sprite();
	sprites[i].sprite_attribute = bullet02_attribute();
	sprites[i].screen_x = col + 3;
	sprites[i].screen_y = row + 1;
	while (sprites[i].sprite != NULL)
		i++;
	sprites[i].sprite = bullet02_sprite();
	sprites[i].sprite_attribute = bullet02_attribute();
	sprites[i].screen_x = col + 3;
	sprites[i].screen_y = row + 3;
	return ;
}

/*
** Changed the ship type and the types of bullets spawned
*/

void			use_special(t_spaceship *player)
{
	if (player->sprites.sprite == spaceship01_sprite())
	{
		player->sprites.sprite = spaceship02_sprite();
		player->sprites.sprite_attribute = spaceship02_attributes();
		player->bullet.spawn = spawn_bullet02;
	}
	else
	{
		player->sprites.sprite = spaceship01_sprite();
		player->sprites.sprite_attribute = spaceship01_attributes();
		player->bullet.spawn = spawn_bullet01;
	}
}

/*
** Testing healing powerup
*/

void		use_heal(t_spaceship *player)
{
	player->hitpoints = player->hitpoints + 100;
}
