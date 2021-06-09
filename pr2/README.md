# Отчёт по практической работе 2
### 1 Введение

Задание:

1.Должна быть выполнена 1 практическая работа

2.Написать программы в соответствии с вариантом 

3.Составить блок-схемы программ

4.Написать отчет по работе в разметке Markdown (README.md)

5.Загрузить на gitlab и убедиться, что проверка pipeline проходит успешно


Задания на первую практическую работу представлены в таблице 1.

Таблица 1 - Задания
| Номер | Задание |
| ------------- | ------------- |
|  1  | ![](https://sun9-12.userapi.com/impf/W3xS7Hc929GImBkT7fb16FxkYH5TneFCYav-bw/ixgDZGnbi0E.jpg?size=539x74&quality=96&sign=bb6d33008b5b0424bb9557da4cf17a25&type=album)  |
| 2  | ![](https://sun9-46.userapi.com/impf/30bGryjB1FFSxPgML7ZiccvuzOMXcfFggUYncA/IT4I6uy8yyc.jpg?size=537x121&quality=96&sign=a77019a760d59443d0fda4e8b23c1f00&type=album) |

###  2 Ход работы
Код программы, который был выполнен в онлайн компиляторе, для первого задания выглядит следующим образом:
```с
#include <stdio.h>

int main()
{
    int n, all = 0, x, i=1;

    (void)scanf("%d", &n);

    for(i; i <= n; i++)
    {
        (void)scanf("%d", &x);
        if(x < 0)
        {
            all++;
        }

    }
    printf("%d", all);
    return 0;
}

```


Результат работы программы представлен на рисунке 1.

![](https://sun9-40.userapi.com/impf/jZKZPX8I6APao0gohhLp6tUn0JoqCD9eamfp0w/Fa3yvSO1sDM.jpg?size=154x87&quality=96&sign=c95985e5d93b85ad993378893f35a036&type=album)

Рисунок 1 — Результат работы программы №1

Код программы, который был выполнен в онлайн компиляторе, для второго задания выглядит следующим образом:

```с
#include <stdio.h>
#include <math.h>
int main()
{
int n;
int i =1;
int x;
int summ =0;


(void)scanf("%d", &n);

for(i; i <= n; i++)
{
    (void)scanf("%d", &x);
summ += pow(-1, (double)i)*x*x;
}
printf("%d", summ);
return 0;
} 

```


Результат работы программы представлен на рисунке 2.

![](https://sun9-69.userapi.com/impf/yrc2z8lLUYY2u5cbh9kwUnQFx4HNqT4yJCFV6g/r69fOKJNgpw.jpg?size=143x89&quality=96&sign=4700ebc3c64d43428e145da3a2247f69&type=album)

Рисунок 2 — Результат работы программы №2

#### 2.1 Настройка pipeline

На рисунке 3 представлено то, как это должно выглядеть.

![](https://sun9-53.userapi.com/impf/2G0MKRuVlsFjxlWaSoh7t7QMgRed25GLbShHfw/A_gv0N-k2yk.jpg?size=323x522&quality=96&sign=63d776a16e55e51b9195216fcf93b9d0&type=album)

Рисунок 3 - Настройка pipeline

#### 2.2 Работа с GitLab

После загрузки проекта он должен пройти pipeline проверку, которая была настроена и выполнена успешно. Результаты проверки представлены на рисунке 4.


![](https://sun9-60.userapi.com/impf/qADvDvW_dKPYGbECoFMQaV8p4CNmAjNycFCmVg/yEnx-NV3rmk.jpg?size=430x694&quality=96&sign=0c093fb290cc902b63aa6e51363e6469&type=album)

Рисунок 4 — Результаты pipeline-проверки

#### 2.3 Работа с блок-схемами
Создание блок схемы для программ, которые изображены на рисуноках 5 и 6.

![](https://sun9-6.userapi.com/impf/nOBp1AWcQYLI4MuXWjntfHUJ_GvYAzBzGg2hUQ/tfSOXExDigw.jpg?size=316x781&quality=96&sign=67f6914a6eb89c764d254fa8e7ce74d3&type=album)

Рисунок 5 — Блок схема для первой программы

![](https://sun9-49.userapi.com/impf/vZnOxmNOWB0DVAUcSruDA4d7uwzrZqXV7z4q-Q/1rsx7vqfa_E.jpg?size=236x691&quality=96&sign=e8965e745fd79d700a2041b6be55f364&type=album)

Рисунок 6 — Блок схема для второй программы
### 3 Заключение
В ходе выполнения практической работы были написаны две программы. Все они прошли проверку и это значит, что работа была выполнена правильно. Была проведена настройка pipeline и были построены блок-схемы по двум программам.
