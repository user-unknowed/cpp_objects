//
// Created by ababa on 2026/5/21.
//

#include "library_managment.hpp"  // 修正拼写
#include <iostream>
#include <cstring>
using namespace std;
int main() {
    Book book[2];
    cout << "input book information:\n" << endl;
    for (int i = 0; i < 2; ++i) {
        book[i].GetBook(i);   // 如果 GetBook 需要索引
    }
    for (int i = 0; i < 2; ++i) {
        book[i].ShowBook();
    }
    return 0;
}
