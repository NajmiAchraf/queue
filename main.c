#include "multitask.h"

char*	S_generateSentence()
{
	//you can change these words to generate new sentences
	const char* ARTICLES[] = {"the", "a", "one", "some", "any"};
	const char* NOUNS[] =  {"storage", "cpu", "algorithm", "api", "binary"};
	const char* VERBS[] =  {"generate", "free", "allocate", "reboot", "setup"};
	const int ARTICLES_SIZE = sizeof(ARTICLES)/sizeof(ARTICLES[0]);
	const int NOUNS_SIZE = sizeof(NOUNS)/sizeof(NOUNS[0]);
	const int VERBS_SIZE = sizeof(VERBS)/sizeof(VERBS[0]);

	char* sentence = calloc((25), sizeof(char));

	strcat(sentence, VERBS[rand()%VERBS_SIZE]);
	strcat(sentence, " ");

	strcat(sentence, ARTICLES[rand()%ARTICLES_SIZE]);
	strcat(sentence, " ");

	strcat(sentence, NOUNS[rand()%NOUNS_SIZE]);
	strcat(sentence, " ");

	sentence[0] = toupper(sentence[0]);

	return sentence;
}

void	execute(t_task *head)
{
	int		i = 0;
	char	*str;

	printf("\033[0;31mBegining of execution : %s\033[0m\n**\n", head->Lib_task);
	str = head->Content;
	while (str[i])
	{
		printf("\033[0;33m%c\033[0m", str[i]);
		// usleep(17000);//needs modificatiom
		if (!str[i + 1])
		printf("\n**\n");
		i++;
	}
	printf("\033[0;31mEnding of execution : %s\033[0m\n\n\n", head->Lib_task);
}

int	main(void)
{
	char	*sentence;
	int		i = 1;
	int		j = 3; // 30
	t_task  *L_full = NULL;
	t_task  *L_empty = NULL;
	t_task  *save;
	t_task	*new;
	t_task	*tmp;
	t_task	*head_tourniquet = NULL;

	srand(time(NULL));
	while(i <= j)
	{
		sentence = S_generateSentence();
		new = new_task(sentence, i);
		add_back(&L_full, new);
		i++;
	}
	i = 0;
	while(i < j)
	{
		new = new_task("\0", 0);
		add_back(&L_empty, new);
		i++;
	}
	save = L_full;
	i = 0;
	while (i < j)
	{
		tmp = copy_task(L_full);
		//should be added to free space
		L_full = L_full->next;
		circular_push(&head_tourniquet, tmp);
		execute(head_tourniquet);
		i++;
	}
	L_full = save;

	printf("\n**********FULL LIST\n");
	printing(L_full);
	printf("\n**********EMPTY LIST\n");
	printing(L_empty);

	printf("*******************************************************\n");
	printf("*******************************************************\n");
	printf("*******************************************************\n");

	full_to_empty(&L_full, &L_empty);
	full_to_empty(&L_full, &L_empty);
	
	printf("\n**********FULL LIST\n");
	printing(L_full);
	printf("\n**********EMPTY LIST\n");
	printing(L_empty);
	return 0;
}
