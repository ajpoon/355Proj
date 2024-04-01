
#include "person.h"

Person::Person(){
    // I'm already done! 
    set_person();
}


Person::~Person(){
    delete birthdate;
    // TODO: complete the method!
    delete email;
    delete phone;
    delete f_name;
    delete l_name;
}

Person::Person(string f_name, string l_name, string b_date, string email, string phone){
    // TODO: Complete this method!
    // phone and email strings are in full version
    this->f_name = f_name;
    this->l_name = l_name;
    birthdate = new Date(b_date); 
    string type, temp;
    for (int i = 1; i < email.length(); i++)
    {
        if (email[i] == ')')
        {
            temp = email.substr(i+2);
            break;
        }
        type += email[i];
    }
    this->email = new Email(type, temp);
    type = "";
    for (int i = 1; i < phone.length(); i++)
    {
        if (phone[i] == ')')
        {
            temp = phone.substr(i+2);
            break;
        }
        type += phone[i];
    }
    this->phone = new Phone(type, temp);

}


Person::Person(string filename){
    set_person(filename);
}


void Person::set_person(){
    // prompts for the information of the user from the terminal
    // first/last name can have spaces!
    // date format must be "M/D/YYYY"
    // We are sure user enters info in correct format.
    // TODO: complete this method!
    
    string temp;
    string type;

    cout << "First Name: ";
    // pay attention to how we read first name, as it can have spaces!
    std::getline(std::cin,f_name);

	cout << "Last Name: ";
    std::getline(std::cin,l_name);

    cout << "Birthdate (M/D/YYYY): ";
    std::getline(std::cin,temp);
    // pay attention to how we passed argument to the constructor of a new object created dynamically using new command
    birthdate = new Date(temp); 

    cout << "Type of email address: ";
    // code here
    std::getline(std::cin,type);
    
    cout << "Email address: ";
    // code here
    std::getline(std::cin,temp);
    email = new Email(type, temp);

    cout << "Type of phone number: ";
    // code here
    std::getline(std::cin,type);
    
    cout << "Phone number: ";
    // code here
    std::getline(std::cin,temp);
    phone = new Phone(type, temp)
}


void Person::set_person(string filename){
    // reads a Person from a file
    // Look at person_template files as examples.     
    // Phone number in files can have '-' or not.
    // TODO: Complete this method!
    string temp, type;
    fstream fin(filename, fstream::in);
    if (fin.is_open())
    {
        getline(fin, temp);
        f_name = temp;
        getline(fin, temp);
        l_name = temp;
        getline(fin, temp);
        birthdate = temp;
        getline(fin, temp);
        for (int i = 1; i < temp.length(); i++)
        {
            if (temp[i] == ')')
            {
                temp = temp.substr(i+2);
                break;
            }
            type += temp[i];
        }
        phone = new Phone(type, temp);
        type = "";
        getline(fin, temp);
        for (int i = 1; i < temp.length(); i++)
        {
            if (temp[i] == ')')
            {
                temp = temp.substr(i+2);
                break;
            }
            type += temp[i];
        }
        email = new Email(type, temp);
    }
    fin.close();
}


bool Person::operator==(const Person& rhs){
    // TODO: Complete this method!
    // Note: you should check first name, last name and birthday between two persons
    // refer to bool Date::operator==(const Date& rhs)
}

bool Person::operator!=(const Person& rhs){ 
    // TODO: Complete this method!
}


void Person::print_person(){
    // Already implemented for you! Do not change!
	cout << l_name <<", " << f_name << endl;
	birthdate->print_date("Month D, YYYY");
    phone->print();
    email->print();
}