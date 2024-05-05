//
// Created by Lenovo on 2024/5/3.
//

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

int main()
{
    //Todo：一个现代C++写法的例子，之后再来研究
    vector<int> vec(10);
    std::generate(vec.begin(), vec.end(), rand);
    std::sort(vec.begin(), vec.end());
    std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(cout, "\n"));
    return 0;
}



/*三种类型：
 * 顺序容器：vector, deque
 * 容器适配器：stack, queue   它们本身不是容器，只是限制了某些功能的顺序容器
 *
 * 关联容器：set, map, unordered set, unordered map   //[key]不检查key是否存在；get(key)检查key是否存在，不存在的话会throw an error
 *         使用自定义的类对象作为map或set的typename时，需要重载 < 运算符，因为map和set是有序的
 *         count()方法返回关键字在set/map中出现的次数(只能为0或1)，但它的速度没有find()方法快，所以更推荐使用find()；在c++20中可用contains()来取代
 * */
/*
 * 运算符重载：
 * - 可以作为类的成员函数实现，a + b 等价于 a.operator+(b)
 * - 可以作为普通函数实现，但为了保证重载后的运算符能够访问对象的私有成员变量，需要将普通函数声明为类的友元函数
 * */