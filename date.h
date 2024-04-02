#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>
using namespace std;

class Date
{
    private:
        int month;
        int day;
        int year;
    public:
        Date(string b_date);
        void print_date();
};

#endif
