//
// Created by Lenovo on 2024/5/13.
//

#include <iostream>
#include <algorithm>
#include <cctype>

using namespace std;

int main(int argc, char* argv[]){
    string str{"avcTEgehGHJJlkdj"};
    cout << "Before process: " << str << endl;
    string res = "";
    auto op = [](char& ch){return (char)(ch + 1);};
    //transform对容器中的元素进行转换
    //Todo:为什么unary predicate使用std::tolower()不行？？？
    transform(str.begin(),str.end(), str.begin(), op);
    cout << "After process: " << str << endl;
    return 0;
}
