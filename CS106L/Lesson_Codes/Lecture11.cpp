//
// Created by warrior on 2024/5/15.
// 运算符重载
#include "StringVector.cpp"


using namespace std;


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
