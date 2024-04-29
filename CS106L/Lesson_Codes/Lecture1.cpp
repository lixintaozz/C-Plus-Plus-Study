//
// Created by Lenovo on 2024/4/28.
//字符串流StringStream
#include<sstream>
#include<iostream>


using namespace std;

//流在c++中是一种抽象概念，c++程序通过将数据输入输出流，然后流再将数据输入输出外部设备（常见有显示屏、键盘等）
//从而简化了程序与外部设备的数据交换。我们在编写程序时只需要与流进行交互，而无需关注外部设备
//我们一般通过一些stream类来操作流，流中通常会具有缓冲区
int main(){
    //使用字符串初始化时，可以指定mode为 stringstream::ate ，这样后面进入流的字符串才会追加在初始化字符串的末尾
    //否则进入流的字符串会先覆盖原字符串
    ostringstream oss("Ito En Green Tea");
    //ostringstream  oss("Ito En Green Tea", stringstream::ate);


    //oss.seekp(0L, ios::end);     等价于   ostringstream  oss("Ito En Green Tea", stringstream::ate);
    //seekp和seekg都是用于操作文件读写位置的方法，第一个参数为偏移量（可以为负），第二个参数指定起始位置
    cout << oss.str() << endl;

    oss << 16.9 << " Ounce";
    cout << oss.str() << endl;


    //oss不能直接输出，是因为ostringstream将数据以字符串的形式存储在内存中，而不是直接输出到屏幕或文件
    oss << "(Pack of " << 12 << ")";
    cout << oss.str() << endl;
    return 0;
}



