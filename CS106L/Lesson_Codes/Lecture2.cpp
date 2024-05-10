//
// Created by Lenovo on 2024/4/29.
//
#include <sstream>
#include <iostream>
#include <stdexcept>
#include <limits>

using namespace std;

int stringToInteger(const string& str);
int getInteger(const string& prompt, const string& reprompt);
int main(){

/* StringStream
* 流有4个状态位：
     good bit：流状态良好，可使用方法bool good()来访问
     eof bit：流达到文件末尾，可使用方法bool eof()来访问
     fail bit：流读取（或输出）的数据类型与预期不符，可使用bool fail()来访问
     bad bit：流发生了严重错误，通常是由于设备故障或不可恢复的错误导致的，可使用bool bad()来访问*/
    string prompt = string("Please enter a number:");
    string reprompt = string("Error, please enter a number again:");
    int val = getInteger(prompt, reprompt);
    cout << "The number " << "is " << val << endl;
    return 0;
}

/* cout刷新缓冲区的三种情况：
 * - 输出缓冲区填满时
 * - 使用flush或endl来进行强制刷新
 * - 大多c++实现在即将输入时，会刷新输出缓冲区
 * */


/*
 * getline(stream, variable, ch)
 * 作用：从stream的缓冲区中读取字符，将其放入variable，直到遇到ch为止
 * 注意：
 * - ch不会被读入variable，但是会从缓冲区中清除(针对getline)
 * - cin会自动跳过新的一行中开头的空白字符
 *
 * cin.ignore()：忽略一个字符
 * - stream：代表流，可以是输入输出流，也可以是文件流
 * - variable：字符串变量
 * - ch：字符变量
 * 返回值：stream
 * */

int getInteger(const string& prompt, const string& reprompt){
    cout << prompt;
    string line;
    while(true){
        if (!getline(cin, line, '\n'))  throw domain_error("...");
        istringstream iss(line);
        int val;
        char remain;
        if (iss >> val && !(iss >> remain)) return val;
        cout << reprompt << endl;
        //iss.clear();  清空流的状态位
        //iss.ignore(numeric_limits<streamsize>::max(), '\n');    清空缓冲区
    }
}


/*
 * pair:  template<typename T1, typename T2>struct
 * e.g.  auto [min, max] = findPriceRange(dist);
 *       pair<int, int> findPriceRange(int dist){
 *          ...
 *       }
 * */







//istringstream对象可以绑定一行字符串，然后以空格为分隔符把该行分隔开来(行缓冲)
int stringToInteger(const string& str){
    istringstream iss(str);
    char ch;
    int res;
    // stream被用作bool值等价于 !stream.fail()
    if (!(iss >> res) || iss >> ch)
        throw domain_error("...");
/* try{} catch [()]{}语块
 * 对于抛出的异常，如果不进行捕获，则程序在发现异常时会终止运行；
    而如果使用catch语句进行捕获后，则程序可以继续运行下去。
    try{
        char ch;
        iss >> ch;
        if (!iss.fail()) throw domain_error("...");
    }
    catch(...){
        cout << "error" << endl;
    }*/
    return res;
}