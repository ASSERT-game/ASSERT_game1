/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 04:13:34 by kmira             #+#    #+#             */
/*   Updated: 2019/08/03 01:39:23 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFAULT_H
# define DEFAULT_H

/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** DEFAULT MACROS
*/

# define GAME_ROWS (25)
# define GAME_COLS (80)

# define TOP_WINDOW_CLIP (2)
# define SIDE_WINDOW_CLIP (2)

# define WIN_ROWS (GAME_ROWS + (TOP_WINDOW_CLIP * 2))
# define WIN_COLS (GAME_COLS + (SIDE_WINDOW_CLIP * 2))

# define VIEW_OFFSET (WIN_COLS * (TOP_WINDOW_CLIP) + SIDE_WINDOW_CLIP)

# define TO_STRING(val) #val

# define MIN_LINES(val) TO_STRING(val)

# define TOTAL_WIN_CHAR WIN_ROWS * WIN_COLS

/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** HEADERS
*/

# include "colors.h"
# include "macros.h"
# include "game_structs.h"

# include <ncurses.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** LAUNCH SCENES
*/

void	enter_main_menu(int *scene);

void	transition(int from, int destination);
void	render(t_char_map map, t_screen *screen);

#endif
