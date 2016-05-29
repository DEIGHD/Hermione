#pragma once
#include <string>
#include <vector>
using namespace std;

class ElementEquation
{
private:
	int m_number = 0;
	string m_operation = "";
	char m_unknown = 'x';
	//ElementEquation *m_element_equation;
	unsigned char m_flag = 0; // 0 -������, 1 - �����, 2 - ��������, 3 - ����������� // 4 - ���� ����������
public:
	void set(int);
	void set(string);
	void set(char);
	//void set(ElementEquation &);

	inline char get_unknown();
	void clear();
};

class Equation
{
public:
	vector<ElementEquation> elements_equation;
	bool parsing_equation_string(string);
};