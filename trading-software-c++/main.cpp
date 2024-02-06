#include <iostream>
#include <vector>
using namespace std;

class account
{
private:
    // user
    string name;
    int balance, bitcoin, dogecoin, deposit, withdraw;
    // crypto
    int qtyBitcoin, qtyDogecoin, priceBitcoin, priceDogecoin;
    // transacion vector
    vector<pair<string, int> > history;
public:
    account()
    {
        // account info
        name = "Demo Account";
        balance = 1000;
        bitcoin = 0;
        dogecoin = 0;
        deposit = 0;
        withdraw = 0;
        // crypto
        qtyBitcoin = 50;
        qtyDogecoin = 50;
    }
    void getPrice(void)
    {
        srand(time(NULL));
        priceBitcoin = rand() % 500;
        priceDogecoin = rand() % 500;
    }
    void trade(void)
    {

        int number;
        char temp;
        cout << "Enter S for Sell and B for Buy : ";
        cin >> temp;

        if (temp == 'B')
        {
            cout << "Enter 1 for Bitcoin and 2 for Dogecoin : ";
            cin >> number;
            if (number == 1)
            {
                cout << "Enter Quantity : ";
                cin >> number;
                if (balance > (number * priceBitcoin))
                {
                    bitcoin += number;
                    balance -= (number * priceBitcoin);
                    history.push_back({"Buy Bitcon : ", (number * priceBitcoin)});
                    cout << "Transaction Successful" << endl;
                }
            }
            else if (number == 2)
            {
                cout << "Enter Quantity : ";
                cin >> number;
                if (balance > (number * priceDogecoin))
                {
                    dogecoin += number;
                    balance -= (number * priceDogecoin);
                    history.push_back({"Buy Dogecoin : ", (number * priceDogecoin)});
                    cout << "Transaction Successful" << endl;
                }
            }
        }
        else if (temp == 'S')
        {
            cout << "Enter 1 for Bitcoin and 2 for Dogecoin : ";
            cin >> number;
            if (number == 1)
            {
                cout << "Enter Quantity : ";
                cin >> number;
                if (number)
                {
                    bitcoin -= number;
                    balance += (number * priceBitcoin);
                    history.push_back({"Sell Bitcon : ", (number * priceBitcoin)});
                    cout << "Transaction Successful" << endl;
                }
            }
            else if (number == 2)
            {
                cout << "Enter Quantity : ";
                cin >> number;
                if (number)
                {
                    dogecoin -= number;
                    balance += (number * priceDogecoin);
                    history.push_back({"Sell Dogecoin : ", (number * priceDogecoin)});
                    cout << "Transaction Successful" << endl;
                }
            }
        }
    }
    void dashboard(void)
    {
        cout << "------------------------------------------------" << endl
             << "\t\tTRADING SOFTWARE" << endl
             << "------------------------------------------------\n"
             << endl;
        getPrice();
        cout << "BITCOIN" << endl
             << "Price : " << priceBitcoin
             << "\tQuantity : " << qtyBitcoin << endl;
        cout << "---------------------------------" << endl;
        cout << "DOGECOIN" << endl
             << "Price : " << priceDogecoin
             << "\tQuantity : " << qtyDogecoin << endl;
        cout << "---------------------------------" << endl;

        cout << "\n"
             << "1 Account Info" << endl
             << "2 Deposit" << endl
             << "3 Withdraw" << endl
             << "4 Buy or Sell" << endl
             << "5 History" << endl
             << "0 Exit" << endl
             << "Enter Choice : ";

        int choice, number;
        char temp;

        cin >> choice;
        cout << "\n";
        switch (choice)
        {
        case 1:
            cout << "ACCOUNT INFO:" << endl
                 << "Name : " << name << endl
                 << "Balance : " << balance << endl
                 << "Bitcoin : " << bitcoin << endl
                 << "Dogecoin : " << dogecoin << endl
                 << "Holding Amount : " << ((bitcoin * priceBitcoin) + (dogecoin * priceDogecoin)) << endl;
            dashboard();
            break;
        case 2:
            cout << "Enter Amount to be Deposit : ";
            cin >> number;
            if (number < 50000)
            {
                balance += number;
                history.push_back({"Deposit : ", number});
                cout << "deposit Successful." << endl;
            }

            dashboard();
            break;
        case 3:
            cout << "Enter Amount to be Withdraw : ";
            cin >> number;
            if (number < 50000)
            {
                balance -= number;
                history.push_back({"Withdraw : ", number});
                cout << "Withdrawal Successful." << endl;
            }
            dashboard();
            break;
        case 4:
            trade();
            dashboard();
            break;

        case 5:
            cout << "Displaying All transactions\n"<<endl;
            for (int i = 0; i < history.size(); i++)
            {
                cout<<history.at(i).first<<history.at(i).second<<endl;
            }
            
            dashboard();
            break;

        case 0:
            break;

        default:
            dashboard();
            break;
        }
    }
};

int main()
{
    cout << "------------------------------------------------" << endl
         << "\t\tTRADING SOFTWARE" << endl
         << "------------------------------------------------" << endl;
    string username, password;
    cout << "Login here.." << endl;
    cout << "Username : ";
    cin >> username;
    cout << "Password : ";
    cin >> password;
    if (username == "Demo" && password == "password")
    {
        account user;
        user.dashboard();
    }

    return 0;
}