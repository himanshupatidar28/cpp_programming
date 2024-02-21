# Chat Bot

This is a simple chat bot program implemented in C++ that interacts with users by responding to their commands and storing information for future reference.

## Features

- **Response Generation**: Generates responses based on user input.
- **Information Storage**: Stores user-provided information for later retrieval.
- **Command Interpretation**: Interprets various commands such as asking questions, providing information, and saying goodbye.
- **Data Persistence**: Stores and retrieves data from a CSV file.

## Usage

1. Compile the code using a C++ compiler.
2. Run the compiled executable file.
3. Start interacting with the chat bot by typing commands in lowercase.
4. Use commands like "remember" to store information, "what" to retrieve stored information, and "bye" to exit the program.

## Command Examples

- **Remember Command**: Type "remember my favorite color is blue" to store the information "favorite color: blue".
- **What Command**: Type "what is my favorite color" to retrieve the stored information about the favorite color.
- **Bye Command**: Type "bye" to exit the chat bot program.

## File Management

- User-provided data is stored in a CSV file named `data.csv`.
- Each line in the CSV file represents a key-value pair, where the key is the information to remember and the value is the stored data.

## Disclaimer

This chat bot application is intended for educational purposes and may not have advanced natural language processing capabilities or robust error handling. Use it responsibly and for fun interaction.

