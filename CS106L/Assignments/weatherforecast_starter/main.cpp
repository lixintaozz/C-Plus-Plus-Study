/* 
Assignment 4: Weather Forecast

This assignment works with template functions and lambdas to become the best weather forecaster
at the Stanford Daily. Be sure to read the assignment details in the PDF.

Submit to Paperless by 11:59pm on 2/16/2024.
*/


#include <iostream>
#include <vector>
#include <fstream>
#include <concepts>
#include <algorithm>
#include <numeric>

// Todo：深入研究concept的用法
// 定义自己的concept：既可以使用std的concept来定义显示接口，也可使用requires来定义更加复杂的隐式接口
template <typename T>
concept numeric = std::integral<T> || std::floating_point<T>;

 //使用requires来定义
/* template <typename T>
concept num = requires(){隐式接口};*/

template <numeric T>
double convert_f_to_c(T data){
    return (data - 32) * 5.0 / 9.0;
}



template<typename Function>
std::vector<double> get_forecast(std::vector<std::vector<int>>& readings, Function fn) {
    std::vector<double> res;
    for (const auto& vec: readings){
        res.push_back(fn(vec));
    }
    return res;
}

int main() {
    std::vector<std::vector<int>> readings = {
        {70, 75, 80, 85, 90},
        {60, 65, 70, 75, 80},
        {50, 55, 60, 65, 70},
        {40, 45, 50, 55, 60},
        {30, 35, 40, 45, 50},
        {50, 55, 61, 65, 70},
        {40, 45, 50, 55, 60}
    };

    std::ofstream ofs("output.txt");
    if (!ofs.is_open()){
        std::cout << "Oops, open fails!" << std::endl;
        exit(EXIT_FAILURE);
    }


    // TODO: Convert temperatures to Celsius and output to output.txt
    std::vector<double> res0;
    for (const auto& item: readings){
        std::transform(item.begin(), item.end(), std::back_inserter(res0), convert_f_to_c<int>);
        for (const auto& num: res0){
            ofs << num << " ";
        }
        ofs << std::endl;
        res0.clear();
    }


    // TODO: Find the maximum temperature for each day and output to output.txt
    auto max = [](const std::vector<int>& x){return static_cast<double > (*std::max_element(x.begin(), x.end()));};
    std::vector<double> res1 = get_forecast(readings, max);
    for (const auto& n: res1){
        ofs << n << " ";
    }
    ofs << std::endl;
    // TODO: Find the minimum temperature for each day and output to output.txt
    auto min = [](const std::vector<int>& x){return static_cast<double > (*std::min_element(x.begin(), x.end()));};
    std::vector<double> res2 = get_forecast(readings, min);
    for (const auto& n: res2){
        ofs << n << " ";
    }
    ofs << std::endl;
    // TODO: Find the average temperature for each day and output to output.txt
    auto aver = [](const std::vector<int>& x){return std::accumulate(x.begin(), x.end(), 0) / static_cast<double>(x.size());};
    std::vector<double> res3 = get_forecast(readings, aver);
    for (const auto& n: res3){
        ofs << n << " ";
    }
    ofs << std::endl;
    return 0;
}