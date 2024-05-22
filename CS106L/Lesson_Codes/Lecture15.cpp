//
// Created by warrior on 2024/5/21.
// C++继承和模板类

#include <iostream>

using namespace std;



class Drink{
public:
    explicit Drink() = default;   //explicit表示这个默认构造函数必须被显式调用，而不能被隐式调用
    explicit Drink(const string& flavor): _flavor(std::move(flavor)){cout << "copy being called!" << endl;}
    explicit Drink(string&& flavor): _flavor(std::move(flavor)){cout << "move being called!" << endl;}
    virtual ~Drink() = default;
    virtual void make(){cout << "Made tea from Drink class" << endl;}

private:
    string _flavor;
};

// 使用 public 继承时，基类的 public 成员在派生类中仍然是 public，protected 成员在派生类中变成 protected，而 private 成员在派生类中仍然是 private。
// 派生类对象可以直接访问基类的 public 和 protected 成员，但不能直接访问基类的 private 成员。
class Tea: public Drink{
public:
    explicit Tea() = default;
    //先调用基类的构造函数创建基类对象，然后再执行派生类的构造函数
    explicit Tea(string& flavor):Drink(std::move(flavor)){}
    void make() override{cout << "Made tea from Tea class" << endl;}  //override的作用是表明这个成员函数是重写了基类的某个虚函数
};



int main(int argc, const char* argv[]){
    string flavor = "Tea";
    Tea t(flavor);
    t.make();
    t.Drink::make();
    return 0;
}

/*
 * 模板：是一种静态(static)多态，会花费较多时间在compile上
 * 继承：是一种动态(dynamic)多态，会花费较多时间在run上
 * */

/*
 * 强制类型转换：
 * e.g. int a = static_cast<int>(b);     //编译时转换
 * */
