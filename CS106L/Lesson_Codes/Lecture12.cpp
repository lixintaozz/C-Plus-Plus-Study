//
// Created by warrior on 2024/5/18.
// 几种特殊的构造函数

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
 *   注意：编译器自动生成的复制构造函数实现的是浅拷贝！需要通过重新分配空间给指针等以实现深拷贝
 * - 复制赋值函数（operator =）
 *   注意：1.需要先释放旧资源，然后再创建新资源   2.判断是不是自己赋值给自己，即a = a的情况，若是则不需要做任何处理
 *
 * 一些规则：
 * - 可以通过在函数声明中令复制构造函数或复制赋值函数=delete来禁止该类定义这两个函数
 * - 析构函数、复制构造函数、复制赋值函数、移动构造函数、移动赋值函数要么同时存在，要么同时不存在
 * */


