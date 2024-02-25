/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 01:09:56 by bloisel           #+#    #+#             */
/*   Updated: 2024/02/25 18:00:16 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char *take_input()
{
	return readline("~$");
}

int	main() 
{
	t_data	dta;
	t_list *lst;
	char *input;	

	init_data(&dta);
	while (1)
	{
		input = take_input();
		
		if (input == NULL)
		{
			printf("\n");
			break;
		}
		if (ft_strlen(input) > 0)
		{
			add_history(input);
		}
		sep_cell(input , lst);
		print_list(lst);
		free(input);
	}
	return (0);
}
