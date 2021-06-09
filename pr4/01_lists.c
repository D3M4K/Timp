#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

struct Line
{
	struct Line* Front;
	struct Line* Back;
	double Data;
};
struct Node
{
	struct Node* Front;
	struct Node* Back;
	double Data;
};
void init(struct Line** l)
{
	*l = (struct Line*)malloc(sizeof(struct Line));
	(*l)->Front = NULL;
	(*l)->Back = NULL;
	(*l)->Data = 2147483648;
}
void clean(struct Line* l)
{
	struct Line* Temp = l;
	free(Temp->Back);
	do
	{
		Temp = Temp->Front;
		free(l);
		l = Temp;
	} while (l != NULL);
}
bool is_empty(struct Line* l)
{
	if (l == NULL)
		return 0;
	else
		return 1;
}
struct Node* find(struct Line* l, int value)
{
	struct Line* Temp = l;
	while (1)
	{
		if (Temp == NULL)
			return NULL;
		else
		{
			if ((Temp->Data) == value)
				return ((struct Node*)l);
		}
		Temp = Temp->Front;
	}
}
int push_back(struct Line* l, int value)
{
	if (l->Data == 2147483648)
	{
		l->Data = value;
		return 0;
	}
	struct Line* Temp = (struct Line*)malloc(sizeof(struct Line));
	Temp = l;
	while (Temp->Front != NULL)
		Temp = Temp->Front;
	Temp->Front = (struct Line*)malloc(sizeof(struct Line));
	Temp->Front->Back = Temp;
	Temp = Temp->Front;
	Temp->Data = value;
	Temp->Front = NULL;
	return 0;
}
int push_front(struct Line** l, int value)
{
	struct Line* Temp = (struct Line*)malloc(sizeof(struct Line));
	Temp->Data = value;
	Temp->Front = (*l);
	Temp->Back = NULL;
	Temp->Front->Back = Temp;
	(*l) = Temp;
	return 0;
}
int insert_after(struct Node* l, int value)
{
	if (l->Front != NULL)
	{
		struct Node* Temp = (struct Node*)malloc(sizeof(struct Node)), * Temp2;
		Temp->Front = l->Front;
		Temp->Back = l;
		Temp->Data = value;
		l->Front->Back = Temp;
		l->Front = Temp;
	}
	else
	{
		l->Front = (struct Node*)malloc(sizeof(struct Node));
		l->Front->Front = NULL;
		l->Front->Data = value;
		l->Front->Back = l;
	}
	return 0;
}
int insert_before(struct Node* l, int value)
{
	if (l->Back != NULL)
	{
		struct Node* Temp = (struct Node*)malloc(sizeof(struct Node)), * Temp2;
		Temp->Back = l->Back;
		Temp->Front = l;
		Temp->Data = value;
		l->Back->Front = Temp;
		l->Back = Temp;
	}
	else
	{
		l->Back = (struct Node*)malloc(sizeof(struct Node));
		l->Back->Back = NULL;
		l->Back->Data = value;
		l->Back->Front = l;
	}
	return 0;
}
int remove_first(struct Line* l, int value)
{
	struct Line* Temp = l;
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
int remove_last(struct Line* l, int value)
{
	struct Line* Temp = l, * TempSaving = NULL;
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
void print(struct Line* l)
{
	while (l != NULL)
	{
		printf("%.0lf ", l->Data);
		l = l->Front;
	}
	printf("\n");
}
void print_inverse(struct Line* l)
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
	struct Line* l, * Temp;
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
	struct Node* el = (struct Node*)l;
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
		el = (struct Node*)malloc(sizeof(struct Node));
		el->Data = b;
		el->Back = NULL;
		el->Front = (struct Node*)l;
		l->Back = (struct Line*)el;
		l = l->Back;
	}
	else
	{
		el = (struct Node*)l;
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
