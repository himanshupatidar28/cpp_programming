#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <ios>
#include <limits>
#include <ctime>
using namespace std;

string bookfile = "book.csv";
string memberfile = "member.csv";
string transactionfile = "transaction.csv";
string all_transactionfile = "all_trans.csv";



class Operations
{
public:
    bool addData(vector<string> data, string file)
    {
        ofstream add;
        add.open(file, ios::app);
        if (1)
        {
            add << data[0];
            for (int i = 1; i < data.size(); i++)
            {
                add << "," << data[i];
            }
            add << endl;
            add.close();
            return true;
        }
        add.close();
        return false;
    }
    vector<string> getData(int id, string file)
    {
        string line, word;
        vector<string> row;
        ifstream get;
        get.open(file);
        while (getline(get, line))
        {
            stringstream s(line);

            while (getline(s, word, ','))
            {
                row.push_back(word);
            }
            if (id == stoi(row[0]))
            {
                get.close();
                return row;
            }
            row.clear();
        }
        get.close();
        return row;
    }
    bool updateData(int id, vector<string> data, string file)
    {
        vector<string> row;
        string line, word;

        ifstream db;
        ofstream temp;
        db.open(file);
        temp.open("temp.csv");
        while (getline(db, line))
        {
            stringstream s(line);
            while (getline(s, word, ','))
            {
                row.push_back(word);
            }

            if (id == stoi(row[0]))
            {
                for (int i = 1; i < row.size(); i++)
                {
                    row[i] = data[(i - 1)];
                }
            }
            addData(row, "temp.csv");
            row.clear();
        }
        temp.close();
        db.close();
        const char *str = file.c_str();
        remove(str);
        rename("temp.csv", str);
        return true;
    }
    bool deleteData(int id, string file)
    {
        vector<string> row;
        string line, word;

        ifstream db;
        ofstream temp;
        db.open(file);
        temp.open("temp.csv");
        while (getline(db, line))
        {
            stringstream s(line);
            while (getline(s, word, ','))
            {
                row.push_back(word);
            }
            if (id != stoi(row[0]))
            {
                addData(row, "temp.csv");
            }
            row.clear();
        }
        temp.close();
        db.close();
        const char *str = file.c_str();
        remove(str);
        rename("temp.csv", str);
        return true;
    }
    bool statusUpdate(int id, string status)
    {
        vector<string> data = getData(id, bookfile);
        data[3] = status;
        if (updateData(id, data, bookfile))
        {
            return true;
        }
        return false;
    }
    void displayData(string file)
    {
        vector<string> row;
        string line, word;

        ifstream db;
        db.open(file);
        while (getline(db, line))
        {
            stringstream s(line);
            while (getline(s, word, ','))
            {
                row.push_back(word);
            }
            for (int i = 0; i < row.size(); i++)
            {
                cout << row[i] << "\t\t";
            }
            cout << endl;
            row.clear();
        }
        db.close();
    }
    void displayData(int index, string input, string file)
    {
        vector<string> row;
        string line, word;

        ifstream db;
        db.open(file);
        while (getline(db, line))
        {
            stringstream s(line);
            while (getline(s, word, ','))
            {
                row.push_back(word);
            }
            if (row[index] == input)
            {
                for (int i = 0; i < row.size(); i++)
                {
                    cout << row[i] << "\t\t";
                }
                cout << endl;
            }
            row.clear();
        }
        db.close();
    }
};

