/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_01.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 16:14:27 by kmira             #+#    #+#             */
/*   Updated: 2019/08/12 16:31:31 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "default.h"
#include "scene_normal_level.h"

t_enemy01	spawn_enemy01(void)
{
	t_enemy01	enemy;

	enemy.e.type = strdup("enemy");
	enemy.e.sprites.sprite = enemy01_sprite();
	enemy.e.sprites.sprite_attribute = enemy01_attribute();
	enemy.e.update = enemy01_step;
	enemy.class.hitpoints = 100;
	enemy.e.x = GAME_COLS - 1;
	enemy.e.y = rand_min_max(3, GAME_ROWS - 3);
	return (enemy);
}

void		fire_enemy_bullet(t_pawn *entities, int row, int col)
{
	int i;

	i = 0;
	while (entities[i].type_entity.sprites.sprite != NULL)
		i++;
	entities[i].type_bullet = spawn_enemy_bullet();
	entities[i].type_entity.x = col;
	entities[i].type_entity.y = row + 1;
	while (entities[i].type_entity.sprites.sprite  != NULL)
		i++;
	entities[i].type_bullet = spawn_enemy_bullet();
	entities[i].type_entity.x = col;
	entities[i].type_entity.y = row + 3;
	return ;
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
		if (rand_min_max(0, 20) == 20 && enemy01->e.x < GAME_COLS - 5)
			fire_enemy_bullet(level_cont->entities, enemy01->e.y, enemy01->e.x);
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

