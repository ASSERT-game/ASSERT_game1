/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projectile_spaceship_01.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 16:17:46 by kmira             #+#    #+#             */
/*   Updated: 2019/08/12 16:18:42 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "default.h"
#include "scene_normal_level.h"

void		bullet_step(t_pawn *pawn, t_normal_level *level_cont)
{
	t_bullet	*bullet;

	bullet = &(pawn->type_bullet);
	bullet->e.x = bullet->e.x + 1;
	if (bullet->e.x > GAME_COLS)
		bullet->e.sprites = EMPTY_SPRITE;
	(void)level_cont;
}

t_bullet	spawn_bullet01(void)
{
	t_bullet	bullet;

	bullet.e.type = strdup("Bullet");
	bullet.e.sprites.sprite = bullet01_sprite();
	bullet.e.sprites.sprite_attribute = bullet01_attribute();
	bullet.e.update = bullet_step;
	return (bullet);
}

t_bullet	spawn_bullet02(void)
{
	t_bullet	bullet;

	bullet.e.type = strdup("Bullet");
	bullet.e.sprites.sprite = bullet02_sprite();
	bullet.e.sprites.sprite_attribute = bullet02_attribute();
	bullet.e.update = bullet_step;
	return (bullet);
}
