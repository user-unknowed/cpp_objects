//
// Created by ababa on 2026/5/14.
//
#include <iostream>//包含iostream头文件，用于输入输出
//#include <string>包含string头文件，用于字符串操作
using namespace std;
class Clock{//类的定义
public://公有成员，可以在类的外部访问
    void TimeSet() {
        cin >> hh >> mm >> ss;
    };
       };
    void TimeShow() {
        cout << "now the time is:\n" << hh << ":" << mm << ":" << ss;
    };
private://私有成员，只能在类的内部访问
    int hh;
    int mm;
    int ss;
};//别忘了分号
