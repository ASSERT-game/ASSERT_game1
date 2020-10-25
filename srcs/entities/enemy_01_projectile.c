/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_01_projectile.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 16:19:29 by kmira             #+#    #+#             */
/*   Updated: 2019/09/02 19:04:39 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "default.h"
#include "scene_normal_level.h"

void		bullet_enemy_step(t_pawn *pawn, t_normal_level *level_cont)
{
	t_bullet	*bullet;

	bullet = &(pawn->type_bullet);
	if (bullet->e.x - 2 > 0 && level_cont->map.frame[(bullet->e.y) * GAME_COLS + bullet->e.x - 2] == (void *)1)
		bullet->e.x = bullet->e.x - 2;
	else
	{
		if (bullet->e.x - 2 > 0 && level_cont->map.frame[(bullet->e.y) * GAME_COLS + bullet->e.x - 2] != (void *)1)
			level_cont->map.frame[(bullet->e.y) * GAME_COLS + bullet->e.x - 2]->type_entity.collide(level_cont->map.frame[(bullet->e.y) * GAME_COLS + bullet->e.x - 2], pawn);
		bullet->e.sprites = EMPTY_SPRITE;
	}
	if (bullet->e.x < 0 + 2)
		bullet->e.sprites = EMPTY_SPRITE;
	(void)level_cont;
}

void		enemy_bullet_collide(t_pawn *self, t_pawn *collision)
{
	(void)self;
	(void)collision;
	;
}

t_bullet	spawn_enemy_bullet(void)
{
	t_bullet	bullet;

	bullet.e.type = strdup("Bullet");
	bullet.e.sprites.sprite = bullet02_sprite();
	bullet.e.sprites.sprite_attribute = bullet02_attribute();
	bullet.e.collide = enemy_bullet_collide;
	bullet.e.update = bullet_enemy_step;
	return (bullet);
}
