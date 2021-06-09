## Отчет по практической работе №4. Двусвязные списки
Выполнил: 

Студент группы 739-1

_______Климанов М.Д.

29.04.2021

### 1 Введение
Задания на первую практическую работу представлены в таблице 1.

Таблица 1 - Задания
| Номер | Задание |
| ------------- | ------------- |
|  1  | Должны быть выполнены предыдущие работы.  |
| 2  | Прочитать про двусвязные списки на СИ. |
| 3 | Написать программу.|
| 4 | Настроить pipeline.|
| 5 | Написать отчет по работе в разметке Markdown (README.md).|
| 6 | Залить на gitlab и убедиться, что pipeline проходит успешно.|
| 7 | Защитить работу у преподавателя.|


Алгоритм выполнения программы:  

1. Считывает количество элементов n, 0 < n <= 2147483647;
2. Создает пустой список, считывает n элементов a, |a| <= 2147483647 и заносит их в список;
3. Выводит содержимое списка, используя функцию print;
4. Считывает k1, k2, k3 (|k| <= 2147483647) и выводит "1", если в списке существует элемент с таким значением и "0" если нет (выводить через пробел, например "1 0 1");
5. Считывает m, |m| <= 2147483647 и вставляет его в конец списка;
6. Выводит содержимое списка, используя функцию print_invers;
7. Считывает t, |t| <= 2147483647 и вставляет его в начало списка;
8. Выводит содержимое списка, используя функцию print;
9. Считывает j и x (0 < j <= 2147483647, |x| <= 2147483647) и вставляет значение x после j-ого элемента списка;
10. Выводит содержимое списка, используя функцию print_invers;
11. Считывает u и y (0 < u <= 2147483647, |y| <= 2147483647) и вставляет значение y перед u-ым элементом списка;
12. Выводит содержимое списка, используя функцию print;
13. Считывает z, |z| <= 2147483647 и удаляет первый элемент (при его наличии), хранящий значение z из списка;
14. Выводит содержимое списка, используя функцию print_invers;
15. Считывает r, |r| <= 2147483647 и удаляет последний элемент (при его наличии), хранящий значение r из списка;
16. Выводит содержимое списка, используя функцию print;
17. Очищает список.

### 2 Ход работы
#### 2.1 Работа с программой
Двусвязный список - динамическая структура данных, состоящая из узлов, каждый из которых содержит как собственно данные, так и ссылки на следующий и предыдущий узлы списка.

Код для описания структуры List  выглядит следущим образом:
```c
struct List
{
	struct List* Front; // указатель на первый элемент списка
	struct List* Back; // указатель на последний элемент списка
	double Data; // значение, которое хранит элемент списка
};

```


Полный код программы находиться в приложении А.

В таблице 2 представлены значения для проверки кода, которые нужно проверить в своей программе.

Таблица 2 - Проверочные входные и выходные данные:
|Input|Output|
|-|-|
|5|
|1 2 3 2 4|1 2 3 2 4|
|2 5 1|1 0 1|
|1| 1 4 2 3 2 1|
|7|7 1 2 3 2 4 1|
|3 0|1 4 2 3 0 2 1 7|
|5 8|7 1 2 0 8 3 2 4 1|
|2|1 4 2 3 8 0 1 7|
|1|7 1 0 8 3 2 4|

При вводе этих данных, программа выдает ожидаемый результат из этого следует, что программа работает корректно.

Результат работы программы представлен на рисунке 1.


