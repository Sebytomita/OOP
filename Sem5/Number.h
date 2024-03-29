#ifndef NUMBER_H
#define NUMBER_H

#include <iostream>
#include <cstring>

class Number {
private:
    char* value;
    int base;
    int length;

    void ConvertToBase(int newBase);

public:
    Number(const char* value, int base);
    Number(const char* value); 
    Number(int value);
    Number(const Number& other);
    Number(Number&& other) noexcept;
    ~Number();

    Number& operator=(const Number& other);
    Number& operator=(Number&& other) noexcept;

    char operator[](int index) const;
    bool operator>(const Number& other) const;
    bool operator<(const Number& other) const;
    bool operator>=(const Number& other) const;
    bool operator<=(const Number& other) const;
    bool operator==(const Number& other) const;
    Number operator+(const Number& other) const;
    Number operator-(const Number& other) const;
    Number& operator+=(const Number& other);
    Number& operator-=(const Number& other);
    Number& operator--(); //prefix
    Number operator--(int); //postfix
    int ConvertToDecimal() const;

    void SwitchBase(int newBase);
    void Print() const;
    int GetDigitsCount() const;
    int GetBase() const;
};

#endif // NUMBER_H
