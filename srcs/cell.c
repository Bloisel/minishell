/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cell.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:55:02 by bloise            #+#    #+#             */
/*   Updated: 2024/02/25 17:58:41 by bloisel          ###   ########.fr       */
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
    add_cl(list , str[i] , i);
}

t_list *add_cl(t_list *list, char *sep, int poz)
{
  t_list *prec;
  t_list *cur;
  t_list *cell;
  int i;

  i = 0;
  cur = list; // 
  cell = cr_list(sep);
  if (list == NULL)
    return (NULL);
  while (i < poz)
  {
     i++;
     prec = cur;
     cur->next = cur;
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
  nlst->data = input;
  nlst->next = NULL;
  nlst->prec = NULL; 
  return nlst;
}

void	print_list(t_list *list)
{
  t_list *lst;

  lst = list;
  
  while (lst != NULL)
  {
    printf ("hi hou ! = %s\n", lst->data);
    lst = lst->next; 
  } 
}
