//
// Created by warrior on 2024/5/7.
// 函数对象、lambda函数

#include <iostream>
#include <vector>

using namespace std;


bool devideby3(int x){
    return x % 3 == 0;
}


template <typename input_iterator, typename functype>
int countOccurences(input_iterator begin, input_iterator end, functype func){
    int cnt = 0;
    for (auto it = begin; it != end; ++ it){
        if (func(*it))
            ++ cnt;
    }
    return cnt;
}



int main(){
    int count = 0;
    vector<int> myvec{1,2,3,4,5,6};
/*    for (auto i: myvec)
        //c++中true转换为整数时值为1，false转换为整数时值为0
        count += i % 2 == 0;
    cout << count << endl;*/
    int cnt = countOccurences(myvec.begin(), myvec.end(), devideby3);
    cout << "myvec has " << cnt << " numbers devided by 3" << endl;
    return 0;
}

/*
 * 显式接口(explicit interface)：
 * e.g.
 * template <typename It, typename Type>
 *     requires Input_Iterator<It> && Iterator_of<It> && Equality_comparable<Value_type<It>, Type>
 * int countOccurences(It begin, It end, Type val);
 * */

/*
 * 函数谓词(predicate)
 * - 返回值为bool值的函数
 *
 * 将函数作为函数参数的三种形式
 * - 函数指针
 * - 函数符类(重载了()运算符的类，它的对象能被看作一个函数)
 * - lambda函数
 *
 * lambda函数语法：
 * auto func = [捕捉的自由参数]( ) [-> return_type]{ 函数体 }
 * - 当函数体只有一句return语句时，-> return_type可省略
 * - lambda函数的本质就是编译器会生成一个函数符类
 * */
