uint16_t satsum(uint16_t x, uint16_t y) {
    uint16_t sum = x + y;
    uint16_t uint16_t_max = ~0;
    if (sum < x || sum < y)
        return uint16_t_max;
    return sum;
}