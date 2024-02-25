/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 01:03:40 by bloisel           #+#    #+#             */
/*   Updated: 2024/02/25 00:20:09 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <signal.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <errno.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../lib/libft.h"

typedef struct s_list
{
	char *cmd_sep;
	char *data;
 struct s_list *cur;
	struct s_list *prec;
	struct s_list *next;
	struct s_list *cell;
} t_list;

typedef struct b_list
{
	char *data;
	
	struct b_list *current;
	struct b_list	*next;
	
}	l_list;

// struct pour cellules en cas de pipe 
typedef	struct			s_pip
{
	char				*cmd_pip;
	struct s_pip		*prev;
	struct s_pip		*next;
}						t_pip;

typedef struct s_data
{
	char *input;
	int 	error;
	char **envv;
	char *envh;
}t_data;

char	*trytry(char **env, t_data *dta);
char **separate(char *env);
void	init_data(t_data *dta);


// cell fonction 
t_list  *cr_list(char *input);
t_list *add_cl(t_list *list, char *sep, int poz);
void sep_cell(char *input , t_list *list);
void	print_list(t_list *list);
void multi_shouf(void *list);

#endif 
