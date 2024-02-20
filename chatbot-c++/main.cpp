#include <iostream>
#include <string>
#include <sstream>
#include <bits/stdc++.h> //transform fn
using namespace std;

void setdata(string input, string output)
{

    vector<string> row;
    string line, word;
    ifstream file;
    ofstream temp;
    int found = 0;
    file.open("data.csv");
    temp.open("temp.csv");
    while (getline(file, line))
    {
        stringstream s(line);
        while (getline(s, word, ','))
        {
            row.push_back(word);
        }
        if (row[0] == input)
        {
            found = 1;
            row[1] = output;
        }
        temp << row[0] << "," << row[1] << endl;
        row.clear();
    }

    if (found == 1)
    {
    }
    else
    {
        row.push_back(input);
        row.push_back(output);
        temp << row[0] << "," << row[1] << endl;
    }
    temp.close();
    file.close();
    remove("data.csv");
    rename("temp.csv", "data.csv");
}

string getdata(string input)
{
    vector<string> row;
    row.clear();
    string line, word;
    ifstream file;
    file.open("data.csv");
    while (getline(file, line))
    {
        stringstream s(line);
        while (getline(s, word, ','))
        {
            row.push_back(word);
        }
        if (input.find(row[0])!= string::npos)
        {
            return "Sir," + row[1];
        }
        row.clear();
    }
    file.close();
    return "Sorry sir, i am not able to understand.";
}


string response(string input)
{
    transform(input.begin(), input.end(), input.begin(), ::tolower);
    if (input == "hey" || input == "hello")
    {
        return "Hello Sir, How are you..";
    }
    else if (input.find("what") != string::npos)
    {
        int pos = input.find("is");
        string output = input.substr(pos + 2, (input.size() - pos));
        return getdata(output);
    }
    else if (input.find("remember") != string::npos)
    {
        int pos = input.find("is");
        string output = input.substr(pos + 2, (input.size() - pos));
        string in = input.substr(8, (input.size() - (output.size() + 11)));
        setdata(in, output);
        return "Sure sir i will remmber ..";
    }
    else if (input.find("bye") != string::npos)
    {
        return "Have a nice day sir";
    }
    else
    {
        return getdata(input);
    }
    return "Sorry sir, i am not able to understand.";
}

int main()
{
    string command;

    cout << "*************************************" << endl
         << "\t\tCHAT BOT" << endl
         << "*************************************" << endl
         << endl;

    cout << "Note : Write any command in small letters," << endl
         << "\tto give info write like ''remember' my fav sport is cricket', " << endl
         << "\twrite 'what' your remmber tagged details" << endl
         << "\twrite 'bye' for exit program" << endl
         << endl;

    do
    {
        cout << ">> ";
        getline(cin, command, '\n');
        cout << response(command);

        cout << endl
             << endl;
    } while (!(command.find("bye") != string::npos));

    system("pause");
    return 0;
}