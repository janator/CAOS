#include <stdio.h>
#include <stdint.h>

typedef enum {
    PlusZero = 0x00,
    MinusZero = 0x01,
    PlusInf = 0xF0,
    MinusInf = 0xF1,
    PlusRegular = 0x10,
    MinusRegular = 0x11,
    PlusDenormal = 0x20,
    MinusDenormal = 0x21,
    SignalingNaN = 0x30,
    QuietNaN = 0x31
} float_class_t;

extern float_class_t classify(double *value_ptr) {
    void *tmp_pointer = value_ptr;
    uint64_t a_value = *((uint64_t *) tmp_pointer);
    uint64_t sign = (a_value >> 63);
    uint64_t exp = (~(1ULL << 11)) & (a_value >> 52);
    uint64_t M = a_value &
                 (~((~(1ULL << 12)) << 52));
    if (exp == 0x7ff) {
        if (M == 0) {
            if (sign == 0)
                return PlusInf;
            else
                return MinusInf;
        }
        else {
            if (M == (1ULL << 51))
                return QuietNaN;
            else
                return SignalingNaN;
        }
    }
    if (exp == 0 && M == 0) {
        if (sign == 0)
            return PlusZero;
        else
            return MinusZero;
    }
    if (exp == 0) {
        if (sign)
            return MinusDenormal;
        else
            return PlusDenormal;
    }
    if (sign) 
        return MinusRegular; 
    else 
        return PlusRegular;
}