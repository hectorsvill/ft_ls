


char *ft_tolower_str(char *str)
{
	char *tmp;

	tmp = str;
	while (*tmp)
	{
		if (*tmp >= 65 && *tmp <= 90)
			*tmp += 32;
		tmp++;
	}
	return (str);
}
