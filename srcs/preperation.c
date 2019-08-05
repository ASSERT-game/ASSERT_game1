/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preperation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 20:11:36 by kmira             #+#    #+#             */
/*   Updated: 2019/08/05 10:41:50 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "default.h"

WINDOW	*init_setup(void)
{
	WINDOW *window;

	if (initscr() == OK)
	{
		cbreak();
		noecho();
		start_color();
		curs_set(0);
	}
	window = newwin(GAME_ROWS + 2, GAME_COLS + 2, 0, 0);
	nodelay(window, true);

	start_color();

	// if (can_change_color() == TRUE)
	// 	exit(1);
	init_color(91, 800, 400, 1000);		//PURPLE
	init_color(77, 800, 400, 100);		//ORANGE
	init_color(78, 980, 784, 196);		//ORANGE2

	init_pair(4, COLOR_RED, COLOR_BLACK);
	init_pair(6, COLOR_CYAN, COLOR_BLACK);
	init_pair(7, COLOR_WHITE, COLOR_BLUE);
	init_pair(12, 91, COLOR_BLACK);
	init_pair(13, 77, COLOR_BLACK);
	init_pair(14, 78, COLOR_BLACK);

	box(window, 0, 0);
	wrefresh(window);
	return (window);
}
