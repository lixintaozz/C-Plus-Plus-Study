//
// Created by warrior on 2024/5/18.
//

#include "StringVector.cpp"
#include <iostream>



int main(int argc, const char* argv[]){
/*
 *  const变量需要在声明的同时对其进行赋值，因为一旦声明以后，就无法对其进行赋值
 *  const int i;
    i = 3;
    const int i = 3;*/
    StringVector vec1{"abc", "def"};
    StringVector vec2 = vec1;
    cout << vec2 << endl;
    return 0;
}

/* 特殊的成员函数（通常可由编译器自动生成）：
 * - 构造函数
 * - 析构函数
 * - 复制构造函数
 *   注意：编译器自动生成的复制构造函数实现的是浅拷贝！
 * - 复制赋值函数（operator =?）
 * */


