### Assignment3知识点总结

1. 定义concept的两种语法
   - 使用requires语法来定义隐式接口，语法格式：requires(){};
   - 使用std预定义的concept来定义显示接口
```c++
//定义显式接口numeric
template <typename T>
concept numeric = std::integral<T> || std::floating_point<T>;
//concept numeric = std::is_arithmetic_v<T>;

//两种语法混合使用
template< class From, class To >
concept convertible_to =
    std::is_convertible_v<From, To> &&
    requires {
        static_cast<To>(std::declval<From>());
    };
```


2. 一个条款：

使用std::transform的时候，要么选用自身作为输出容器，这时应传入.begin()方法；要么使用一个
新的容器做作为输出容器，这时应传入std::back_inserter()。

3. 按指定格式输出的语法
