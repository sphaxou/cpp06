#ifndef CONVERTOR_HPP
#define CONVERTOR_HPP
#include <string>

class Convertor
{
	private:
		long int	int_scalar;
		char char_scalar;
		float float_scalar;
		double double_scalar;

		int type; //0 char, 1 int, 2 float, 3 double, -1 error
		int findtype(const char *s);
		int special_case(const std::string &s);
		int	handle_number(const char *s);
		void set_scalar(const char *s);

		bool char_ok(double);
		bool int_ok(double);
		bool float_ok(double);
		bool double_ok(double);

		Convertor();
		Convertor(const Convertor &src);
		Convertor &operator=(Convertor const &src);
	public:
		Convertor(const char *s);

		void print_from_char();
		void print_from_int();
		void print_from_float();
		void print_from_double();

		int	gettype() const;

		class no_type_exception: public std::exception
		{
			public:
				virtual const char *what() const throw(){return ("Could not detect a correct type");}
		};
};

#endif