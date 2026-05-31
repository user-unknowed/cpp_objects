//
// Created by ababa on 2026/5/22.
//

#ifndef C_BANK_MANAGEMENT_H
#define C_BANK_MANAGEMENT_H

#include <iostream>
#include <string>
#include <ctime>

using namespace std;

class CreditCard;

class Transaction {
private:
    const CreditCard& card;
    time_t timestamp;
    string type;
    float amount;

public:
    Transaction(const CreditCard& card, const string& type, float amount);
    void logTransaction() const;
};

class CreditCard {
private:
    string cardNumber;
    string cardHolder;
    float creditLimit;
    float currentDebt;
    static int totalCards;

public:
    CreditCard(const string& number, const string& holder, float limit);
    ~CreditCard();

    bool spend(float amount);
    bool repay(float amount);
    void displayInfo() const;
    string getCardNumber() const;
    string getCardHolder() const;
    static int getTotalCards();
};

#endif //C_BANK_MANAGEMENT_H