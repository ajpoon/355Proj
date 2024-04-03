#include "network.h"
#include <limits>
#include "misc.h"
#include <fstream>
#include <string>

Network::Network(){
    head = NULL;
    tail = NULL;
    count = 0;
}


Network::Network(string fileName){
    // TODO: complete this method!
    // Implement it in one single line!
    // You may need to implement the load method before this!
}

Network::~Network(){ 
}

Person* Network::search(Person* searchEntry){
    // Searches the Network for searchEntry
    // if found, returns a pointer to it, else returns NULL
    // TODO: Complete this method

    Person* curr = head;
    for(int i=0; i<count;i++){
        if(curr == NULL)
            return NULL;
        else if(curr == searchEntry){
            return curr;
        }
        else{
            curr = curr->next;
        }
    }
    return NULL;
}


Person* Network::search(string fname, string lname){
    // New == for Person, only based on fname and lname
    // if found, returns a pointer to it, else returns NULL
    // TODO: Complete this method
    // Note: two ways to implement this, 1st making a new Person with fname and lname and and using search(Person*), 2nd using fname and lname directly.
    Person* curr = head;
    for(int i=0; i<count;i++){
        if(curr == NULL)
            return NULL;
        else if(curr->f_name == fname && curr->l_name == lname){
            return curr;
        }
        else{
            curr = curr->next;
        }
    }
    return NULL;
}




void Network::loadDB(string filename){
    // TODO: Complete this method

    // read the people from the file and create a doubly linked list with info from each person
    
    Person* newPerson = new Person;

    string temp, type;
    ifstream fin(filename);
    getline(fin, temp);
    newPerson->f_name = temp;
    getline(fin, temp);
    newPerson->l_name = temp;
    getline(fin, temp);
    newPerson->birthdate = new Date(temp);
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
    newPerson->phone = new Phone(type, temp);
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
    
    head = tail = newPerson;

    
    while(getline(fin, temp)){
        Person* newPerson = new Person(filename);
        tail->next = newPerson;
        newPerson->prev = tail;
        tail = newPerson;
        
    }
    

    
}

void Network::saveDB(string filename){
    // TODO: Complete this method
    //open file with filename and then go through linked list to print info to the .txt file

    ofstream output;
    output.open(filename);

    Person* ptr = head;

    while(ptr != NULL){
        output << ptr->f_name << endl;
        output << ptr->l_name << endl;
        //output << ptr->birthdate-> << endl;
        //string phonenum = ptr.(phone.get_contact());
        //output << "(" << phonenum << ") " << endl;
        // output << "(" << curr.type << ") " << curr.phonenum << endl; 
        output << "--------------------" << endl;
        
        
        ptr = ptr->next;

    }
    
}


void Network::printDB(){
    // Leave me alone! I know how to print! 
    // Note: Notice that we don't need to update this even after adding to Personattributes
    // This is a feature of OOP, classes are supposed to take care of themselves!
    cout << "Number of people: " << count << endl;
    cout << "------------------------------" << endl;
    Person* ptr = head;
    while(ptr != NULL){
        ptr->print_person();
        cout << "------------------------------" << endl;
        ptr = ptr->next;
    }
}



void Network::push_front(Person* newEntry){
    newEntry->prev = NULL;
    newEntry->next = head;

    if (head != NULL)
        head->prev = newEntry;
    else
        tail = newEntry;
    
    head = newEntry;
    count++;
}


void Network::push_back(Person* newEntry){
    // Adds a new Person (newEntry) to the back of LL
    // TODO: Complete this method

    //check if the person exists
    Person* curr = head;

    
    while(curr != NULL){
        if(curr->next == NULL){
            curr->next = newEntry;
            newEntry->prev = curr;
            newEntry->next = NULL;
            tail = newEntry;
        }
        else{
            curr = curr->next;
        }
    }
    if(head == NULL){
        head = tail = newEntry;
    }
    
    
}


