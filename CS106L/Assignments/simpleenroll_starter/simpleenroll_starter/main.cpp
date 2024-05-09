/*
 * CS106L SimpleEnroll Assignment Part 1
 * Created by Fabio Ibanez
 */

#include "utils.cpp"
#include <exception>
#include <iostream>
#include <system_error>
#include <vector>

/*
 * 原始字符串字面值：R"(字符串)" ----不进行任何转义的字符串  tip:windows文件系统的路径为反斜杠
 * c++会生成exe文件，所以使用相对路径时，相对的路径应该是exe文件所在的路径，而非cpp源文件所在的路径
 * */
std::string COURSES_PATH = "courses.csv";    //全局变量，可以被该文件中的所有函数访问
                                             //定义在函数内的变量称为局部变量，只能在函数内部访问

bool structTest() {
  Course c{"Standard C++ Programming", "1", "2023-2024 Winter"}; //结构体中也能添加成员函数？
  return true;
}


//命令行处理技术：argc表示参数个数（包含命令本身），argv表示一个字符指针数组
int main(int argc, char* argv[]) {
  std::vector<Course> vector_of_courses;

  if (!structTest()) {
    std::cerr << "structTest Failed 😞";  //cerr流无缓冲区，clog流有缓冲区
  } else {
    std::cout << "structTest Passed! ✅" << '\n';
  }

  parse_csv(COURSES_PATH, vector_of_courses);

  write_courses_offered(vector_of_courses);

  write_courses_not_offered(vector_of_courses);


  FILE *pipe = popen("python3 utils/autograder.py", "r");
  if (!pipe)
    return -1;

  char buffer[128];
  while (!feof(pipe)) {
    if (fgets(buffer, 128, pipe) != NULL)
      std::cout << buffer;
  }
  pclose(pipe);

  // uncomment this line to debug
   //print_vector(vector_of_courses);
  return 0;
}
