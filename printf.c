#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c, int *count)
{
	*count += write(1, &c, 1);
}
void	ft_putstr(char *str, int *count)
{
	int	i;

	if (!str)
		str = "(null)";
	i = 0;
	while (str[i])
	{
		ft_putchar(str[i], count);
		i++;
	}
}
void	ft_putnbr(long nbr, int *count)
{
	if (nbr < 0)
	{
		ft_putchar('-', count);
		ft_putnbr(-nbr, count);
	}
	else if (nbr > 9)
	{
		ft_putnbr(nbr / 10, count);
		ft_putnbr(nbr % 10, count);
	}
	else
		ft_putchar(nbr + '0', count);
}
void	ft_puthexa(unsigned int nbr, int *count)
{
	if (nbr >= 16)
	{
		ft_puthexa(nbr / 16, count);
		ft_puthexa(nbr % 16, count);
	}
	else
		ft_putchar("0123456789abcdef"[nbr], count);
}

int	ft_printf(const char *fmt, ...)
{
	int	i;
	int	count;
	va_list	args;

	count = 0;
	i = 0;
	va_start(args, fmt);
	while (fmt[i])
	{
		if (fmt[i] == '%')
		{
			i++;
			if (fmt[i] == 's')
				ft_putstr(va_arg(args, char *), &count);
			else if (fmt[i] == 'd')
				ft_putnbr(va_arg(args, int), &count);
			else if (fmt[i] == 'x')
				ft_puthexa(va_arg(args, unsigned int), &count);
			else
				ft_putchar(fmt[i], &count);
		}
		else
			ft_putchar(fmt[i], &count);
		i++;
	}
	va_end(args);
	return (count);
}

int	main()
{
	int	real;
	int	mine;

	mine = ft_printf("Little test with s : %s, with (NULL)s : %s, with +d : %d, with -d : %d, with +x : %x, with -x : %x\n", "Hello World!", (char *)0, 23456, -12345, 2345, -2345);
	real = printf("Little test with s : %s, with (NULL)s : %s, with +d : %d, with -d : %d, with +x : %x, with -x : %x\n", "Hello World!", (char *)0, 23456, -12345, 2345, -2345);
	ft_printf("Mine : %d\n", mine);
	printf("Real : %d\n", real);
}