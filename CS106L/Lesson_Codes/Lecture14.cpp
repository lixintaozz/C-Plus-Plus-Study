//
// Created by warrior on 2024/5/20.
// namespace

#include <iostream>

/*namespace Lecture14{
    class person{
    public:
        std::string name;
        void printName() const;
    };
}*/



int main(int argc, const char* argv[]){

    return 0;
}

/* 使用namespace包装函数（类）时，用namespace{}分别包装函数（类）的声明和定义即可
 *
 * namespace Lecture14{
    void person::printName() const{
        std::cout << name << std::endl;
    }
}*/


/*
 * 通过定义一个仅包含纯虚函数的类可以实现类似于java中的interface的功能
 * 但是关于public,private继承方式的不同，导致的对类中成员的访问权限有何不同，需要进一步学习c++ primer plus
 * */

