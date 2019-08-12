/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spaceship.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 16:12:38 by kmira             #+#    #+#             */
/*   Updated: 2019/08/12 16:34:27 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "default.h"
#include "scene_normal_level.h"

t_spaceship	spawn_player(int no)
{
	t_spaceship	player;

	player.e.type = strdup("Player_n");
	player.e.type[7] = no + '0';
	player.e.sprites.sprite = spaceship02_sprite();
	player.e.sprites.sprite_attribute = spaceship02_attributes();
	player.e.update = player_step;
	player.class.hitpoints = 100;
	player.e.x = 5;
	player.e.y = 5;
	player.class.bullet.spawn = fire_bullet02;
	return (player);
}

void		player_step(t_pawn *pawn, t_normal_level *level_cont)
{
	t_spaceship		*player;
	t_game_input	input;

	input = level_cont->input;
	player = &(pawn->type_spaceship);
	player->class.hitpoints = level_cont->player.class.hitpoints - 1;
	if (input.keys_pressed & FLAG_MOVE_UP)
		player->e.y = player->e.y - 1;
	if (input.keys_pressed & FLAG_MOVE_DOWN)
		player->e.y = player->e.y + 1;
	if (input.keys_pressed & FLAG_MOVE_LEFT)
		player->e.x = player->e.x - 2;
	if (input.keys_pressed & FLAG_MOVE_RIGHT)
		player->e.x = player->e.x + 2;
	if (input.keys_pressed & FLAG_FIRE)
		player->class.bullet.spawn(level_cont->entities, player->e.y, player->e.x);
	if (input.keys_pressed & FLAG_SPECIAL)
		use_special(player);
	if (input.keys_pressed & FLAG_HEAL)
		use_heal(player);
	level_cont->player = *player;
}

void		fire_bullet01(t_pawn *entities, int row, int col)
{
	int i;

	i = 0;
	while (entities[i].type_entity.sprites.sprite != NULL)
		i++;
	entities[i].type_bullet = spawn_bullet01();
	entities[i].type_entity.x = col + 2;
	entities[i].type_entity.y = row;
	while (entities[i].type_entity.sprites.sprite  != NULL)
		i++;
	entities[i].type_bullet = spawn_bullet01();
	entities[i].type_entity.x = col + 2;
	entities[i].type_entity.y = row + 4;
	return ;
}

/*
** Fires two '*' bullets
*/

void		fire_bullet02(t_pawn *entities, int row, int col)
{
	int i;

	i = 0;
	while (entities[i].type_entity.sprites.sprite != NULL)
		i++;
	entities[i].type_bullet = spawn_bullet02();
	entities[i].type_entity.x = col + 3;
	entities[i].type_entity.y = row + 1;
	while (entities[i].type_entity.sprites.sprite  != NULL)
		i++;
	entities[i].type_bullet = spawn_bullet02();
	entities[i].type_entity.x = col + 3;
	entities[i].type_entity.y = row + 3;
	return ;
}

/*
** Changed the ship type and the types of bullets spawned
*/

void		use_special(t_spaceship *player)
{
	if (player->e.sprites.sprite == spaceship01_sprite())
	{
		player->e.sprites.sprite = spaceship02_sprite();
		player->e.sprites.sprite_attribute = spaceship02_attributes();
		player->class.bullet.spawn = fire_bullet02;
	}
	else
	{
		player->class.e.sprites.sprite = spaceship01_sprite();
		player->e.sprites.sprite_attribute = spaceship01_attributes();
		player->class.bullet.spawn = fire_bullet01;
	}
}

/*
** Testing healing powerup
*/

void		use_heal(t_spaceship *player)
{
	player->class.hitpoints = player->class.hitpoints + 100;
	if (player->class.hitpoints > MAX_HP)
		player->class.hitpoints = MAX_HP;
}
