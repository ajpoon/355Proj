#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>

class Date
{
    private:
        int month;
        int day;
        int year;
    public:
        Date();
        void print_date();
}