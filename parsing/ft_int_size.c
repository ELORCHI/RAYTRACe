
int ft_int_size(int i)
{
	int 	size;

	if (i < 0)
		size = 1;
	while (i != 0)
	{
		i /= 10;
		size++;
	}
	return (size)
}