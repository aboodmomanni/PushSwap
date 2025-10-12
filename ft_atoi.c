#include "push.h"

static int numchecker(char *num)
{
	int i;

	i = 0;
	if (num[i] == '-' || num[i] == '+')
		i++;
	if (!num[i])
		return (0);
	while (num[i])
	{
		if (num[i] < '0' || num[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

long long ft_atoi(char *num)
{
	int sign;
	int i;
	long long sum;

	sum = 0;
	i = 0;
	sign = 1;
	while (num[i] == ' ' || (num[i] >= 9 && num[i] <= 13))
		i++;
	if (!numchecker(&num[i]))
		ft_error();
	if (num[i] == '-' || num[i] == '+')
	{
		if (num[i] == '-')
			sign *= -1;
		i++;
	}
	while (num[i] >= '0' && num[i] <= '9')
	{
		sum = sum * 10 + (num[i] - '0');
		if (sum * sign > 2147483647 || sum * sign < -2147483648)
			ft_error();
		i++;
	}
	return (sign * sum);
}
