#include <stdio.h>
#include <stdint.h>


int main() {
    uint64_t set = 0, current = 0;
    int c;
    while ((c = getchar()) != EOF) {
        if (c == '|') {
            set |= current;
            current = 0;
        }
        if (c == '&') {
            set &= current;
            current = 0;
        }
        if (c == '^') {
            set ^= current;
            current = 0;
        }
        if (c == '~') {
            if (current == 0) {
                set = ~set;
            } else {
                current =~ current;
            }
        }
        // current = 000123456789AB...Za...z, первые два бита не используются, с 61 бита по 52 цифры,
        // c 51 по 26 заглавные буквы, с 25 по 0 строчные
        if (c >= '0' && c <= '9') {
            current |= 1ULL << (61 - c + '0');
        }
        if (c >= 'a' && c <='z') {
            current |= 1ULL << (25 - c + 'a');
        }
        if (c >= 'A' && c <= 'Z') {
            current |= 1ULL << (51 - c + 'A');
        }

    }
    for (int i = 0; i < 10; ++i) {
        if (set & 1ULL << (61 - i))
            printf("%d", i);
    }
    for (char i = 'A'; i <= 'Z'; ++i) {
        if (set & 1ULL << (51 - i + 'A'))
            printf("%c", i);
    }
    for (char i = 'a'; i <= 'z'; ++i) {
        if (set & 1ULL << (25 - i + 'a'))
            printf("%c", i);
    }
    return 0;
}