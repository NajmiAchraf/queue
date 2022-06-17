#ifndef MULTITASK_H
# define MULTITASK_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
# include <time.h>
# include <ctype.h>

typedef struct s_task
{
	char			*Content;
	char			*Lib_task;
	int				State_task;
	int				Time_task;
	int				Mem_task;
	int				Level_task;
	struct s_task	*next;
} t_task;

char	*ft_itoa(int nbr);
char	*ft_strjoin(char const *s1, char const *s2);
t_task	*new_task(char *content, int nb);
t_task	*copy_task(t_task *node);
void	add_front(t_task **lst, t_task *new);
void	circular_push(t_task **head, t_task *new);
t_task	*find_last(t_task *lst);
void	clear(t_task **lst, void (*del)(void *));
void	delone(t_task *lst, void (*del)(void*));
void	add_back(t_task **lst, t_task *new);
int		find_size(t_task *lst);
char*	S_generateSentence();
int		printing(t_task *lst);
void	full_to_empty(t_task **L_full, t_task **L_empty);
void	free_to_full(t_task **L_full, t_task **L_empty);
#endif
