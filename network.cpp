#include "network.h"
#include <limits>
#include "misc.h"
#include <fstream>

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
            return &curr;
        }
        else{
            curr = curr->next;
        }
    }

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
        else if(curr.fname == fname && curr.lname == lname){
            return &curr;
        }
        else{
            curr = curr->next;
        }
    }
}




void Network::loadDB(string filename){
    // TODO: Complete this method

    // read the people from the file and create a doubly linked list with info from each person
    ifstream file(filename);

    Person* curr = head;

    string firstname = '';

    while(getline(file, firstname)){
        string sa = '';
        if(count == 0){
            Person* head = new Person();
            string fname = firstname;
            getline(file, sa);
            string lname = sa;
            getline(file, sa);
            string date = sa;
            getline(file, sa);
            string email = sa;
            getline(file, sa);
            string phone = sa;
            head(fname, lname, date, email, phone);
            count++
            getline(file, sa); // gets the dashed line
            head->prev = NULL;
            head->next = NULL;
        }
        else{
            Person* newone = new Person();
            string fname = firstname;
            getline(file, sa);
            string lname = sa;
            getline(file, sa);
            string date = sa;
            getline(file, sa);
            string email = sa;
            getline(file, sa);
            string phone = sa;
            newone(fname, lname, date, email, phone);
            count++
            Person* curr = head;
            Person* curr = pprev;
            for(int i = 0; i < count; i++){
                pprev = curr;
                curr = curr->next;
            }
            newone = curr;
            newone->prev = pprev;
            newone->next = NULL;
        }
    }
}

void Network::saveDB(string filename){
    // TODO: Complete this method
    //open file with filename and then go through linked list to print info to the .txt file
    //check that this is really the variable names and how you access the variables in the person class

    ofstream output;
    output.open(filename);

    Person* curr = head;

    for(int i = 0; i < count; i++){
        if(curr == NULL){
            break;
        }
        else{
            output << curr.f_name << endl;
            output << curr.l_name << endl;
            output << curr.birthdate << endl;
            output << "(" << curr.type << ") " << curr.email << endl;
            output << "(" << curr.type << ") " << curr.phonenum << endl; 
            output << "--------------------" << endl;
        }
        
        curr = curr->next;

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
    curr = head;

    if (head == NULL){
        push_front(newEntry);
        break;
    }
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


bool Network::remove(string fname, string lname){
    // TODO: Complete this method
        // need to find where the person is and then delete them
    Person* curr = head;
    if(curr == NULL)
        return NULL;
    else if(curr.fname == fname && curr.lname == lname){
        (curr->prev)->next = curr->next;
        (curr->next)->prev = curr->prev;
    }
    else{
        curr = curr->next;
    }
        
        // need to figure out the right time to delete curr too
    delete curr;
    
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
            loadDB(filename);
            // If file with name FILENAME does not exist: 
            if (!outputFile.is_open()) {
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
            int track = 1;
            Person* curr = head;
            for(int i = 0; i < count; i++){
                if(curr = Person){
                    break;
                }
                else{
                    curr = curr->next;
                }
            }

            if(track == count){
                cout << "Adding a new person \n";
                push_front(Person);
            }
        }
        else if (opt == 4){
            // TODO: Complete me!
            // if found, cout << "Remove Successful! \n";
            // if not found: cout << "Person not found! \n";
            cout << "Removing a person \n";
            cout << "First name: ";
            fname = Person->f_name
            cout << fname;
            cout << "Last name: ";
            lname = Person->l_name
            cout << lname;
            if(remove(fname, lname)){
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
            Person* curr = head;
            if(curr == NULL){
                cout << "Person not found! \n";
            }
            else{
                if(curr.lname == lname){
                    cout << curr.f_name << endl;
                    cout << curr.l_name << endl;
                    cout << curr.birthdate << endl;
                    cout << "(" << curr.type << ") " << curr.email << endl;
                    cout << "(" << curr.type << ") " << curr.phonenum << endl; 
                }
                else{
                    curr = curr->next;
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
