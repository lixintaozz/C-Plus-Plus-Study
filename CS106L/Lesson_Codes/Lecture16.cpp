//
// Created by warrior on 2024/5/23.
// RAII和Smart pointer

#include <iostream>
#include <memory>


using namespace std;

struct person{
    string name;
    int age;
};


// noexcept应该在构造或者析构函数中出现的原因：比如在析构的一半抛出异常，会导致内存泄漏
//Todo:研究std::lock_guard<>的用法，以及weak_ptr<>可能的在多线程中的用法
int main(int argc, const char* argv[]){
    // 独占拥有权，一个对象只能由一个 unique_ptr 拥有。
    //unique_ptr<person> p1(new person);

    //共享拥有权，多个 shared_ptr可以同时拥有相同的对象，当没有指针指向对象时，对象才会析构
    shared_ptr<person> p1(new person);
    p1->name = "Li Hua";
    p1->age = 18;
    cout << p1->name << " " << p1->age << endl;
    shared_ptr<person> p2 = std::move(p1);
    cout << p2->name << " " << p2->age << endl;
    // 与 std::shared_ptr 不同，std::weak_ptr 不会增加对象的引用计数。
    // 它提供了一种方法来观察和访问 shared_ptr 管理的对象，而不会造成所有权问题
    weak_ptr<person> p3 = p2;
    // weak_ptr 本身并不拥有对象，当你需要访问 weak_ptr 所指向的对象时，你可以使用 wp.lock() 方法来尝试获取一个 std::shared_ptr
    std::shared_ptr<person> p4 = p3.lock();
    cout << p4->name << " " << p4->age << endl;
    //使用weak_ptr观察有多少指针指向 shared_ptr 管理的对象
    cout << p3.use_count() << " " << endl;
    return 0;
}

/* RAII:
 * 总是使用构造函数来获取资源，使用析构函数来释放资源（目的是为了避免内存泄露）
 *
 * 智能指针：本质上就是实现一个类，使用它的构造函数来获取资源，使用它的析构函数来释放资源
 * 三种智能指针：
 * - std::unique_ptr
 * - std::shared_ptr
 * - std::weak_ptr
 * */