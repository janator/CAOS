# Сборник скатанных решений акоса 2019 года на фивте ПМФ*
## Phy01-0
### ДАННЫЙ РЕПОЗИТОРИЙ(МАТЕРИАЛ) СОЗДАН И (ИЛИ) РАСПРОСТРАНЕН КОМПАНИЕЙ, КОТОРОЙ НАПЛЕВАТЬ НА ПРИЗЫВЫ УДАЛЯТЬ КОНТЕНТ И УГРОЗУ ОТЧИСЛЕНИЯ. А ЕЩЕ ЭТА КОМПАНИЯ ПРИЗЫВАЕТ ВАС ВЫКЛАДЫВАТЬ СВОИ РЕШЕНИЯ ПОСЛЕ ЗАКРЫТИЯ КУРСА АКОСА.
На стандартном потоке ввода подается последовательно вещественное число x и целое число в 16-ричной записи y.
Единственным аргументов программы является целое число z в 27-ричной системе исчисления.
Необходимо вывести вычислить значение x + y + z и вывести его на стандартный поток вывода с точностью до 3-го знака после точки. 

In the standard stream, the number of real numbers x and the integer in the hexadecimal notation y are entered.
The only argument to the program is the integer z in the 27-digit system.
It is necessary to calculate the value of x + y + z and output it to the standard stream with an accuracy of 3 digits after the point.

