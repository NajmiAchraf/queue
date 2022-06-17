#include "multitask.h"

static int	count(int n)
{
	int	r;

	r = 0;
	if (n < 0)
		r++;
	while (n)
	{
		n /= 10;
		r++;
	}
	return (r);
}

char	*ft_itoa(int nbr)
{
	char	*str;
	long	n;
	int		r;

	n = nbr;
	r = count(nbr);
	str = malloc ((r + 1) * sizeof (char));
	if (!str)
		return (NULL);
	str[r--] = '\0';
	if (n < 0)
	{
		n *= -1;
		str[0] = '-';
	}
	while (n)
	{
		str[r--] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	str = malloc ((strlen (s1) + strlen (s2) + 1) * sizeof (char));
	if (!str)
		return (0);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	j = -1;
	while (s2[++j])
		str[i++] = s2[j];
	str[i] = '\0';
	return (str);
}
