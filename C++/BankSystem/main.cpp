#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>
#include "Account.h"

using namespace std;  

const int ACCOUNT_NUMBER_SIZE = 10;
const int PIN_SIZE = 5;
const int ACCOUNT_BALANCE_SIZE = 10;
const int NEW_LINE_SIZE = 2;
const int RECORD_SIZE =  ACCOUNT_NUMBER_SIZE + PIN_SIZE + NEW_LINE_SIZE;

bool find_account(int acno ,int password,int account_size, istream& stream)
{
    Account new_account;
    
    if(stream.fail())
    {
        cout << "File does not exist. \n"; 
        exit(1);
    }
    else
    {
        stream.seekg(0, ios::end);
        int nrecords = stream.tellg() / RECORD_SIZE;
        int current_record =0;
        cout << "There are currently " << nrecords<< " many records \n";    
        while(current_record < nrecords + 1)
        {
            stream.seekg(current_record * RECORD_SIZE, ios::beg);

            string line;
            getline(stream,line);

            string current_acno = line.substr(0, 9);
            string current_pin = line.substr(9,14);

            int x,y;

            stringstream account_string(current_acno);
            stringstream pin_string(current_pin);
            
            account_string >> x;
            pin_string >> y;
           
            if(acno == x && password == y)
            {
                return true;
            }
            current_record++;
        }
        return false;
    }
}
void write_account(int acno, int password, ostream& stream)
{
    stream.seekp(0, ios::beg);  

    stream <<acno << setw(ACCOUNT_NUMBER_SIZE) 
                << password 
                << setw(PIN_SIZE )<< "\n";
    
    cout << acno << " " << password;
}

Account get_account(int acno, istream& stream)
{
    Account account;
    if(stream.fail())
    {
        exit(1);   
    }
    else 
    {
        stream.seekg(0 , ios::end);
        int current_record = 0;
        int nrecords =  stream.tellg()/RECORD_SIZE;

        stream.seekg(0, ios::beg);
        while(current_record < nrecords + 1)
        {
            stream.seekg(current_record * RECORD_SIZE, ios::beg);

            string line;
            getline(stream, line);
            
            string account_string = line.substr(0,9);
            stringstream next_account(account_string);
            
            int nextaccount;
            next_account >> nextaccount;
          
            if(acno == nextaccount)
            {
                string pin_string = line.substr(10,14);
                stringstream pin_convert(pin_string);
                int password;
                pin_convert >> password;
                return  Account(acno, password); 
            }
            current_record++;
        }
        cout << "Account not found. \n";
        exit(1);
    } 
}

int main(){

    cout << "Hello. In order to access your account you must confirm your credentials" << endl;

    int account_number;
    int password;

    Account current_account;   
    fstream stream; 
    bool login = false, signup = false;
  
    cout  << "/*/*/*/*/ 1: Log in   /*/*/*/*/" << endl;
    cout  << "/*/*/*/*/ 2: Sign up  /*/*/*/*/" << endl;

        int input;
        while(input != 1 && input != 2)
        {
            cin >> input;
            switch(input)
            {
                case 1:
                    login = true;
                    break;
                case 2:
                    signup = true;
                    break;
                default:
                    break;
            }
        }
        
       if(login == true)
       {
            cout << "You selected login. \n";
            cout << "Enter your account number. \n";
            int acno;
            cin >> acno;

            cout << "Enter your pin. \n";
            int pin;
            cin >> pin;

            fstream stream;      
            stream.open("data.txt", ios::in );
            if(find_account(acno, pin, RECORD_SIZE, stream))
            {
                cout << "Acount found.\n";
                current_account = get_account(acno, stream);
                cout << current_account.get_acno();
            }
            else
            {
                cout << "Account not found. \n";
            }
            
            stream.close();
       }
       else if(signup == true)
       {
            cout << "You selected signup. \n";
            cout << "Enter new account number. \n";
            int acno;
            cin >> acno;

            cout << "Enter new pin. \n";
            int pin;
            cin >> pin;

            
            stream.open("data.txt" , ios::out | ios::app);
            if(stream.fail())
            {
                cout << "File not found";
                exit(1);
            }
            else
            {
                write_account( acno, pin, stream);
            }

            stream.close();
       }
}