## ОТЧЕТ ПО ПРАКТИЧЕСКОЙ РАБОТЕ №5

### 1 Введение
Задания на пятую практическую работу представлены в таблице 1.

Таблица 1 - Задания
| Номер | Задание |
| ------------- | ------------- |
|  1  | Должны быть выполнены предыдущие работы.  |
| 2 | Написать программу.|
| 3 | Настроить pipeline.|
| 4 | Написать отчет по работе в разметке Markdown (README.md).|
| 5 | Залить на gitlab и убедиться, что pipeline проходит успешно.|
| 6 | Защитить работу у преподавателя.|


Алгоритм выполнения программы:  

1. Создает пустое дерево, считывает 4 элемента ai, |ai| <= 2147483647 и заносит их в дерево;
2. Выводит дерево (используя функцию print_tree) и пустую строку;
3. Считывает 3 элемента ai, |ai| <= 2147483647 и заносит их в дерево;
4. Выводит дерево и пустую строку;
5. Считывает m1, |m1| <= 2147483647 и ищет элемент с заданным значением в дереве; выводит через пробел значение предка и потомков найденного элемента, если нет значений предка или потомков вывести "_" вместо таких значений; вывести "-", если элемент не найден; вывести пустую строку;
6. Считывает m2, |m2| <= 2147483647 и ищет элемент с заданным значением в дереве; выводит через пробел значение предка и потомков найденного элемента, если нет значений предка или потомков вывести "_" вместо таких значений; вывести "-", если элемент не найден; вывести пустую строку;
7. Считывает m3, |m3| <= 2147483647 и удаляет из дерева элемент с заданным значением (если такой элемент есть);
8. Выводит дерево и пустую строку;
9. Выполняет левый поворот дерева относительно корня, пока это возможно;
10. Выводит дерево и пустую строку;
11. Выполняет правый поворот дерева относительно корня, пока это возможно;
12. Выводит дерево и пустую строку;
13. Выводит на экран количество элементов в дереве и пустую строку;
14. Очищает дерево
15. Выводит дерево и пустую строку;


### 2 Ход работы
#### 2.1 Работа с программой
Дерево — это граф без петель и циклов. Деревья используются для организации данных в виде иерархической структуры.

Код для описания структуры tree выглядит следущим образом:
```c
struct tree
{
	struct tree* right; // указатель на правую часть дерева
	struct tree* left; // указатель на левую часть дерева
	double data; // значение, которое хранит элемент списка
};
```

Для того, чтобы начать работу с деревьями, нужно их инициализировать.

Код инициализации дерева выглядит следущим образом:
```c
void init(struct tree** t) //передаем адрес ячейки с корнем
{
	*t = (struct tree*)malloc(sizeof(struct tree)); // выделение памяти
	(*t)->right = NULL; // показываем, что правая и левая часть дерева равна нулю
	(*t)->left = NULL;
	(*t)->data = 2147483648; //переменная, которая хранит данное значение, для проверки на пустоту
}
```
Код функции, которая удаляет все элементы из дерева, выглядит следущим образом:
```c
void clean(struct tree* t)
{
	if (t != NULL)
	{
		if (t->right != NULL)
			clean(t->right);
		if (t->left != NULL)
			clean(t->left);
		free(t); // освобождение памяти
	}
}
```

