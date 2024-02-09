/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 01:09:56 by bloisel           #+#    #+#             */
/*   Updated: 2023/10/21 02:09:23 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	main(int argc, char **argv, char **env)
{
	t_data dta;
	char *test;
	char **test2;
	t_list *lst = NULL;
	init_data(&dta);
	printf("%d\n", argc);
	printf("%s\n", argv[1]);
	test = trytry(env , &dta);
	test2 = separate(test);
	multi_shouf(lst);
		
	//print_list(lst);
	// -lreadine makefile  
	// while (1)
	//{
	//	dta.input = readline("~$");
	//	if (!dta.input)	
	//	{
	//		printf("\n");
	//		break;
	//	}
	//	if (dta.input)
	//	{
	//	//add_history(dta.input);
	//	printf("Execution commande etc etc input de nouveau \n");
	//	}
	//	free(dta.input);
	//}
	return (0);
}
