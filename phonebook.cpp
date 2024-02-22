#include<iostream>
#include<string>
#include<vector>

// I can't add comments on GitHub for some reason (maybe it only works with pull requests?)
// so I'll make some *actual* comments in the code itself.


int Menu();


// It's good practice to add a brief comment at the beginning of each class, to describe the
// purpose of the class, why we need it and what role it serves in the software

// As an example:
// This class models a single entry in the Phonebook's database. It's mainly used for contacts
// handling and contact's information storage
class Contact
{
    public:

    // It's good practice to give each class its own pair of files:
    // in this case I would expect a contact.h file with the class definition
    // and a contact.cpp file with the functions' bodies, including constructors.
    Contact(const std::string& name, 
            const std::string& surname, 
            const std::string& number) 
            {setName(name);
            setSurname(surname);
            setNumber(number);}
            
    // Using setters and getters for private members is ok, but it promotes a coding style
    // that is more verbose and slightly more difficult to read.
    // It looks like a so called POJO (Plain Old Java Object), which is not a style that we normally use
    // in C++. This is an advanced topic that requires a lot of experience and finesse to find the right
    // balance between strict encapsulation and code brevity. That said, when in doubt, always encapsulate, 
    // because it's the safer choice.
    void setName(const std::string& name) { m_name = name; }
    const std::string& getName() const {return m_name; }

    void setSurname(const std::string& surname) {m_surname = surname; }
    const std::string& getSurname() const { return m_surname; }

    void setNumber(const std::string& number) { m_number = number; }
    const std::string& getNumber() const {return m_number; }

    // The function display() is a function that does nothing, "functionally speaking".
    // It's only purpose is determined by it's console output, which is technically a side effect.
    // What do I mean by side effect? Something that occurs outside of the object's itself.
    // display() doesn't have a return value, and it doesn't modify the object in any way (because it's const)
    // Any other action other than those two things is considered a side effect.

    // The best practice here would be to create another class whose only responsibility would be the 
    // user interaction: printing text and reading inputs.
    // This hypotetical new class could then be used to display our Contacts like this:
    // UserInterface::display(myContact);
    // where the function void display(const Contact&) is a static function (more on that in the book)                    
    void display() const
    {
        std::cout << "Contact: " << getName() << ' ' << getSurname() << std::endl;
        std::cout << "Phonenumber: " << getNumber() << std::endl;
    }
   
    private:
    std::string m_name;
    std::string m_surname;
    std::string m_number;

};

// These two should be part of the UserInterface class
Contact full_input();
std::vector<std::string> user_name_surname();
// ... also, returning a "partial" Contact (without the number) is a better option here, because it keeps a
// clear connection between each of the strings and its meaning. 
// What is the meaning of the first string here? And what about the second one? is there a third string?
// All those questions can turn into bugs very easily in a large program.

