//
// Created by ababa on 2026/5/21.
#include <iostream>
#include <cstring>
using namespace std;
struct Book{
private:
    string name;
    string author;
    string publisher;
    float price;
    int page;
public:
    void GetBook(int i);
    void ShowBook();
};
extern Book book[2];