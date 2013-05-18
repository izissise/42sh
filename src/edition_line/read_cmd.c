/*
** read_cmd.c for read_cmd in /home/remi/Dropbox/Projet/edition_ligne_termcap
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Sun May  5 16:03:47 2013 remi robert
** Last update Sat May 18 19:14:13 2013 remi robert
*/

#include "42sh.h"

char	*init_read_cmd(char *prompt, char *cmd, t_param *param)
{
  param->str_prompt = prompt;
  if (mod_raw(param->fd_tty) == EXIT_FAILURE)
    {
      my_putstr("Error mod_raw termcap\n", 2, -1);
      return (NULL);
    }
  my_putstr(param->str_prompt, 1, -1);
  if (SIZE_BUFFER <= 0 ||
      (cmd = malloc(sizeof(char) * SIZE_BUFFER)) == NULL)
    return (NULL);
  cmd[0] = '\0';
  get_pos_curser(&param->x, &param->y, param->fd_tty);
  param->begin_pos_x = param->x;
  param->begin_pos_y = param->y;
  param->pos = 0;
  param->pos_history = 0;
  return (cmd);
}

char	*loop_cmd(char *prompt, t_param *param, t_history **history)
{
  int	ret;
  char	buff[10];

  ret = 1;
  while (ret > 0)
    {
      signal(SIGWINCH, gere_change_window);
      if ((ret = read(0, buff, 9)) == -1)
        return (NULL);
      buff[ret] = '\0';
      if (buff[0] == CTRLD && buff[1] == '\0')
        return (NULL);
      if (buff[0] == '\n' && buff[1] == '\0')
        return (return_string(param->cmd, param, history));
      if (get_window_size(param->cmd, param->begin_pos_x) == 1 &&
          gere_keyboard(buff, param->cmd, param, history) == 1)
        {
          add_caractere(param->cmd, param, buff[0]);
          view(param->cmd, param);
        }
    }
  return (param->cmd);
}

char	*read_cmd(char *prompt, t_param *param, t_history **history)
{
  int	tty;

  if ((tty = isatty(0)) == 0)
    param->fallback = 0;
  else if (check_perror("stdin", tty) == -1)
    return (NULL);
  if (param->fallback == 0)
    {
      my_putstr(prompt, 1, -1);
      return (get_next_line(0));
    }
  param->cmd = NULL;
  if ((param->cmd = init_read_cmd(prompt, param->cmd, param)) == NULL)
    return (NULL);
  return (loop_cmd(prompt, param, history));
}
