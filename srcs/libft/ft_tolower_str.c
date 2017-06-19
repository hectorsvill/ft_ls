


char *ft_tolower_str(char *str)
{
	while (*str)
	{
		if (*str >= 65 && *str <= 90)
			*str += 32;
		str++;
	}
	return (str);
}
