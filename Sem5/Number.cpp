#include "Number.h"
#include <cstring>
#include <cctype>
#include <algorithm>

Number::Number(const char* value, int base) : base(base) {
    this->length = strlen(value);
    this->value = new char[this->length + 1];
    strcpy(this->value, value);
}

Number::Number(const char* value) : base(10) {
    this->length = strlen(value);
    this->value = new char[this->length + 1];
    strcpy(this->value, value);
}

Number::Number(const Number& other) : base(other.base), length(other.length) {
    this->value = new char[this->length + 1];
    strcpy(this->value, other.value);
}

Number::Number(Number&& other) noexcept : value(other.value), base(other.base), length(other.length) {
    other.value = nullptr;
}

Number::~Number() {
    delete[] value;
}

Number& Number::operator=(const Number& other) {
    if (this != &other) {
        delete[] value;
        base = other.base;
        length = other.length;
        value = new char[length + 1];
        strcpy(value, other.value);
    }
    return *this;
}

Number& Number::operator=(Number&& other) noexcept {
    if (this != &other) {
        delete[] value;
        value = other.value;
        base = other.base;
        length = other.length;
        other.value = nullptr;
    }
    return *this;
}

char Number::operator[](int index) const {
    if (index >= 0 && index < length)
        return value[index];
    return '\0';
}

bool Number::operator>(const Number& other) const {
    Number temp1(*this);
    Number temp2(other);
    temp1.ConvertToBase(base);
    temp2.ConvertToBase(base);
    if (temp1.length > temp2.length)
        return true;
    else if (temp1.length < temp2.length)
        return false;
    else {
        for (int i = 0; i < temp1.length; ++i) {
            if (temp1.value[i] > temp2.value[i])
                return true;
            else if (temp1.value[i] < temp2.value[i])
                return false;
        }
    }
    return false;
}

bool Number::operator<(const Number& other) const {
    return other > *this;
}

bool Number::operator>=(const Number& other) const {
    return !(*this < other);
}

bool Number::operator<=(const Number& other) const {
    return !(*this > other);
}

bool Number::operator==(const Number& other) const {
    return base == other.base && strcmp(value, other.value) == 0;
}

Number Number::operator+(const Number& other) const {

    // baza maxima
    int maxBase = (base > other.base) ? base : other.base;
    Number temp1(*this);
    Number temp2(other);
    temp1.ConvertToBase(maxBase);
    temp2.ConvertToBase(maxBase);

    return temp1; 
}

 int Number::ConvertToDecimal() const {
    int decimalValue = 0;
    int multiplier = 1;
    for (int i = length - 1; i >= 0; --i) {
        int digitValue;
        if (isdigit(value[i])) {
            digitValue = value[i] - '0';
        } else if (isalpha(value[i])) {
            digitValue = toupper(value[i]) - 'A' + 10;
        } else {
            return 0;
        }
        decimalValue += digitValue * multiplier;
        multiplier *= base;
    }
    return decimalValue;
}

Number Number::operator-(const Number& other) const {

    // baza maxima
    int maxBase = (base > other.base) ? base : other.base;
    Number temp1(*this);
    Number temp2(other);
    temp1.ConvertToBase(maxBase);
    temp2.ConvertToBase(maxBase);

    // decimal
    int decimalValue1 = temp1.ConvertToDecimal();
    int decimalValue2 = temp2.ConvertToDecimal();

    int result = decimalValue1 - decimalValue2;

    // baza curenta
    char buffer[100];
    int length = 0;
    do {
        int remainder = result % base;
        buffer[length++] = (remainder < 10) ? (remainder + '0') : (remainder - 10 + 'A');
        result /= base;
    } while (result > 0);

    // invers
    char* newValue = new char[length + 1];
    for (int i = 0; i < length; ++i) {
        newValue[i] = buffer[length - i - 1];
    }
    newValue[length] = '\0';

    return Number(newValue, base);
}

