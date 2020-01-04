#include <stdio.h>
#include <stdint.h>
#include <string.h>

uint16_t char_to_int(char chr) {
    if (chr >= '0' && chr <= '9') {
        return chr - '0';
    } else if (chr >= 'A' && chr <= 'Q') {
        return chr - 'A' + 10;
    } else if (chr >= 'a' && chr <= 'q') {
        return chr - 'a' + 10;
    }
    return -1;
}

// Схема Горнера
uint64_t transfer_from_27_to_dec(char *number) {
    uint64_t result = char_to_int(number[0]);
    for (uint32_t i = 1; i < strlen(number); ++i) {
        result *= 27;
        result += char_to_int(number[i]);
    }
    return result;
}

int main(int argc, char *argv[]) {
    char *z = argv[1];
    double x;
    int y;
    scanf("%lf%x", &x, &y);
    uint64_t z_in_dec = transfer_from_27_to_dec(z);
    double sum;
    sum = x + y + z_in_dec;
    printf("%.3lf\n", sum);
    return 0;
}