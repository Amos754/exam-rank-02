#include <unistd.h>

int	check(char c, char *str, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}
int	main(int ac, char **av)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = 0;
	if (ac == 3)
	{
		while (av[1][i])
		{
			if (check(av[1][i], av[1], i) == 0)
				write(1, &av[1][i], 1);
			i++;
		}
		tmp = i;
		i = 0;
		while (av[2][i])
		{
			if (check(av[2][i], av[1], tmp) == 0)
			{
				if (check(av[2][i], av[2], i) == 0)
					write(1, &av[2][i], 1);
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}