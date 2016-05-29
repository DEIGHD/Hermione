#include <string>
#include <vector>
#include "hermione.h"
using namespace std;

void ElementEquation::set(int iNumber)
{
	m_number = iNumber;
	m_flag = 1;
}

void ElementEquation::set(string sOperation)
{
	m_operation = sOperation;
	m_flag = 2;
}

void ElementEquation::set(char cUnknown)
{
	m_unknown = cUnknown;
	m_flag = 3;
}

inline char ElementEquation::get_unknown()
{
	return m_unknown;
}

void ElementEquation::clear()
{
	m_number = 0;
	m_operation = "";
	m_flag = 0;
}

bool Equation::parsing_equation_string(string strEquation)
{
	if (strEquation.length() == 0)
	{
		return false;
	}
	ElementEquation eElement;
	string sNumberBuf = "";
	string sOperationBuf = "";
	for (unsigned int i = 0; i < strEquation.length(); i++)
	{
		if (isdigit(strEquation[i]))
		{
			if (sOperationBuf != "")
			{
				eElement.set(sOperationBuf);
				elements_equation.push_back(eElement);
				eElement.clear();
				sOperationBuf = "";
			}
			sNumberBuf += strEquation[i];
		}
		else
		{
			if (sNumberBuf != "")
			{
				eElement.set(atoi(sNumberBuf.c_str()));
				elements_equation.push_back(eElement);
				eElement.clear();
				sNumberBuf = "";
			}
			if (strEquation[i] != eElement.get_unknown())
			{
				sOperationBuf += strEquation[i];
			}
			else
			{
				eElement.set(sOperationBuf);
				elements_equation.push_back(eElement);
				eElement.clear();
				sOperationBuf = "";

				eElement.set(strEquation[i]);
				elements_equation.push_back(eElement);
				eElement.clear();
			}
		}

	}

	if (sNumberBuf != "")
	{
		eElement.set(atoi(sNumberBuf.c_str()));
		elements_equation.push_back(eElement);
		eElement.clear();
		sNumberBuf = "";
	}

/*	if (sOperationBuf != "")
	{
		if (sOperationBuf.length() > 1)
		{
			return false;
		}
		if (sOperationBuf[0] == eElement.get_unknown())
		{
			eElement.set(sOperationBuf[0]);
			elements_equation.push_back(eElement);
			eElement.clear();
			sOperationBuf = "";
		}
	}*/

	return true;
}