#ifndef STROKA_H
#define STROKA_H

#include <iostream>
using namespace std;

class Stroka {
private:
    char* str;
    int length;

public:
    Stroka();
    Stroka(const char* s);
    Stroka(const Stroka& s);
    Stroka(int size);
    ~Stroka();

    Stroka& operator=(const Stroka& s);
    Stroka operator+(const Stroka& s) const;
    int operator==(const Stroka& s) const;

    int dlinia() const;
    const char* c_str() const { return str; }

    friend ostream& operator<<(ostream& os, const Stroka& s);
    friend istream& operator>>(istream& is, Stroka& s);
};

#endif