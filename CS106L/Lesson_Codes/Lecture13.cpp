//
// Created by warrior on 2024/5/19.
// 移动语义

#include <iostream>
#include <vector>

template <typename T>
void swap(T& a, T& b){
    T temp = std::move(a);
    a = std::move(b);
    b = std::move(temp);
}

template <typename T>
void printVector(const T& container){
    for (const auto& item: container){
        std::cout << item << " "; 
    }
    std::cout << std::endl;
}

//Todo:研究jinanpiwang对应的代码

int main(int argc, const char* argv[]){
    std::vector<int> vec1{1, 2, 3};
    std::vector<int> vec2{4, 5, 6};
    std::cout << "Before swap: " << std::endl;
    printVector(vec1);
    printVector(vec2);
    swap(vec1, vec2);
    std::cout << "After swap: " << std::endl;
    printVector(vec1);
    printVector(vec2);
    return 0;
}

/*
 * 左值和右值：
 * - 左值：左值是有名字的，并且能通过取地址符&来获取它的地址
 * - 右值：右值是没有名字的，它是一个临时值，并且不能通过取地址符&来获取它的地址
 * */

/* 新加的两种特殊函数(用于处理实参为右值的情况)：
 * - 移动构造函数
 * - 移动赋值函数
 * std::move()   //将一个左值声明为右值
 * 核心：将左值赋给左值，执行的是复制操作，因为前第一个左值有名字，可能会被再次访问
 *      将右值赋给左值，执行的是移动操作，因为右值没有名字，后续不会被访问，所以将其移动给左值
 *      事实上的移动语义就是借助std::move()实现的，与右值引用关系不大
 * */
