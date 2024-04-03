
#include "date.h"

Date::Date(string b_date){
    string str_month = "";
    string str_day = "";
    string str_year = "";

    int cycle = 0;

    for(int i = 0; i < b_date.length(); i++){
        if(b_date[i] == '/'){
            cycle++;
        }
        else{
            if(cycle == 0){
                str_month = str_month + b_date[i];
            }
            if(cycle == 1){
                str_day = str_day + b_date[i];
            }
            if(cycle == 2){
                str_year = str_year + b_date[i];
            }
        }
    }

    month = stoi(str_month);
    day = stoi(str_day);
    year = stoi(str_year);
}

void Date::print_date(){

    if(month == 1){
        strbirth = "January " + to_string(day) + ", " + to_string(year);
    }
    else if(month == 2){
        strbirth = "February " + to_string(day) + ", " + to_string(year);
    }
    else if(month == 3){
        strbirth = "March " + to_string(day) + ", " + to_string(year);
    }
    else if(month == 4){
        strbirth = "April " + to_string(day) + ", " + to_string(year);
    }
    else if(month == 5){
        strbirth = "May " + to_string(day) + ", " + to_string(year);
    }
    else if(month == 6){
        strbirth = "June " + to_string(day) + ", " + to_string(year);
    }
    else if(month == 7){
        strbirth = "July " + to_string(day) + ", " + to_string(year);
    }
    else if(month == 8){
        strbirth = "August " + to_string(day) + ", " + to_string(year);
    }
    else if(month == 9){
        strbirth = "September " + to_string(day) + ", " + to_string(year);
    }
    else if(month == 10){
        strbirth = "October " + to_string(day) + ", " + to_string(year);
    }
    else if(month == 11){
        strbirth = "November " + to_string(day) + ", " + to_string(year);
    }
    else if(month == 12){
        strbirth = "December " + to_string(day) + ", " + to_string(year);
    }

    cout << strbirth << endl;
}

string Date::get_date(){
    return strbirth;
}

int Date::get_month()
{
    return month;
}

int Date::get_day()
{
    return day;
}

int Date::get_year()
{
    return year;
}
