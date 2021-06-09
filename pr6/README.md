## Введение
Цель работы: получение практических навыков по работе с бинарными деревьями. В частности нужно реализовать обходы деревьев. Также необходимо закрепить навыки по работе с динамическими структурами.  

Таблица 1 - Постановленные задачи 

| Номер | Задание |
| ------------- | ------------- |
| 1| Должны быть выполнены предыдущие работы |
|2 | Прочитать про односвязные списки на СИ |
|3| Написать программу |
|4| Настроить pipeline |
|5| Написать отчет по работе в разметке Markdown (README.md)|
|6| Залить на gitlab и убедиться, что pipeline проходит успешно|
|7| Защитить работу у преподавателя|
## 1 Теоретические сведения
### 1.1 Бинарное дерево 
Бинарное дерево — это иерархическая структура данных, в которой каждый узел имеет значение (оно же является в данном случае и ключом) и ссылки на левого и правого потомка. Узел, находящийся на самом верхнем уровне (не являющийся чьим либо потомком) называется корнем. Узлы, не имеющие потомков (оба потомка которых равны NULL) называются листьями.

Бинарное дерево поиска — это бинарное дерево, обладающее дополнительными свойствами: значение левого потомка меньше значения родителя, а значение правого потомка больше значения родителя для каждого узла дерева. То есть, данные в бинарном дереве поиска хранятся в отсортированном виде. При каждой операции вставки нового или удаления существующего узла отсортированный порядок дерева сохраняется. При поиске элемента сравнивается искомое значение с корнем. Если искомое больше корня, то поиск продолжается в правом потомке корня, если меньше, то в левом, если равно, то значение найдено и поиск прекращается.

### 1.2 Обходы дерева.

Обход дерева (известный также как поиск по дереву) — вид обхода графа, обусловливающий процесс посещения (проверки и/или обновления) каждого узла структуры дерева данных ровно один раз. Такие обходы классифицируются по порядку, в котором узлы посещаются. Алгоритмы в статье относятся к двоичным деревьям, но могут быть обобщены и для других деревьев.

## 2 Ход работы
### 2.1 Реализация программы на языке СИ

Двоичное дерево — иерархическая структура данных, в которой каждый узел имеет не более двух потомков (детей). Как правило, первый называется родительским узлом, а дети называются левым и правым наследниками. Двоичное дерево не является упорядоченным ориентированным деревом. Для практических целей обычно используют два подвида двоичных деревьев — двоичное дерево поиска и двоичная куча.

Для практических целей обычно используют два подвида двоичных деревьев — двоичное дерево поиска и двоичная куча.

Для начала необходимо создать структуру tree, а также объявить прототипы функций.

Код представлен ниже:

```c
struct tree
{
	struct tree* right;
	struct tree* left;
	int data;
};
int deep(struct tree* t);
int insert(struct tree* t, int value);
void init(struct tree** t, int value);
int print_width(struct tree* t);
}

``` 
Реализованные функий вместе с полным кодом программы находятся в приложениях А,Б и В.

Функция main является начальной точкой для выполнения программы. Она обычно управляет выполнением программы, вызывая другие ее функции. Как правило, выполнение программы завершается в конце функции main, но по разным причинам это может случиться и в других местах программы.

Главная функция main представлена ниже, для всех трех программ она аналогична меняется лишь название функции в конце поэтому дублировать нет смысла: 

```c
int main()
{
	int main()
{
	struct tree* t;
	int i;
	int value;

	scanf("%d", &value);

	init(&t, value);

	for (i = 0; i < 6; i++)
	{
		scanf("%d", &value);
		insert(t, value);
	}

	print_width(t);
	
	return 1;
}
``` 

Для начала необходимо вручную протестировать работу программы, чтобы понять есть ли какие - либо очевединые ошибки, которые необходимо исправить. Программа не выдает ошибок при запуске - это означает, что она не содержит синтаксических ошибок. Так же при вводе нескольких разных значений программа выдает ожидаемый результат. Пример работы программы представлен на рисунке 1.

