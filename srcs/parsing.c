/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloise <bloise@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:55:02 by bloise            #+#    #+#             */
/*   Updated: 2024/02/09 16:03:09 by bloise           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void multi_shouf(void *list)
{
	int i = 0;
	int j = 0;
	char **str;
	char **str1;
	char *test = "Echo World; Echo Noukarien";
	char *test1 = "Nalalalal | Nalala Noukarien";
	str = ft_split(test, ';');	
  	str1 = ft_split(test1 , '|');	
  	while (str[i++])
		add_cell(list , test , i);
	while (str1[j++])
		add_cell(list , test1 , j);
}


t_list	*create_cell(char *cmd_sep)
{
  t_list	*cell;

  cell = malloc(sizeof(t_list));
  if (!(cell))
  	return (NULL);
  cell->previous= NULL;
  cell->next = NULL;
  cell->pipecell = NULL;
  cell->cmd_sep = cmd_sep;
  print_list(cell);
  return (cell);
}

t_list *add_cell(t_list *list, char *cmd_sep, int pos)
{
  t_list	*prec; 
  t_list	*cur;
  t_list	*cell;
  int		i;

  cur = list;
  i = 0;
  cell = create_cell(cmd_sep);
  if (list == NULL)
  	return (cell);
  //print_list(list);
  while (i < pos)
  {
  	i++;
  	prec = cur;
  	cur = cur->next;
  }
  prec->next = cell;
  cell->next = cur;
  return (list);
}

void	print_list(t_list *list)
{
  int		i;

  i = 0;
  while (list)
  {
  	printf("-----------------------------------\n");
  	printf("| i = %d                            \n", i);
  	printf("| list->cmd_sep : %s            \n", list->cmd_sep);
  	printf("-----------------------------------\n");
  	list = list->next;
  	i++;
  }
}
