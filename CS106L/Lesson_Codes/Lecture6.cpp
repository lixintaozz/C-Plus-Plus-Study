//
// Created by Lenovo on 2024/5/6.
// Template

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

//Todo:还有一个例子要实现泛型化
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
        //Todo:typeid的用法
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
    double res = getTypeValue<double>();
    cout << "The value is: " << res << endl;
    return 0;
}