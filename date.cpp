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
    string birthdate;
    if(month == 1){
        birthdate = "January " + to_string(day) + ", " + to_string(year);
    }
    else if(month == 2){
        birthdate = "February " + to_string(day) + ", " + to_string(year);
    }
    else if(month == 3){
        birthdate = "March " + to_string(day) + ", " + to_string(year);
    }
    else if(month == 4){
        birthdate = "April " + to_string(day) + ", " + to_string(year);
    }
    else if(month == 5){
        birthdate = "May " + to_string(day) + ", " + to_string(year);
    }
    else if(month == 6){
        birthdate = "June " + to_string(day) + ", " + to_string(year);
    }
    else if(month == 7){
        birthdate = "July " + to_string(day) + ", " + to_string(year);
    }
    else if(month == 8){
        birthdate = "August " + to_string(day) + ", " + to_string(year);
    }
    else if(month == 9){
        birthdate = "September " + to_string(day) + ", " + to_string(year);
    }
    else if(month == 10){
        birthdate = "October " + to_string(day) + ", " + to_string(year);
    }
    else if(month == 11){
        birthdate = "November " + to_string(day) + ", " + to_string(year);
    }
    else if(month == 12){
        birthdate = "December " + to_string(day) + ", " + to_string(year);
    }

    cout << birthdate << endl;
}