![](https://sun9-16.userapi.com/impg/9L0HmBPJDMr9Ci1BPQKsf_oNny06wdhXo1_dnw/0i6iKcltSLo.jpg?size=171x381&quality=96&sign=a811e70454e99aabab50d20f95908ed4&type=album)

Рисунок 1 — Результат работы программы.

#### 2.2 Настройка pipeline

Для корректной загрузки файлов на удаленный репозиторий в файле .gitlab_cy.yml наужно найти пункт stages и добавить pr4. Далее нужно убрать комментарии, чтобы все работало. На рисунке 2 представлено то, как это должно выглядеть.

![](https://sun9-11.userapi.com/impg/uVIaUXxAQt3EMJTH3zc9JBu2yRIoeuDh3an9vA/kpwatRcDnik.jpg?size=290x378&quality=96&sign=87420e00be612d45611467e0439764aa&type=album)

Рисунок 2 - Настройка pipeline

#### 2.3 Работа с GitLab

Далее, внесем последние изменения в наш локальный проект и передадим его в GitLab. 
После загрузки проекта он должен пройти pipeline проверку. 

Результаты проверки представлены на рисунке 3.

![](https://sun9-49.userapi.com/impg/JQ-IMXF16BLFh0VqO4lkTmrUkcgcXtQuFhIevA/C5fyByh8MIQ.jpg?size=490x581&quality=96&sign=1e15d77859adc8476783d11c4bfb600c&type=album)

Рисунок 3 — Результаты pipeline-проверки




### 3 Заключение
В процессе выполнения практической работы были изучены принципы работы с двусвязными списками в языке программирования C, а также были изучены некоторые функции для работы с таким списком.


### Приложение A
(обязательное)

Листининг кода программы

```c
#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>


struct List
{
	struct List* Front;
	struct List* Back;
	double Data;
};
void init(struct List** l) //получаем значение, взятое по адресу адреса
{
	*l = (struct List*)malloc(sizeof(struct List));
	(*l)->Front = NULL;
	(*l)->Back = NULL;
	(*l)->Data = 2147483648;
}
void clean(struct List* l)
{
	struct List* Temp = l;
	free(Temp->Back);
	do
	{
		Temp = Temp->Front;
		free(l);
		l = Temp;
	} while (l != NULL);
}
bool is_empty(struct List* l) // проверка на пустоту списка
{
	if (l == NULL)
		return 0;
	else
		return 1;
}
struct List* find(struct List* l, int value)
{
	struct List* Temp = l;
	while (1)
	{
		if (Temp == NULL)
			return NULL;
		else
		{
			if ((Temp->Data) == value)
				return ((struct List*)l);
		}
		Temp = Temp->Front;
	}
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
	while (Temp->Front != NULL)
		Temp = Temp->Front;
	Temp->Front = (struct List*)malloc(sizeof(struct List));
	Temp->Front->Back = Temp;
	Temp = Temp->Front;
	Temp->Data = value;
	Temp->Front = NULL;
	return 0;
}
int push_front(struct List** l, int value)
{
	struct List* Temp = (struct List*)malloc(sizeof(struct List));
	Temp->Data = value;
	Temp->Front = (*l);
	Temp->Back = NULL;
	Temp->Front->Back = Temp;
	(*l) = Temp;
	return 0;
}
int insert_after(struct List* l, int value)
{
	if (l->Front != NULL)
	{
		struct List* Temp = (struct List*)malloc(sizeof(struct List)), * Temp2;
		Temp->Front = l->Front;
		Temp->Back = l;
		Temp->Data = value;
		l->Front->Back = Temp;
		l->Front = Temp;
	}
	else
	{
		l->Front = (struct List*)malloc(sizeof(struct List));
		l->Front->Front = NULL;
		l->Front->Data = value;
		l->Front->Back = l;
	}
	return 0;
}
int insert_before(struct List* l, int value)
{
	if (l->Back != NULL)
	{
		struct List* Temp = (struct List*)malloc(sizeof(struct List)), * Temp2;
		Temp->Back = l->Back;
		Temp->Front = l;
		Temp->Data = value;
		l->Back->Front = Temp;
		l->Back = Temp;
	}
	else
	{
		l->Back = (struct List*)malloc(sizeof(struct List));
		l->Back->Back = NULL;
		l->Back->Data = value;
		l->Back->Front = l;
	}
	return 0;
}
int remove_first(struct List* l, int value)
{
	struct List* Temp = l;
	if (l != NULL)
	{
		while (1)
		{
			if ((Temp->Front) == NULL)
				return 1;
			if ((Temp->Front->Data) == value)
			{
				Temp = Temp->Front;
				if (Temp->Front != NULL)
				{
					Temp->Back->Front = Temp->Front;
					Temp->Front->Back = Temp->Back;
					free(Temp);
				}
				else
				{
					Temp->Back->Front = NULL;
					free(Temp);
				}
				return 0;
			}
			Temp = Temp->Front;
		}
	}
	else
		return 1;
}
int remove_last(struct List* l, int value)
{
	struct List* Temp = l, * TempSaving = NULL;
	if (l != NULL)
	{
		while (Temp->Front != NULL)
		{
			if ((Temp->Front->Data) == value)
				TempSaving = Temp->Front;
			Temp = Temp->Front;
		}
		if (TempSaving != NULL)
		{
			if (TempSaving->Front != NULL)
			{
				TempSaving->Back->Front = TempSaving->Front;
				TempSaving->Front->Back = TempSaving->Back;
				free(TempSaving);
			}
			else
			{
				TempSaving->Back->Front = NULL;
				free(TempSaving);
			}
			return 1;
		}
		return 0;
	}
	else
		return -1;
}
void print(struct List* l)
{
	while (l != NULL)
	{
		printf("%.0lf ", l->Data);
		l = l->Front;
	}
	printf("\n");
}
void print_inverse(struct List* l)
{
	while (l->Front != NULL)
		l = l->Front;
	while (l != NULL)
	{
		printf("%.0lf ", l->Data);
		l = l->Back;
	}
	printf("\n");
}
int main()
{
	struct List* l, * Temp;
	int N, i;
	double a, b;
	scanf("%d", &N);
	init(&l);
	for (i = 0; i < N; i++)
	{
		scanf("%lf", &a);
		push_back(l, a);
	}
	print(l);
	for (i = 0; i < 3; i++)
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
	scanf("%lf", &a);
	push_back(l, a);
	print_inverse(l);
	scanf("%lf", &a);
	push_front(&l, a);
	print(l);
	scanf("%lf", &a);
	scanf("%lf", &b);
	struct List* el = (struct List*)l;
	while (a != 1)
	{
		el = el->Front;
		a--;
	}
	insert_after(el, b);
	print_inverse(l);
	scanf("%lf", &a);
	scanf("%lf", &b);
	if (a == 1)
	{
		el = (struct List*)malloc(sizeof(struct List));
		el->Data = b;
		el->Back = NULL;
		el->Front = (struct List*)l;
		l->Back = (struct List*)el;
		l = l->Back;
	}
	else
	{
		el = (struct List*)l;
		while (a != 1)
		{
			el = el->Front;
			a--;
		}
		insert_before(el, b);
	}
	print(l);
	scanf("%lf", &a);
	if (l->Data == a)
	{
		Temp = l->Front;
		free(l);
		l = Temp;
		l->Back = NULL;
	}
	else
		remove_first(l, a);
	print_inverse(l);
	scanf("%lf", &a);
	if ((remove_last(l, a) == 0) && (l->Data == a))
	{
		Temp = l->Front;
		free(l);
		l = Temp;
	}
	print(l);
	clean(l);
	return 1;
}
```
