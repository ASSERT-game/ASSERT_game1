/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entry_main_menu.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 04:30:58 by kmira             #+#    #+#             */
/*   Updated: 2019/08/02 07:49:22 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "default.h"
#include "main_menu.h"

int					break__of_main_menu(t_main_menu *main_menu_cont)
{
	if (main_menu_cont->exit_condition == 0)
		return (0);
	else
		return (1);
}

t_main_menu			alloc__of_main_menu(void)
{
	struct s_main_menu result;

	bzero(&result, sizeof(result));
	result.exit_condition = 4;
	return (result);
}

void				listen_of_main_menu(t_main_menu *main_menu_cont)
{
	return ;
}

void				update_of_main_menu(t_main_menu *main_menu_cont)
{
	main_menu_cont->exit_condition--;
	return ;
}

void				render_of_main_menu(void)
{
	printf("This is your frame\n");
	return ;
}

void				clean__of_main_menu(void)
{
	printf("Cleaned up main_menu\n");
	return ;
}

void	enter_main_menu(int *scene)
{
	SCENE_LOOP(main_menu, main_menu);
}

int		main(void)
{
	int scene;

	enter_main_menu(&scene);
}
