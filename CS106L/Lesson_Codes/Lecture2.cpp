//
// Created by Lenovo on 2024/4/29.
//
#include <sstream>
#include <iostream>

using namespace std;

int main(){
    // 流有4个状态位：
    // good bit：流状态良好，可使用方法bool good()来访问
    // eof bit：流达到文件末尾，可使用方法bool eof()来访问
    // fail bit：流读取（或输出）的数据类型与预期不符，可使用bool fail()来访问
    // bad bit：流发生了严重错误，通常是由于设备故障或不可恢复的错误导致的，可使用bool bad()来访问

    //流在后三个状态位被设置（为1）时，流就停止工作，无法进行输入输出


    //istringstream对象可以绑定一行字符串，然后以空格为分隔符把该行分隔开来



    return 0;
}