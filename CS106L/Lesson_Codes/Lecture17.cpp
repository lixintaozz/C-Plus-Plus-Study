//
// Created by warrior on 2024/5/24.
// 多线程简介

#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

using namespace std;

//定义了一把互斥锁
mutex mtx;

/* 不符合RAII原则，"锁"这种资源可通过lock_guard
 * void greet(size_t id){
    mtx.lock();
    cout << "Greeting from thread " << id << endl;
    for (size_t i = 0; i < 5; ++ i){
        cout << i << " ";
    }
    cout << endl;
    mtx.unlock();
}*/

//符合RAII原则
void greet(size_t id){
    lock_guard<mutex> lg(mtx);  //使用lock_guard<>来控制"锁"资源
    cout << "Greeting from thread " << id << endl;
    for (size_t i = 0; i < 5; ++ i){
        cout << i << " ";
    }
    cout << endl;
}

int main(int argc, const char* argv[]){
    cout << "Start greeting!" << endl;
/*    //定义两个线程
    thread thread1(greet, 1);
    thread thread2(greet, 2);

    //main线程依次等待thread1,thread2完成
    thread1.join();
    thread2.join();*/

    vector<thread> threads;
    const size_t num_threads = 3;
    threads.reserve(num_threads);   //提前为vector分配足够的容量，从而减少了容器可能的复制、移动开销
    for(size_t i = 0; i < num_threads; ++ i)
        //threads.push_back(thread(greet, i));
        //这里，emplace_back 直接将参数传递给 std::thread 的构造函数，而不需要显式创建 std::thread 对象
        threads.emplace_back(greet, i);

    for (auto& item: threads){
        item.join();
    }

    cout << "Greetings from threads done! " << endl;
    return 0;
}

