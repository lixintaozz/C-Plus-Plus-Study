//
// Created by warrior on 2024/4/30.
// vector[]访问、struct bind的用法

#include <iostream>
#include <sstream>
#include <vector>
#include <iterator>
#include <algorithm>


int main(){
    using std::vector;
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
/*  //使用[]来访问vector元素时，不会检查下标访问是否越界，原因是为了提高程序的运行效率，节省时间
    cout << vec[15] << endl;
    //使用at()方法访问vector元素时，会检查下标访问是否越界，如果越界，编译器会报错
    cout << vec.at(15) << endl;*/

    return 0;
}


/*
 * 结构绑定(c++17)：auto [ , , ] = struct or tuple...
 * struct能用于作为函数返回值，以实现多个数据的返回
 * uniform initialization{}
 * */

/*
 * vector访问操作更快,deque(双端队列)适用于push_front()的情况
 */