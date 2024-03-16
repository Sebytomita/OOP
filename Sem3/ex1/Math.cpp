#include "Math.h"
#include <stdarg.h>
#include <cstring>

int Math::Add(int a, int b) {
    return a + b;
}

int Math::Add(int a, int b, int c) {
    return a + b + c;
}

int Math::Add(double a, double b) {
    return static_cast<int>(a + b);
}

int Math::Add(double a, double b, double c) {
    return static_cast<int>(a + b + c);
}

int Math::Mul(int a, int b) {
    return a * b;
}

int Math::Mul(int a, int b, int c) {
    return a * b * c;
}

int Math::Mul(double a, double b) {
    return static_cast<int>(a * b);
}

int Math::Mul(double a, double b, double c) {
    return static_cast<int>(a * b * c);
}

int Math::Add(int count, ...) {
    va_list k;
    va_start(k, count);
    int sum = 0;
    for (int i = 0; i < count; ++i) {
        sum += va_arg(k, int);
    }
    va_end(k);
    return sum;
}

char* Math::Add(const char* ch1, const char* ch2) {
    if (ch1 == nullptr || ch2 == nullptr)
        return nullptr;

    size_t lg1 = strlen(ch1);
    size_t lg2 = strlen(ch2);
    char* strfinal = new char[lg1 + lg2 + 1];
    strcpy(strfinal, ch1);
    strcat(strfinal, ch2);
    return strfinal;
}
