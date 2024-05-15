//
// Created by Lenovo on 2024/5/15.
// const的用法

#include <iostream>

int main(){
    //tip:从右向左看
    //常量指针指向一个非常量int
    int* const p = new int;    // (*p)++ OK       p++ NOT ALLOWED
    //非常量指针指向一个常量int
    const int* q = new int;    // (*p)++ NOT ALLOWED     p++    OK
    //常量指针指向一个常量int     //(*p)++和p+ BOTH NOT ALLOWED
    const int* const r1 = new int;
    int const* const r2 = new int;
    delete p;
    delete q;
    delete r1;
    delete r2;
    return 0;
}

//std::search             在一个容器是否能够搜索到另一个容器，字符串匹配
//std::inner_product           求两个向量的内积，属于numeric库

/*
 * const作用迭代器
 * const vector<int>::iterator itr跟int* const itr用法一致，表示不能修改迭代器的指向
 * 要想让一个迭代器指向的元素不能被修改，需要定义一个新的const_iterator
 * */

/* 析构函数
 * - ~类名::类名()
 * - 析构函数没有参数
 * - 析构函数不允许重载
 * - 析构函数常用于释放类中new出来的在堆里的内存
 * - 与栈区普通对象不同，堆区指针对象并不会自己主动执行析构函数，就算运行到主函数结束，
 *   指针对象的析构函数也不会被执行，只有使用delete才会触发析构函数
 * */
