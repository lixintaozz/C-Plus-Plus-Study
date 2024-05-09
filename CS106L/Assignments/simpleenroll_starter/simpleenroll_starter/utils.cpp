/*
 * CS106L SimpleEnroll Assignment Part 1
 * Created by Fabio Ibanez
 * Please complete each STUDENT TODO in this file.
 *
 * Students must implement: parse_csv, write_courses_offered,
 * write_courses_not_offered
 */

#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string>


//Todo: 1.文件读写流的使用
//      2.cstring和string的区别，使用区别
//      3.vector删除的坑

// STUDENT
//路径是正斜杠还是反斜杠都可以，只要当是反斜杠时，注意避免转义就行
std::string COURSES_OFFERED_CSV_PATH = "student_output/courses_offered.csv";

std::string COURSES_NOT_OFFERED_CSV_PATH = "student_output/courses_not_offered.csv";

//c++中类和结构体的 使用方式 基本一致
struct Course {
  std::string title;
  std::string number_of_units;
  std::string quarter;

  // 在类的成员函数形参列表后添加const限定符，能够将this指针转换为一个常量指针，从而保证无法通过this指针来修改成员变量的值
  // 类的每个成员函数都有隐式的this指针，包括构造和析构函数
  bool operator==(const Course &other) const {
    return title == other.title && number_of_units == other.number_of_units &&
           quarter == other.quarter;
  }
};

// forward declarations
void delete_elem_from_vector(std::vector<Course> &v, Course &elem);
std::vector<std::string> split(std::string s, char delim);

/*
 * This function should populate the vector_of_courses with structs of type
 * Class We want to create these structs with the records in the courses.csv
 * file, where each line is a record!
 *
 * Hints:
 * 1) Take a look at the split function we provide
 * 2) Each LINE is a record! *this is important, so we're saying it again :>)*
 */
void parse_csv(const std::string& filename, std::vector<Course>& vector_of_courses){
  std::ifstream ifs;    //定义文件流对象
  ifs.open(filename);   //将文件流对象与某一文件绑定
  if (!ifs.is_open()) {
      std::cout << "Oops, open csv file fails!" << std::endl;
      exit(1);
  }
  std::string line;
  std::getline(ifs, line);  //跳过第一行
  while (std::getline(ifs, line)){
      auto vec = split(line, ',');
      Course course{vec.at(0), vec.at(1), vec.at(2)};
      vector_of_courses.push_back(course);
  }
  std::cout << "Read in csv file successfully!" << std::endl;
  ifs.close();   //断开文件流对象与某一文件的连接，但该文件流对象仍可连接到其他文件
}

/*
 * This function has TWO requirements.
 * 1) Write the courses that are offered to the file courses_offered.csv inside
 * the student_output folder
 *
 * 2) Delete classes that are offered from vector_of_courses.
 * IMPORTANT: do this after you write out to the file!
 *
 * HINTS:
 * 1) Keep track of the classes that you need to delete!
 * 2) Use the delete_elem_from_vector function we give you!
 */
void write_courses_offered(std::vector<Course>& vector_of_courses) {
  std::ofstream ofs;
  ofs.open(COURSES_OFFERED_CSV_PATH);
  if (!ofs.is_open())
      std::cout << "Oops, open csv file fails!" << std::endl;
  else{
      for(auto& item: vector_of_courses){
          if (item.quarter != "null"){
              ofs << item.title << ","
                  << item.number_of_units << ","
                  << item.quarter << std::endl;
              //删除可能会有问题？？？
              //delete_elem_from_vector(vector_of_courses, item);
          }
      }
  }
  ofs.close();
}

/*
 * This function writes the courses NOT offered to the file
 * courses_not_offered.csv inside of the student_output folder
 *
 * This function is ALWAYS called after the write_courses_offered function.
 * vector_of_courses will trivially contain classes that are not offered
 * since you delete offered classes from vector_of_courses in the
 * 'write_courses_offered' function.
 *
 * HINT: This should be VERY similar to write_courses_offered
 */
void write_courses_not_offered(std::vector<Course>& vector_of_courses) {
  std::ofstream ofs;
  ofs.open(COURSES_NOT_OFFERED_CSV_PATH);
  if (!ofs.is_open())
      std::cout << "Oops, open csv file fails!" << std::endl;
  else{
      for(auto& item: vector_of_courses){
          //cstring为什么可以直接赋给string,文件流的参数为什么得是cstring？？？
          if (item.quarter == "null")
            ofs << item.title << ","
                << item.number_of_units << ","
                << item.quarter << std::endl;
      }
  }
  ofs.close();
}

/* ######## HEYA! DON'T MODIFY ANYTHING BEYOND THIS POINT THX ######## */

// TODO: ADD DOCUMENTATION COMMENTS
void print_vector(std::vector<Course> vector_of_courses) {
  for (int i = 1; i < vector_of_courses.size(); ++i) {
    std::cout << vector_of_courses[i].title << ","
              << vector_of_courses[i].number_of_units << ","
              << vector_of_courses[i].quarter << std::endl;
  }
}

void delete_elem_from_vector(std::vector<Course> &v, Course &elem) {
  auto it = std::find(v.begin(), v.end(), elem);
  v.erase(it);
}

std::vector<std::string> split(std::string s, char delim) {
  std::vector<std::string> return_vec;
  std::stringstream ss(s);
  std::string token;
  while (getline(ss, token, ',')) {
    return_vec.push_back(token);
  }
  return return_vec;
}
