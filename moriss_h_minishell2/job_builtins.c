/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Mon Oct  8 16:20:21 2012 hugues morisset
*/

#include "include.h"

void	builtin_fg(t_prg *cmd, t_sh_info *shell)
{

}

void	builtin_bg(t_prg *cmd, t_sh_info *shell)
{
  kill(cmd->pidf, SIGCONT);
}

void	builtin_jobs(t_prg *cmd, t_sh_info *shell)
{

}
