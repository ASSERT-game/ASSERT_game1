/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transition.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 04:53:19 by kmira             #+#    #+#             */
/*   Updated: 2019/08/05 22:22:05 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "default.h"

void	transition(int from, int destination)
{
	printf("Here is your transition!\n");
	if (destination == MAIN_MENU)
		enter_main_menu(&destination);
	else if (destination == LEVEL_01)
		enter_level_1(&destination);
	else
		printf("THANK YOU FOR PLAYING\n");
	(void)from;
}
