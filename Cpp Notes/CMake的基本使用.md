#### CMake的基本使用





##### CMake三个主要的工作阶段

- 配置阶段：这个阶段会读取存储在源码树目录中的项目信息，收集工作环境的信息。通过执行CMakeLists.txt文件来收集项目的结构，目标和依赖项等信息。并创建一个 CMakeCache.txt文件，节省下次配置期间的时间开销

- 生成阶段：读取项目配置之后，CMake将为当前工作环境生成一个构建系统（例如 MakeFile文件）。构建系统是其他构建工具的简化配置文件。

- 构建阶段：构建器根据构建系统，组织系统中的编译器、链接器等进行构建，生成目标文件（一般为可执行文件）

    

#### CMake构建项目的主要步骤（重要）

1. 生成项目构建系统（即对应上面的配置阶段和生成阶段）

    ```cmake
    cmake -S <path to source> -B <path to build>
    	  -C <cache script>
    	  -D //修改缓存变量
    
    
    //用于调试和跟踪的命令
    cmake --system-information [file]    
    cmake --log-level=<level>
    cmake --trace
    
    ```

2. 构建项目（build）

    ```cmake
    cmake --build <path to build> [--<build-tool-options>]
    	  --verbose  //显示调试信息  
    ```

3. 安装项目

    构建工件（一般为可执行文件）后，可以将其复制到正确的目录中

    ```cmake
    cmake --install <path to build>
    	  -- prefix   //在项目配置中指定的安装路径前面添加前缀
    	  -- verbose  //指定调试信息
    ```



#### 一些基本概念

- 文件列表：指包含CMake语言的文件
- CMakeLists.txt：至少需要包含两个命令
    - cmake_minimum_required(VERSION <x.xx>)
    - project(<name><OPTIONS>)，提供的名称将存储在PROJECT_NAME中

