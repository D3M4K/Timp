**ОТЧЕТ ПО ПРАКТИЧЕСКОЙ РАБОТЕ №3**

**ТЕХНОЛОГИИ И МЕТОДЫ ПРОГРАММИРОВАНИЯ**

Выполнил
студент гр. 739-1
Климанов Михаил Денисович
3.04.2021




### 1 Введение
Цель работы: познакомиться с односвязным списком, как с динамической структурой данных, а также написать программу, реализующую несколько функций для работы с односвязным списком.

Задание:

1.Должны быть выполнены предыдущие работы

2.Прочитать про односвязные списки на СИ

3.Написать программу

4.Настроить pipeline

5.Написать отчет по работе в разметке Markdown (README.md)

6.Залить на gitlab и убедиться, что pipeline проходит успешно

7.Защитить работу у преподавателя




Алгоритм выполнения программы:  

1.считывает количество элементов n, 0 < n <= 2147483647;

2.создает пустой список, считывает n элементов a, |a| <= 2147483647 и заносит их в список;

3.выводит содержимое списка, используя функцию print;

4.считывает k1, k2, k3 (|k| <= 2147483647) и выводит "1", если в списке существует элемент с таким значением и "0", если нет (выводить через пробел, например "1 0 1");

5.считывает m, |m| <= 2147483647 и вставляет его в конец списка;

6.выводит содержимое списка, используя функцию print;

7.считывает t, |t| <= 2147483647 и вставляет его в начало списка;

8.выводит содержимое списка, используя функцию print;

9.считывает j и x (0 < j <= 2147483647, |x| <= 2147483647) и вставляет значение x после j-ого элемента списка;

10.выводит содержимое списка, используя функцию print;

11.считывает z, |z| <= 2147483647 и удаляет первый элемент (при его наличии), хранящий значение z из списка;

12.выводит содержимое списка, используя функцию print;

13.очищает список.

### 2 Ход работы
#### 2.1 Работа с программой

В функции описывается выделение памяти под корень списка и последний узел списка.
Далее представлены функции, которые нужно реализовать для работы с односвязным списком.

```c
// инициализация пустого списка
void init(list *l);

// удалить все элементы из списка
void clean(list *l);

// проверка на пустоту списка
bool is_empty(list *l);

// поиск элемента по значению. вернуть NULL если эжемент не найден
node *find(list *l, int value);

// вставка значения в конец списка, вернуть 0 если успешно
int push_back(list *l, int value);

// вставка значения в начало списка, вернуть 0 если успешно
int push_front(list *l, int value);

// вставка значения после указанного узла, вернуть 0 если успешно
int insert_after(node *n, int value);

// удалить первый элемент из списка с указанным значением, 
// вернуть 0 если успешно
int remove_node(list *l, int value);

// вывести все значения из списка в прямом порядке через пробел,
// после окончания вывода перейти на новую строку
void print(list *l);
```
Реализованные функии вместе с полным кодом программы представлены ниже.

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>// bool,
struct List
{
struct List* NextBlock;
double Data;
};
struct node
{
struct node* NextBlock;
double Data;
};
void init(struct List** l)  // инициализация пустого списка
{
*l = (struct List*)malloc(sizeof(struct List));//выделение памяти под корень списка
(*l)->NextBlock = NULL;//первый узел списка
(*l)->Data = 2147483648;
}
int push_back(struct List* l, int value)
{
if (l->Data == 2147483648)
{
l->Data = value;
return 0;
}
struct List* Temp = (struct List*)malloc(sizeof(struct List));
Temp = l;
while (Temp->NextBlock != NULL)//из Temp получаем NextBlock
Temp = Temp->NextBlock;
Temp->NextBlock = (struct List*)malloc(sizeof(struct List));
Temp = Temp->NextBlock;
Temp->Data = value;
Temp->NextBlock = NULL;
return 0;
}
struct node* find(struct List* l, int value)
{
struct List* Temp = l;
while (1)
{
if (Temp == NULL)
return NULL;
else
{
if ((Temp->Data) == value)
return ((struct node*)l);
}
Temp = Temp->NextBlock;
}
}
int push_front(struct List** l, int value) // вставка значения в начало списка, вернуть 0 если успешно
{
struct List* Temp = (struct List*)malloc(sizeof(struct List));
Temp->Data = value;
Temp->NextBlock = (*l);
(*l) = Temp;
return 0;
}
int insert_after(struct node* l, int value) // вставка значения после указанного узла
{
struct List* Temp = (struct List*)malloc(sizeof(struct List)), * Temp2;
Temp2 = (struct List*)l->NextBlock;
l->NextBlock = (struct node*)Temp;
Temp->Data = value;
Temp->NextBlock = Temp2;
return 0;
}
int remove_node(struct List* l, int value) // удалить первый элемент из списка с указанным значением
{
struct List* Temp = l;
if (l != NULL)
{
while (1)
{
if ((Temp->NextBlock) == NULL)
return 1;
if ((Temp->NextBlock->Data) == value)
{
struct List* Temp2 = (struct List*)malloc(sizeof(struct List));
Temp2 = Temp->NextBlock->NextBlock;
free(Temp->NextBlock);
Temp->NextBlock = Temp2;
return 0;
}
Temp = Temp->NextBlock;
}
}
else
return 1;
}
void clean(struct List* l)
{
struct List* Temp = l;
do
{
Temp = Temp->NextBlock;
free(l);//освобождение памяти удаленного узла
l = Temp;//переставляем указатель
} while (l != NULL);
}

