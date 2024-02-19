#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
using namespace std;

class contact
{
private:
    string fname;
    string desc;
    string mobile;
    string tel;
    string address;

public:
    void displayAll(void)
    {
        system("cls");
        string line, data;
        vector<string> row;
        cout << "PHONE BOOK " << endl
             << endl;

        ifstream file;
        file.open("contact.csv");

        while (getline(file, line))
        {
            stringstream s(line);

            while (getline(s, data, ','))
            {
                row.push_back(data);
            }

            cout << "Name : " << row[0] << endl
                 << "Desc : " << row[1] << endl
                 << "Mob : " << row[2] << "\tTel : " << row[3] << endl
                 << "Address : " << row[4] << endl
                 << endl;

            row.clear();
        }

        file.close();
        system("pause");
    }
    vector<string> search(string input)
    {
        string line, data;
        vector<string> row, notfound;

        ifstream file;
        file.open("contact.csv");

        while (getline(file, line))
        {
            stringstream s(line);

            while (getline(s, data, ','))
            {
                row.push_back(data);
            }

            if (row[0] == input)
            {
                file.close();
                return row;
            }

            row.clear();
        }

        file.close();
        row.push_back("not found");
        return row;
    }
    void searchDisplay(void)
    {
        system("cls");
        string input;
        cout << "SEARCH CONTACT :" << endl
             << endl;
        cout << "Search Input (Name) : ";
        cin >> input;

        vector<string> data = search(input);
        if (data[0] == "not found")
        {
            cout << "\nNot Found" << endl;
        }
        else
        {
            cout << "\nName : " << data[0] << endl
                 << "Desc : " << data[1] << endl
                 << "Mob : " << data[2] << "\tTel : " << data[3] << endl
                 << "Address : " << data[4] << endl
                 << endl;
        }

        data.clear();
        system("pause");
    }
    bool addData(void)
    {
        contact c1;
        system("cls");
        cout << "ADD CONATCT :" << endl
             << endl;
        cout << "Name : ";
        cin >> c1.fname;
        cout << "Description : ";
        cin >> c1.desc;
        cout << "Mobile No. : ";
        cin >> c1.mobile;
        cout << "Tel. : ";
        cin >> c1.tel;
        cout << "Address : ";
        cin >> c1.address;

        ofstream file;
        if (c1.mobile != "")
        {
            file.open("contact.csv", ios::app);
            file << c1.fname << "," << c1.desc << "," << c1.mobile << "," << c1.tel << "," << c1.address << endl;
            file.close();
            return true;
        }
        return false;
    }
    bool deleteData(void)
    {
        system("cls");
        string line, data, input;
        vector<string> row;
        cout << "DELETE CONTACT " << endl
             << endl;
        cout << "Enter Name to delete contact : ";
        cin >> input;

        ifstream file;
        file.open("contact.csv");
        ofstream del;
        del.open("temp.csv", ios::app);
        while (getline(file, line))
        {
            stringstream s(line);

            while (getline(s, data, ','))
            {
                row.push_back(data);
            }

            if (row[0] == input)
            {
            }
            else
            {
                del << row[0] << "," << row[1] << "," << row[2] << "," << row[3] << "," << row[4] << endl;
            }

            row.clear();
        }
        del.close();
        file.close();
        remove("contact.csv");
        rename("temp.csv", "contact.csv");
        return true;
    }
} c1;

int main()
{
    int choice = 0;
    while (choice < 5)
    {
        system("cls");

        cout << "***************************************************" << endl
             << "\t\tCONTACT BOOK" << endl
             << "***************************************************\n"
             << endl;

        cout << "1. View All Contact" << endl
             << "2. Search Contact" << endl
             << "3. Add Contact" << endl
             << "4. Delete" << endl
             << "0. Exit" << endl;
        cout << "Enter Choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            c1.displayAll();
            break;
        case 2:
            c1.searchDisplay();
            break;
        case 3:
            if (c1.addData())
            {
                cout << "Conatct Added Successfuly.." << endl;
                system("pause");
            }
            else
            {
                cout << "Error....Try Again." << endl;
            }
            break;
        case 4:
            if (c1.deleteData())
            {
                cout << "Conatct Deleted Successfuly.." << endl;
                system("pause");
            }
            else
            {
                cout << "Error....Try Again." << endl;
            }
            break;

        default:
            system("pause");
            return 0;
            break;
        }
    }
    system("pause");
    return 0;
}