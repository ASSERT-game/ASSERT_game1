/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_02.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 16:15:32 by kmira             #+#    #+#             */
/*   Updated: 2019/08/12 21:08:50 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "default.h"
#include "scene_normal_level.h"

void		enemy_02_collide(t_pawn *self, t_pawn *collision)
{
	(void)self;
	(void)collision;
	;
}

t_enemy02	spawn_enemy02(void)
{
	t_enemy02	enemy;

	enemy.e.type = strdup("enemy");
	enemy.e.sprites.sprite = enemy02_sprite();
	enemy.e.sprites.sprite_attribute = enemy02_attribute();
	enemy.e.collide = enemy_02_collide;
	enemy.e.update = enemy02_step;
	enemy.class.hitpoints = 100;
	enemy.e.x = GAME_COLS - 1;
	enemy.e.y = rand_min_max(3, GAME_ROWS - 3);
	return (enemy);
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

