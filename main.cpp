// ------------------------------ //
//  Copyright(R) 2018 Micha³ Czy¿ //
//   Unauthorised Republishing,   //
//     Modifying or Selling       //
//         is Prohibited          //
// ------------------------------ //
#include <algorithm>   // transform()
#include <cctype>      // toupper(), tolower()
#include <functional>  // ptr_fun()
#include <iostream>    // cin, cout
#include <string>      // getline(), string
#include <sstream>
#include <cstdlib>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    // strings definitons
    string line;
    int number;
    string country;


    // number checker
    cout << "Please insert your cellphone number: ";
    while (getline(cin, line))
    {
        stringstream ss(line);
        if (ss >> number)
        {
            if (ss.eof())
            {   // Success
                break;
            }
        }
        cout << "Invalid number! Please insert your cellphone number without formatting: ";
    }
    string str_number = to_string(number);

    // country checker
    cout << "Specify your cellphone number's country:(v1.0 -- only US & Poland) ";
    cin >> country;
    char input[100];
    cin.getline(input,sizeof(input));
    transform( country.begin(), country.end(), country.begin(), ptr_fun <int, int> ( tolower ) );

    // ifs

    while (true) {
        if (country == "usa" || country == "us" || country == "united states")
        {
            if (str_number.length() > 7)
            {
                cout << "Your number is too long! Restarting..." << endl;
                cin.sync();
                cin.clear();
                main();
            }
            else if (str_number.length() < 7)
            {
                cout << "Your number is too short! Restarting..." << endl;
                cin.sync();
                cin.clear();
                main();
            }
            else
            {
                string format;
                cout << "What format do you choose:" << endl << "(1) Local: 555-1234" << endl << "(2) Domestic: (555) 555-1234" << endl << "(3) International: +1-555-555-1234" << endl << "> ";
                cin >> format;
                char input[100];
                cin.getline(input,sizeof(input));
                transform( format.begin(), format.end(), format.begin(), ptr_fun <int, int> ( tolower ) );

                if (format == "local" || format == "1")
                {
                    int n = str_number.length();
                    char char_array[n+1];
                    strcpy(char_array, str_number.c_str());
                    string valid_number;

                    ostringstream oss;
                    oss << char_array[0] << char_array[1] << char_array[2] << "-" << char_array[3] << char_array[4] << char_array[5] << char_array[6];
                    valid_number = oss.str();

                    cout << "Your number is: " << valid_number << endl;
                }
                else if (format == "domestic" || format == "2")
                {

                    int area_code;
                    string line;

                    cout << "Please insert your cellphone number's Telephone Area Code: ";
                    while (getline(cin, line))
                    {
                        stringstream ss(line);
                        if (ss >> area_code)
                        {
                            if (ss.eof())
                            {   // Success
                                break;
                            }
                        }
                        cout << "Invalid area code! Telephone Area Codes are 3 digit numbers" << endl;
                        cout << "Please insert your cellphone number's Telephone Area Code: ";
                    }
                    string str_area_code = to_string(area_code);

                    while(true)
                    {
                        if (str_area_code.length() != 3)
                        {
                            cin.sync();
                            cin.clear();
                            cout << "Invalid area code! Telephone Area Codes are 3 digit numbers" << endl;
                            cout << "Please insert your cellphone number's Telephone Area Code: ";
                            cin >> str_area_code;
                            continue;
                        }
                        else
                        {
                            break;
                        }
                    }
                    int n = str_number.length();
                    char char_array[n+1];
                    strcpy(char_array, str_number.c_str());
                    string valid_number;

                    ostringstream oss;
                    oss << "(" << str_area_code << ") " << char_array[0] << char_array[1] << char_array[2] << "-" << char_array[3] << char_array[4] << char_array[5] << char_array[6];
                    valid_number = oss.str();

                    cout << "Your number is: " << valid_number << endl;
                }
                else if (format == "international" || format == "3")
                {
                    int n = str_number.length();
                    char char_array[n+1];
                    strcpy(char_array, str_number.c_str());
                    string valid_number;

                    ostringstream oss;
                    oss << "+1-" << char_array[0] << char_array[1] << char_array[2] << "-" << char_array[3] << char_array[4] << char_array[5] << char_array[6];
                    valid_number = oss.str();

                    cout << "Your number is: " << valid_number << endl;
                }
                break;
            }
        }
        else if (country == "pl" || country == "pol" || country == "poland" || country == "polska")
        {
            if (str_number.length() > 9)
            {
                cout << "Your number is too long! Restarting..." << endl;
                cin.sync();
                cin.clear();
                main();
            }
            else if (str_number.length() < 9)
            {
                cout << "Your number is too short! Restarting..." << endl;
                cin.sync();
                cin.clear();
                main();
            }
            else
            {
                int n = str_number.length();
                char char_array[n+1];
                strcpy(char_array, str_number.c_str());
                string valid_number;

                ostringstream oss;
                oss << "+48 " << char_array[0] << char_array[1] << char_array[2] << " " << char_array[3] << char_array[4] << char_array[5] << " " << char_array[6] << char_array[7] << char_array[8];
                valid_number = oss.str();

                cout << "Your number is: " << valid_number << endl;

                break;
            }
        }
        else
        {
            cout << "Invalid or Not Supported Country! Specify your cellphone number's country: ";
            cin >> country;
            cin.sync();
            cin.clear();
            continue;
        }
    }


    string quit;
    cout << "Do you want to quit? (y/n) ";
    cin >> quit;

    while (true)
    {
        if (quit == "y" || quit == "yes")
        {
            exit(0);
        }
        else if (quit == "n" || quit == "no")
        {
            cin.sync();
            cin.clear();
            main();
        }
        else
        {
            cout << "Do you want to quit? (y/n) ";
            cin >> quit;
            continue;
        }
    }
}