Number& Number::operator+=(const Number& other) {

    // baza maxima
    int maxBase = (base > other.base) ? base : other.base;
    ConvertToBase(maxBase);
    Number temp(other);
    temp.ConvertToBase(maxBase);

    // decimal
    int decimalValue1 = ConvertToDecimal();
    int decimalValue2 = temp.ConvertToDecimal();

    int result = decimalValue1 + decimalValue2;

    // baza curenta
    char buffer[100];
    int length = 0;
    do {
        int remainder = result % base;
        buffer[length++] = (remainder < 10) ? (remainder + '0') : (remainder - 10 + 'A');
        result /= base;
    } while (result > 0);

    // invers
    char* newValue = new char[length + 1];
    for (int i = 0; i < length; ++i) {
        newValue[i] = buffer[length - i - 1];
    }
    newValue[length] = '\0';

    // final
    delete[] value;
    value = newValue;
    length = length;
    return *this;
}

Number& Number::operator-=(const Number& other) {
    
    // baza maxima
    int maxBase = (base > other.base) ? base : other.base;
    ConvertToBase(maxBase);
    Number temp(other);
    temp.ConvertToBase(maxBase);

    // decimal
    int decimalValue1 = ConvertToDecimal();
    int decimalValue2 = temp.ConvertToDecimal();

    int result = decimalValue1 - decimalValue2;

    // baza curenta
    char buffer[100];
    int length = 0;
    if (result < 0) {
        while (result < 0) {
            result += base;
        }
    }
    do {
        int remainder = result % base;
        buffer[length++] = (remainder < 10) ? (remainder + '0') : (remainder - 10 + 'A');
        result /= base;
    } while (result > 0);

    // invers
    char* newValue = new char[length + 1];
    for (int i = 0; i < length; ++i) {
        newValue[i] = buffer[length - i - 1];
    }
    newValue[length] = '\0';

    // final
    delete[] value;
    value = newValue;
    length = length;
    return *this;
}

Number& Number::operator--() {
    if (length > 0) {
        char* newValue = new char[length];
        std::copy(value + 1, value + length, newValue);
        newValue[length - 1] = '\0';
        delete[] value;
        value = newValue;
        length--;
    }
    return *this;
}

/// prefix
Number& Number::operator--() {
    if (length > 0) {
        char* newValue = new char[length];
        std::copy(value + 1, value + length, newValue);
        newValue[length - 1] = '\0';
        delete[] value;
        value = newValue;
        length--;
    }
    return *this;
}

/// postfix 
Number Number::operator--(int) {
    Number temp(*this);
    --(*this);
    return temp;
}

void Number::SwitchBase(int newBase) {
    if (newBase >= 2 && newBase <= 16) {
        ConvertToBase(newBase);
        base = newBase;
    }
}

void Number::ConvertToBase(int newBase) {
    // baza 10
    int decimalValue = 0;
    int multiplier = 1;
    for (int i = length - 1; i >= 0; --i) {
        int digitValue;
        if (isdigit(value[i])) {
            digitValue = value[i] - '0';
        } else if (isalpha(value[i])) {
            digitValue = toupper(value[i]) - 'A' + 10;
        } else {
            return;
        }
        decimalValue += digitValue * multiplier;
        multiplier *= base;
    }

    // convertire baza
    char* newValue = new char[length * 4];
    int index = 0;
    while (decimalValue > 0) {
        int remainder = decimalValue % newBase;
        char digitChar;
        if (remainder < 10) {
            digitChar = '0' + remainder;
        } else {
            digitChar = 'A' + (remainder - 10);
        }
        newValue[index++] = digitChar;
        decimalValue /= newBase;
    }

    // invers
    for (int i = 0; i < index / 2; ++i) {
        std::swap(newValue[i], newValue[index - i - 1]);
    }

    // val + lg
    delete[] value;
    value = new char[index + 1];
    strncpy(value, newValue, index);
    value[index] = '\0';
    length = index;

    delete[] newValue;
}

void Number::Print() const {
    std::cout << "Value: " << value << " Base: " << base << std::endl;
}

int Number::GetDigitsCount() const {
    return length;
}

int Number::GetBase() const {
    return base;
}