bool is_empty(struct List* l)
{
if (l == NULL)
return 0;
else
return 1;
}

void print(struct List* l)
{
while (l != NULL)
{
printf("%.0lf ", l->Data);
l = l->NextBlock;
}
printf("\n");
}
int main()
{
struct List* l, * Temp;
int N, i;
double a, b;
scanf("%d", &N);//1
init(&l);//2
for (i = 0; i < N; i++)
{
scanf("%lf", &a);
push_back(l, a);
}
print(l);//3
for (i = 0; i < 3; i++)//4
{
scanf("%lf", &a);
if (find(l, a) == NULL)
printf("0");
else
printf("1");
if (i != 2)
printf(" ");
else
printf("\n");
}
scanf("%lf", &a);//5
push_back(l, a);
print(l);//6
scanf("%lf", &a);//7
push_front(&l, a);
print(l);//8
scanf("%lf", &a);//9
scanf("%lf", &b);
struct node* el = (struct node*)l;
while (a != 1)
{
el = el->NextBlock;
a--;
}
insert_after(el, b);
print(l);//10
scanf("%lf", &a);//11
if (l->Data == a)
{
Temp = l->NextBlock;
free(l);
l = Temp;
}
else
remove_node(l, a);
print(l);//12
clean(l);//13
return 1;
}
```
Проверим работу программы с помощью данных в таблице 1 входных и выходных данных.

Таблица 1 - Проверочные входные и выходные данные:
|Input|Output|
|-|-|
|1 2 3 2 4|1 2 3 2 4|
|2 5 1|1 0 1|
|5| 1 2 3 2 4 5|
|7|7 1 2 3 2 4 5|
|3 0|7 1 2 0 3 2 4 5|
|2|7 1 0 3 2 4 5|

Результат работы программы представлен на рисунке 1.



![](https://sun9-15.userapi.com/impf/7-1Kad0HoSgvWOgQq3uRtbKZByFRyVA2m3E2Fg/eWnyEH1ItCg.jpg?size=319x351&quality=96&sign=bdf6598203e8f35a2d8e144756887368&type=album)


Рисунок 1 — Результат работы программы.


#### 2.2 Работа с GitLab


После загрузки, проект должен пройти pipeline проверку. Результаты проверки представлены на рисунке 2.



![](https://sun9-68.userapi.com/impf/dX9hmgW5iy4ZQRKFkmE58dcZKGWBiq3l0cr3sQ/Au0Qr1E3rrg.jpg?size=267x292&quality=96&sign=eb145331d39a5540800fffa0c1913e96&type=album)

Рисунок 2 — Результаты pipeline-проверки




### 3 Заключение
В процессе выполнения практической работы были изучены принципы работы с односвязными(линейными) списками в языке программирования C, а также разработана программа с реализацией некоторых функций для работы с таким списком.


