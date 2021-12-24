#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <string>
#include <iostream>
#include <cstdlib>

Base	*generate(void)
{
	
	int selected = rand() % 3;

	if (selected == 0)
	{
		std::cout << "generating A" << std::endl;
		return (new A());
	}
	if (selected == 1)
	{
		std::cout << "generating B" << std::endl;
		return (new B());
	}
	if (selected == 2)
	{
		std::cout << "generating C" << std::endl;
		return (new C());
	}
	return (NULL);
}

void identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << 'A' << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << 'B' << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << 'C' << std::endl;
}

void identify(Base &p)
{
	try
	{
		A &a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << 'A' << std::endl;
	}
	catch(const std::exception& e)
	{
		(void)e;
	}

	try
	{
		B &b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << 'B' << std::endl;
	}
	catch(const std::exception& e)
	{
		(void)e;
	}
	
	try
	{
		C &c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << 'C' << std::endl;
	}
	catch(const std::exception& e)
	{
		(void)e;
	}
}

int main()
{
	srand(time(NULL));
	Base	*base;
	base = generate();
	identify(base);
	identify(*base);
	delete base;
	base = generate();
	identify(base);
	identify(*base);
	delete base;
	base = generate();
	identify(base);
	identify(*base);
	delete base;
	base = generate();
	identify(base);
	identify(*base);
	delete base;
	base = generate();
	identify(base);
	identify(*base);
	delete base;
	return (0);
}