bool Network::remove(string fname, string lname){
    // TODO: Complete this method
        // need to find where the person is and then delete them
    Person* curr = head;
    for(int i = 0; i < count; i++){
        if(curr == NULL)
            return false;
        else if(curr->f_name == fname && curr->l_name == lname){
            (curr->prev)->next = curr->next;
            (curr->next)->prev = curr->prev;
            return true;
        }
        else{
            curr = curr->next;
        }
    }
    
    
}


void Network::showMenu(){
    // TODO: Complete this method!
    // All the prompts are given to you, 
    // You should add code before, between and after prompts!

    int opt;
    while(1){
        cout << "\033[2J\033[1;1H";
        printMe("banner"); // from misc library

        cout << "Select from below: \n";
        cout << "1. Save network database \n";
        cout << "2. Load network database \n";
        cout << "3. Add a new person \n";
        cout << "4. Remove a person \n";
        cout << "5. Print people with last name  \n";
        cout << "\nSelect an option ... ";
        
        if (cin >> opt) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Wrong option! " << endl;
            return;
        }
        
        // You may need these variables! Add more if you want!
        string fname, lname, fileName, bdate;
        cout << "\033[2J\033[1;1H";

        if (opt==1){
            // TODO: Complete me!
            cout << "Saving network database \n";
            cout << "Enter the name of the save file: ";
            cin >> fileName;
            
            // Save the network database into the file with the given name,
            // with each person saved in the format the save as printing out the person info,
            // and people are delimited similar to "networkDB.txt" format

            saveDB(fileName);
            cout << "Network saved in " << fileName << endl;
        }
        else if (opt==2){
            // TODO: Complete me!
            cout << "Loading network database \n";
            // TODO: print all the files in this same directory that have "networkDB.txt" format
            // print format: one filename one line.
            // This step just shows all the available .txt file to load.
            cout << "Enter the name of the load file: "; 
            cin >> fileName;
            loadDB(fileName);
            ifstream file(fileName);
            // If file with name FILENAME does not exist: 
            if (!file.is_open()) {
                cout << "File " << fileName << " does not exist!" << endl;
            }
            // If file is loaded successfully, also print the count of people in it: 
            else{
                cout << "Network loaded from " << fileName << " with " << count << " people \n";
            }
        }
        else if (opt == 3){
            // TODO: Complete me!
            // TODO: use push_front, and not push_back 
            // Add a new Person ONLY if it does not exists!
            cout << "Adding a new person \n";

            cin >> fname;
            cin >> lname;
            Person* ptr = search(fname, lname);
            if(ptr != NULL){
                push_front(ptr);
            }
        }
        else if (opt == 4){
            // TODO: Complete me!
            // if found, cout << "Remove Successful! \n";
            // if not found: cout << "Person not found! \n";
            cout << "Removing a person \n";
            cout << "First name: ";
            cin >> fname;
            cout << "Last name: ";
            cin >> lname;


            Person* ptr = search(fname, lname);
            if(ptr != NULL){
                remove(fname, lname);
                cout << "Remove Successful! \n";
            }
            else{
                cout << "Person not found! \n";
            }
        }
        else if (opt==5){
            // TODO: Complete me!
            // print the people with the given last name
            // if not found: cout << "Person not found! \n";
            cout << "Print people with last name \n";
            cout << "Last name: ";
            cin >> lname;

            Person* curr = search("", lname);

            if(curr == NULL){
                cout << "Person not found! \n";
            }
            else{
                while(curr != NULL){
                    if(curr->l_name == lname){
                        curr->print_person();
                    }
                    else{
                        curr = curr->next;
                    }
                }

                
            }
        }
        
        else
            cout << "Nothing matched!\n";
        
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "\n\nPress Enter key to go back to main menu ... ";
        string temp;
        std::getline (std::cin, temp);
        cout << "\033[2J\033[1;1H";
    }
}
