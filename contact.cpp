
#include "contact.h"
// TODO: Add needed libraries!

Email::Email(string type, string email_addr){
    // TODO: Complete me!
    this->type = type;
    this->email_addr = email_addr;
}


void Email::set_contact(){
    // TODO: Do not change the prompts!
	
    cout << "Enter the type of email address: ";
    // some code here
    cin >> type;
    cout << "Enter email address: ";
    // some code here
    cin >> email_addr;
}


string Email::get_contact(string style){
    // Note: We have default argument in declaration and not in definition!
    if (style=="full")
	    return "(" + type + ") " + email_addr;
    else 
        return email_addr;
}


void Email::print(){
    // Note: get_contact is called with default argument
	cout << get_contact() << endl;
}


Phone::Phone(string type, string num){
    // TODO: It is possible that num includes "-" or not, manage it!
    // TODO: Complete this method!
    // Note: We don't want to use C++11! stol is not valid!
    // 650-288-9281
    this->type = type;
    if (num[3] == '-' && num[7] == '-')
    {
        phone_num = num;
    }
    else
    {
        string num_format;
        for (int i = 0; i < num.length(); i++)
        {
            if (i == 3 || i == 6)
            {
                num_format += "-";
            }
            num_format += num[i];
        }
        phone_num = num_format;
    }
}


void Phone::set_contact(){
    // TODO: Complete this method
    // Use the same prompts as given!
	cout <<"Enter the type of phone number: ";
    cin >> type;
    string num;
	cout << "Enter the phone number: ";
    cin >> num;
    if (num[3] == '-' && num[7] == '-')
    {
        phone_num = num;
    }
    else
    {
        string num_format;
        for (int i = 0; i < num.length(); i++)
        {
            if (i == 3 || i == 6)
            {
                num_format += "-";
            }
            num_format += num[i];
        }
        phone_num = num_format;
    }
}


string Phone::get_contact(string style){
    // TODO: Complete this method, get hint from Email 
    if (style=="full")
	    return "(" + type + ") " + phone_num;
    else 
        return phone_num;
}


void Phone::print(){
    // Note: get_contact is called with default argument
	cout << get_contact() << endl;
}
