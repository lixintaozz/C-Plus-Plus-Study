//
// Created by Lenovo on 2024/5/11.
// 常见的STL算法的使用方法

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iterator>

using namespace std;

int main(){
    vector<int> vec{1, 2, 3, 7, 6, 9, 2, 4, 8};
/*    auto cmp = [](const int& x, const int& y){return x < y;};
    auto [min, max] = minmax_element(vec.begin() + 3,vec.end(), cmp);
    cout << "min:" << *min << " max:" << *max <<endl;*/

/*Todo:find their usage
    auto doub = [](const int& sum, const int& y){return sum + 1;};
    int res = accumulate(vec.begin(), vec.end(), 0, doub);
    cout << res << endl;

    transform(vec.begin(), vec.end(), vec.begin(),
              [](int item) { return item + 1; });
    for (auto item: vec) {
        cout << item << " ";
    }*/



/*  STL的nth_element是一个非常有用的算法，它用于重新排列元素，
    以便第n个位置的元素（假如所有元素都经过排序）会出现在其应有的位置上，
    而且它前面的所有元素都不大于它，它后面的所有元素都不小于它。
    时间复杂度为o(n)，比快排快
    注意：容器中的元素不是有序的

 *  nth_element(vec.begin(), vec.begin() + 6 , vec.end());
 *  //输出调整后位于第7位置的元素（索引为6，因为开始于0）
    cout << "The seventh element is "  << vec[6] << endl;
    for (auto item: vec){
        cout << item << " ";
    }*/

/*  copy_if是一个算法函数，通常用于从一个容器中复制满足特定条件的元素到另一个容器中。
    copy_if不会扩容，使用iterator adaptor可以解决这个问题*/
    vector<int> vec1(4);
    vector<int> vec2(0);
    auto dep = [](int& x){return x >= 6;};
    auto print = [](const vector<int>& v){for (auto item:v) cout << item << " ";};
    copy_if(vec.begin(), vec.end(), vec1.begin(), dep);
    copy_if(vec.begin(), vec.end(), back_inserter(vec2), dep);
    print(vec1);
    cout << endl;
    print(vec2);

/* std::ostream_iterator的构造函数接受两个参数：输出流对象和一个分隔符字符串。
 * 当使用std::ostream_iterator来输出元素时，每次将一个元素放入std::ostream_iterator后，
 * 该元素会被写入到输出流中，并在它之后添加指定的分隔符字符串。
    copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));*/

    return 0;
}


/*
 * 不同容器在使用erase()方法删除某元素后，对其迭代器会造成的影响
 * 共同影响：被删除元素的迭代器会失效
 * vector：在被删元素之后所有的迭代器均失效
 * deque：所有迭代器均失效（除非被删除元素在链头或链尾）
 * */

/* 常见的STL函数
 * - std::sort()    对容器进行排序
 * - std::nth_element()     先对容器进行排序，然后返回指向第n个元素的迭代器
 * - std::stable_partition()     将符合unary predicate的元素放在前面，不符合的放在后面，元素之间的相对顺序不变
 * - std::copy_if()  输出容器使用back_inserter()
 * - std::copy()   将容器内容复制到输出流cout中，即实现了输出
 * - std::remove_if()  配合erase()方法一起使用  将需要删除的元素移到容器尾部，返回指向删除元素后的容器的最后一个元素后的迭代器，它不能改变容器的大小
 * - std::find()   对于set和map而言，自身的find()方法比stl::find()更快
 * - std::minmax_element()   返回指向容器中最大元素和最小元素的迭代器
 * */