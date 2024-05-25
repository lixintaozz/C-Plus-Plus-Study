/* 
Assignment 2: Marriage Pact

This assignment asks you to discover your one true love using containers and pointers.
There are two parts: implement get_applicants and find_matches.

Submit to Paperless by 11:59pm on 2/1/2024.
*/

#include <iostream>
#include <string>
#include <queue>
#include <set>
#include <fstream>
#include <vector>
#include <sstream>

const std::string path = "students.txt";

//使用std::getline()来实现split函数，返回值为std::vector
std::vector<std::string> split(const std::string& str, std::vector<std::string>& sv){
    std::stringstream ss(str);
    std::string s;
    while (std::getline(ss, s, ' ')){
        sv.push_back(s);
    }
    return sv;
}


std::set<std::string> get_applicants(const std::string& filename) {

    std::ifstream ifs(filename);
    //使用is_open()方法来检查文件是否打开
    if (!ifs.is_open()){
        std::cout << "Oops, File can't open!" << std::endl;
        exit(EXIT_FAILURE);
    }
    std::string line;
    std::set<std::string> sets;
    while (std::getline(ifs, line)){
        sets.insert(line);
        //std::cout << line << std::endl;
    }
    return sets;
}

std::queue<std::string*> find_matches(std::set<std::string> &students) {
    //假设名字叫Stephen Curry
    std::queue<std::string *> queue;
    for (auto &item: students) {
/*         size_t pos = item.find(" ") + 1;
        bool flag = item[0] == 'S' && item[pos] == 'C'; */
        
        //使用自己定义的split函数来实现
        std::vector<std::string> sv;
        sv.reserve(2);
        split(item, sv);
        bool flag = sv[0][0] == 'S' && sv[1][0] == 'C';

        if (flag) {
            // 在C++中，std::set 内部存储的元素默认为const
            // 在编译器层面，这意味着如果您尝试获取 std::set 中一个元素的指针，
            // 您将得到一个指向 const 数据的指针（即 const std::string*）
            // 因此在这里需要使用const_cast<std::string*>()将其转换为std::string*
            auto p = const_cast<std::string *>(&item);
            queue.push(p);
        }
    }
    return queue;
}



int main(){
    auto set = get_applicants(path);
    auto queue = find_matches(set);
    while(!queue.empty()){
        std::cout << *queue.front()  << std::endl;
        queue.pop();
    }
    return 0;
}
