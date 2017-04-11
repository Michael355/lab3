// laba3.cpp: определяет точку входа для консольного приложения.
//


#include "stdafx.h"
#pragma once
#include <stdio.h>
#include <tchar.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
struct Element
{
	int data;
	Element *next;
};
//функция добавления элемента x в заданную позицию
void add(Element *&top, int pos, int x)
{
	int j = 1;
	int i;
	Element *pnew, *p = top;
	pnew = new Element;
	pnew->data = x;
	if (pos <= 1 || top == NULL)
	{
		pnew->next = top; top = pnew;
	}
	else
	{
		for (i = 1; i<pos - 1; i++)
		if (p->next != NULL)
		{
			p = p->next;
			j++;
		}
		if (pos <= j + 1)
		{
			pnew->next = p->next; p->next = pnew;
		}
	}
}
// функция для вывода списка
void print(Element *top)
{
	Element *p = top;
	while (p != NULL)
	{
		cout << p->data << ' ';
		p = p->next;
	}
	cout << endl;
}
//удалить все
void clrscr(Element *&top)
{
	while (top != NULL)
	{
		if (top == NULL)
		{
			cout << "List is empty!" << endl;
		}
		else
		{
			Element *p = top;
			top = top->next;
			delete p;
		}
	}
}
//удаление элемента с позиции 
void delet(Element *&top, int pos2)
{
	Element *a = top, *b;
	int i = 0;
	while (a != NULL)
	{
		a = a->next;
		i++;
	}
	if (pos2>i || pos2<1)
	{
		cout << "There is no such position in the list!" << endl;
	}//проверка на сущ-е позиции      
	else
	{
		if (pos2 == 1)
		{
			a = top->next;//если эл-т первый
			top = a;
		}
		if (pos2>1)
		{
			i = 1;//если эл-т не первый
			a = top;
			while (i != pos2 - 1)
			{
				i++; a = a->next;
			}
			b = a->next;
			a->next = b->next;//сдвигаем
			delete b;
		}
	}
}

int main() {
	int pos, pos2;
	int x, r, n;
	Element *top = NULL;
	cout << "Enter amount of elements: ";// количество элементов
	cin >> n;
	if (n != 0)
	for (int i = 1; i <= n; i++) // формирование списка
	{
		r = rand() % 100;
		add(top, i, r); // вставка элемента 
	}
	print(top); // вывод списка
	cout << "AddInsert" << endl << "Symvol: ";
	cin >> x;
	cout << "Position: ";
	cin >> pos;
	add(top, pos, x); // добавление элементов в позицию списка
	print(top);
	cout << "Delete" << endl << "Position: ";
	cin >> pos2;
	delet(top, pos2);
	print(top);
	system("pause");
}
