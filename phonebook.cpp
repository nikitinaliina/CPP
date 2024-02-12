#include<iostream>
#include<string>
#include<vector>

using namespace std;

int Menu();

class Contact
{
    public:
    Contact(const string& name, 
            const string& surname, 
            const string& number);

    void setName(const string& name) { m_name = name; }
    const string& getName() const {return m_name; }

    void setSurname(const string& surname) {m_surname = surname; }
    const string& getSurname() const { return m_surname; }

    void setNumber(const string& number) { m_number = number; }
    const string& getNumber() const {return m_number; }
                        
    void display() const
    {
        cout << "Contact: " << getName() << ' ' << getSurname() << endl;
        cout << "Phonenumber: " << getNumber() << endl;
    }
   
    private:
    string m_name;
    string m_surname;
    string m_number;

};

int main()
{
    vector<Contact>phonebook;

    
    while (true) {
        int choice {Menu()};
        switch(choice) 
        {
            case 1:
            {
            string name, surname, number;
            cout << "Enter Name" << endl;
            cin >> name;
            cout << "Enter Surname" << endl;
            cin >> surname;
            cout << "Enter Number" << endl;
            cin >> number;
            phonebook.push_back(Contact(name, surname, number));
            cout << "Contact added succesfully!" << endl;
            break;
            }
          
            case 2: 
            {
                cout << "Contact in Phonebook: " << endl;
                    for (const Contact& contact : phonebook)
                        {
                            contact.display();
                        }
                        break;
            }
            case 3:
            return 0;
            default:
                cout << "Invalid choice. Try again!" << endl;                  
    
        }
    }
return 0;
    
}

int Menu()
{
    int choice;
    cout << "Phonebook Menu" << endl;
    cout << "1. Add Contact" << endl;
    cout << "2. Display Contact" << endl;
    cout << "3. Edit Contact" << endl;
    cout << "4. Display All Contacts" << endl;
    cout << "5. Delete Contact" << endl;
    cout << "6. Exit" << endl;
    cin >> choice;
    return choice;
}