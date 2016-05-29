#include <iostream>
#include <string>
#include "hermione.h"

int main()
{
	Equation equation;
	string str_equation = "23*x+12/4=1";

	//cin >> str_equation;
	equation.parsing_equation_string(str_equation);

	return 0;
}