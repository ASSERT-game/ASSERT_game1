/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   levels_common.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 07:54:24 by kmira             #+#    #+#             */
/*   Updated: 2019/08/07 02:18:40 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "default.h"
#include "scene_normal_level.h"

#define KEY_ITER 1

int			break__of_normal_level(t_normal_level *level_cont)
{
	int result;

	result = 1;
	if (level_cont->player.e.x > GAME_COLS || level_cont->player.e.x < -1)
		result = 0;
	if (level_cont->player.e.y > GAME_ROWS || level_cont->player.e.y < -1)
		result = 0;
	if (level_cont->player.class.hitpoints <= ZERO_HP)
		result = 0;
	if (level_cont->exit_condition == 0)
		result = 0;
	if (result == 0)
		level_cont->scenes.destination = EXIT_SCENE;
	return (result);
}

void		listen_of_normal_level(WINDOW *window, t_game_input *input)
{
	int				j;
	char			in_char;

	input->keys_pressed = 0;
	j = 0;
	while (j < KEY_ITER)
	{
		in_char = wgetch(window);
		if (in_char == 'w')
			input->keys_pressed = input->keys_pressed | FLAG_MOVE_UP;
		if (in_char == 's')
			input->keys_pressed = input->keys_pressed | FLAG_MOVE_DOWN;
		if (in_char == 'a')
			input->keys_pressed = input->keys_pressed | FLAG_MOVE_LEFT;
		if (in_char == 'd')
			input->keys_pressed = input->keys_pressed | FLAG_MOVE_RIGHT;
		if (in_char == ' ')
			input->keys_pressed = input->keys_pressed | FLAG_FIRE;
		if (in_char == 't')
			input->keys_pressed = input->keys_pressed | FLAG_SPECIAL;
		if (in_char == 'h')
			input->keys_pressed = input->keys_pressed | FLAG_HEAL;
		j++;
	}
	return ;
}

void		clean_up_empty_sprites(t_pawn *entities, t_sprite *sprites)
{
	int	i;
	int j;

	j = 0;
	i = 0;
	while (entities[j].type_entity.sprites.sprite != NULL)
		j++;
	while (entities[i].type_entity.sprites.sprite != NULL)
	{
		if (entities[i].type_entity.sprites.sprite == (char *)1)
		{
			while (&entities[i] < &entities[j] &&
			(entities[j].type_entity.sprites.sprite == NULL
			|| entities[j].type_entity.sprites.sprite == (char *)1))
				j--;
			entities[i] = entities[j];
			sprites[i] = entities[i].type_entity.sprites;
			entities[j].type_entity.sprites = NULL_SPRITE;
			sprites[j] = NULL_SPRITE;
		}
		i++;
	}
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
	int			delta;

	delta = 1;
	enemy01 = &(pawn->type_enemy01);
	if (level_cont->game_tick % 2 == 0)
	{
		if (rand_min_max(0, 3) != 3)
			enemy01->e.x = enemy01->e.x - 1;
		if (level_cont->game_tick % 12 == 0)
		{
			if (enemy01->e.y > level_cont->player.e.y && enemy01->e.x - level_cont->player.e.x < 90)
			{
				if (enemy01->e.y - level_cont->player.e.y > 15)
					enemy01->e.y = enemy01->e.y + 2;
				enemy01->e.y = enemy01->e.y - 2;
			}
			else if (enemy01->e.y < level_cont->player.e.y && enemy01->e.x - level_cont->player.e.x < 90)
			{
				if (level_cont->player.e.y - enemy01->e.y > 15)
					enemy01->e.y = enemy01->e.y - 2;
				enemy01->e.y = enemy01->e.y + 2;
			}
		}
	}
	if (enemy01->e.x < 0)
		enemy01->e.sprites = EMPTY_SPRITE;
	(void)level_cont;
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

t_bullet	spawn_bullet01(void)
{
	t_bullet	bullet;

	bullet.e.type = strdup("Bullet");
	bullet.e.sprites.sprite = bullet01_sprite();
	bullet.e.sprites.sprite_attribute = bullet01_attribute();
	bullet.e.update = bullet_step;
	return (bullet);
}

int			rand_min_max(int min, int max)
{
	int a;

	if (min >= max)
		return (0);
	a = (rand() % (max + 1 - min)) + min;
	return (a);
}

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
