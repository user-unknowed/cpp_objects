//
// Created by ababa on 2026/5/22.
//

#include "Bank_management.hpp"

int CreditCard::totalCards = 0;

CreditCard::CreditCard(const string& number, const string& holder, float limit)
    : cardNumber(number), cardHolder(holder), creditLimit(limit), currentDebt(0.0) {
    totalCards++;
    cout << "Credit card opened successfully! Card Number: " << cardNumber << ", Card Holder: " << cardHolder << endl;
}

CreditCard::~CreditCard() {
    totalCards--;
}

bool CreditCard::spend(float amount) {
    if (amount <= 0) {
        cout << "Error: Amount must be greater than 0!" << endl;
        return false;
    }
    
    float availableCredit = creditLimit - currentDebt;
    if (amount > availableCredit) {
        cout << "Risk Warning: Amount exceeds available credit! Available: " << availableCredit << ", Attempted: " << amount << endl;
        return false;
    }
    
    currentDebt += amount;
    Transaction(*this, "Spend", amount).logTransaction();
    cout << "Spend successful! Amount: " << amount << ", Current Debt: " << currentDebt << endl;
    return true;
}

bool CreditCard::repay(float amount) {
    if (amount < 0) {
        cout << "Error: Repay amount cannot be negative!" << endl;
        return false;
    }
    
    if (amount == 0) {
        cout << "Info: Repay amount is 0, no action needed." << endl;
        return true;
    }
    
    if (amount > currentDebt) {
        float overPayment = amount - currentDebt;
        currentDebt = 0;
        cout << "Repay successful! Amount: " << amount << ", Overpayment: " << overPayment << ", Current Debt: " << currentDebt << endl;
    } else {
        currentDebt -= amount;
        cout << "Repay successful! Amount: " << amount << ", Current Debt: " << currentDebt << endl;
    }
    
    Transaction(*this, "Repay", amount).logTransaction();
    return true;
}

void CreditCard::displayInfo() const {
    cout << "===== Credit Card Info =====" << endl;
    cout << "Card Number: " << cardNumber << endl;
    cout << "Card Holder: " << cardHolder << endl;
    cout << "Credit Limit: " << creditLimit << endl;
    cout << "Current Debt: " << currentDebt << endl;
    cout << "Available Credit: " << creditLimit - currentDebt << endl;
    cout << "============================" << endl;
}

string CreditCard::getCardNumber() const {
    return cardNumber;
}

string CreditCard::getCardHolder() const {
    return cardHolder;
}

int CreditCard::getTotalCards() {
    return totalCards;
}

Transaction::Transaction(const CreditCard& card, const string& type, float amount)
    : card(card), type(type), amount(amount) {
    timestamp = time(nullptr);
}

void Transaction::logTransaction() const {
    struct tm* localTime = localtime(&timestamp);
    cout << "===== Transaction Record =====" << endl;
    cout << "Transaction Time: " << localTime->tm_year + 1900 << "-" 
         << localTime->tm_mon + 1 << "-" 
         << localTime->tm_mday << " " 
         << localTime->tm_hour << ":" 
         << localTime->tm_min << ":" 
         << localTime->tm_sec << endl;
    cout << "Card Holder: " << card.getCardNumber() << " (" << card.getCardHolder() << ")" << endl;
    cout << "Transaction Type: " << type << endl;
    cout << "Transaction Amount: " << amount << endl;
    cout << "==============================" << endl;
}

int main() {
    cout << "Welcome to Credit Card Management System!" << endl << endl;

    CreditCard card1("6222021234567890", "Wang Wu", 5000.0);
    CreditCard card2("6222020987654321", "Zhao Liu", 10000.0);

    cout << endl << "Total Credit Cards in System: " << CreditCard::getTotalCards() << endl << endl;

    cout << "=== Testing Wang Wu's Credit Card ===" << endl;
    card1.displayInfo();

    cout << endl << "Test Normal Spend (1000)..." << endl;
    card1.spend(1000.0);

    cout << endl << "Test Normal Spend (2000)..." << endl;
    card1.spend(2000.0);

    cout << endl << "Test Over Limit Spend (3000, Available: 2000)..." << endl;
    card1.spend(3000.0);

    cout << endl << "Test Repay (1500)..." << endl;
    card1.repay(1500.0);

    cout << endl << "Test Zero Repay..." << endl;
    card1.repay(0);

    cout << endl << "Test Negative Repay..." << endl;
    card1.repay(-100);

    card1.displayInfo();

    cout << endl << "=== Testing Zhao Liu's Credit Card ===" << endl;
    card2.displayInfo();

    cout << endl << "Test Normal Spend (5000)..." << endl;
    card2.spend(5000.0);

    cout << endl << "Test Over Repay (6000)..." << endl;
    card2.repay(6000.0);

    card2.displayInfo();

    const CreditCard vipCard("6222021111222233", "VIP User", 50000.0);
    cout << endl << "=== Testing VIP Const Object ===" << endl;
    vipCard.displayInfo();
    cout << "VIP Card Number: " << vipCard.getCardNumber() << endl;

    cout << endl << "Program ended!" << endl;
    return 0;
}