//
// Created by Lenovo on 2024/5/15.
// const的用法

#include <iostream>

int main(){
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

//std::search   在一个容器是否能够搜索到另一个容器，字符串匹配
//std::inner_product  求两个向量的内积     属于numeric库

/*
 * const作用迭代器
 * const vector<int>::iterator itr跟int* const itr用法一致，表示不能修改迭代器的指向
 * 要想让一个迭代器指向的元素不能被修改，需要定义一个新的const_iterator
 * */
