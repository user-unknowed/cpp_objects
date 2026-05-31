//
// Created by ababa on 2026/5/14.
//
#include "show_the_time.h"//包含头文件，头文件中包含了类的定义和声明
#include <iostream>

using namespace std;
int main() {
    Clock now;//创建一个Clock类的对象now
    now.TimeSet();//调用对象now的TimeSet成员函数，设置时间，进入到类的内部访问
    now.TimeShow();//调用对象now的TimeShow成员函数，显示时间，进入到类的内部访问
    return 0;
}
