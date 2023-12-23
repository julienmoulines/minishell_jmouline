#include "minishell.h"

int ft_check_exit(char *str)
{
    char *exit;
    int i = 0;
    exit = "exit";

    while (str[i])
    {
        if (str[i] != exit[i])
            return 0;
        i++;
    }
    return 1;
}

int fin_du_programme(char *str)
{

    if (ft_strlen(str) == 4 && ft_check_exit(str) == 1)
        return(0);
    return 1;
}

void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab[i]);
	free(tab);
}

void	ft_delete_token(t_token *token)
{
	t_token	*to_delete;
	to_delete = token;
	token = token->next;
	while (token)
	{
		to_delete = token;
		token = token->next;
		free(to_delete);
	}
}

void	find_special_token(t_commande *commande, t_token *token)
{
	token = commande->first_token;
	while (token)
	{
		if (token->token[0] = '|')
			ft_split_commande
		token = token->next;
	}
}

void	parsing(char *line, t_commande *commande, t_token *token)
{
	char 	**splited;
	int		i;
	t_token	*tokenfirst;

	tokenfirst = malloc(sizeof(t_token));
	commande = malloc(sizeof(t_commande));
	i = 2;
	splited = ft_split(line, ' ');
	if (splited == NULL || splited[0] == NULL)
        return (free(tokenfirst));
	commande->commande = splited[0];

	if (splited[1])
	{
		tokenfirst->token = splited[1];
		tokenfirst->first = tokenfirst;
		commande->first_token = tokenfirst;
		token = tokenfirst;
		while (splited[i] && splited[i][0])
		{
			t_token *new_token = malloc(sizeof(t_token));
			new_token->token = splited[i];
			new_token->next = NULL;
			new_token->first = tokenfirst;
			token->next = new_token;
			token = new_token;
			token->first = tokenfirst;
			i++;
		}
		token = tokenfirst;
		find_special_token(commande, token);
	}
}

void	free_struct(t_commande *commande, t_token *token)
{
	t_token	*current;
	t_token *next_token;

	current = commande->first_token;
    while (current)
	{
        next_token = current->next;
        free(current->token);
        free(current);
        current = next_token;
    }
	free(commande);
}

int main(int ac, char **av, char **env)
{
	t_commande	*commande;
    t_token		*token;
	char 		*line;
	
	(void)commande;
	(void)token;
	(void)ac;
	(void)av;
	(void)env;

    while (1)
    {
		commande = malloc(sizeof(t_commande));
        line = readline("~$ ");
		if (line)
        	add_history(line);
        if (fin_du_programme(line) == 0)
            return (free(line), 0);
        parsing(line, commande, token);
		free(line);
		free(commande);
    }
}
