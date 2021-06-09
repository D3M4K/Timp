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
