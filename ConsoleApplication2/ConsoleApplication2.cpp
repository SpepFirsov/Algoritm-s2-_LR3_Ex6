// ConsoleApplication2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <iostream>
#include <list>  
#include <stack>
#include<time.h>
using namespace std;

struct Stack {
    int num;
    Stack* next;
}list1;

void In(Stack** list1, int num);
void View(Stack* list1);
void StackDel(Stack** list1);
int* MaxFinder(Stack* list1);
int* MinFinder(Stack* list1);

int main()
{
    setlocale(LC_ALL, "Rus");
    srand(time(0));

    Stack* begin;
    begin = NULL;
    cout << "Кол-во элементов:";
    int list;
    cin >> list;

    for (int i = 0; i != list; i++)
        In(&begin, ((-10 + rand() % 50)));
    View(begin);

    int* min = MinFinder(begin);
    int* max = MaxFinder(begin);

    swap(*min, *max);
    View(begin);
    return 0;
}
void In(Stack** list1, int num)
{
    Stack* t = new Stack;
    t->num = num;
    t->next = *list1;
    *list1 = t;
}
void View(Stack* list1)
{
    Stack* t = list1;
    if (list1 == NULL) {
        cout << "Стек пуст!" << endl;
        return;
    }
    while (t != NULL) {
        cout << t->num << endl;
        t = t->next;
    }
}
int* MinFinder(Stack* list1)
{
    int* min = &list1->num;
    Stack* t = list1;
    while (t != NULL) {
        if (t->num < *min)
            min = &t->num;
        t = t->next;
    }
    cout << "Минимальный элемент:" << *min << endl;

    return min;
}
int* MaxFinder(Stack* list1)
{
    int* max = &list1->num;
    Stack* t = list1;
    while (t != NULL) {
        if (t->num > *max)
            max = &t->num;
        t = t->next;
    }
    cout << "Максимальный элемент:" << *max << endl;

    return max;
}