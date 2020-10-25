/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spaceship_projectile.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 16:17:46 by kmira             #+#    #+#             */
/*   Updated: 2020/10/24 18:58:33 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "default.h"
#include "scene_normal_level.h"

void		bullet_step(t_pawn *pawn, t_normal_level *level_cont)
{
	t_bullet	*bullet;

	bullet = &(pawn->type_bullet);
	mvwprintw(level_cont->screen->window, 2, 2, "%d", bullet->e.y);
	wrefresh(level_cont->screen->window);
	if (bullet->e.x < GAME_COLS - 1)
	{
		if (level_cont->map.frame[(bullet->e.y - 1) * GAME_COLS + bullet->e.x + 1] == (void *)1)
			bullet->e.x = bullet->e.x + 1;
		else
		{
			if (level_cont->map.frame[(bullet->e.y - 1) * GAME_COLS + bullet->e.x + 1] != (void *)1)
				level_cont->map.frame[(bullet->e.y - 1) * GAME_COLS + bullet->e.x + 1]->type_entity.collide(level_cont->map.frame[(bullet->e.y - 1) * GAME_COLS + bullet->e.x + 1], pawn);
			bullet->e.sprites = EMPTY_SPRITE;
		}
	}
	if (bullet->e.x >= GAME_COLS - 1)
		bullet->e.sprites = EMPTY_SPRITE;
	bullet->e.x = bullet->e.x + 1;
	(void)level_cont;
}

void		bullet_01_collide(t_pawn *self, t_pawn *collision)
{
	(void)self;
	(void)collision;
	;
}

void		bullet_02_collide(t_pawn *self, t_pawn *collision)
{
	(void)self;
	(void)collision;
	;
}

t_bullet	spawn_bullet01(void)
{
	t_bullet	bullet;

	bullet.e.type = strdup("Fullet");
	bullet.e.sprites.sprite = bullet01_sprite();
	bullet.e.sprites.sprite_attribute = bullet01_attribute();
	bullet.e.collide = bullet_01_collide;
	bullet.e.update = bullet_step;
	return (bullet);
}

t_bullet	spawn_bullet02(void)
{
	t_bullet	bullet;

	bullet.e.type = strdup("Fullet");
	bullet.e.sprites.sprite = bullet02_sprite();
	bullet.e.sprites.sprite_attribute = bullet02_attribute();
	bullet.e.collide = bullet_02_collide;
	bullet.e.update = bullet_step;
	return (bullet);
}
