#include <stdint.h>

extern int
check_int(uint32_t u32) /* retval: 0 - false, 1 - true */
{
    int right_border = 0, left_border;
    if (u32 == 0) {
        return 1;
    }
    while (!(u32 & 1)) {
        u32 >>= 1;
        ++right_border;
    }
    left_border = right_border;
    ++right_border;
    while (u32 > 0) {
        u32 >>= 1;
        ++left_border;
    }
    if ((left_border - right_border) <= 23) {
        return 1;
    }
    return 0;
}