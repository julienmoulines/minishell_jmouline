#include <string.h>
#include <stdio.h>

int ft_check_exit(char *str)
{
    char *exit;
    int i = 0;
    exit = "exit\n";

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

    if (strlen(str) == 5 && ft_check_exit(str) == 1)
        return(0);
    return 1;
}

#include "GNL/get_next_line_bonus.h"

int main(int ac, char **av, char **env)
{
    char *line;
    write(0, "~$", 3);
    while (1)
    {
        line = get_next_line(0);
        if (fin_du_programme(line) == 0)
            return (0);
        //parsing;
        write(0, "~$", 3);
    }
}