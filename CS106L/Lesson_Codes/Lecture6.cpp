//
// Created by warrior on 2024/5/6.
// Template

#include <iostream>
#include <vector>
#include <sstream>
#include <iterator>

using namespace std;

//一个要实现泛型化的例子：
//形参使用常引用的一个好处是，它既可以接受常引用，也可以接受普通引用
template <typename T>
tuple<bool, int, int> mismatch(const T& vec1, const T& vec2){
    auto iter1 = vec1.begin();
    auto iter2 = vec2.begin();
    while (iter1 != vec1.end() && *iter1 == *iter2){
        ++ iter1;
        ++ iter2;
    }
    if (iter1 == vec1.end()) return {true, 0, 0};
    //std::distance函数返回两个迭代器之间的距离，在遍历时可用于替代index
    else return {false, distance(vec1.begin(), iter1), distance(vec2.begin(),iter2)};
}


//泛型编程
template <typename input_iterator, typename datatype>
int countOccurences(input_iterator begin, input_iterator end, datatype val){
    int count = 0;
    for(auto it = begin; it != end; ++ it){
        if (*it == val) ++count;
    }
    return count;
}

template <typename T>
T getTypeValue(){
    while(true){
        //typeid(T).name返回类型T的名称，具体返回值取决于编译器的实现，返回的名称通常是
        //编译器内部使用的名称，并不一定是易于人类阅读的形式
        cout << "Please enter a " << typeid(T).name() << ":" << endl;
        string line;T res; char remain;
        if (!getline(cin,line))
            throw domain_error("...");
        istringstream iss(line);
        //使用istringstream对象iss来实现类型转换
        if ((iss >> res) && !(iss >> remain)) return res;
        else cout << "Please enter again!" << endl;
    }
}



int main(){
/*    std::vector<int> myvec{1, 2, 3, 3, 7, 6};
    int val = 3;
    cout << countOccurences(myvec.begin(), myvec.end(), val) << endl;*/
/*    double res = getTypeValue<double>();
    cout << "The value is: " << res << endl;*/
    vector<int> vec1{1, 2, 3, 4, 5};
    vector<int> vec2{1, 2, 3, 4, 6};
    auto [equal, index1, index2] = mismatch(vec1, vec2);
    if (equal) cout << "vec1 matchs vec2!" <<endl;
    else cout << "Oops! vec1 mismatchs vec2 at index: " << index1 << endl;
    return 0;
}