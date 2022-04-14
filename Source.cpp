#include "Header.h"
void push(elem*& stack, char value)
{
	//Создаем элемент стека (размещаем в памяти)
	elem* newel = new elem;
	newel->value = value;
	//Проверка пустоты стека
	if (!stack)
	{
		//Стек пустой, новый элемент будет первым
		stack = newel;
	}
	else
	{
		//Стек заполнен, новый элемент размещается на вершине
		newel->next = stack;
		stack = newel;
	}
}


bool pop(elem*& stack, char& value)
{
	//Проверка стека на пустоту
	if (!stack) return false; //Признак того, что значение не возвращено
	elem* old_el = stack;//Сохранение указателя на текущую вершину во временной переменной
	value = stack->value;//Сохранение значения элемента из стека
	stack = stack->next;//Изменение вершин стека
	delete old_el;//Очищаем память из-под удаляемого элемента
	return true;
}

char* peek(elem* stack)
{
	//Проверка стека на пустоту
	if (!stack) return nullptr; //Сохранение значения элемента стека
	return &stack->value;
}

void clear(elem*& stack)
{
	char value;
	while (stack) pop(stack, value);
}
