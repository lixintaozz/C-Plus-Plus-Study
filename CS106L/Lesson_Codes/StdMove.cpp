//
// Created by warrior on 2024/5/22.
// 移动语义中的std::move()研究

#include <iostream>

using namespace std;

class person{
public:
    int _age;
    string _name;
    person(int age, string name): _age(age), _name(std::move(name)){}

    person(person&& p) noexcept {  //这里的右值引用一般不加const,因为很有可能修改p
        cout << "hello from move constructor" << endl;
        _age = std::move(p._age);
        _name = std::move(p._name);
    }

    person& operator=(person&& p){//这里的p相当于给了右值一个名字，这样它就成了一个左值，因此我们需要进一步使用std::move()来实现真正的移动

        if (this != &p){
            cout << "hello from assign constructor" << endl;
            _age = std::move(p._age);
            _name = std::move(p._name);
        }
        return *this;
    }
};


int main(){
/*    person p1(18, "Li hua");
    cout << "before move, address for age: " << &(p1._age) << " address for name: " << &(p1._name) << endl;
    person p2 = std::move(p1);
    cout << "address for age: " << &(p2._age) << " address for name: " << &(p2._name) << endl;
    cout << "after move, address for age: " << &(p1._age) << " address for name: " << &(p1._name) << endl;*/

    int a = 3;
    cout << "address for a: " << &a << endl;
    int b = std::move(a);
    cout << "address for b: " << &b << endl;
    return 0;
}

/*
 * std::move()的作用：std::move()唯一的作用就是将变量强制转换为右值
 * std::move只是把左值转换成右值，比如a = std::move(b)，则是相当于a = 右值b
   然后因为等于号相当于.operator=()，所以就变为了a.operator=(右值b)
   =号是用来调用类型的赋值函数的，而如果=的右边是右值，则会调用对应的移动赋值函数
   如果对应的移动赋值函数中，将原有的内容删除，则b就用不了了，但是这需要你自己决定
   通常我们使用move就是为了这样，所以一般我们也这样实现，所以不是move做了一切，而是我们做了一切

   对于c++内置类型（如int）而言，使用std::move()本质上还是会执行复制操作，因为内置类型的复制操作和
   移动操作开销是一致的，没必要移动
   int a = 3;
   int b = std::move(a)等价于int b = 右值a，也等价于int b = 3;
   所以a和b的地址不一样
 * */