[Solution phy01-0](https://github.com/rudykh/CAOS/blob/master/phy01/phy01-0.c).

## Phy01-1
Реализовать функцию с прототипом: <br>
`uint16_t satsum(uint16_t x, uint16_t y);`<br>
которая выполняет сложение с насыщением, то есть, в случае целочисленного переполнения возвращает максимально возможное целое число для данного типа данных. <br>
В коде программы запрещено использовать константы, отличные от 0 и 1.<br>
Запрещено использовать платформо-зависимые или компиляторо-зависимые функции, типы данных с повышенной разрядностью или вещественные типы даннх. 

Implement a function with a prototype: <br>
`uint16_t satsum(uint16_t x, uint16_t y);`<br>
which performs saturation addition, that is, in the case of integer overflow, returns the maximum possible integer for a given data type. <br>
It is forbidden to use constants other than 0 and 1 in the program code. <br>
It is forbidden to use platform-specific or compiler-dependent functions, data types with increased bit depth or real data types.

[Solution phy01-1](https://github.com/rudykh/CAOS/blob/master/phy01/phy01-1.c).

## Phy01-2
Реализуйте функцию с прототипом: <br>
```
typedef enum {
    PlusZero      = 0x00,
    MinusZero     = 0x01,
    PlusInf       = 0xF0,
    MinusInf      = 0xF1,
    PlusRegular   = 0x10,
    MinusRegular  = 0x11,
    PlusDenormal  = 0x20,
    MinusDenormal = 0x21,
    SignalingNaN  = 0x30,
    QuietNaN      = 0x31`
} float_class_t;

extern float_class_t
classify(double *value_ptr);
``` 
которая классифицирует специальные значения вещественного числа, на которое указывает value_ptr, в соответствии со стандартом IEEE 754.

При решении допускается использовать только побитовые операции, включая сдвиги.

Implement the function with the prototype: 
```
typedef enum {
    PlusZero      = 0x00, 
    MinusZero     = 0x01,
    PlusInf       = 0xF0,
    MinusInf      = 0xF1,
    PlusRegular   = 0x10,
    MinusRegular  = 0x11,
    PlusDenormal  = 0x20,
    MinusDenormal = 0x21,
    SignalingNaN  = 0x30,
    QuietNaN      = 0x31
} float_class_t;

extern float_class_t
classify(double *value_ptr); 
```
which classifies the special values of a real number pointed to by value_ptr, in accordance with the IEEE 754 standard.

When solving, it is allowed to use only bitwise operations, including shifts.

[Solution phy01-2](https://github.com/rudykh/CAOS/blob/master/phy01/phy01-2.c).

## Phy01-3
Реализуйте калькулятор выражений над множествами в обратной польской записи.<br>
На стандартном потоке ввода задается последовательность, состоящая из символов-значений, и символов-операций.<br>
Значениями являются цифры от 0 до 9, и буквы английского алфавита (заглавные и строчные). Последовательности значений кодируют множества из 62 элементов.<br>
Операциями являются:
- & - пересечение множеств;
- | - объединение множеств;
- ^ - симметрическая разность;
- ~ - дополнение текущего результата до полного множества.

В начальный момент времени, множество-результат является пустым. При чтении символов со стандартного потока ввода, когда встречается символ операции, то эта операция применяется к множеству-результату и последнему прочитанному множеству (как в обратной польской записи).<br>
Вывести на экран полученное итоговое значение множества в нормализованной форме: сначала цифры, затем заглавные буквы, потом - строчные (упорядоченные по алфавиту).<br>
Для хранения множеств использовать, суммарно, не более 16 байт памяти.

Implement an expression calculator over sets in the reverse Polish notation. <br>
A sequence of characters and values is entered. <br>
The values are numbers from 0 to 9, and the letters of the English alphabet (uppercase and lowercase). Value sequences encode a set of 62 elements. <br>
The operations are:
- & - intersection of many;
- | - union of sets;
- ^ is the symmetric difference;
- ~ - addition of the current result to the full amount.

At the initial time, the result set is empty. When reading characters from a standard input stream, when an operation character is encountered, this operation is applied to the result set and the last read set (as in the reverse Polish notation). <br>
Display the resulting total value of the set in normalized form: first the numbers, then the capital letters, then the lowercase (sorted alphabetically). <br>
To store sets, use, in total, no more than 16 bytes of memory.

[Solution phy01-3](https://github.com/rudykh/CAOS/blob/master/phy01/phy01-3.c).

## Phy01-4
Реализуйте функцию с прототипом:
```
extern int<br>
check_int(uint32_t u32); /* retval: 0 - false, 1 - true */
```
которая проверяет, может ли число u32 быть представлено типом float:<br>
```
float f = u32;
uint64_t y = f;
assert(u32==y);
```
Функция должна вернуть 1, если число может быть представлено типом float, или 0, - если не может.

Допускается исользовать только побитовые операции.

Implement the function with the prototype:<br>
```
extern int
check_int (uint32_t u32); / * retval: 0 - false, 1 - true * / 
```
which checks if a u32 number can be represented by a float type:
```
float f = u32;
uint64_t y = f;
assert (u32 == y); 
```
The function should return 1 if the number can be represented by the float type, or 0 if it cannot.

Only bitwise operations are allowed.

[Solution phy01-4](https://github.com/rudykh/CAOS/blob/master/phy01/phy01-4.c).

## Phy02-0
Реализуйте функцию с меткой f, которая вычисляет значение выражения y=Ax<sup>2</sup>+Bx+C
Значения A, B, C и x хранятся, соответсвенно, в регистрах r0, r1, r2 и r3.

Результат вычисления выражения сохраните в регистре r0.

Все аргументы и значение выражения представимы 32-разрядными знаковыми целыми числами.

Использовать оперативную память запрещено, - можно использовать только регистры.

Implement a function labeled f that evaluates the value of the expression y=Ax<sup>2</sup>+Bx+C
The values of A, B, C and x are stored, respectively, in the registers r0, r1, r2 and r3.

The result of evaluating the expression is stored in register r0.

All arguments and the meaning of an expression are representable by 32-bit signed integers.

Using RAM is prohibited - only registers can be used.

[Solution phy02-0](https://github.com/rudykh/CAOS/blob/master/phy02/phy02-0.S).

## Phy02-1
Реализуйте на языке ассемблера ARM функцию с сигнатурой:
```int summ(int x0, int N, int *X)```
Функция должна вычислять значение x0+∑xi, где 0<e; i<N

Implement in ARM assembly language a function with a signature:
```int summ (int x0, int N, int * X)```
The function should calculate the value x0 + ∑xi, where 0 <e; i <N

[Solution phy02-1](https://github.com/rudykh/CAOS/blob/master/phy02/phy02-1.S).

## Phy02-2
Реализуйте функцию solve, с прототипом
```int solve(int A, int B, int C, int D);```
которая находит минимальное значение x ∈[0,254], которое является одним из корней уравнения: Ax<sup>3</sup>+Bx<sup>2</sup>+Cx+D=0.

Все аргументы и значение выражения представимы 32-разрядными знаковыми целыми числами.

Не забывайте про сохраняемые регистры; можно использовать для этого память на стеке.

Гарантируется, что на тестовых данных существует целочисленное решение.

Implement the solve function with the prototype
```int solve (int A, int B, int C, int D);```
which finds the minimum value x ∈ [0,254], which is one of the roots of the equation: Ax<sup>3</sup>+Bx<sup>2</sup>+Cx+D=0.

All arguments and the meaning of an expression are representable by 32-bit signed integers.

Do not forget about stored registers; You can use the memory on the stack for this.

It is guaranteed that there is an integer solution on the test data.

[Solution phy02-2](https://github.com/rudykh/CAOS/blob/master/phy02/phy02-2.S).

## Phy03-0
Реализуйте функцию calculate, которая вычисляет значение выражения: R=(A\*B)+(C\*D), где A, B, C, и D - это глобальные переменные типа uint32_t, объявленные во внешнем модуле компиляции, а R, - глобальная переменная типа uint32_t в текущем модуле компиляции.

Implement the calculate function, which calculates the value of the expression: R=(A\* B)+(C\*D), where A, B, C, and D are global variables of the uint32_t type, declared in the external compilation unit, and R, - a global variable of type uint32_t in the current compilation unit.

[Solution phy03-0](https://github.com/rudykh/CAOS/blob/master/phy03/phy03-0.S).

## Phy03-1
Реализуйте программу, которая вычисляет сумму двух целых десятичных чисел. Размер типа равен размеру машинного слова.

Можно использовать функции стандартной библиотеки языка Си scanf и printf.

В качестве точки входа можно считать функцию main.

Implement a program that calculates the sum of two integer decimal numbers. The type size is the size of a machine word.

You can use the functions of the standard C library scanf and printf.

The function main can be considered as an entry point.

[Solution phy03-1](https://github.com/rudykh/CAOS/blob/master/phy03/phy03-1.S).

## Phy03-2
Напишите программу, которая читает со стандартного потока ввода последовательность символов, и выводит только те из них, которые являются десятичными цифрами от 0 до 9.

Можно использовать функции стандартной библиотеки языка Си: fgetc и fputc.

В качестве точки входа можно считать функцию main.

Write a program that reads a sequence of characters from the standard input stream and displays only those that are decimal digits from 0 to 9.

You can use the functions of the standard C library: fgetc and fputc.

The function main can be considered as an entry point.

[Solution phy03-2](https://github.com/rudykh/CAOS/blob/master/phy03/phy03-2.S).

## Phy03-3
Реализуйте программу, которая считывает символы со стандартного потока ввода, а затем выводит их в обратном порядке.<br>
Можно использовать функции стандартной библиотеки языка Си: fgetc, fputc, realloc и free.<br>
В качестве точки входа можно считать функцию main.

Implement a program that reads characters from a standard input stream and then outputs them in reverse order. <br>
You can use the functions of the standard C library: fgetc, fputc, realloc, and free. <br>
The function main can be considered as an entry point.

[Solution phy03-3](https://github.com/rudykh/CAOS/blob/master/phy03/phy03-3.S).

## Phy04-0
Реализуйте функцию на языке ассемблера x86 (IA-32) или x86-64 с сигнатурой:
```extern void summ(int N, const int *A, const int *B, int *R);```
Функция вычисляет значения Ri=Ai+Bi для всех i от 0 до N.<br>
Память для хранения массива-результата уже выделена.

Implement the function in assembly language x86 (IA-32) or x86-64 with the signature:
```extern void summ (int N, const int * A, const int * B, int * R);```
The function calculates the values R<sub>i</sub>=A<sub>i</sub>+B<sub>i</sub> for all i from 0 to N.<br>
Memory for storing the result array has already been allocated.

[Solution phy04-0](https://github.com/rudykh/CAOS/blob/master/phy04/phy04-0.S).

## Phy04-1
Реализуйте на языке ассемблера x86 (IA-32) или x86-64 функцию с сигнатурой:
```
extern double my_sin(double x)
```
которая вычисляет значение sin(x).<br>
Запрещено использовать встроенные тригонометрические инструкции.<br>
Для вычислений используйте известный вам из курса Математического анализа способ разложения функции в ряд. Точность результата должна быть маскимально возможной для типа данных double. 

Implement in x86 (IA-32) or x86-64 assembly language a function with a signature:
```
extern double my_sin (double x)
```
which calculates the value of sin(x). <br>
It is forbidden to use the built-in trigonometric instructions. <br>
For calculations, use the method of expanding a function in a series known to you from the course of Mathematical Analysis. The accuracy of the result should be maskably possible for the double data type.

[Solution phy04-1](https://github.com/rudykh/CAOS/blob/master/phy04/phy04-1.S).

## Phy04-2
Implement a function on asm-x86 (IA-32) or x86-64 with this signature:
```
extern void mergesort(int from, int to, const int *in, int *out);
```    
This function should do merge sort of integers.<br>
Parameters from and to are indices of left and right boundaries of sorting areas; in is a source array, out - a pointer to the allocated memory for the result.<br>
Use only stack memory, usage of the heap is forbidden.

[Solution phy04-2](https://github.com/rudykh/CAOS/blob/master/phy04/phy04-2.S).

## Phy04-3
Реализуйте на языке ассемблера x86 (IA-32) или x86-64 функцию с сигнатурой:
```
extern float dot_product(int N, const float *A, const float *B);
```
которая вычисляет скалярное произведение векторов A и B.<br>
Гарантируется, что N больше нуля, но не гарантируется, что N кратно четырём.<br>
Значения исходных векторов хранятся в произвольных адресах памяти, поэтому выравнивание для них не гарантируется.<br>
Необходимо минимизировать количество выполняемых вычислительных инструкций, используя векторные вычисления. Доступен набор команд SSE 4.2. Для архитектуры x86-64 также доступен набор команд AVX.

Implement in x86 (IA-32) or x86-64 assembly language a function with a signature:
```
extern float dot_product (int N, const float * A, const float * B);
```
which calculates the scalar product of vectors A and B. <br>
It is guaranteed that N is greater than zero, but it is not guaranteed that N is a multiple of four. <br>
The values of the source vectors are stored in arbitrary memory addresses, so alignment for them is not guaranteed. <br>
It is necessary to minimize the number of computational instructions that are executed using vector calculations. SSE 4.2 command set available. For the x86-64 architecture, the AVX command set is also available.

[Solution phy04-3](https://github.com/rudykh/CAOS/blob/master/phy04/phy04-3.S).

## Phy05-0
Реализуйте на языке ассемблера x86 или x86_64 программу, которая выводит "Hello, World!".<br>
Использование стандартной библиотеки Си запрещено.<br>
Точка входа в программу - функция \_start.

Implement an x86 or x86_64 assembly language program that displays "Hello, World!". <br>
Using the C standard library is prohibited. <br>
The entry point to the program is the \_start function.

[Solution phy05-0](https://github.com/rudykh/CAOS/blob/master/phy05/phy05-0.S).

## Phy05-1
Реализуйте на языке ассемблера x86 или x86_64 программу, которая копирует содержимое со стандартного потока ввода на стандартный поток вывода.<br>
Использование стандартной библиотеки Си запрещено.<br>
Точка входа в программу - функция \_start.

Implement a program in x86 or x86_64 assembly language that copies content from a standard input stream to a standard output stream. <br>
Using the C standard library is prohibited. <br>
The entry point to the program is the \_start function.

[Solution phy05-1](https://github.com/rudykh/CAOS/blob/master/phy05/phy05-1.S).

## Phy05-2
Реализуйте на языке ассемблера x86 или x86_64 программу, которая читает со стандартного потока ввода текст, после чего выводит все строки текста в обратном порядке.<br>
Использование стандартной библиотеки Си запрещено.<br>
Точка входа в программу - функция \_start.

Implement a program in x86 or x86_64 assembly language that reads text from a standard input stream and then displays all lines of text in reverse order. <br>
Using the C standard library is prohibited. <br>
The entry point to the program is the \_start function.<br>
**Input
```
Мой дядя самых честных правил,
Когда не в шутку занемог,
Он уважать себя заставил
И лучше выдумать не мог.
```
**Output
```
И лучше выдумать не мог.
Он уважать себя заставил
Когда не в шутку занемог,
Мой дядя самых честных правил,
```

[Solution phy05-2](https://github.com/rudykh/CAOS/blob/master/phy05/phy05-2.S).

## Phy06-0
Программе в аргументах командной строки передаются три имени файла. Первый аргумент - входной файл, два остальных - выходные.<br>
Реализуйте программу, которая читает символы из первого файла, во второй файл записывает только цифры, а в третий - всё остальное.<br>
Разрешается использовать только низкоуровневый ввод-вывод POSIX.<br>
Если входной файл не существует, то нужно завершить работу с кодом 1.<br>
Если не возможно создать один из выходных файлов, то завершить работу с кодом 2.<br>
При возникновении других ошибок ввода-вывода - завершить работу с кодом 3.<br>

Three file names are passed to the program in command line arguments. The first argument is the input file, the other two are the output.<br>
Implement a program that reads characters from the first file, writes only numbers to the second file, and everything else to the third.<br>
Only low-level POSIX I / O is allowed.<br>
If the input file does not exist, then you need to exit with code 1.<br>
If it is not possible to create one of the output files, then exit with code 2.<br>
If other I / O errors occur, exit with code 3.

[Solution phy06-0](https://github.com/rudykh/CAOS/blob/master/phy06/phy06-0.c).

## Phy06-1
Программе в аргументе командной строки передается имя файла с бинарными данными в Little-Endian.<br>
Файл хранит внутри себя односвязный список элементов:
```
struct Item {
  int value;
  uint32_t next_pointer;
};
```
Поле value храние значение элемента списка, поле next_pointer - позицию в файле (в байтах), указывающую на следующий элемент. Признаком последнего элемента является значение next_pointer, равное 0.<br>
Расположение первого элемента списка (если он существует) - строго в нулевой позиции в файле, расположение остальных - случайным образом.<br>
Выведите на экран значения элементов в списке в текстовом представлении.<br>
Для работы с файлом использовать только низкоуровневый ввод-вывод POSIX.

The program receives a binary file name in Little-Endian in a command line argument. <br>
The file contains a single-linked list of elements inside:
```
struct Item {
  int value;
  uint32_t next_pointer;
};
```
The value field is the value of the list item, the next_pointer field is the position in the file (in bytes), indicating the next item. A sign of the last element is next_pointer, which is 0. <br>
The location of the first element of the list (if it exists) is strictly at the zero position in the file, the location of the rest is random. <br>
Display the values of the items in the list in the text view. <br>
To work with the file, use only low-level POSIX.

[Solution phy06-1](https://github.com/rudykh/CAOS/blob/master/phy06/phy06-1.c).

## Phy06-2
Программе на стандартном потоке ввода передаётся список имён файлов.<br>
Необходимо посчитать суммарный размер в байтах всех файлов, которые являются регулярными.

The program receives a list of file names on a standard input stream. <br>
It is necessary to calculate the total size in bytes of all files that are regular.

[Solution phy06-2](https://github.com/rudykh/CAOS/blob/master/phy06/phy06-2.c).

## Phy06-3
Программе на стандартном потоке ввода передаётся список имён файлов.<br>
Если файл является символической ссылкой, то нужно вывести абсолютное имя того файла, на который эта ссылка указывает.<br>
Если файл является регулярным, то необходимо создать символическую ссылку в текущем каталоге, приписав в названии файла префикс link_to_.

The program receives a list of file names on a standard input stream. <br>
If the file is a symbolic link, then you need to display the absolute name of the file to which this link points. <br>
If the file is regular, then you need to create a symbolic link in the current directory, assigning the link_to_ prefix to the file name.

[Solution phy06-3](https://github.com/rudykh/CAOS/blob/master/phy06/phy06-3.c).

## Phy07-0
Программе передаются два аргумента: имя каталога и три целых числа, - год, месяц и день.<br>
Вывести на стандартный поток вывода список имен файлов указанного каталога, которые были модифицированы начиная с указанной даты (по местному часовому поясу).

Two arguments are passed to the program: the directory name and three integers, - year, month and day. <br>
Display a list of file names for the specified directory on standard output, which have been modified since the specified date (in the local time zone).

[Solution phy07-0](https://github.com/rudykh/CAOS/blob/master/phy07/phy07-0.c).

## Phy07-1
Реализуйте программу, которая читает со стандартного потока ввода строки - временные метки в формате:
```
YYYY-MM-DD HH:mm
```
Где YYYY - год, MM - месяц, DD - день, HH - час в 24-часовом формате, mm - минуты.<br>
Гарантируется, что ввод содержит не менее двух строк.<br>
На стандартный поток вывода необходимо вывести интервалы времени в минутах, прошедшие между соседними временными метками.<br>
Не забывайте учитывать возможные переводы стрелок зимнего/летнего времени, а также законодательные инициативы по отмене/введению перевода часов на летнее время.

Implement a program that reads from a standard line input stream - timestamps in the format:
```
YYYY-MM-DD HH: mm
```
Where YYYY - year, MM - month, DD - day, HH - hour in 24-hour format, mm - minutes. <br>
It is guaranteed that the input contains at least two lines. <br>
On the standard output stream, it is necessary to display the time intervals in minutes that have elapsed between adjacent timestamps. <br>
Do not forget to consider the possible translations of the hands of winter / summer time, as well as legislative initiatives to cancel / introduce the conversion of clocks to daylight saving time.

[Solution phy07-1](https://github.com/rudykh/CAOS/blob/master/phy07/phy07-1.c).

## Phy07-2
Программе в качестве аргумента строки передается имя каталога.<br>
Необходимо посчитать суммарный размер всех регулярных файлов в этом каталоге и во всех вложенных подкаталогах.<br>
Результат вывести на стандартный поток вывода.

The program is passed the directory name as an argument to the string.<br>
It is necessary to calculate the total size of all regular files in this directory and in all subdirectories.<br>
Output the result to standard output.

[Solution phy07-2](https://github.com/rudykh/CAOS/blob/master/phy07/phy07-2.c).

## Phy07-3
Implement function
```
extern void normalize_path(char * path);
```
which handles filepathes (ending with any symbol except /) and directory pathes (ending with /).

Function must convert text to the canonic form:<br>
1. remove duplication of consecutive /<br>
2. handle fragments ./ and ../

It's forbidden to use string library function. Use pointer arithmetic.

[Solution phy07-3](https://github.com/rudykh/CAOS/blob/master/phy07/phy07-3.c).

## Phy07-4
Реализуйте упрощённый аналог команды ls -l.<br>
Программе в качестве первого аргумента передаётся имя каталога.<br>
Необходимо вывести содержимое каталога в виде:<br>
АТТРИБУТЫ КОЛ_ВО_ССЫЛОК ВЛАДЕЛЕЦ ГРУППА РАЗМЕР ИМЯ<br>
Если в качестве аргумента указано имя файла, то вывести информацию только об этом единственном файле.<br>
Для символических ссылок выведите ещё и имена файлов, на которые они ссылаются.<br>
В случае ошибки - вывести текст ошибки на стандартный поток ошибок и завершить работу с кодом 1.

Implement a simplified counterpart to the ls -l command. <br>
It is necessary to display the contents of the directory in the form: <br>
ATTRIBUTES KOL_VO_REFERENCE OWNER GROUP SIZE NAME <br>
The file name is specified as an argument.<br>
Only file names are used to indicate names.<br>
In case of errors, output the error text to the standard error stream and exit with code 1

[Solution phy07-4](https://github.com/rudykh/CAOS/blob/master/phy07/phy07-4.c).

## Phy08-0
Программе передаются два аргумента: имя файла, и строка для поиска.<br>
Необходимо найти все вхождения строки в текстовом файле, используя отображение на память с помощью системного вызова mmap.<br>
На стандартный поток вывода вывести список всех позиций (с нуля) в файле, где втречаются строка.

Two arguments are passed to the program: the file name, and the search string. <br>
You must find all occurrences of a string in a text file using memory mapping using the mmap system call. <br>
On the standard output stream, list all the positions (from scratch) in the file where the line meets.

[Solution phy08-0](https://github.com/rudykh/CAOS/blob/master/phy08/phy08-0.c).

## Phy08-1
Программе в аргументе командной строки передается имя файла с бинарными данными в Little-Endian.<br>
Файл хранит внутри себя односвязный список элементов:
```
struct Item {
  int value;
  uint32_t next_pointer;
};
```
Поле value храние значение элемента списка, поле next_pointer - позицию в файле (в байтах), указывающую на следующий элемент. Признаком последнего элемента является значение next_pointer, равное 0.<br>
Расположение первого элемента списка (если он существует) - строго в нулевой позиции в файле, расположение остальных - случайным образом.<br>
Выведите на экран значения элементов в списке в текстовом представлении.<br>
Используйте отображение содержимого файла на память.

The program receives a binary file name in Little-Endian in a command line argument. <br>
The file contains a single-linked list of elements inside:
```
struct Item {
  int value;
  uint32_t next_pointer;
};
```
The value field is the value of the list item, the next_pointer field is the position in the file (in bytes), indicating the next item. A sign of the last element is next_pointer, which is 0. <br>
The location of the first element of the list (if it exists) is strictly at the zero position in the file, the location of the rest is random. <br>
Display the values of the items in the list in the text view. <br>
Use mapping the contents of a file to memory.

[Solution phy08-1](https://github.com/rudykh/CAOS/blob/master/phy08/phy08-1.c).

## Phy08-2
Программе передаются три аргумента: имя файла, положительное целое число N - размер квадратной матрицы, и положительное число W - ширина клетки матицы в символах.<br>
Необходимо в указанном файле сформировать текст, который содержит матрицу, состоящую из чисел от 1 до N2, таким образом, чтобы числа заполняли её по спирали, по часовой стрелке.<br>
Числа должны быть выровнены по правой границе ячейки матрицы.
Используйте mmap для записи в файл.<br>
Можно использовать функции форматного вывода для преобразования числа в строку.

Three arguments are passed to the program: the file name, a positive integer N is the size of the square matrix, and a positive number W is the width of the matrix cell in characters. <br>
It is necessary to form a text in the specified file that contains a matrix consisting of numbers from 1 to N2, so that the numbers fill it in a spiral, clockwise. <br>
The numbers should be aligned on the right border of the matrix cell.
Use mmap to write to a file. <br>
You can use the formatted output functions to convert a number to a string.

[Solution phy08-2](https://github.com/rudykh/CAOS/blob/master/phy08/phy08-2.c).

## Phy09-0
Программе передается аргумент - целое число N > 0. <br>
Необходимо создать N-1 дополнительных процессов таким образом, чтобы у каждого процесса было не более одного дочернего процесса.<br>
Каждый из процессов должен вывести на стандартный поток ввода ровно одно число таким образом, чтобы вы выходе получилась строка:
```1 2 3 4 ... N```
**Внимание!** В этой задаче будет сравнение с учетом пробельных символов. Между числами должен быть ровно один пробел, а завершается строка символом перевода строки.

The argument is passed to the program - an integer N > 0. <br>
You must create N-1 additional processes so that each process has no more than one child process. <br>
Each of the processes should output exactly one number to the standard input stream so that you get a line:
```1 2 3 4 ... N```
**Attention!** In this task there will be a comparison taking into account whitespace characters. There must be exactly one space between the numbers, and the line ends with a line feed character.

[Solution phy09-0](https://github.com/rudykh/CAOS/blob/master/phy09/phy09-0.c).

## Phy09-1
Программе на стандартный поток ввода задается некоторое арифметическое выражение в синтаксисе языка python3.<br>
Необходимо вычислисть это выражение, и вывести результат.<br>
Использовать дополнительные процессы запрещено.

A standard input stream program is given some arithmetic expression in python3 syntax. <br>
You need to calculate this expression and print the result. <br>
Using additional processes is prohibited.

[Solution phy09-1](https://github.com/rudykh/CAOS/blob/master/phy09/phy09-1.c).

## Phy09-2
На стандартном потоке ввода задается строка текста, которая состоит слова (последовательности непробельных символов), между которыми может быть произвольное количество пробельных символов, включая перевод строки.<br>
Необходимо посчитать количество слов, если известно, что их не больше, чем 255, и вывести это значение на стандартный поток вывода.<br>
Используйте создание новых процессов таким образом, чтобы каждый процесс читал не более одного слова, например, c помощью scanf("%s", ...).<br>
Вывод результата возможен только из того процесса, который запущен самым первым (т.е. из исходной программы).<br>
Итоговая программа должна вернуться с кодом возврата 0.<br>
Размер каждого слова не превышает 4096 байт.

On a standard input stream, a line of text is set that consists of words (sequences of non-whitespace characters), between which there can be an arbitrary number of whitespace characters, including line feeds. <br>
It is necessary to calculate the number of words, if it is known that there are no more than 255 of them, and output this value to the standard output stream. <br>
Use the creation of new processes so that each process reads no more than one word, for example, using scanf ("% s", ...). <br>
The output of the result is possible only from the process that was launched by the very first (i.e., from the source program). <br>
The final program should return with a return code of 0. <br>
The size of each word does not exceed 4096 bytes.

[Solution phy09-2](https://github.com/rudykh/CAOS/blob/master/phy09/phy09-2.c).

## Phy09-3
Программе на стандартном потоке ввода задается выражение в синтаксисе языка Си.<br>
Необходимо вычислить значение этого выражения (итоговый результат представим типом int) и вывести его на стандартный поток вывода.

A program on a standard input stream is given an expression in the syntax of the C language. <br>
It is necessary to calculate the value of this expression (the final result is represented by the int type) and output it to the standard output stream.

[Solution phy09-3](https://github.com/rudykh/CAOS/blob/master/phy09/phy09-3.c).

## Phy10-0
Реализуйте программу, которая принимает два аргумента: CMD - команда для запуска, IN - имя файла, направляемого на ввод.<br>
Программа должна запускать указанную команду, передавая ей на вход содежимое файла IN.<br>
На стандартный поток вывода вывести количество байт, которое было записано запущенной командой в стандартный поток вывода. Вывод самой команды никуда выводить не нужно.

Implement a program that takes two arguments: CMD is the command to start, IN is the name of the file to be sent to input. <br>
The program should run the specified command, passing it the contents of the IN file.<br>
On the standard output stream, output the number of bytes that were written by the running command to the standard output stream. The output of the command itself does not need to be displayed anywhere.

[Solution phy10-0](https://github.com/rudykh/CAOS/blob/master/phy10/phy10-0.c).

## Phy10-1
Программе в качестве аргумента передается имя файла программы на языке Си. Необходимо попытаться её скомпилировать с помощью штатного компилятора gcc, после чего вывести на стандартный поток вывода: количество строк программы с ошибками (error), и количество строк программы с предупреждениями (warning). В одной строке может быть найдено несколько ошибок или предупреждений, - нужно вывести именно количество строк.<br>
Запрещено создавать временные файлы для сохранения вывода ошибок компилятора.<br>
Используйте передачу текста от компилятора через каналы.

The program receives the C file name of the program as an argument. You must try to compile it using the standard gcc compiler, and then output to the standard output stream: the number of lines of the program with errors (error), and the number of lines of the program with warnings (warning). Several errors or warnings can be found in one line - you need to print exactly the number of lines. <br>
It is forbidden to create temporary files to save the output of compiler errors.

[Solution phy10-1](https://github.com/rudykh/CAOS/blob/master/phy10/phy10-1.c).

## Phy10-2
Программе передаётся два аргумента: CMD1 и CMD2. Необходимо запустить два процесса, выполняющих эти команды, и перенаправить стандартный поток вывода CMD1 на стандартный поток ввода CMD2.<br>
В командной строке это эквивалентно CMD1 | CMD2.<br>
Родительский процесс должен завершаться самым последним!

Two arguments are passed to the program: CMD1 and CMD2. You must start two processes that execute these commands and redirect the standard CMD1 output stream to the standard CMD2 input stream.<br>
On the command line, this is equivalent to CMD1 | CMD2.<br>
The parent process should end with the very latest!

[Solution phy10-2](https://github.com/rudykh/CAOS/blob/master/phy10/phy10-2.c).

## Phy10-3
Программе передаётся произвольное количество аргументов: CMD1, CMD2, ..., CMDN.<br>
Необходимо реализовать эквивалент запуска их командной строки: CMD1 | CMD2 | ... | CMDN.<br>
Родительский процесс должен завершаться самым последним!

An arbitrary number of arguments is passed to the program: CMD1, CMD2, ..., CMDN. <br>
You must implement the equivalent of starting their command line: CMD1 | CMD2 | ... | CMDN. <br>
The parent process should end with the very latest!


[Solution phy10-3](https://github.com/rudykh/CAOS/blob/master/phy10/phy10-3.c).

## Phy10-4
Программе передаётся произвольное количество аргументов: CMD1, CMD2, ..., CMDN.<br>
Необходимо реализовать эквивалент запуска их командной строки: CMD1 | CMD2 | ... | CMDN.<br>
Родительский процесс должен завершаться самым последним!<br>
В отличие от предыдущей задачи, разрешается использовать только два канала.<br>
Допускается использовать не более 8 открытых файловых дескрипторов.

An arbitrary number of arguments is passed to the program: CMD1, CMD2, ..., CMDN. <br>
You must implement the equivalent of starting their command line: CMD1 | CMD2 | ... | CMDN. <br>
The parent process must end with the very latest! <br>
Unlike the previous task, only two channels are allowed. <br>
Only 8 open file descriptors are allowed.

[Solution phy10-4](https://github.com/rudykh/CAOS/blob/master/phy10/phy10-4.c).

## Phy11-0
Программа при запуске сообщает на стандартный поток вывода свой PID, выталкивает буфер вывода с помощью fflush, после чего начинает обрабатывать поступающие сигналы.<br>
При поступлении сигнала SIGTERM необходимо вывести на стандартный поток вывода целое число: количество ранее поступивших сигналов SIGINT и завершить свою работу.<br>
Семантика повединия сигналов (Sys-V или BSD) считается не определенной.

The program at startup reports its PID to the standard output stream, pushes the output buffer using fflush, and then starts processing incoming signals. <br>
When a SIGTERM signal arrives, you must output an integer to the standard output stream: the number of previously received SIGINT signals and complete your work. <br>
The semantics of signal coupling (Sys-V or BSD) are considered undefined.

[Solution phy11-0](https://github.com/rudykh/CAOS/blob/master/phy11/phy11-0.c).

## Phy11-1
Программа при запуске сообщает на стандартный поток вывода свой PID, после чего читает со стандартного потока вывода целое число - начальное значение, которое затем будет изменяться.<br>
При поступлении сигнала SIGUSR1 увеличить текущее значение на 1 и вывести его на стандартный поток вывода.<br>
При поступлении сигнала SIGUSR2 - умножить текущее значение на -1 и вывести его на стандартный поток вывода.<br>
Семантика повединия сигналов (Sys-V или BSD) считается не определенной.
Не забывайте выталкивать буфер вывода.

The program at startup reports its PID to the standard output stream, after which it reads an integer from the standard output stream - the initial value, which will then be changed. <br>
When the signal SIGUSR1 arrives, increase the current value by 1 and output it to the standard output stream. <br>
When a SIGUSR2 signal arrives, multiply the current value by -1 and output it to the standard output stream. <br>
The semantics of signal coupling (Sys-V or BSD) are considered undefined.
Remember to pop out the output buffer.

[Solution phy11-1](https://github.com/rudykh/CAOS/blob/master/phy11/phy11-1.c).

## Phy11-2
Программе в качестве аргументов передаются N имен текстовых файлов.<br>
Программа должна обрабатывать множество сигналов от SIGRTMIN до SIGRTMAX, причем номер сигнала в диапазоне от SIGRTMIN+1 определяет порядковый номер файла из аргументов:
```
x = signo - SIGRTMIN; // SIGRTMIN <= signo <= SIGRTMAX
                      // 1 <= x <= SIGRTMAX-SIGRTMIN
```
При получении очередного сигнала необходимо прочитать одну строку из определенного файла и вывести её на стандартный поток вывода.<br>
При получении сигнала с номером SIGRTMIN, т.е. при номере аргумента, равным 0, - корректно завершить свою работу с кодом 0.<br>
Все остальные сигналы нужно игнорировать.<br>
Если для вывода используются высокоуровневые функции стандартной библиотеки Си, то необходимо выталкивать буфер обмена после вывода каждой строки.

The program receives N text file names as arguments. <br>
The program must process many signals from SIGRTMIN to SIGRTMAX, and the signal number in the range from SIGRTMIN + 1 determines the serial number of the file from the arguments:
```
x = signo - SIGRTMIN; // SIGRTMIN <= signo <= SIGRTMAX
                      // 1 <= x <= SIGRTMAX-SIGRTMIN
```
When you receive the next signal, you need to read one line from a specific file and output it to the standard output stream. <br>
When receiving a signal with SIGRTMIN number, i.e. with the argument number equal to 0, correctly complete its work with the code 0. <br>
All other signals must be ignored. <br>
If the high-level functions of the standard C library are used for output, then it is necessary to populate the clipboard after the output of each line.

[Solution phy11-2](https://github.com/rudykh/CAOS/blob/master/phy11/phy11-2.c).

## Phy11-3
Программа обрабатывать сигнал SIGRTMIN, вместе с которым передается некоторое беззнаковой 32-битное целое число N.<br>
Все остальные сигналы нужно игнорировать.<br>
При получении очередного сигнала нужно уменьшить это число на единицу и отправить его обратно тому процессу, который его послал (используя тот же самый сигнал).<br>
Взаимодействие останавливается при получении значения N==0, после чего нужно корректно завершить работу.<br>
Запрещается использовать signalfd, программа будет компилироваться без поддержки Linux-специфичных расширений.

The program processes the SIGRTMIN signal, with which some unsigned 32-bit integer N. is transmitted. <br>
All other signals must be ignored. <br>
When you receive the next signal, you need to reduce this number by one and send it back to the process that sent it (using the same signal). <br>
The interaction stops when the value N == 0 is received, after which the work must be completed correctly. <br>
It is forbidden to use signalfd, the program will compile without support for Linux-specific extensions.

[Solution phy11-3](https://github.com/rudykh/CAOS/blob/master/phy11/phy11-3.c).

## Phy12-0
Программе передаются два аргумента: строка с IPv4-адресом в стандартной десятичной записи (четыре числа, разделенные точкой), и номер порта.<br>
Программа должна установить соединение с указанным сервером, после чего читать со стандартного потока ввода целые знаковые числа в тектовом формате, и отправлять их в бинарном виде на сервер. Порядок байт - Little Endian.<br>
В ответ на каждое число полученное число, сервер отправляет целое число (в таком же формате), и все эти числа необходимо вывести на стандартный поток вывода в текстовом виде.<br>
Если сервер по своей инициативе закроет соединение, то нужно завершить работу с кодом возврата 0.

Two arguments are passed to the program: a string with an IPv4 address in standard decimal notation (four numbers separated by a dot), and a port number. <br>
The program should establish a connection with the specified server, then read integer signed numbers in the text format from the standard input stream and send them in binary form to the server. Byte Order - Little Endian. <br>
In response to each number received, the server sends an integer (in the same format), and all these numbers must be output to the standard output stream in text form. <br>
If the server closes the connection on its own initiative, then you need to exit with return code 0.

[Solution phy12-0](https://github.com/rudykh/CAOS/blob/master/phy12/phy12-0.c).

## Phy12-1
Необходимо реализовать программу-сервер, которой передаются два аргумента: номер порта и полный путь к каталогу с данными.<br>
Программа должна прослушивать TCP-соединение на сервере localhost и указанным номером порта.<br>
После получения сигнала SIGTERM или SIGINT сервер должен закончить обработку текущего соединения, если оно есть, после чего корректно завершить свою работу.<br>
Внимание: в этой задаче признаком конца строк считается пара символов "\r\n", а не одиночный символ '\n'.<br>
Каждое соединение должно обрабатываться следующим образом:<br>
1. Клиент отправляет строку вида GET ИМЯ_ФАЙЛА HTTP/1.1<br>
2. Клиент отправляет произвольное количество непустых строк<br>
3. Клиент отправляет пустую строку;

После получения пустой строки от клиента, сервер должен отправить клиенту слеющие данные:<br>
1. Строку HTTP/1.1 200 OK, если файл существует, или HTTP/1.1 404 Not Found, если файл не существует, или HTTP/1.1 403 Forbidden, если файл существует, но не доступен для чтения<br>
2. Строку Content-Length: %d, где %d - размер файла в байтах<br>
3. Пустую строку<br>
4. Содержимое файла as-is

После отправки ответа клиенту, нужно закрыть соединение и не нужно ждать ожидать от клиента следующих запросов.

[Solution phy12-1](https://github.com/rudykh/CAOS/blob/master/phy12/phy12-1.c).

## Phy12-2
Аргументом программы является целое число - номер порта на сервере localhost.<br>
Программа читает со стандартного потока ввода целые числа в тектовом формате, и отправляет их в бинарном виде (little-endian) на сервер как UDP-сообщение.<br>
В ответ сервер отправляет целое число (также в бинарном виде, little-endian), которое необходимо вывести на стандартный поток вывода.

The argument to the program is an integer - the port number on the localhost server. <br>
The program reads integers in the text format from the standard input stream and sends them in binary form (little-endian) to the server as a UDP message. <br>
In response, the server sends an integer (also in binary form, little-endian), which must be output to the standard output stream.

[Solution phy12-2](https://github.com/rudykh/CAOS/blob/master/phy12/phy12-2.c).

## Phy12-3
Необходимо реализовать программу-сервер, которой передаются два аргумента: номер порта и полный путь к каталогу с данными.<br>
Программа должна прослушивать TCP-соединение на сервере localhost и указанным номером порта.<br>
После получения сигнала SIGTERM или SIGINT сервер должен закончить обработку текущего соединения, если оно есть, после чего корректно завершить свою работу. Если при этом были запущены дочерние процессы - они должны быть завершены самим сервером.<br>
**Внимание:** в этой задаче признаком конца строк считается пара символов "\r\n", а не одиночный символ '\n'.<br>
Каждое соединение должно обрабатываться следующим образом:<br>
1. Клиент отправляет строку вида GET ИМЯ_ФАЙЛА HTTP/1.1<br>
2. Клиент отправляет произвольное количество непустых строк<br>
3. Клиент отправляет пустую строку

После получения пустой строки от клиента, сервер должен отправить клиенту слеющие данные:<br>
1. Строку HTTP/1.1 200 OK, если файл существует, или HTTP/1.1 404 Not Found, если файл не существует, или HTTP/1.1 403 Forbidden, если файл существует, но не доступен для чтения<br>
Если файл не является выполняемым, то:<br>
1. Строку Content-Length: %d, где %d - размер файла в байтах<br>
2. Пустую строку<br>
3. Содержимое файла as-is

Если файл является выполняемым, то после вывода строки HTTP/1.1 200 OK нужно выполнить этот файл, перенаправив его стандартный поток вывода клиенту as-is.<br>
После отправки ответа клиенту, нужно закрыть соединение и не нужно ждать ожидать от клиента следующих запросов.

[Solution phy12-3](https://github.com/rudykh/CAOS/blob/master/phy12/phy12-3.c).

## Phy13-0
Реализуйте функцию с сигнатурой:
```
extern size_t
read_data_and_count(size_t N, int in[N])
  ```      
которая читает данные из файловых дескрипторов in[X] для всех 0 ≤ X < N , и возвращает суммарное количество прочитанных байт из всех файловых дескрипторов.<br>
Скорость операций ввода-вывода у файловых дескрипторов - случайная. Необходимо минимизировать суммарное астрономическое время чтения данных.<br>
По окончании чтения необходимо закрыть все файловые дескрипторы.<br>
Указание: используйте неблокирующий ввод-вывод. Для тестирования можно использовать socketpair.

[Solution phy13-0](https://github.com/rudykh/CAOS/blob/master/phy13/phy13-0.c).

## Phy13-1
Программе задается единственный аргумент - номер TCP-порта.<br>
Необходимо принимать входящие соединения на TCP/IPv4 для сервера localhost, читать данные от клиентов в текстовом виде, и отправлять их обратно в текстовом виде, заменяя все строчные буквы на заглавные. Все обрабатываемые символы - из кодировки ASCII.<br>
Одновременных подключений может быть много. Использовать несколько потоков или процессов запрещено.<br>
Сервер должен корректно завершать работу при получении сигнала SIGTERM.<br>
Указание: используйте неблокирующий ввод-вывод.

[Solution phy13-0](https://github.com/rudykh/CAOS/blob/master/phy13/phy13-1.c).
