---
title: C++ 入门基础
toc: true
categories: [C++, 基础]
tags: C++
---
<!-- more -->
## 注释风格
推荐用`//`

## 头文件名

![头文件命名约定](/post_gallery/Cplusplus/day1_1.png)

前缀c表示转换后的C

## 名称空间

```
using namespace std;	// lazy approach, all names available
```

表示不必使用`std::`前缀,更好的方法是只使所需的名称可用:

```
using std::cout;	// make cout available
```

## c++中关于cout与printf的简单区别

cin cout效率没scanf printf高

[结论](https://blog.csdn.net/qq_42191017/article/details/81709315)
[cin与scanf cout与printf效率问题](https://blog.csdn.net/l2580258/article/details/51319387)

## lambda闭包

Lambda函数的语法定义如下：

```
[capture](parameters) mutable ->return-type{statement}
```

其中：

`[capture]：`捕捉列表。捕捉列表总是出现在 lambda 表达式的开始处。事实上，[] 是 lambda 引出符。编译器根据该引出符判断接下来的代码是否是 lambda 函数。捕捉列表能够捕捉上下文中的变量供 lambda 函数使用。
`(parameters)：`参数列表。与普通函数的参数列表一致。如果不需要参数传递，则可以连同括号 () 一起省略。
`mutable：mutable` 修饰符。默认情况下，lambda 函数总是一个 const 函数，mutable 可以取消其常量性。在使用该修饰符时，参数列表不可省略（即使参数为空）。
`->return_type`：返回类型。用追踪返回类型形式声明函数的返回类型。出于方便，不需要返回值的时候也可以连同符号 -> 一起省略。此外，在返回类型明确的情况下，也可以省略该部分，让编译器对返回类型进行推导。
`{statement}`：函数体。内容与普通函数一样，不过除了可以使用参数之外，还可以使用所有捕获的变量。

在 lambda 函数的定义式中，参数列表和返回类型都是可选部分，而捕捉列表和函数体都可能为空，C++ 中最简单的 lambda 函数只需要声明为：
在Lambda表达式内可以访问当前作用域的变量，这是Lambda表达式的闭包（Closure）行为。

[Python闭包](http://baijiahao.baidu.com/s?id=1601023189180094497&wfr=spider&for=pc)
lambda: 见图片

## 基于范围的for循环(C++11)

for 语句允许简单的范围迭代：

```
int my_array[5] = {1, 2, 3, 4, 5};
// 每个数组元素乘于 2
for (int &x : my_array)
{
    x *= 2;
    cout << x << endl;  
}
// auto 类型也是 C++11 新标准中的，用来自动获取变量的类型
for (auto &x : my_array) {
    x *= 2;
    cout << x << endl;  
}
```

## C++ 随机数

关于随机数生成器，有两个相关的函数。一个是 rand()，该函数只返回一个伪随机数。生成随机数之前必须先调用 srand() 函数。

srand函数是随机数发生器的初始化函数。

原型： void srand(unsigned seed);

用法：它需要提供一个种子，这个种子会对应一个随机数，如果使用相同的种子后面的rand()函数会出现一样的随机数。如： srand(1); 直接使用 1 来初始化种子。不过为了防止随机数每次重复，常常使用系统时间来初始化，即使用 time 函数来获得系统时间，它的返回值为从 00:00:00 GMT, January 1, 1970 到现在所持续的秒数，然后将 time_t 型数据转化为(unsigned)型再传给 srand 函数，即： srand((unsigned) time(&t)); 还有一个经常用法，不需要定义time_t型t变量,即： srand((unsigned) time(NULL)); 直接传入一个空指针，因为你的程序中往往并不需要经过参数获得的t数据。

下面是一个关于生成随机数的简单实例。实例中使用了 time() 函数来获取系统时间的秒数，通过调用 rand() 函数来生成随机数：
```
#include <stdlib.h>
#include <stdio.h>
#include <time.h> /*用到了time函数，所以要有这个头文件*/
#define MAX 10
 
int main( void)
{
    int number[MAX] = {0};
    int i;
    srand((unsigned) time(NULL)); /*播种子*/
    for(i = 0; i < MAX; i++)
    {
        number[i] = rand() % 100; /*产生100以内的随机整数*/
        printf("%d ", number[i]);
    }
    printf("\n");
    return 0;
}
```

## 




























