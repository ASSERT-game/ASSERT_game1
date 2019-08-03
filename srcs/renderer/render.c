/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 21:23:26 by kmira             #+#    #+#             */
/*   Updated: 2019/08/03 02:29:39 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "default.h"
#include <ncurses.h>

/*
** If necessary one can create another map view for 'particle-effects'
** and print it ontop of the previous one after it has been printed.
**
** There is also no need for erasing the window because the entire game
** screen is being overwritten.
*/

void	render(t_char_map map, t_screen *screen)
{
	int	i;
	int	offset;

	i = 0;
	offset = VIEW_OFFSET;
	while (i < GAME_ROWS)
	{
		mvwprintw(screen->window, i + 1, 1, "%.*s", GAME_COLS, &map.frame[VIEW_OFFSET + (i * (WIN_COLS))]);
		i++;
	}
	wrefresh(screen->window);
}
