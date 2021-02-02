#include "./libft/libft.h"
#include "parsing.h"

float	to_float(int int_part, int decimal_part, int negative)
{
	int 	decimal_len;
	int 	tmp;
	float	number;

	tmp = int_part;
	decimal_len = ft_int_size(decimal_part);
	int_part = int_part * pow(10, decimal_len);
	if (negative == 1 && int_part != 0)
		decimal_part = -1 * decimal_part;
	int_part = int_part + decimal_part;
	number = int_part * pow(10, -decimal_len);
	if (negative == 1 && tmp == 0)
		number *= -1;
	return (number);
}

float	ft_atof(char *line)
{
	int 	int_part;
	int 	decimal_part;
	int 	int_len;
	int		negative;
	float	number;

	int_len = 0;
	negative = 0;
	if (line[0] == '-' && line[1] == '0')
	{
		negative = 1;
		int_len = 1;
	}
	printf("negative |%d|\n",negative);
	int_part = ft_atoi(line);
	printf("int_part==%d\n", int_part);
	negative = (int_part < 0) ? 1 : negative;
	int_len += ft_int_size(int_part);
	printf("int_len==%d\n", int_len);
	decimal_part = ft_atoi(line + int_len + 1);
	printf("int_part == %d\ndecimal_part == %d\n is_negative == %d\n", int_part, decimal_part, negative);
	number = to_float(int_part, decimal_part, negative);
	return(number); 
}

int main()
{
	float decimal;
	char *line = "222,2";
	int test;

	test = ft_atoi(line);
	decimal = ft_atof(line);
	printf("%f",decimal);
	return (0);
}