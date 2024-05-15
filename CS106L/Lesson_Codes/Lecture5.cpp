//
// Created by warrior on 2024/5/5.
// 迭代器类型以及std::pair的用法

#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    std::vector<int> vec{5, 4, 3, 2, 1};
    for (auto i:vec){
        std::cout << i << ' ';
    }
    std::cout << std::endl;

    //find返回一个iterator，如果能找到则返回指向第一个val的iterator，否则返回end()
    auto it = find(vec.begin(), vec.end(), 5);
    if (it == vec.end()) std::cout << "Cannot find val";
    else std::cout << "Find " << *it << " successfully!";
    std::cout << std::endl;
    return 0;
}


/*
 * 几种创建std::pair<string, int>的方式
 * - std::pair<string, int> p{"Phone number", 6532565};  //uniform initialization 不仅可用于初始化结构体，基本上可用于初始化一切类型
 * - std::make_pair("Phone number", 6532565);
 * - {"Phone number", 6532565}; //结构体本身的定义
 * */

/*
 * 两个可用于迭代器遍历的方法，具体的使用方法待后续使用时再查询
 * lower_bound()
 * upper_bound()
 * */

/*五种迭代器的类型：
 * input iterator（顺序，只读，只能被单次解引用）
 *    ===> forward iterator（同时包含input iter和output iter的功能，能够多次解引用）
 *    ===> bidirectional iterator（能--的forward iter）===> random iterator（能jmup的bidirectional iter）
 * output iterator（顺序，只写，只能被单次解引用）
 * */


