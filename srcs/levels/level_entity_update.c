/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   level_entity_update.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 15:42:22 by kmira             #+#    #+#             */
/*   Updated: 2019/08/07 16:00:14 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "default.h"
#include "scene_normal_level.h"

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


void		bullet_step(t_pawn *pawn, t_normal_level *level_cont)
{
	t_bullet	*bullet;

	bullet = &(pawn->type_bullet);
	bullet->e.x = bullet->e.x + 1;
	if (bullet->e.x > GAME_COLS)
		bullet->e.sprites = EMPTY_SPRITE;
	(void)level_cont;
}


void		enemy01_step(t_pawn *pawn, t_normal_level *level_cont)
{
	t_enemy01	*enemy01;
	t_spaceship	player;
	int			delta;

	delta = 1;
	enemy01 = &(pawn->type_enemy01);
	player = level_cont->player;
	if (level_cont->game_tick % 2 == 0)
	{
		if (rand_min_max(0, 3) != 3)
			enemy01->e.x = enemy01->e.x - 1;
		if (0 < enemy01->e.x - player.e.x && enemy01->e.x - player.e.x < 40)
			enemy01->e.x = enemy01->e.x - 1;
		if (level_cont->game_tick % 12 == 0)
		{
			if (enemy01->e.y >= player.e.y && enemy01->e.x - player.e.x < 90)
			{
				if (enemy01->e.y - player.e.y > 15)
					enemy01->e.y = enemy01->e.y + 2;
				enemy01->e.y = enemy01->e.y - 2;
			}
			else if (enemy01->e.y < player.e.y && enemy01->e.x - player.e.x < 90)
			{
				if (player.e.y - enemy01->e.y > 15)
					enemy01->e.y = enemy01->e.y - 2;
				enemy01->e.y = enemy01->e.y + 2;
			}
		}
	}
	if (enemy01->e.x < 0)
		enemy01->e.sprites = EMPTY_SPRITE;
	(void)level_cont;
}

void		enemy02_step(t_pawn *pawn, t_normal_level *level_cont)
{
	t_enemy02	*enemy02;

	enemy02 = &(pawn->type_enemy02);
	if (level_cont->game_tick % 2 == 0)
		enemy02->e.x = enemy02->e.x - 1;
	if (enemy02->e.x < 0)
		enemy02->e.sprites = EMPTY_SPRITE;
	(void)level_cont;
}

