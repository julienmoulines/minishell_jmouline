#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "libft/libft.h"

typedef struct s_commande
{
	char 			*commande;
	struct s_token 	*first_token;
} t_commande;

typedef struct s_token
{
	char 			*token;
	struct s_token	*next;
	struct s_token	*first;
} t_token;

#endif