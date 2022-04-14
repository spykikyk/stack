#include <iostream>
#include "Header.h"
#include <string>
using namespace std;

int fillStackSequence(elem*& stack, string str)
{
	int n = 0;

	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '[' || str[i] == '(' || str[i] == '<' || str[i] == '{' || str[i] == ']' || str[i] == ')' || str[i] == '>' || str[i] == '}') {
			if (str[i] == ']' || str[i] == ')' || str[i] == '>' || str[i] == '}') {
				char val;
				if (int(*peek(stack)) + 2 == int(str[i]) || int(*peek(stack)) + 1 == int(str[i])) {
					pop(stack, str[n]);
				}
				else {
					cout << "Неправильно закрытая скобка " << str[i] << " на " << i + 1 << " месте " << endl;
					pop(stack, str[n]);
					n = 1;
				}
			}
			else {
				push(stack, str[i]);
				n = i;
			}
			
		}

	}
	return n;
	
}

void elements(elem*& stack)//Функция заполнения стека
{
	string str = "";
	cin >> str;
	cout << str.size() << endl;
	int f = fillStackSequence(stack, str);
	//if (!f) {
		//cout << "Неправильно расположены скобки" << endl;
	//}
}


//Функция вывода содержимого стека на экран
void showStack(elem*& stack)//Функция вывода содержимого стека на экран
{
	while (stack)
	{
		char val;
		if (pop(stack, val)) //Если элемент из стека получен, выводим на экран
		{
			cout << val << ((stack) ? " " : "\n");
		}
	}
}void main()
{
	setlocale(LC_ALL, "Russian");
	elem* stack = nullptr;
	elements(stack);
	system("pause");
}
