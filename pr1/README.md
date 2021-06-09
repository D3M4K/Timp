# Отчет по практической работе №1

## Задание

Задания на первую практическую работу представлены в таблице 1.

Таблица 1 - Задания
| Номер | Задание |
| ------------- | ------------- |
|  1  | Написать программу, печатающую в stdout фразу "Hello, World!" на отдельной строке.  |
| 2  | Написать программу, принимающую на вход два числа, разделённые пробелом, и суммирующую их. Ввод чисел производить из stdin, вывод результата - в stdout. Вводимые числа не превосходят по модулю 2147483647.  |
| 3 | Написать программу, принимающую на вход числа x и y, разделённые пробелом, и вычисляющую x в степени y. Ввод чисел производить из stdin, вывод результата - в stdout. Вводимые числа не превосходят по модулю 2147483647. Реализовывать возведение в степень через цикл/рекурсию не допускается. |

## Ход работы


Написанные программы должны пройти проверку pipeline. На рисунке 1 показан результат проверки.


<img width="250" height="350" src="https://sun9-16.userapi.com/impf/-LVxJWja6go5tDQxNZaIoF2fTUXRQsSCovfOGQ/Sg49zqnUUf0.jpg?size=196x374&quality=96&sign=b0a6fc0ff9f08451d0bf3f70853cda21&type=album">

Рисунок 1 - Проверка программ

Листинг первой программы: 
```C
int main() 
{
    printf("Hello, World!");
    return 0;
}
```
На рисунке 2 представлен результат работы программы.

<p align="center">

  <img width="250" height="150" src="https://sun9-71.userapi.com/impf/OTkOTHmSfv_lJhQMGBJO3vUhJgnUAog8AGnA0g/5O3Y7qf3zsU.jpg?size=131x60&quality=96&sign=567bb3f5f33bc98693aefdbfd232beda&type=album">

</p>
Рисунок 2 - Результат работы программы

Листинг кода второй программы:
```C
#include <stdio.h>

int main() 
{
    double i, o, p;
    (void)scanf( "%lf %lf", &i, &o);
    p = i + o;
    printf("%lf\n", p);
    return 0;
}
```
На рисунке 3 представлен результат работы программы.

<p align="center">

  <img width="250" height="150" src="https://sun9-66.userapi.com/impf/dxjQWYUiBpDTw_A0GT-23ItQfwkMFoI4YHgGHw/I0raH-w-F8k.jpg?size=104x57&quality=96&sign=a8dda04998990208110dd4fedcefdb52&type=album">

</p>
Рисунок 3 - Результат работы программы

Листинг кода третьей программы:
```C
#include <stdio.h>
#include <math.h>

int main() 
{
    double i, p;
    (void)scanf("%lf %lf", &i, &p);
    printf("%lf\n", pow(i, p));
    return 0;
}
```
На рисунке 4 представлен результат работы программы.
<p align="center">

  <img width="250" height="150" src="https://sun9-63.userapi.com/impf/8EkFDGb64PAeYAOEo0BojjRkB7AyN9rdoXc5XA/4D_RSWrV2uM.jpg?size=107x54&quality=96&sign=bc49b6d68cc8cd8548507ee4a652385e&type=album">

</p>

Рисунок 4 - Результат работы программы



## Результат
В ходе выполнения практической работы были разработаны три программы. Каждая программа прошла проверку. Это означает, что все программы  работают верно.
