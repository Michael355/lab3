// laba3.cpp: ���������� ����� ����� ��� ����������� ����������.
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
//������� ���������� �������� x � �������� �������
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
// ������� ��� ������ ������
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
//������� ���
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
//�������� �������� � ������� 
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
	}//�������� �� ���-� �������      
	else
	{
		if (pos2 == 1)
		{
			a = top->next;//���� ��-� ������
			top = a;
		}
		if (pos2>1)
		{
			i = 1;//���� ��-� �� ������
			a = top;
			while (i != pos2 - 1)
			{
				i++; a = a->next;
			}
			b = a->next;
			a->next = b->next;//��������
			delete b;
		}
	}
}

int main() {
	int pos, pos2;
	int x, r, n;
	Element *top = NULL;
	cout << "Enter amount of elements: ";// ���������� ���������
	cin >> n;
	if (n != 0)
	for (int i = 1; i <= n; i++) // ������������ ������
	{
		r = rand() % 100;
		add(top, i, r); // ������� �������� 
	}
	print(top); // ����� ������
	cout << "AddInsert" << endl << "Symvol: ";
	cin >> x;
	cout << "Position: ";
	cin >> pos;
	add(top, pos, x); // ���������� ��������� � ������� ������
	print(top);
	cout << "Delete" << endl << "Position: ";
	cin >> pos2;
	delet(top, pos2);
	print(top);
	system("pause");
}
