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




/* c风格字符串可以直接赋给string对象，c风格字符串也可以直接与string对象进行比较
 * */


/* 文件读写流 ifstream、ofstream
 * 读：
 * - 单个字符：get()方法
 * - 单行字符：std::getline()函数
 * 写：
 * - << 运算符
 * */


/*
 * 迭代器遍历中使用erase删除vector中指定的元素后，迭代器会自动指向被删除元素的下一个元素
 * 解决方案：
 * 1.使用vector.erase()方法
 * - 修改迭代器的更新方式，当删除元素时it = vec.erase(it)，否则 ++it
 * - 由于从vector删除元素后，vector就不是原来的vector了，因此每当从vector删除元素后，我们就需要重新来遍历新的vector
 * 2.直接不使用vector.erase()方法
 * - 使用std::erase,std::erase_if(since c++20)
 * */


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
      exit(EXIT_FAILURE);
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
          }
      }
/*      for (auto iter = vector_of_courses.begin(); iter != vector_of_courses.end();){ //迭代器遍历删除vector指定元素
          if (iter->quarter != "null"){
              iter = vector_of_courses.erase(iter);
          }else{
              ++iter;
          }
      }*/

      //std::erase_if(vector_of_courses, [](Course & course){return course.quarter != "null";});   c++20用法

/*      while (true){   //范围遍历删除vector中指定元素
          bool flag = false;
          for (auto& item: vector_of_courses){
              if (item.quarter != "null") {
                  flag = true;
                  delete_elem_from_vector(vector_of_courses, item);
                  break;   //每当从vector中删除元素时，就需要重新使用一个for循环来遍历这个新的vector
              }

          }

          if (!flag)
              break;
      }*/
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