![](https://sun9-38.userapi.com/impg/iKZhWMkcfidEhFw9tdeg_uB9zE6bA7NSN95I6Q/oxZ5asgv50Y.jpg?size=260x62&quality=96&sign=1416e5235e4b615c5dc732321ac3a0a1&type=album)

Рисунок 1 — Пример работы программы первой программы.

![](https://sun9-23.userapi.com/impg/cL_th1AmeDZbK6y_hGXW_mPc0eAZOG8hVqwaPg/ycWkY9cxnME.jpg?size=267x68&quality=96&sign=4df3064a6fab5e14fb2905cbe7c8a188&type=album)

Рисунок 2 — Пример работы программы второй программы.

![](https://sun9-34.userapi.com/impg/Jf3mLpRugTf0Sl-YWMEND3ZJ613MLeT2UkQVYg/SlGPO74bd6Q.jpg?size=253x67&quality=96&sign=8e89f248e71119c22ce27cc4c0e462f1&type=album)

Рисунок 3 — Пример работы программы третьей программы.

Из рисунков 1, 2, 3 видно, что программа работает корректно (выдает ожидаемый результат), а значит код написан правильно. 

#### 2.2 Тестирование разработанной программы
Pipeline — это целый набор разных команд, которые можно выполнить для проекта в рамках одной итерации.
Для тестирования разработанной программы сперва необходимо настроить pipeline, после загрузить файл с программой в систему gitlab, после чего начнется проверка разработанной программы. Результаты проверки представлены на рисунке 2.

![](https://sun9-3.userapi.com/impg/OJOquNczsiUzgLDM4aKgWOSkoIkHB7foKaKwzw/h-0uDXf_sGU.jpg?size=217x205&quality=96&sign=d63479ac130ab3134a470a12c8e198d9&type=album)

Рисунок 2 — Результаты тестирования программы.


## 3 Вывод

В результате выполнения лабораторной работы были достигнуты поставленные цели и решины необходимые задачи. Получены практические навыки работы с указателями, бинарными деревьями и динамической памятью. В частности написаны функции для работы с бинарным деревом. Реализованы обходы деревьев: прямой, обратный и в ширину.

## Приложение A

(обязательное)

Листининг кода  первой программы

```c
#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
struct tree
{
	struct tree* right;
	struct tree* left;
	int data;
};
int deep(struct tree* t);
int insert(struct tree* t, int value);
void init(struct tree** t, int value);
int print_width(struct tree* t);

int main()
{
	struct tree* t;
	int i;
	int value;

	scanf("%d", &value);

	init(&t, value);

	for (i = 0; i < 6; i++)
	{
		scanf("%d", &value);
		insert(t, value);
	}

	print_width(t);
	
	return 1;
}

int deep(struct tree* t)
{
	int rig = 0, lef = 0;
	if ((t->right) != NULL)
		rig = deep(t->right);
	if ((t->left) != NULL)
		lef = deep(t->left);
	if (rig > lef)
		return (rig + 1);
	return (lef + 1);
}

int insert(struct tree* t, int value)
{
	if (t->data == value)

		return 1;

	if (value > (t->data))
	{
		if ((t->right) != NULL)

			return(insert(t->right, value));

		else
		{
			t->right = (struct tree*)malloc(sizeof(struct tree));
			t->right->right = NULL;
			t->right->left = NULL;
			t->right->data = value;
			return 0;
		}
	}
	else
	{
		if ((t->left) != NULL)

			return(insert(t->left, value));

		else
		{
			t->left = (struct tree*)malloc(sizeof(struct tree));

			t->left->right = NULL;

			t->left->left = NULL;

			t->left->data = value;

			return 0;
		}
	}
}

void init(struct tree** t, int value)
{
	*t = (struct tree*)malloc(sizeof(struct tree));

	(*t)->right = NULL;

	(*t)->left = NULL;

	(*t)->data = value;
}

int print_width(struct tree* t)
{
	struct tree* currnet = t;
	int rang = 0, i, j, p, h, spac = 0; int* m;
	rang = deep(t);

	m = (int*)malloc(sizeof(int));

	for (i = 0; i < rang; i++)
	{   

		if (i != 0)
		{
			m = (int*)realloc(m, i * sizeof(int));
			for (j = 0; j < i; j++)
				m[j] = 0;
		}


		j = 1;

		h = i;

		while (h != 0)// получение кол-ва элементов на определнном уровне
		{
			j = j * 2;
			h--;
		}
		while (j != 0) // проход для каждого элемента
		{
			p = 0;
			currnet = t;
			for (p = 0; p < i; p++) // проход на определенного узла
			{
			if (m[p] == 0)
			{
			if ((currnet->left) != NULL)

			currnet = currnet->left;
			else
			{
			p = -1;
			break;
			}
			}
				else
				{
				if ((currnet->right) != NULL)
				currnet = currnet->right;
				else
				{
				p = -1;
				break;
				}
			}
		}
			if (i != 0)// изменение массива 
			{
				h = i - 1;
				m[h]++;
				while (1)
				{
					if (m[h] == 2)
					{
						m[h] = 0;
						h--;
						if (h < 0)
							break;
						else
							m[h]++;
					}
					else
						break;
				}
			}
			if (p != -1) // если есть элемент
			{
				if (spac == 1)
				{
					printf(" ");
					spac = 1;
				}
				printf("%d", currnet->data);
				spac = 1;
			}
			j--;
		}
	}
	return 0;
}
```

## Приложение Б

(обязательное)

Листининг кода  второй  программы

```c
#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
struct tree
{
	struct tree* right;
	struct tree* left;
	int data;
};
int insert(struct tree* t, int value);
void init(struct tree** t, int value);
int print_direct(struct tree* t);

int main()
{
	struct tree* t;

	int value;

	int i;

	scanf("%d", &value);

	init(&t, value);

	for (i = 0; i < 6; i++)
	{
		scanf("%d", &value);
		insert(t, value);
	}

	print_direct(t);

	return 1;
}

int insert(struct tree* t, int value)
{
	if (t->data == value)
		return 1;
	if (value > (t->data))
	{
		if ((t->right) != NULL)
			return(insert(t->right, value));
		else
		{
			t->right = (struct tree*)malloc(sizeof(struct tree));

			t->right->right = NULL;

			t->right->left = NULL;

			t->right->data = value;

			return 0;
		}
	}
	else
	{
		if ((t->left) != NULL)

			return(insert(t->left, value));

		else

		{
			t->left = (struct tree*)malloc(sizeof(struct tree));

			t->left->right = NULL;

			t->left->left = NULL;

			t->left->data = value;

			return 0;
		}
	}
}
void init(struct tree** t, int value)
{
	*t = (struct tree*)malloc(sizeof(struct tree));

	(*t)->right = NULL;

	(*t)->left = NULL;

	(*t)->data = value;

}
int print_direct(struct tree* t)
{
	struct tree* current[7];
	int i = 0;
	current[0] = t;
	printf("%d", (int)current[i]->data);
	while (1)
	{
		while (1)//запись до конца
		{
			while ((current[i]->left) != NULL)
			{
			current[i + 1] = current[i]->left;
			i++;
			printf(" %d", (int)current[i]->data);
			}
			if ((current[i]->right) != NULL)
			{
			current[i + 1] = current[i]->right;
			i++;
			printf(" %d", (int)current[i]->data);
			}
			else
			break;
		}
		while ((i != 0) && ((current[i - 1]->right) == current[i]))
		i--;
		if (i == 0)
		break;
		while (i != 0)
		{
		if ((current[i - 1]->right) != NULL)
		{
		current[i] = current[i - 1]->right;
		printf(" %d", (int)current[i]->data);
		break;
		}
		else
		{
		i--;
		if (i == 0)
		return 0;
		}
	}
}
return 0;
}
```

## Приложение В

(обязательное)

Листининг кода  третий  программы

```c
#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
struct tree
{
	struct tree* right;

	struct tree* left;

	int data;

};
int print_reverse(struct tree* t);
void init(struct tree** t, int value);
int insert(struct tree* t, int value);

int main()
{
	struct tree* t;

	int value;

	int i;

	scanf("%d", &value);

	init(&t, value);

	for (i = 0; i < 6; i++)
	{
		scanf("%d", &value);
		insert(t, value);
	}

	print_reverse(t);

	return 1;

}

int insert(struct tree* t, int value)
{
	if (t->data == value)

		return 1;

	if (value > (t->data))
	{
		if ((t->right) != NULL)

			return(insert(t->right, value));

		else
		{
			t->right = (struct tree*)malloc(sizeof(struct tree));

			t->right->right = NULL;

			t->right->left = NULL;

			t->right->data = value;

			return 0;
		}
	}
	else
	{
		if ((t->left) != NULL)
			return(insert(t->left, value));
		else
		{
			t->left = (struct tree*)malloc(sizeof(struct tree));

			t->left->right = NULL;

			t->left->left = NULL;

			t->left->data = value;

			return 0;
		}
	}
}

void init(struct tree** t, int value)
{
	*t = (struct tree*)malloc(sizeof(struct tree));

	(*t)->right = NULL;

	(*t)->left = NULL;

	(*t)->data = value;
}


int print_reverse(struct tree* t)
{
	if(t==NULL)
	return;
	print_reverse(t->left);
	print_reverse(t->right);
	printf("%d ",t->data);
}
```
