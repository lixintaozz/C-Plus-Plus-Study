### Ubuntu下安装gcc-13.3.0

#### 采用的是源码安装的方式





#### 首先按照下面的博客安装gcc-13.3.0

参考这篇博客[Linux系统ubuntu22.04安装最新版的gcc13.1.0编译器，支持c++20、23_gcc-13.1.0.tar.gz下载-CSDN博客](https://blog.csdn.net/weixin_48617416/article/details/131729829?spm=1001.2014.3001.5506)





#### 由于系统中可能存在多个gcc版本，正常情况下参考以下链接来切换版本

参考这篇博客https://blog.csdn.net/m0_51661400/article/details/134872446

这里我测试了博客中的第二种方法：
将gcc-13.3.0的可执行文件（一般是：/usr/local/bin）的路径添加到PATH中





#### 修改系统的.so动态库文件的搜索路径


1. 参考这篇博客[添加lib库自动搜索路径到/etc/ld.so.conf,然后ldconfig使设置生效_libopen-rte.so ldconfig-CSDN博客](https://blog.csdn.net/xpy123/article/details/45039213)。

注意：这篇博客的修改ld.so.conf的方式有问题，不需要在路径前面加include，直接把路径加进去就行

2. 修改bashrc
```shell
vim ~/.bashrc
export LD_LIBRARY_PATH=[your path]:$LD_LIBRARY_PATH
```