Код функции, которая осуществляет поиск элемента по значению, выглядит следущим образом:
```c
struct tree* find(struct tree* t, int value)
{
	if (t->data == value) // сравниваем
		return t;
	else
	{
		if (value < t->data) // если значение меньше чем корень, то
		{
			if (t->left != NULL) // то обходим слева по дереву
				return(find(t->left, value));
			else
				return NULL;
		}
		else
		{
			if (t->right != NULL) // обходим справа
				return(find(t->right, value));
			else
				return NULL;
		}
	}
}
```
Код функции, которая вставляет значение в дерево (0 - вставка выполнена успешно, 1 - элемент существует, 2 - не уадлось выделить память для нового элемента), выглядит следущим образом:
```c
int insert(struct tree* t, int value)
{
	if (t->data == 2147483648) // проверка на пустоту 
	{
		t->data = value;
		return 0;
	}
	if (t->data == value) // не надо ничего вставлять
		return 1;
	if (value > (t->data))
	{
		if ((t->right) != NULL) // проверяем пусто ли справа
			return(insert(t->right, value)); // рекурсия
		else
		{
			t->right = (struct tree*)malloc(sizeof(struct tree));
			t->right->right = NULL; // присвоил значения нулл потомкам
			t->right->left = NULL;
			t->right->data = value; // родителю потомков записали значение value
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
```
Код функции, которая удаляет элемент из дерева, выглядит следущим образом:
```c
int remove_node(struct tree** t, int value) // передаем адрес корня
{
	if ((*t)->data == value) // разименовываем адрес и сравниваем значения
	{
	if ((*t)->right != NULL)
		{
			struct tree* actual = (*t)->right, // создаем указатель 1 и присваиваем (*t)->right
				* actual2;
	if (actual->left != NULL)
			{
	while (actual->left->left != NULL)
				actual = actual->left;
				(*t)->data = actual->left->data;
				actual2 = actual->left;
				actual->left = actual2->right;
				free(actual2); // освобождение 
			}
	else
			{
				struct tree* Temp;
				(*t)->data = (*t)->right->data;
				Temp = (*t)->right;
				(*t)->right = (*t)->right->right;
				free(Temp);
			}
		}
    else
		{
			struct tree* Temp;
			Temp = (*t);
			(*t) = (*t)->left;
			free(Temp);
			Temp = NULL;
		}
	return 0;
	}
	else
	{
	if (value < ((*t)->data))
		{
	if ((*t)->left != NULL)
				return(remove_node(&((*t)->left), value));
	else
				return 1;
		}
	else
		{
	if (((*t)->right) != NULL)
				return(remove_node(&((*t)->right), value));
	else
				return 1;
		}
	}
}
```
Код функции, которая удаляет минимальный элемент из поддерева, выглядит следущим образом:
```c
int remove_min(struct tree* t)
{
	struct tree* actual = t, * actual2;
	
	if (actual->left != NULL)
	{
		while (actual->left->left != NULL) // идем в глубину левого поддерева
		actual = actual->left;
		actual2 = actual->left;
		actual->left = actual2->right;
		free(actual2);
	}

	else
	{
		actual = t->right; // иначе идет на правое поддерево и удаляет первый элемент, тк глубже значения больше
		free(t);
		t = actual;
	}
	return 0;
}
```
Код функции, которая выполняет правое вращение поддерева, выглядит следущим образом:
```c
int rotate_right(struct tree** t)
{
	if (*t == NULL) // нулл ли в корне
		return 1;
	struct tree* a,
		* b, 
		* c = (*t)->right, 
		* iks = (*t)->left, 
		* eg = (*t), 
		* actual =(struct tree*)malloc(sizeof(struct tree));


	if (iks != NULL)
	{
	a = iks->left;
	b = iks->right;
	}
	else
	return 1;

	actual->right = eg;

	actual->left = a;

	actual->right->right = c;

	actual->right->left = b;

	actual->data = iks->data;

	free(iks);

	(*t) = actual;

	return 0;
}
```
Код функции, которая выполняет левое вращение поддерева, выглядит следущим образом:
```c
int rotate_left(struct tree** t)
{
	if (*t == NULL)
		return 1;
	struct tree* a = (*t)->left, 

		* b, 
		* c,
		* iks = (*t), 
		* eg = (*t)->right,
		* actual = (struct tree*)malloc(sizeof(struct tree));

	if (eg != NULL)
	{
		b = eg->left;
		c = eg->right;
	}
	else
		return 1;
	actual->right = c;
	actual->left = iks;
	actual->left->right = b;
	actual->left->left = a;
	actual->data = eg->data;

	free(eg);

	(*t) = actual;

	return 0;
}
```
Код функции, которая выводит все значения дерева t, аналогично функции print , выглядит следущим образом:
```c
int print_tree(struct tree* t)
{if (t == NULL)
{
printf("-\n");
return 1;
}
```
Полный код программы находиться в приложении А.

