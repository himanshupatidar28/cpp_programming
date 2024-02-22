# Library Management System

This program implements a simple library management system using C++. It allows administrators to manage books, members, perform book transactions (issue, return, payment), and generate various reports.

## How to Use

### Compilation
Compile the program using any C++ compiler. For example, using g++:

```bash
g++ main.cpp -o library_management_system_c++
```

### Execution
Run the compiled executable:

```bash
./library_management_system_c++
```

### Functionality
Upon running the program, you will be prompted with a login screen for the admin. The default admin credentials are:
- Admin ID: Admin
- Password: Librarian

After successful login, you can perform the following actions:

1. **Book Management**: Add, delete, update, or search for books.
2. **Member Management**: Add, delete, update, or search for members.
3. **Book Transaction**: Issue, return, or make payments for books.
4. **Reports**: View reports such as all books, all members, all transactions, due books, paymented books, or search for member profiles.

### Note
- Data for books, members, and transactions are stored in CSV files (`book.csv`, `member.csv`, `transaction.csv`, `all_trans.csv`).
- Upon each operation (add, update, delete), the program interacts with the respective CSV files to perform the desired action.

## Dependencies
- C++ Standard Library
- Compiler supporting C++11 features

## License
Author: Himanshu Patidar
Date: 22 Feburary 2024

This licensed for only personal using for students and developers as learning license not for selling someone.
