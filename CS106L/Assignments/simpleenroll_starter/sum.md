### Assignment1知识点总结

#### C风格字符串与std::string
1. std::string实现了一个参数类型为const char*的构造函数，因此可以直接用c风格字符串来初始化std::string,
而且c风格字符串也可以直接与string对象进行比较
2. R"()"是一种特殊格式的C风格字符串，它不会对字符串中的字符进行转义
3. c++是一种编译语言而不是解释语言，它会为源代码文件生成一个可执行文件，因此源代码中有关文件的相对路径应当
是相对于可执行文件所在目录的路径

#### 文件读写方式
1. 流:ifstream、ofstream
2. 检查文件是否打开：.is_open()方法
3. 读取文件：
   - 一次读取一行：std::getline()
   - 一次读取一个字符：.get()方法
4. 写入文件： << 运算符

#### 遍历删除vector中的元素
1. 存在的问题：迭代器遍历中使用erase删除vector中指定的元素后，迭代器会自动指向被删除元素的下一个元素
2. 解决方案：

使用.erase()方法
- 修改迭代器的更新方式，当删除元素时it = vec.erase(it)，否则 ++it
- 由于从vector删除元素后，vector就不是原来的vector了，因此每当从vector删除元素后，我们就需要重新来遍历新的vector

使用std::erase()、std::erase_if()直接删除

5. 常量成员函数
 - 在类的成员函数形参列表后添加const限定符，能够将this指针转换为一个常量指针，从而保证无法通过this指针来修
 改成员变量的值
- 类的每个成员函数都有隐式的this指针，包括构造和析构函数

6. 使用stringstream来实现split函数
```c++
std::vector<std::string> split(std::string s, char delim) {
  std::vector<std::string> return_vec;
  std::stringstream ss(s);
  std::string token;
  while (getline(ss, token, ',')) {
    return_vec.push_back(token);
  }
  return return_vec;
}

```