class book : public Operations
{
private:
    int isbn;
    string title;
    string author;
    string status;

public:
    void addbook(void)
    {
        system("cls");
        cout << "\tADD BOOK " << endl
             << endl;
        cout << "ISBN : ";
        cin >> isbn;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Title : ";
        getline(cin, title);
        cout << "Author : ";
        getline(cin, author);
        status = "Available";
        vector<string> data;
        data.push_back(to_string(isbn));
        data.push_back(title);
        data.push_back(author);
        data.push_back(status);
        if (addData(data, bookfile))
        {
            cout << "Added Successfully" << endl;
        }
        else
        {
            cout << "ERROR" << endl;
        }
        system("pause");
    }
    void updatebook(void)
    {
        system("cls");
        cout << "\tUPDATE BOOK " << endl
             << endl;
        cout << "ISBN  to update: ";
        cin >> isbn;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Title : ";
        getline(cin, title);
        cout << "Author : ";
        getline(cin, author);
        status = 'A';
        vector<string> data;
        data.push_back(to_string(isbn));
        data.push_back(title);
        data.push_back(author);
        data.push_back(status);
        if (updateData(isbn, data, bookfile))
        {
            cout << "Updated Successfully" << endl;
        }
        else
        {
            cout << "ERROR" << endl;
        }
        system("pause");
    }
    void deleteBook(void)
    {
        system("cls");
        cout << "\tDELETE BOOK " << endl
             << endl;
        cout << "ISBN  to Delete: ";
        cin >> isbn;
        if (deleteData(isbn, bookfile))
        {
            cout << "Deleted Successfully" << endl;
        }
        else
        {
            cout << "ERROR" << endl;
        }
        system("pause");
    }
    void searchbook(void)
    {
        system("cls");
        cout << "\tSEARCH BOOK " << endl
             << endl;
        cout << "ISBN  to Search: ";
        cin >> isbn;
        vector<string> data = getData(isbn, bookfile);
        cout << "ISBN : " << data[0] << endl;
        cout << "Title : " << data[1] << endl;
        cout << "Author : " << data[2] << endl;

        system("pause");
    }
    void displaybook(void)
    {
        system("cls");
        cout << "\t ALL BOOKS" << endl
             << endl;
        cout << "ISBN\t Title\t\t Author\t Status" << endl
             << "--------------------------------------------------------------------------------" << endl;
        displayData(bookfile);
        system("pause");
    }
};
class member : public Operations
{
private:
    int id;
    string name;
    string desc;
    string contact;

public:
    void addmember(void)
    {
        system("cls");
        cout << "\tADD MEMBER " << endl
             << endl;
        cout << "User ID : ";
        cin >> id;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "name : ";
        getline(cin, name);
        cout << "Description : ";
        getline(cin, desc);
        cout << "Contact : ";
        getline(cin, contact);

        vector<string> data;
        data.push_back(to_string(id));
        data.push_back(name);
        data.push_back(desc);
        data.push_back(contact);
        if (addData(data, memberfile))
        {
            cout << "Added Successfully" << endl;
        }
        else
        {
            cout << "ERROR" << endl;
        }
        system("pause");
    }
    void updatemember(void)
    {
        system("cls");
        cout << "\tUPDATE MEMBER " << endl
             << endl;
        cout << "User ID to Update : ";
        cin >> id;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "name : ";
        getline(cin, name);
        cout << "Description : ";
        getline(cin, desc);
        cout << "Contact : ";
        getline(cin, contact);

        vector<string> data;
        data.push_back(to_string(id));
        data.push_back(name);
        data.push_back(desc);
        data.push_back(contact);
        if (updateData(id, data, memberfile))
        {
            cout << "Updated Successfully" << endl;
        }
        else
        {
            cout << "ERROR" << endl;
        }
        system("pause");
    }
    void deletemember(void)
    {
        system("cls");
        cout << "\tDELETE MEMBER " << endl
             << endl;
        cout << "User ID to delete : ";
        cin >> id;
        if (deleteData(id, memberfile))
        {
            cout << "Deleted Successfully" << endl;
        }
        else
        {
            cout << "ERROR" << endl;
        }
        system("pause");
    }
    void searchmember(void)
    {
        system("cls");
        cout << "\tSEARCH MEMBER " << endl
             << endl;
        cout << "Id to Search: ";
        cin >> id;
        vector<string> data = getData(id, memberfile);
        cout << "ISBN : " << data[0] << endl;
        cout << "Title : " << data[1] << endl;
        cout << "Author : " << data[2] << endl;

        system("pause");
    }
    void displaymember(void)
    {
        system("cls");
        cout << "\t ALL MEMBERS" << endl
             << endl;
        cout << "ID\t Name\t Description\t Contact" << endl
             << "--------------------------------------------------------------------------------" << endl;
        displayData(memberfile);
        system("pause");
    }
};
class transaction : public Operations
{
private:
    int bookid;
    string type;
    int userid;
    int pay = 0;
    string date;

public:
    void book_transaction(int a)
    {
        system("cls");
        cout << "\tBOOK TRANSACTION " << endl
             << endl;
        vector<string> data;
        time_t now = time(0);
        char *t = ctime(&now);
        date = t;
        cout << "ISBN : ";
        cin >> bookid;
        cout << "Member ID : ";
        cin >> userid;
        if (a == 1)
        {
            type = "Issue";
        }
        else if (a == 2)
        {
            type = "Return";
            cout << "Fine Amount : ";
            cin >> pay;
        }
        else if (a == 3)
        {
            type = "Payment";
            cout << "Pay Amount : ";
            cin >> pay;
        }
        data.push_back(to_string(bookid));
        data.push_back(type);
        data.push_back(to_string(userid));
        data.push_back(to_string(pay));
        data.push_back(date);

        if (a == 1 || a == 3)
        {
            if (addData(data, transactionfile))
            {
                addData(data, all_transactionfile);
                if (statusUpdate(bookid, type))
                {
                    cout << "Transaction Completed" << endl;
                }
            }
        }
        else if (a == 2)
        {
            if (deleteData(bookid, transactionfile))
            {
                addData(data, all_transactionfile);
                if (statusUpdate(bookid, "Available"))
                {
                    cout << "Transaction Completed" << endl;
                }
            }
        }
        else
        {
            cout << "ERROR.." << endl;
        }
        system("pause");
    }
    void allTransactions(int input)
    {
        system("cls");
        // input = 1 for all, 2 for Issue, 3 for Payment, 4 for user report
        int index;
        if (input == 1)
        {
            cout << "\t TRANSACTION HISTORY" << endl
                 << endl;
            cout << "ISBN\t Type\t Member ID\t Pay \t\t Date" << endl
             << "--------------------------------------------------------------------------------" << endl;
            displayData(all_transactionfile);
        }
        else if (input == 2)
        {
            cout << "\t DUE BOOKS" << endl
                 << endl;
            cout << "ISBN\t Type\t Member ID\t Pay \t\t Date" << endl
             << "--------------------------------------------------------------------------------" << endl;
            index = 1; // type index in data strucure
            displayData(index, "Issue", transactionfile);
        }
        else if (input == 3)
        {
            cout << "\t PAYMENTED BOOKS" << endl
                 << endl;
            cout << "ISBN\t Type\t Member ID\t Pay \t\t Date" << endl
             << "--------------------------------------------------------------------------------" << endl;
            index = 1;
            displayData(index, "Payment", transactionfile);
        }
        else if (input == 4)
        {
            cout << "\t MEMBER PROFILE" << endl
                 << endl;
            index = 2;
            cout << "\nEnter Member ID : ";
            cin >> userid;
            vector<string> user = getData(userid, memberfile);
            cout << "\nUser ID : " << user[0] << endl
                 << "Name : " << user[1] << endl
                 << "Description : " << user[2] << endl
                 << "Contact : " << user[3] << endl
                 << endl;
            cout << "Books Transaction :- " << endl;
            cout << "ISBN\t Type\t Member ID\t Pay \t\t Date" << endl
             << "--------------------------------------------------------------------------------" << endl;
            displayData(index, to_string(userid), transactionfile);
        }
        else
        {
            cout << "ERROR" << endl;
        }
        system("pause");
    }
};
class admin : public book, public member, public transaction
{
private:
    string id = "Admin";
    string password = "Librarian";

public:
    bool login(void)
    {
        string inID, inPass;
        cout << "\tAdmin ID : ";
        cin >> inID;
        cout << "\tPassword : ";
        cin >> inPass;
        if (inID == id && inPass == password)
        {
            return true;
        }
        return false;
    }
    void manageBook(void)
    {
        int choice;
        system("cls");
        cout << "\t MANAGE BOOKS" << endl
             << endl;
        cout << "\t1 Add Book" << endl
             << "\t2 Delete Book" << endl
             << "\t3 Update Book" << endl
             << "\t4 Search Book" << endl
             << "\t0 Back" << endl
             << "\tEnter Choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            addbook();
            break;
        case 2:
            deleteBook();
            break;
        case 3:
            updatebook();
            break;
        case 4:
            searchbook();
            break;

        default:
            break;
        }
    }
    void manageMember(void)
    {
        system("cls");
        int choice;
        cout << "\t MANAGE MEMBERS" << endl
             << endl;
        cout << "\t1 Add Member" << endl
             << "\t2 Delete Member" << endl
             << "\t3 Update Member" << endl
             << "\t4 Search Member" << endl
             << "\t0 Back" << endl
             << "\tEnter Choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            addmember();
            break;
        case 2:
            deletemember();
            break;
        case 3:
            updatemember();
            break;
        case 4:
            searchmember();
            break;
        default:
            break;
        }
    }
    void iss_ret_Book(void)
    {
        system("cls");
        int choice;
        cout << "\tBOOK TRANSACTION" << endl
             << endl;
        cout << "\t1 Issue Book" << endl
             << "\t2 Return Book" << endl
             << "\t3 Payment Book" << endl
             << "\t0 Back" << endl
             << "\tEnter Choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            book_transaction(choice);
            break;
        case 2:
            book_transaction(choice);
            break;
        case 3:
            book_transaction(choice);
            break;
        default:
            break;
        }
    }
    void reports(void)
    {
        system("cls");
        int choice;
        cout << "\t REPORTS" << endl
             << endl;
        cout << "\t1 All Books" << endl
             << "\t2 All Members" << endl
             << "\t3 All Transactions" << endl
             << "\t4 Due Books" << endl
             << "\t5 Paymented Books" << endl
             << "\t6 Search Member Profile" << endl
             << "\t0 Back" << endl
             << "\tEnter Choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            displaybook();
            break;
        case 2:
            displaymember();
            break;
        case 3:
            allTransactions(1); // all
            break;
        case 4:
            allTransactions(2); // due
            break;
        case 5:
            allTransactions(3); // payment
            break;
        case 6:
            allTransactions(4); // user profile
            break;
        default:
            break;
        }
    }
} admin;

int main()
{
    int choice = 0;
    cout << "**************************************************************" << endl
         << "\t\t LIBRARY MANAGEMENT SYSTEM" << endl
         << "**************************************************************" << endl
         << endl;

    if (admin.login())
    {
        while (choice < 5)
        {
            system("cls");
            cout << "**************************************************************" << endl
                 << "\t\t LIBRARY MANAGEMENT SYSTEM" << endl
                 << "**************************************************************" << endl
                 << endl;
            cout << "\t1 Book Management" << endl
                 << "\t2 Member Management" << endl
                 << "\t3 Book Transaction" << endl
                 << "\t4 Reports" << endl
                 << "\t0 Exit" << endl
                 << "\tEnter Choice : ";
            cin >> choice;
            switch (choice)
            {
            case 1:
                admin.manageBook();
                break;
            case 2:
                admin.manageMember();
                break;
            case 3:
                admin.iss_ret_Book();
                break;
            case 4:
                admin.reports();
                break;

            default:
                system("pause");
                return 0;
                break;
            }
        }
    }

    return 0;
}