#include<iostream>
#include<string>
#include<vector>



int Menu();

class Contact
{
    public:
    Contact(const std::string& name, 
            const std::string& surname, 
            const std::string& number) 
            {setName(name);
            setSurname(surname);
            setNumber(number);}
            

    void setName(const std::string& name) { m_name = name; }
    const std::string& getName() const {return m_name; }

    void setSurname(const std::string& surname) {m_surname = surname; }
    const std::string& getSurname() const { return m_surname; }

    void setNumber(const std::string& number) { m_number = number; }
    const std::string& getNumber() const {return m_number; }
                        
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

Contact full_input();
std::vector<std::string> user_name_surname();


int main()
{
    std::vector<Contact>phonebook;
    bool done {false};   
    while (!done) 
    {
        int choice = Menu();
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
                        contact_found = true;
                        std::vector<Contact>::iterator i;
                        *i = contact;
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