int main()
{
    // The phone book should have its own class and functions
    std::vector<Contact>phonebook;
    bool done {false};   

    // Here we have a mixture of phonebook functions and user interface functions mixed together.
    // We should try to separate those two things with functions like: Phonebook.add() and userInterface::inputNewContact(),
    // UserInterface::displayMainMenu(), ::displaySearchMenu(), ::handleMainMenuChoice(), etc....
    // (or something like that, it's just a quick suggestion, there could be better ways to do the same thing).
    while (!done) 
    {
        int choice = Menu();

        // What do 1, 2, 3, etc... mean?
        // We should define some constants to make our code easier to read. Example:
        // enum class MainMenuChoice : int
        // {
        //     Add,
        //     Search,
        //     Update,
        //     List,
        //     Delete,
        //     Exit
        // };

        // then we can use things like

        // UserInterface::displayMainMenu();
        // UserInterface::handleMainMenuChoice();

        // and inside UserInterface::handleMainMenuChoice() we can have

        // int rawInput;
        // cin >> rawInput;
        // MainMenuChoice choice = static_cast<MainMenuChoice>(rawInput);

        // switch (choice)
        // {
        //     case MainMenuChoice::Add:
        //         ....
        //     case MainMenuChoice::Search:
        //         ....
        //         etc...
        // }

        switch(choice) 
        {
            
            case 1:
            {
                Contact contact = full_input();
                phonebook.push_back(contact);
                std::cout << "Contact added succesfully!" << std::endl;
                break;
            }
            case 2: 
            {
                // Re: What is the meaning of the first string here? And what about the second one? is there a third string?
                // All those questions can turn into bugs very easily in a large program.
                std::vector<std::string> user = user_name_surname();
                std::string name = user[0];
                std::string surname = user[1];
              
                std::cout << "Contact in Phonebook: " << std::endl;
                bool contact_found {false};
                    for (const auto& contact : phonebook)
                        {
                            if (contact.getName() == name && contact.getSurname() == surname)
                            {
                                contact_found = true;
                                contact.display();
                                break;
                            }
  
                        }
                        if (contact_found == false)
                        {
                            std::cout << "No contact found !" << std::endl;
                        }
                break;            
            }
            case 3:
            {
                std::vector<std::string> user = user_name_surname();
                std::string name = user[0];
                std::string surname = user[1];
                bool contact_found {false};
                    for (auto& contact : phonebook)
                        {
                            if (contact.getName() == name && contact.getSurname() == surname)
                            contact_found = true;
                            {
                                // Nested menus... another reason to wrap every menu in its own function within
                                // a dedicated class
                                contact.display();
                                int select;
                                std::cout << "Choose update: " << std::endl;
                                std::cout << "1. Update Name" << std::endl;
                                std::cout << "2. Update Surname" << std::endl;
                                std::cout << "3. Update Number" << std::endl;
                                std::cin >> select;

                                switch(select)
                                {
                            case 1:
                                {
                                    std::string new_name;
                                    std::cout << "Insert new name" << std::endl;
                                    std::cin >> new_name;
                                    contact.setName(new_name);
                                    break;
                                }
                            case 2:
                                {
                                    std::string new_surname;
                                    std::cout << "Insert new surname" << std::endl;
                                    contact.setSurname(new_surname);
                                    break;
                                }
                            case 3:
                                {
                                    std::string new_number;
                                    std::cout << "Insert new number" << std::endl;
                                    contact.setNumber(new_number);
                                    break;
                                }
                                case 4:
                                return 0;
                                default:
                                std::cout << "Invalid choice. Try again!" << std::endl; 
                                }
                
                            }
                            if (contact_found == false)
                            {
                                std::cout << "No contact found !" << std::endl;
                            }

                        }
                break;
            }
            
            case 4:
            {
                for (auto& contact : phonebook)
                {
                    contact.display();   
                }
                break;
            }
            case 5:
            {
                bool contact_found {false};
                std::vector<std::string> user = user_name_surname();
                std::string name = user[0];
                std::string surname = user[1];
                
                for (auto& contact : phonebook)
                
                {
                    if (contact.getName() == name && contact.getSurname() == surname) 
                    {
                        // This code is very nested... try to stay under 4 levels of nesting for/if/switch/while loops
                        // Create more functions and put them into suitable classes to break up the nesting into
                        // smaller pieces of code. Smaller functions are easier to read and to debug.
                        contact_found = true;
                        std::vector<Contact>::iterator i;
                        *i = contact;
                        // Can't you just call phonebook.erase(contact) here or am I missing something?
                        phonebook.erase(i); 
                    if (contact_found == false)
                    {
                        std::cout << "No contact found !" << std::endl;
                    }
                    
                    }    
                }    
                
            break;
            }    
            case 6:
                done = true;
                break;
            default:
                std::cout << "Invalid choice. Try again!" << std::endl;                  
            
        }
    }
    

    return 0;
    
}

Contact full_input()
{
    std::string name, surname, number;
    std::cout << "Enter Name" << std::endl;
    std::cin >> name;
    std::cout << "Enter Surname" << std::endl;
    std::cin >> surname;
    std::cout << "Enter Number" << std::endl;
    std::cin >> number;
    Contact a {name, surname, number};
    return a;    
}

std::vector<std::string> user_name_surname()
{
    std::vector<std::string> user_name_surname;
    std::string n;
    std::string s;
    std::cout << "Enter a name and a surname" << std::endl;
    std::cin >> n >> s;
    user_name_surname.push_back(n);
    user_name_surname.push_back(s);
    return user_name_surname;
}

int Menu()
{
    int choice;
    std::cout << "Phonebook Menu" << std::endl;
    std::cout << "1. Add Contact" << std::endl;
    std::cout << "2. Display Contact" << std::endl;
    std::cout << "3. Edit Contact" << std::endl;
    std::cout << "4. Display All Contacts" << std::endl;
    std::cout << "5. Delete Contact" << std::endl;
    std::cout << "6. Exit" << std::endl;
    std::cin >> choice;
    return choice;
}