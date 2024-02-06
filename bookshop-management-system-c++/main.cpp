#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class book
{
private:
    int bookid;
    char booktitle[34];
    char author[25];
    int quantity;
    int price;

public:
    void deleteBook(void)
    {
        book delBook;
        int tempid, tempidcnf;
        cout << "\t\tDELETE BOOK FORM" << endl;
        cout << "Enter book id : ";
        cin >> tempid;
        cout << "Confirm book id : ";
        cin >> tempidcnf;
        if (tempid == tempidcnf)
        {
            ifstream bookfromfile;
            bookfromfile.open("books.dat");
            ofstream boooktofile;
            boooktofile.open("temp.dat");
            while (bookfromfile.read((char *)&delBook, sizeof(delBook)))
            {

                if (delBook.bookid == tempidcnf)
                {
                }
                else
                {
                    boooktofile.write((char *)&delBook, sizeof(delBook));
                }
            }
            boooktofile.close();
            bookfromfile.close();

            bookfromfile.open("temp.dat");
            boooktofile.open("books.dat");
            while (bookfromfile.read((char *)&delBook, sizeof(delBook)))
            {
                boooktofile.write((char *)&delBook, sizeof(delBook));
            }
            boooktofile.close();
            bookfromfile.close();
        }
        else
        {
            cout << "Something Went Wrong !! Please Check Book id..";
        }
    }
    void addBook(void)
    {
        book add_book;
        cout << "\t\tADD BOOK FORM" << endl;
        cout << "Enter Book id : ";
        cin >> add_book.bookid;
        cout << "Enter Book Title : ";
        cin >> add_book.booktitle;
        cout << "Enter Author : ";
        cin >> add_book.author;
        cout << "Enter Quantity : ";
        cin >> add_book.quantity;
        cout << "Enter Price : ";
        cin >> add_book.price;
        ofstream addbooktofile;
        addbooktofile.open("books.dat", ios::app);
        addbooktofile.write((char *)&add_book, sizeof(add_book));
        addbooktofile.close();
        cout << "Book Added Successfully!!" << endl;
    }

    void bookList(void)
    {
        cout << "\t\tBOOK LIST" << endl;
        ifstream getbookfromfile;
        getbookfromfile.open("books.dat");
        book getBook;
        cout << "Book ID\t"
             << "Book Title\t"
             << "Author\t"
             << "Quantity\t"
             << "Price\t" << endl;
        while (getbookfromfile.read((char *)&getBook, sizeof(getBook)))
        {
            cout << getBook.bookid << "\t"
                 << getBook.booktitle << "\t"
                 << getBook.author << "\t"
                 << getBook.quantity << "\t\t"
                 << getBook.price << endl;
        }
        getbookfromfile.close();
    }
    void setQuantity(int task, int tempid, int tempQuantity)
    {
        book setdata;
        ifstream bookdata;
        bookdata.open("books.dat");
        ofstream boooktofile;
        boooktofile.open("temp.dat");
        while (bookdata.read((char *)&setdata, sizeof(setdata)))
        {
            if (setdata.bookid == tempid)
            {
                if (task == 1)
                {
                    setdata.quantity -= tempQuantity;
                }
                else
                {
                    setdata.quantity += tempQuantity;
                }
                boooktofile.write((char *)&setdata, sizeof(setdata));
            }
            else
            {
                boooktofile.write((char *)&setdata, sizeof(setdata));
            }
        }
        boooktofile.close();
        bookdata.close();

        bookdata.open("temp.dat");
        boooktofile.open("books.dat");
        while (bookdata.read((char *)&setdata, sizeof(setdata)))
        {
            boooktofile.write((char *)&setdata, sizeof(setdata));
        }
        boooktofile.close();
        bookdata.close();
    }
};

class billbook : public book
{
private:
    char name[35];
    int contact;
    char transaction;
    int transBookid;
    int bookQuantity;
    int bookPrice;
    int totalAmount;

public:
    void transactions(int usertask)
    {
        billbook newBill;
        book bookRecord;
        cout << "\t\tBOOK TRANSACTIONS" << endl;
        cout << "Enter Book id : ";
        cin >> newBill.transBookid;
        cout << "Enter Book Quantity : ";
        cin >> newBill.bookQuantity;
        cout << "Enter Book Price : ";
        cin >> newBill.bookPrice;
        cout << "Enter Name : ";
        cin >> newBill.name;
        cout << "Enter Contact : ";
        cin >> newBill.contact;
        newBill.totalAmount = newBill.bookQuantity * newBill.bookPrice;
        ofstream billfile;
        billfile.open("billbook.dat", ios::app);
        if (usertask == 1)
        {
            newBill.transaction = 'S';
        }
        else if (usertask == 2)
        {
            newBill.transaction = 'P';
        }
        bookRecord.setQuantity(usertask, newBill.transBookid, newBill.bookQuantity);
        billfile.write((char *)&newBill, sizeof(newBill));
        billfile.close();
    }
    void billList(void)
    {
        cout << "\t\tBILL BOOK" << endl;
        ifstream billfromfile;
        billfromfile.open("billbook.dat");
        billbook getBill;
        cout << "Name\t\t"
             << "Contact\t\t"
             << "Transcation\t"
             << "Book ID\t"
             << "Quantity\t"
             << "Price\t"
             << "Total Amount" << endl;
        while (billfromfile.read((char *)&getBill, sizeof(getBill)))
        {
            cout << getBill.name << "\t"
                 << getBill.contact << "\t"
                 << getBill.transaction << "\t\t"
                 << getBill.transBookid << "\t"
                 << getBill.bookQuantity << "\t\t"
                 << getBill.bookPrice << "\t\t"
                 << getBill.totalAmount << endl;
        }
        billfromfile.close();
    }
};

int main()
{
    cout << "\t\tWELCOME TO BOOKSHOP\n";
    book book_obj;
    billbook bill;
    int choice;
    cout << "1 Book List" << endl
         << "2 Add/Delete Book" << endl
         << "3 Sell/Purchase Book" << endl
         << "4 Billbook" << endl
         << "0 exit" << endl;
    cout << "Enter your choice : ";
    cin >> choice;
    cout << "\n";
    switch (choice)
    {
    case 1:
        book_obj.bookList();
        main();
        break;
    case 2:
        int add_delete;
        cout << "Enter 1 for ADD or 2 for DELETE : ";
        cin >> add_delete;
        if (add_delete == 1)
        {
            book_obj.addBook();
        }
        else if (add_delete == 2)
        {
            book_obj.deleteBook();
        }
        main();
        break;
    case 3:
        int sellorpurchase;
        cout << "Enter 1 for SELL or 2 for PURCHASE : ";
        cin >> sellorpurchase;
        if (sellorpurchase == 1 || 2)
        {
            bill.transactions(sellorpurchase);
        }

        main();
        break;
    case 4:
        bill.billList();
        main();
        break;

    default:
        break;
    }
    return 0;
}