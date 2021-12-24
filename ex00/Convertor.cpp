#include "Convertor.hpp"
#include <iostream>
#include <limits>
#include <cmath>

Convertor::Convertor(const char *s)
{
	type = findtype(s);
	set_scalar(s);
}

void Convertor::set_scalar(const char *s)
{
	switch (type)
	{
		case -1:
			throw no_type_exception();
		case 0:
			char_scalar = s[0];
			break;
		case 1:
			int_scalar = atol(s);
			break;
		case 2:
			float_scalar = atof(s);
			break;
		case 3:
			double_scalar = atof(s);
			break;
	}
}

int Convertor::findtype(const char *s)
{
	int i;
	if ((i = special_case(s)))
		return (i);
	if ((s[0] >= '0' && s[0] <= '9') || s[0] == '-' || s[0] == '+')
		return (handle_number(s));
	if (!s[1])
		return (0);
	return (-1);
}

int Convertor::special_case(const std::string &s)
{
	const std::string doubles[] =
	{"inf", "+inf", "-inf", "nan"};
	const std::string floats[] =
	{"inff", "+inff", "-inff", "nanf"};
	for (int i = 0; i < 4; i++)
	{
		if (s == floats[i])
			return (2);
		if (s == doubles[i])
			return (3);
	}
	return (0);
}

int	Convertor::handle_number(const char *s)
{
	int dot = 0;
	int i = 0;

	if (s[i] == '-' && s[i + 1])
		i++;
	if (s[i] == '.' && (s[i + 1] == 'f' || s[i + 1] == 0))
		return (-1);
	while (s[i] == '.' || (s[i] >= '0' && s[i] <= '9'))
	{
		if (s[i] == '.')
			dot++;
		if (dot > 1)
			return (-1);
		i++;
	}
	if (!s[i])
	{
		if (dot == 1)
			return (3);
		return (1);
	}
	if (s[i] == 'f' && !s[i + 1] && dot == 1)
		return (2);
	return (-1);
}

int	Convertor::gettype() const{
	return (type);
}

bool Convertor::char_ok(double n)
{
	if (n - static_cast<int>(n) != 0 || n > 127 || n < 0)
		std::cout << "char: impossible" << std::endl;
	else if (n <= 31 || n == 127)
		std::cout << "char: Non diplayable" << std::endl;
	else
	{
		return true;
	}
	return false;		
}

bool	Convertor::int_ok( double number )
{
	return (number <= std::numeric_limits<int>::max()
			&& number >= std::numeric_limits<int>::min()
			&& number != std::numeric_limits<double>::infinity()
			&& number != -std::numeric_limits<double>::infinity()
			&& number != std::numeric_limits<double>::quiet_NaN());
}

bool	Convertor::float_ok( double number )
{
	return ((number <= std::numeric_limits<float>::max()
			&& number >= -std::numeric_limits<float>::max())
			|| number == std::numeric_limits<double>::infinity()
			|| number == -std::numeric_limits<double>::infinity()
			|| std::isnan(number));
}

void	Convertor::print_from_char()
{
	std::cout << "char: " << char_scalar << std::endl;
	std::cout << "int: " << static_cast<int>(char_scalar) << std::endl;
	std::cout << "float: " << static_cast<float>(char_scalar) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(char_scalar) << ".0" << std::endl;
}

void Convertor::print_from_int()
{
	if (char_ok(int_scalar))
		std::cout << "char: " << static_cast<char>(int_scalar) << std::endl;
	if (int_ok(int_scalar))
		std::cout << "int: " << static_cast<int>(int_scalar) << std::endl;
	else
		std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << static_cast<float>(int_scalar) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(int_scalar) << ".0" << std::endl;
}

void Convertor::print_from_float()
{
	if (char_ok(float_scalar))
		std::cout << "char: " << static_cast<char>(float_scalar) << std::endl;
	if (int_ok(float_scalar))
		std::cout << "int: " << static_cast<int>(float_scalar) << std::endl;
	else
		std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << float_scalar << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(float_scalar) << std::endl;
}

void Convertor::print_from_double()
{
	if (char_ok(double_scalar))
		std::cout << "char: " << static_cast<char>(double_scalar) << std::endl;
	if (int_ok(double_scalar))
		std::cout << "int: " << static_cast<int>(double_scalar) << std::endl;
	else
		std::cout << "int: impossible" << std::endl;
	if (float_ok(double_scalar))
		std::cout << "float: " << static_cast<float>(double_scalar) << "f" << std::endl;
	else
		std::cout << "float: impossible" << std::endl;	
	std::cout << "double: " << double_scalar << std::endl;
}