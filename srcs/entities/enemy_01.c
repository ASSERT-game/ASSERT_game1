/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_01.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 16:14:27 by kmira             #+#    #+#             */
/*   Updated: 2020/10/24 18:49:44 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "default.h"
#include "scene_normal_level.h"

void		enemy_01_collide(t_pawn *self, t_pawn *collision)
{
	if (collision->type_entity.type[0] == 'F')
		self->type_enemy01.class.hitpoints = self->type_enemy01.class.hitpoints - 140;
	(void)self;
	(void)collision;
	;
}

t_enemy01	spawn_enemy01(void)
{
	t_enemy01	enemy;

	enemy.e.type = strdup("enemy");
	enemy.e.sprites.sprite = enemy01_sprite();
	enemy.e.sprites.sprite_attribute = enemy01_attribute();
	enemy.e.collide = enemy_01_collide;
	enemy.e.update = enemy01_step;
	enemy.class.hitpoints = 100;
	enemy.e.x = GAME_COLS - 10;
	enemy.e.y = rand_min_max(5, GAME_ROWS - 5);
	return (enemy);
}

void		fire_enemy_bullet(t_pawn *entities, int row, int col)
{
	int i;

	i = 0;
	while (entities[i].type_entity.sprites.sprite != NULL)
		i++;
	entities[i].type_bullet = spawn_enemy_bullet();
	entities[i].type_entity.x = col - 2;
	entities[i].type_entity.y = row + 1;
	while (entities[i].type_entity.sprites.sprite  != NULL)
		i++;
	entities[i].type_bullet = spawn_enemy_bullet();
	entities[i].type_entity.x = col - 2;
	entities[i].type_entity.y = row + 3;
	return ;
}

void		update_enemy_01_sprite(t_enemy01 *enemy, int tick)
{
	if (tick % 20 <= 10)
	{
		enemy->class.e.sprites.sprite = enemy01_sprite();
		enemy->e.sprites.sprite_attribute = enemy01_attribute();
	}
	else if (tick % 20  > 10)
	{
		enemy->e.sprites.sprite = enemy01_sprite_alt();
		enemy->e.sprites.sprite_attribute = enemy01_attribute_alt();
	}
}

void		enemy01_step(t_pawn *pawn, t_normal_level *level_cont)
{
	t_enemy01	*enemy01;
	t_spaceship	player;
	int			delta;

	delta = 1;
	enemy01 = &(pawn->type_enemy01);
	player = level_cont->player;
	if (enemy01->e.x - 1 > 0 && level_cont->map.frame[(enemy01->e.y) * GAME_COLS + enemy01->e.x - 1] == (void *)1)
		enemy01->e.x = enemy01->e.x - 1;
	else
	{
		if (enemy01->e.x - 1 > 0 && level_cont->map.frame[(enemy01->e.y) * GAME_COLS + enemy01->e.x - 1] != (void *)1)
			level_cont->map.frame[(enemy01->e.y) * GAME_COLS + enemy01->e.x - 1]->type_entity.collide(level_cont->map.frame[(enemy01->e.y) * GAME_COLS + enemy01->e.x - 1], pawn);
		enemy01->e.sprites = EMPTY_SPRITE;
	}
	if (level_cont->game_tick % 2 == 0)
	{
		if (rand_min_max(0, 50) == 20 && enemy01->e.x < GAME_COLS - 5)
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
	update_enemy_01_sprite(enemy01, level_cont->game_tick);
	if (enemy01->class.hitpoints <= 0)
		enemy01->e.sprites = EMPTY_SPRITE;
	if (enemy01->e.x <= 1)
		enemy01->e.sprites = EMPTY_SPRITE;
	(void)level_cont;
}

