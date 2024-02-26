/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cell.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:55:02 by bloise            #+#    #+#             */
/*   Updated: 2024/02/26 04:06:32 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void sep_cell(char *input, t_list *list)
{
  char **str;
  int i;

  i = -1;
  str = ft_split(input , '|');
  while (str[++i])
  {
    list = add_cl(list , str[i] , i); 
  }
}

t_list *add_cl(t_list *list, char *sep, int poz)
{
  t_list *prec;
  t_list *cur;
  t_list *cell;
  int i;

  cur = list;
  i = 0; //
  // print_list(cur); 
  cell = cr_list(sep);
  print_list(cell); 
  if (list == NULL)
    return (cell);
  while (i < poz)
  {
     i++;
     prec = cur;
     cur = cur->next;
  }   
  prec->next = cell; // cell est egale au separateur 
  cell->next = cur; // prochain separateur est egale 
  return (list); 
}

t_list  *cr_list(char *input)
{
  t_list *nlst = malloc(sizeof(t_list));
  if (nlst == NULL)
  {
    printf("erreur content lst\n");
    return (NULL);
  }
  nlst->cur = NULL;
  // nlst->data = strdup(input);
  nlst->data = input;
  nlst->next = NULL;
  nlst->prec = NULL; 
  return nlst;
}

void	print_list(t_list *list)
{
  // t_list *lst;

  // lst = list;
  while (list)
  {
    printf ("hi hou ! = %s\n", list->data);
    list = list->next;
  } 
}
