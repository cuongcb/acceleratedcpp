#include <iostream>
#include <string>

void GreetingStyleOne()
{
	std::cout << "Please enter your first name: ";

	std::string firstName;
	std::cin >> firstName;

	std::cout << "Hello, " << firstName << "!" << std::endl;
}

void GreetingStyleTwo()
{
	std::cout << "Please enter your first name: ";
	std::string firstName;
	std::cin >> firstName;

	const std::string greeting = "Hello, " + firstName + "!";

	const std::string spaces(greeting.length(), ' ');
	const std::string second = "* " + spaces + " *";
	const std::string first(second.length(), '*');

	std::cout << std::endl;
	std::cout << first << std::endl;
	std::cout << second << std::endl;
	std::cout << "* " << greeting << " *" << std::endl;
	std::cout << second << std::endl;
	std::cout << first << std::endl;
}

void GreetingStyleThree()
{
	std::cout << "Please enter your first name: ";

	std::string firstName;
	std::cin >> firstName;

	const std::string greeting = "Hello, " + firstName + "!";

	const int pad = 1;

	const int rows = pad * 2 + 3;
	const std::string::size_type cols = greeting.size() + pad * 2 + 2;

	std::cout << std::endl;

	for (int r = 0; r != rows; ++r)
	{
		std::string::size_type c = 0;

		while (c != cols)
		{
			if (r == pad + 1 && c == pad + 1)
			{
				std::cout << greeting;
				c += greeting.size();
			}
			else
			{
				if (r == 0 || r == rows - 1 || c == 0 || c == cols - 1)
					std::cout << "*";
				else
					std::cout << " ";
				++c;
			}
		}
		std::cout << std::endl;
	}
}