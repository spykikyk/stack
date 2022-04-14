#pragma once
//Структура для хранения элементов стека
struct elem {
	char value; // Информационное поле стека
	elem* next = nullptr; // Адресное поле стека
};
//Добавление элемента в стек
void push(elem*& stack, char value);
//Удаление элемента из стека с возвратом хранимого значения
bool pop(elem*& stack, char& value);
//Возврат значения с вершины стека, без удаления самого элемента
char* peek(elem* stack);
//Удаление всего стека
void clear(elem*& stack);

