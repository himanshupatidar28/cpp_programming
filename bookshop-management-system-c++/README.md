# Bookshop Management System

This is a simple bookshop management system implemented in C++. It allows users to view the list of books, add or delete books from inventory, and record transactions (sales or purchases) in a bill book.

## Features

- **Book Listing**: Displays the list of books available in the inventory with details such as book ID, title, author, quantity, and price.
- **Add/Delete Books**: Provides functionality to add new books to the inventory or delete existing books based on user input.
- **Transaction Recording**: Records transactions of selling or purchasing books in a bill book, including details such as customer name, contact, book ID, quantity, price, and total amount.

## Usage

1. Compile the code using a C++ compiler.
2. Run the compiled executable file.
3. Choose from the available options to perform desired actions:
   - **Book List**: View the list of books available in the inventory.
   - **Add/Delete Book**: Add a new book to the inventory or delete an existing book.
   - **Sell/Purchase Book**: Record a transaction for selling or purchasing books.
   - **Billbook**: View the bill book containing records of transactions.
   - **Exit**: Terminate the program.

## File Management

- Book details are stored in a binary file named `books.dat`.
- Transaction records are stored in a binary file named `billbook.dat`.

## Note

- Book ID is a unique identifier for each book.
- The system does not include advanced features such as user authentication, GUI, or database integration.

## Disclaimer

This bookshop management system is intended for educational purposes and may not have advanced features or robust error handling. Use it responsibly and for learning purposes.

