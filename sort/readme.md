测试Sort算法，包括 冒泡排序、选择排序、插入排序  快速排序、归并排序、基数排序、希尔排序

##开启o2优化前输出如下：
====== Sorting Algorithm Performance Test ======
Data Size: n = 100000
-----------------------------------------------

O(n^2):
Bubble Sort                        10076 ms
Selection Sort                     4134 ms
Insertion Sort                     2877 ms

O(n log n):
Quick Sort (first pivot)           20 ms
Three-Way Quick Sort (random pivot)24 ms
Merge Sort                         21 ms

Other:
Base Sort                          37 ms
Shell Sort                         27 ms
================================================

##开启o2优化后输出如下：
====== Sorting Algorithm Performance Test ======
Data Size: n = 100000
-----------------------------------------------

O(n^2):
Bubble Sort                        3676 ms
Selection Sort                     8785 ms
Insertion Sort                     1144 ms

O(n log n):
Quick Sort (first pivot)           17 ms
Three-Way Quick Sort (random pivot)22 ms
Merge Sort                         21 ms

Other:
Base Sort                          19 ms
Shell Sort                         20 ms
================================================



注：洛谷 p1177 题解
1、关于test.sh的使用方法，linux环境下输入命令 chmod -x test.sh，译为change mode to executable
2、本文件夹下有test_rand_max，测试了rand()函数的最大值，结果为INT_MAX,生成0~INT_MAX之间的伪随机数
3、关于O2优化，值得注意的是选择排序有较大程度的负优化
4、使用第一个元素为基准的双指针快速排序速度最快
5、在INT_MAX下，baseSort函数有过报错，原因在于取的exp超出了INT最大范围变成负数，应初始化long long
6、未测试与树相关的排序方法：如堆排序、二叉树排序， 未测试分块优化