В таблице 2 представлены значения для проверки кода, которые нужно проверить в своей программе.

Таблица 2 - Проверочные входные и выходные данные:
|Input|Output|
|-|-|
|2 1 3 2| 2 |
||1 3|
|0 4 5|2|
|| 1 3|
||0_ _4|
||_ _ _ _ _ _ _5|
|3| 2_4 |
|6|-|
|2|3|
||14|
||0_ _5|
||5|
||4 _ |
||3_ _ _|
||1_ _ _ _ _|
||0_ _ _ _ _ _ _ _|
||0|
|| _ 1 |
|| _ _ _ 3|
|| _ _ _ _ _ 4|
|| _ _ _ _ _ _ _ _ 5|
||5|
||-|

При вводе этих данных, программа выдает ожидаемый результат из этого следует, что программа работает корректно.

Результат работы программы представлен на рисунке 1.


![](https://sun9-11.userapi.com/impg/qudEk6wtlEe652zvD2fZh_usBxRHg0IJRrWzmA/Dk6rvY-82fg.jpg?size=278x730&quality=96&sign=75a17af5776422a00cb5d7be5f46e9c8&type=album)

Рисунок 1 — Результат работы программы.

#### 2.2 Настройка pipeline

Для корректной загрузки файлов на удаленный репозиторий в файле .gitlab_cy.yml наужно найти пункт stages и добавить pr5. Далее нужно убрать комментарии, чтобы все работало. На рисунке 2 представлено то, как это должно выглядеть.

![](https://sun9-37.userapi.com/impg/7FyQHyEhVszfNx0o4i_VKJKf5JJlLGoJdqbt-A/YDN-jOy71YQ.jpg?size=451x238&quality=96&sign=5517bbca253703956852d93ba5188ee9&type=album)

Рисунок 2 - Настройка pipeline

#### 2.3 Работа с GitLab

Далее, внесем последние изменения в наш локальный проект и передадим его в GitLab. 
После загрузки проекта он должен пройти pipeline проверку. 

Результаты проверки представлены на рисунке 3.

![](https://sun9-28.userapi.com/impg/QgzDye_MZfDV70Q9vNeQNNi0vj-NoRyC_gVp5A/ZB_6Ps7UZw4.jpg?size=324x273&quality=96&sign=952e5f7690c3b3071314e27fc24f2420&type=album)

Рисунок 3 — Результаты pipeline-проверки




### 3 Заключение
В процессе выполнения практической работы были изучены принципы работы с деревьями в языке программирования C, а также были изучены некоторые функции для работы с таким деревом.


### Приложение A
(обязательное)

Листининг кода программы

```c
#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

struct tree
{
	struct tree* right;
	struct tree* left;
	double data;
};

// Инициализация дерева

void init(struct tree** t);

// Удалить все элементы из дерева

void clean(struct tree* t);

// Поиск элемента по значению. Вернуть NULL если элемент не найден

struct tree* find(struct tree* t, int value);

int find_with_output(struct tree* t, int value);

// Вставка значения в дерево:

int insert(struct tree* t, int value);

int deep(struct tree* t);

// Удалить элемент из дерева:

int remove_node(struct tree** t, int value);

// Удалить минимальный элемент из поддерева, корнем которого является n
// Вернуть значение удаленного элемента

int remove_min(struct tree* t);

// Выполнить правое вращение поддерева, корнем которого является n:

int rotate_right(struct tree** t);

// Выполнить левое вращение поддерева, корнем которого является n:

int rotate_left(struct tree** t);

// Вывести все значения дерева t

int print_tree(struct tree* t);

int all(struct tree* t);

int main()
{
	struct tree* tr;

	int i;

	double value;

	init(&tr);
	for (i = 0; i < 4; i++)
	{
		scanf("%lf", &value);
		insert(tr, value);
	}

	print_tree(tr);

	printf("\n");

	for (i = 0; i < 3; i++)
	{
		scanf("%lf", &value);

		insert(tr, value);
	}

	print_tree(tr);

	printf("\n");

	for (i = 0; i < 2; i++)
	{
		scanf("%lf", &value);

		value = find_with_output(tr, value);

		if (value == 1)

		printf("-");

		printf("\n\n");
	}
	scanf("%lf", &value);

	remove_node(&tr, value);

	print_tree(tr);
	printf("\n");

	while (1)
	{
	value = rotate_left(&tr);
	if (value == 1)
	break;
	}
	print_tree(tr);
	printf("\n");
	while (1)
	{
	value = rotate_right(&tr);
	if (value == 1)
	break;
	}
	print_tree(tr);
	printf("\n");
	printf("%d\n\n", all(tr));
	clean(tr);
	tr = NULL;
	print_tree(tr);
	return 0;
}
void init(struct tree** t)
{
	*t = (struct tree*)malloc(sizeof(struct tree));
	(*t)->right = NULL;
	(*t)->left = NULL;
	(*t)->data = 2147483648;
}
void clean(struct tree* t)
{
	if (t != NULL)
	{
		if (t->right != NULL)
			clean(t->right);
		if (t->left != NULL)
			clean(t->left);
		free(t);
	}
}
struct tree* find(struct tree* t, int value)
{
	if (t->data == value)
		return t;
	else
	{
		if (value < t->data)
		{
			if (t->left != NULL)
				return(find(t->left, value));
			else
				return NULL;
		}
		else
		{
			if (t->right != NULL)
				return(find(t->right, value));
			else
				return NULL;
		}
	}
}
int find_with_output(struct tree* t, int value)
{
	if (t->data == value)
	{
		printf("_ ");
		if (t->left != NULL)
			printf("%d ", (int)t->left->data);
		else
			printf("_ ");
		if (t->right != NULL)
			printf("%d", (int)t->right->data);
		else
			printf("_");
	}
	else
	{
	if (value < t->data)
		{
	if (t->left != NULL)
			{
	if (t->left->data == value)
				{
					printf("%d ", (int)t->data);
	if ((t->left->left) != NULL)
						printf("%d ", (int)t->left->left->data);
	else
						printf("_ ");
	if ((t->left->right) != NULL)
						printf("%d", (int)t->left->right->data);
	else
						printf("_");
				}
	else
	           return(find_with_output(t->left, value));
			}
			else
				return 1;
		}
		else
		{
	if (t->right != NULL)
			{
	if (t->right->data == value)
				{
					    printf("%d ", (int)t->data);
	if ((t->right->left) != NULL)
						printf("%d ", (int)t->right->left->data);
	else
						printf("_ ");
	if ((t->right->right) != NULL)
						printf("%d", (int)t->right->right->data);
	else
						printf("_");
				}
	else
					return(find_with_output(t->right, value));
			}
	else
				return 1;
		}
	}
	return 0;
}
int insert(struct tree* t, int value)
{
	if (t->data == 2147483648)
	{
		t->data = value;
		return 0;
	}
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
int deep(struct tree* t)
{
	int k = 0, lis = 0;


	if ((t->right) != NULL)


		k = deep(t->right);

	if ((t->left) != NULL)

		lis = deep(t->left);

	if (k > lis)

	return (k + 1);

	return (lis + 1);
}
int remove_node(struct tree** t, int value)
{
	if ((*t)->data == value)
	{
	if ((*t)->right != NULL)
		{
			struct tree* actual = (*t)->right, 
				* actual2;
	if (actual->left != NULL)
			{
	while (actual->left->left != NULL)
				actual = actual->left;

				(*t)->data = actual->left->data;

				actual2 = actual->left;

				actual->left = actual2->right;

				free(actual2);
			}
	else
			{
				struct tree* Temp;
				(*t)->data = (*t)->right->data;
				Temp = (*t)->right;
				(*t)->right = (*t)->right->right;
				free(Temp);
			}
		}
    else
		{
			struct tree* Temp;
			Temp = (*t);
			(*t) = (*t)->left;
			free(Temp);
			Temp = NULL;
		}
	return 0;
	}
	else
	{
	if (value < ((*t)->data))
		{
	if ((*t)->left != NULL)
				return(remove_node(&((*t)->left), value));
	else
				return 1;
		}
	else
		{
	if (((*t)->right) != NULL)
				return(remove_node(&((*t)->right), value));
	else
				return 1;
		}
	}
}
int remove_min(struct tree* t)
{
	struct tree* actual = t, * actual2;
	
	if (actual->left != NULL)
	{
		while (actual->left->left != NULL)
		actual = actual->left;
		actual2 = actual->left;
		actual->left = actual2->right;
		free(actual2);
	}

	else
	{
		actual = t->right;
		free(t);
		t = actual;
	}
	return 0;
}
int rotate_right(struct tree** t)
{
	if (*t == NULL)
		return 1;
	struct tree* a,
		* b, 
		* c = (*t)->right, 
		* iks = (*t)->left, 
		* eg = (*t), 
		* actual =(struct tree*)malloc(sizeof(struct tree));


	if (iks != NULL)
	{
	a = iks->left;
	b = iks->right;
	}
	else
	return 1;

	actual->right = eg;

	actual->left = a;

	actual->right->right = c;

	actual->right->left = b;

	actual->data = iks->data;

	free(iks);

	(*t) = actual;

	return 0;
}
int rotate_left(struct tree** t)
{
	if (*t == NULL)
		return 1;
	struct tree* a = (*t)->left, 

		* b, 
		* c,
		* iks = (*t), 
		* eg = (*t)->right,
		* actual = (struct tree*)malloc(sizeof(struct tree));

	if (eg != NULL)
	{
		b = eg->left;
		c = eg->right;
	}
	else
		return 1;
	actual->right = c;
	actual->left = iks;
	actual->left->right = b;
	actual->left->left = a;
	actual->data = eg->data;

	free(eg);

	(*t) = actual;

	return 0;
}
int print_tree(struct tree* t)
{if (t == NULL)
{
printf("-\n");
return 1;
}

struct tree* actual = t;
int level = 0, i, j, k, skk;
int* crest;

	level = deep(t);
	crest = (int*)malloc(sizeof(int));
	for (i = 0; i < level; i++)
	{
		if (i != 0)
		{
		crest = (int*)realloc(crest, i * sizeof(int));
		for (j = 0; j < i; j++)
				crest[j] = 0;
		}

		j = 1;

		skk = i;

		while (skk != 0)

		{
		j = j * 2;
		skk--;
		}

		while (j != 0)
		{
			k = 0;
			actual = t;
			for (k = 0; k < i; k++)
			{
			if (crest[k] == 0)
			{
			if ((actual->left) != NULL)
			actual = actual->left;
			else
			{
			k = -1;
			break;
				}
				}
			else
				{
			if ((actual->right) != NULL)
						actual = actual->right;
			else
			{
			k = -1;
			break;
			            }
				}
			}
			if (i != 0)
			{
				skk = i - 1;
				crest[skk]++;
				while (1)
				{
				if (crest[skk] == 2)
					{
						crest[skk] = 0;
						skk--;
				if (skk < 0)
				break;
				else
				crest[skk]++;
					}
				else
				break;
				}
			}
			if (k == -1)
				printf("_");
			else
				printf("%d", (int)actual->data);
			j--;
			if (j != 0)
				printf(" ");
		}
		printf("\n");
	}
	return 1;
}
int all(struct tree* t)
{
	if (t == NULL)
		return 0;
	int k, lis;
	lis = all(t->left);
	k = all(t->right);
	return (lis + k + 1);
}
```

