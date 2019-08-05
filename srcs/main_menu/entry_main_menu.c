/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entry_main_menu.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 04:30:58 by kmira             #+#    #+#             */
/*   Updated: 2019/08/03 20:11:46 by kmira            ###   ########.fr       */
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

	result->exit_condition = 4;

	result->screen = malloc(sizeof(*result->screen));
	result->screen->window = init_setup();

	int i;

	i = 0;
	memset(result->map.frame, ' ', sizeof(result->map.frame));
	while (i < GAME_ROWS)
	{
		result->map.frame[VIEW_OFFSET + (i * WIN_COLS) + 0] = 'a';
		result->map.frame[VIEW_OFFSET + (i * WIN_COLS) + 2] = 'b';
		result->map.frame[VIEW_OFFSET + (i * WIN_COLS) + 4] = 'c';
		result->map.frame[VIEW_OFFSET + (i * WIN_COLS) + 6] = 'd';
		result->map.frame[VIEW_OFFSET + (i * WIN_COLS) + 8] = 'e';
		result->map.frame[VIEW_OFFSET + (i * WIN_COLS) + 10] = 'f';
		result->map.frame[VIEW_OFFSET + (i * WIN_COLS) + 12] = 'g';
		result->map.frame[VIEW_OFFSET + (i * WIN_COLS) + 14] = 'h';
		result->map.frame[VIEW_OFFSET + (i * WIN_COLS) + 16] = 'i';
		result->map.frame[VIEW_OFFSET + (i * WIN_COLS) + 18] = 'j';
		result->map.frame[VIEW_OFFSET + (i * WIN_COLS) + 20] = 'k';
		result->map.frame[VIEW_OFFSET + (i * WIN_COLS) + 22] = 'l';
		result->map.frame[VIEW_OFFSET + (i * WIN_COLS) + 24] = 'm';
		result->map.frame[VIEW_OFFSET + (i * WIN_COLS) + 26] = 'n';
		result->map.frame[VIEW_OFFSET + (i * WIN_COLS) + 28] = 'o';
		result->map.frame[VIEW_OFFSET + (i * WIN_COLS) + 30] = 'p';
		result->map.frame[VIEW_OFFSET + (i * WIN_COLS) + 32] = 'q';
		result->map.frame[VIEW_OFFSET + (i * WIN_COLS) + 34] = 'r';
		result->map.frame[VIEW_OFFSET + (i * WIN_COLS) + 36] = 's';
		result->map.frame[VIEW_OFFSET + (i * WIN_COLS) + 38] = 't';
		result->map.frame[VIEW_OFFSET + (i * WIN_COLS) + 40] = 'u';
		result->map.frame[VIEW_OFFSET + (i * WIN_COLS) + 42] = 'v';
		result->map.frame[VIEW_OFFSET + (i * WIN_COLS) + 44] = 'w';
		result->map.frame[VIEW_OFFSET + (i * WIN_COLS) + 46] = 'x';
		result->map.frame[VIEW_OFFSET + (i * WIN_COLS) + 48] = 'y';
		result->map.frame[VIEW_OFFSET + (i * WIN_COLS) + 50] = 'z';
		result->map.frame[VIEW_OFFSET + (i * WIN_COLS) + 52] = 'a';
		result->map.frame[VIEW_OFFSET + (i * WIN_COLS) + 54] = 'b';
		result->map.frame[VIEW_OFFSET + (i * WIN_COLS) + 56] = 'c';
		result->map.frame[VIEW_OFFSET + (i * WIN_COLS) + 58] = 'd';
		result->map.frame[VIEW_OFFSET + (i * WIN_COLS) + 60] = 'p';
		result->map.frame[VIEW_OFFSET + (i * WIN_COLS) + 62] = 'q';
		result->map.frame[VIEW_OFFSET + (i * WIN_COLS) + 64] = 'r';
		result->map.frame[VIEW_OFFSET + (i * WIN_COLS) + 66] = 's';
		result->map.frame[VIEW_OFFSET + (i * WIN_COLS) + 68] = 'y';
		result->map.frame[VIEW_OFFSET + (i * WIN_COLS) + 70] = 'z';
		result->map.frame[VIEW_OFFSET + (i * WIN_COLS) + 72] = 'a';
		result->map.frame[VIEW_OFFSET + (i * WIN_COLS) + 74] = 'b';
		result->map.frame[VIEW_OFFSET + (i * WIN_COLS) + 76] = 'c';
		result->map.frame[VIEW_OFFSET + (i * WIN_COLS) + 78] = 'd';
		result->map.frame[VIEW_OFFSET + (i * WIN_COLS) + 80] = 'e';
		result->map.frame[VIEW_OFFSET + (i * WIN_COLS) + 82] = 'f';
		i++;
	}
	box(result->screen->window, 0, 0);
	return (result);
}

void		listen_of_main_menu(t_main_menu *main_menu_cont)
{
	return ;
}

void		update_of_main_menu(t_main_menu *main_menu_cont)
{
	main_menu_cont->exit_condition--;
	return ;
}

void		clean__of_main_menu(void)
{
	return ;
}

void		enter_main_menu(int *scene)
{
	char in_char;

	SCENE_LOOP(main_menu, main_menu);
	in_char = wgetch(main_menu_cont->screen->window);
}

int			main(void)
{
	int scene;

	scene = 0;
	enter_main_menu(&scene);
	return (1);
}
