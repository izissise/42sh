/*
** print_prompt.c for print_prompt in /home/remi/42sh
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Wed Apr 10 08:55:38 2013 remi robert
** Last update Wed Apr 10 08:57:15 2013 remi robert
*/

#include "my_func.h"

void	print_prompt(t_param *param)
{
  if (param->str_prompt != NULL)
    {
      curseur(param->prompt.x, param->prompt.y);
      my_put_str(param->str_prompt);
      curseur(param->current_pos.x, param->current_pos.y);
    }
}
