# CAOS
## Phy01-0
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
`typedef enum {
    PlusZero      = 0x00,\\
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
classify(double *value_ptr);` <br>
которая классифицирует специальные значения вещественного числа, на которое указывает value_ptr, в соответствии со стандартом IEEE 754.

При решении допускается использовать только побитовые операции, включая сдвиги.

Implement the function with the prototype: <br>
`typedef enum {
    PlusZero      = 0x00, \\
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
classify(double *value_ptr);` <br>
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
Реализуйте функцию с прототипом:<br>
`extern int<br>
check_int(uint32_t u32); /* retval: 0 - false, 1 - true */`<br>
которая проверяет, может ли число u32 быть представлено типом float:<br>
`float f = u32;<br>
uint64_t y = f;<br>
assert(u32==y);`<br>
Функция должна вернуть 1, если число может быть представлено типом float, или 0, - если не может.

Допускается исользовать только побитовые операции.

Implement the function with the prototype:<br>
`extern int<br>
check_int (uint32_t u32); / * retval: 0 - false, 1 - true * / `<br>
which checks if a u32 number can be represented by a float type:<br>
`float f = u32;<br>
uint64_t y = f;<br>
assert (u32 == y); `<br>
The function should return 1 if the number can be represented by the float type, or 0 if it cannot.

Only bitwise operations are allowed.

[Solution phy01-4](https://github.com/rudykh/CAOS/blob/master/phy01/phy01-4.c).
