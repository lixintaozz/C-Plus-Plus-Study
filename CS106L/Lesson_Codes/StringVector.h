//
// Created by Lenovo on 2024/5/18.
//

#ifndef CS106L_STRINGVECTOR_H
#define CS106L_STRINGVECTOR_H

#include <iostream>
#include <vector>
#include <iterator>

using namespace std;


class StringVector{
    vector<string> vec;
public:
    StringVector(const initializer_list<string>& init);
    void push_back(const string& str);
    StringVector& operator+=(const string& str);
    friend StringVector operator+(const StringVector& str1, const StringVector& str2);
    friend ostream& operator<<(ostream& os, const StringVector& stringVector);
    StringVector(const StringVector& sv)noexcept;

};



#endif //CS106L_STRINGVECTOR_H
