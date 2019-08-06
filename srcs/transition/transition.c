/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transition.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 04:53:19 by kmira             #+#    #+#             */
/*   Updated: 2019/08/06 11:47:33 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "default.h"

void	transition(int from, int destination)
{
	// box(stdscr, 0, 0);
	// mvwprintw(stdscr, 20, 20, "Here is your transition!\n");
	// wrefresh(stdscr);
	// sleep(1);
	if (destination == MAIN_MENU)
		enter_main_menu(&destination);
	else if (destination == LEVEL_01)
		enter_level_1(&destination);
	else
		printf("THANK YOU FOR PLAYING\n");
	(void)from;
}
