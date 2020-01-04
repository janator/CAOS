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
classify(double *value_ptr);` <br>
которая классифицирует специальные значения вещественного числа, на которое указывает value_ptr, в соответствии со стандартом IEEE 754.

При решении допускается использовать только побитовые операции, включая сдвиги.

Implement the function with the prototype: <br>
`typedef enum {
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
classify(double *value_ptr);` <br>
which classifies the special values of a real number pointed to by value_ptr, in accordance with the IEEE 754 standard.

When solving, it is allowed to use only bitwise operations, including shifts.

[Solution phy01-2](https://github.com/rudykh/CAOS/blob/master/phy01/phy01-2.c).
