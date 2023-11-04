// Clc4Week04Serialization.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <exception>
#include <vector>
#include "DynamicArray.h"
#include "RandomIntegerProvider.h"
#include "IntegerKeyboardProvider.h"

using std::cout, std::cin, std::exception, std::endl;
using std::vector;

#include "Dice.h"
#include "FractionsTextProvider.h"
#include "Fibonacci.h"
#include "Atm.h"
#include "BankAccount.h"

int main()
{
    // ATM chi tra ra tien boi so cua 50.000
    Atm nvcAtm(50000);
    //Atm nvcAtm(50000);

    // So du toi thieu >= 50000
    BankAccount minh("Minh", 320000);

     auto [success, paid, message] = minh.withdraw(nvcAtm,100000);  
    //minh.withdraw(nvcAtm, 120000);
    //minh.withdraw(nvcAtm, 300000);

     if (success == true) {
         cout << "Withdraw successfully." << endl;
         cout << "Paid: " << paid << endl;  // 100.000
         cout << "User's balance:" << minh.availableBalance() << endl; // 220.000
     }
     else {
         cout << "Cannot withdraw. Reason: " << message << endl;
     }


   /* Fibonacci f;
    f.generate(7);
    cout << f;*/

    // Deserialization - Serialization
   /* string input = "data.txt";
    FractionsTextProvider provider;
    vector<Fraction> fractions = provider.next(input);

    Fraction sum;
    for (int i = 0; i < fractions.size(); i++) {
        sum = sum + fractions[i];
    }

    cout << sum;*/


    //int start = 7;
    //int end(start); // int (const int&)

    //IntegersKeyboardProvider provider;
    //DynamicArray numbers = provider.next("Nhap vao mang so nguyen.");
    //cout << numbers;

    //DynamicArray primes(numbers);

    //DynamicArray temp;

    //temp = primes;
    //temp = numbers;
    //temp = temp;


    /*DynamicArray primes;
    cout << "Nhap vao mang so nguyen to." << endl;
    cin >> primes;
    cout << primes;*/

    /*numbers.push_back(25);
    numbers.push_back(-1);
    numbers.push_back(11);
    numbers.push_back(-1);
    numbers.push_back(7);

    numbers.push_back(18);*/

    /*try
    {
        for (int i = 0; i < numbers.size(); i++) {
            cout << numbers[i] << " ";
        }

        cout << numbers[100]; 
    }
    catch (const std::exception& ex)
    {
        cout << "Error in processing. Reason: " << ex.what() << endl;
        /// logging
    }*/

    /*RandomIntegerProvider provider;    

    for (int i = 0; i < 10; i++) {
        cout << provider.next(10, 100) << " ";
    }


    Dice dice1;
    for (int i = 1; i <= 10; i++) {
        cout << dice1.roll() << " ";
    }*/
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
