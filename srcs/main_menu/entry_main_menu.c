/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entry_main_menu.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 04:30:58 by kmira             #+#    #+#             */
/*   Updated: 2019/08/05 23:07:16 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "default.h"
#include "main_menu.h"

int			break__of_main_menu(t_main_menu *main_menu_cont)
{
	if (main_menu_cont->exit_condition == 0)
		return (0);
	else
		return (1);
}

t_main_menu	*alloc__of_main_menu(void)
{
	struct s_main_menu *result;

	result = malloc(sizeof(*result));
	bzero(result, sizeof(*result));

	result->exit_condition = 100;

	result->screen = malloc(sizeof(*result->screen));
	result->screen->window = init_setup();

	result->sprites = malloc(sizeof(*(result->sprites)) * (100));
	bzero(result->sprites, sizeof(*(result->sprites)) * (100));

	result->sprites[0].sprite = main_menu_sprite();
	result->sprites[0].sprite_attribute = main_menu_attribute();
	result->sprites[0].screen_x = 1;
	result->sprites[0].screen_y = 1;

	result->sprites[1] = NULL_SPRITE;

	result->screen = malloc(sizeof(*result->screen));
	result->screen->window = init_setup();

	return (result);
}

void		listen_of_main_menu(WINDOW *window, t_game_input *input)
{
	char	in_char;

	in_char = wgetch(window);

	(void)input;
	return ;
}

void		update_of_main_menu(t_main_menu *main_menu_cont)
{
	main_menu_cont->exit_condition--;
	return ;
}

void		clean__of_main_menu(t_main_menu *main_menu_cont)
{
	main_menu_cont->scenes.destination = LEVEL_01;
	return ;
}

void		enter_main_menu(int *scene)
{
	SCENE_LOOP(main_menu, main_menu);
	(void)scene;
}
