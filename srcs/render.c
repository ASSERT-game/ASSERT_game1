/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 21:23:26 by kmira             #+#    #+#             */
/*   Updated: 2019/08/04 21:43:07 by kmira            ###   ########.fr       */
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

void	render_sprites(t_sprite *sprites, t_screen *screen)
{
	int	i;
	int	j;
	int	start_col;
	int	start_row;

	i = 0;
	while (sprites[i].sprite != NULL)
	{
		j = 0;
		start_col = sprites[i].screen_x;
		start_row = sprites[i].screen_y;
		while (sprites[i].sprite[j] != '\0')
		{
			if (sprites[i].sprite[j] == '\n')
			{
				sprites[i].screen_y = sprites[i].screen_y + 1;
				sprites[i].screen_x = start_col;
			}
			else
			{
				if (sprites[i].sprite[j] != ' ')
				{
					wattron(screen->window, sprites[i].sprite_attribute[j]);
					mvwaddch(screen->window, sprites[i].screen_y, sprites[i].screen_x, sprites[i].sprite[j]);
					wattroff(screen->window, sprites[i].sprite_attribute[j]);
				}
				sprites[i].screen_x = sprites[i].screen_x + 1;
			}
			j++;
		}
		sprites[i].screen_x = start_col;
		sprites[i].screen_y = start_row;
		i++;
	}
}

void	render(t_sprite *sprites, t_screen *screen)
{
	werase(screen->window);
	box(screen->window, 0, 0);
	render_sprites(sprites, screen);
	wrefresh(screen->window);
}
