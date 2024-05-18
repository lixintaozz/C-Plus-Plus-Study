//
// Created by warrior on 2024/5/15.
// 运算符重载
#include "Lecture11.h"

using namespace std;


//使用initializer_list定义构造函数
StringVector::StringVector(const initializer_list<std::string> &init): vec(init) {}

void StringVector::push_back(const std::string &str) {
    vec.push_back(str);
}

StringVector& StringVector::operator+=(const std::string &str) {
    vec.push_back(str);
    return *this;
}

StringVector operator+(const StringVector& vec1, const StringVector& vec2){
    StringVector res = vec1;
/*    for (const auto& item:vec2.vec){
        res.vec.push_back(item);
    }*/
    //back_inserter从容器后面插值，并且能够自动扩充容器容量
    copy(vec2.vec.begin(),vec2.vec.end(), back_inserter(res.vec));
    return res;
}

// <<只能重载为普通函数，不能重载为成员函数
// 重载输出流操作符 << 作为友元函数的原因是因为该函数需要访问 StringVector 类的私有成员 vec。
ostream& operator<<(ostream& os, const StringVector& stringVector){
    os << "StringVector:";
    //使用ostream_iterator<>(输出流，分隔符)来输出
    copy(stringVector.vec.begin(),stringVector.vec.end(),ostream_iterator<string>(os," "));
    return os;
}




int main(int argc, char* argv[]){
    StringVector vec1{"abc", "def"};
    StringVector vec2{"ghi", "jkl", "mno"};
    StringVector res = vec1 + vec2;
    cout << res;
    //cout  << vec1 << endl;
    //vec1.push_back("cgcl");
    //cout  << vec1 << endl;
    //cout << vec3 << endl;
    return 0;
}
