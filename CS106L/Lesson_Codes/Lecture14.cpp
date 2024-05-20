//
// Created by warrior on 2024/5/20.
// namespace

#include <iostream>
#include <string>

namespace Lecture14{
    class person{
    public:
        std::string name;
        void printName() const;
        person(const std::initializer_list<char>& str);
    };
}



int main(int argc, const char* argv[]){
    Lecture14::person p{'a','b','c', 'd'};   //这里使用了initializer_list来进行初始化
    p.printName();
    //std::string str("abc");    这里并不是使用的统一列表初始化方式来初始化的，{}并不能作为判断是否使用了统一列表初始化的依据
    //std::cout << str;
    return 0;
}

 //使用namespace包装函数（类）时，用namespace{}分别包装函数（类）的声明和定义即可
 namespace Lecture14{
    void person::printName() const{
        std::cout << name << std::endl;
    }
    person::person(const std::initializer_list<char>& str):name(str){}
}


/*
 * 一个仅包含纯虚函数的类可以实现类似于java中的interface的功能
 * 纯虚函数声明语法：virtual return_type funcname() = 0
 * 虚函数声明语法：前面加virtual关键字即可
 * 包含纯虚函数的类不能通过实例化创建对象
 * */

