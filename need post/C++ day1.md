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

## 指针

`*` 来返回位于操作数所指定地址的变量的值

在变量声明的时候，如果没有确切的地址可以赋值，为指针变量赋一个 `NULL` 值是一个良好的编程习惯。赋为 `NULL` 值的指针被称为空指针

```
#include <iostream>

using namespace std;

int main ()
{
   int  *ptr = NULL;

   cout << "ptr 的值是 " << ptr ;
 
   return 0;
}
```

输出：

```
ptr 的值是 0
```

### 指针运算

```
ptr++
```

在执行完上述的运算之后，`ptr` 将指向位置 1004，因为 `ptr` 每增加一次，它都将指向下一个整数位置，即当前位置往后移 4 个字节。

这个运算会在不影响内存位置中实际值的情况下，移动指针到下一个内存位置。

如果 `ptr` 指向一个地址为 1000 的字符，上面的运算会导致指针指向位置 1001，因为下一个字符位置是在 1001。

### C++ 指针数组

下面是一个指向整数的指针数组的声明：

```
int *ptr[MAX];
```

```
#include <iostream>
 
using namespace std;
const int MAX = 3;
 
int main ()
{
   int  var[MAX] = {10, 100, 200};
   int *ptr[MAX];
 
   for (int i = 0; i < MAX; i++)
   {
      ptr[i] = &var[i]; // 赋值为整数的地址
   }
   for (int i = 0; i < MAX; i++)
   {
      cout << "Value of var[" << i << "] = ";
      cout << *ptr[i] << endl;
   }
   return 0;
}
```

当上面的代码被编译和执行时，它会产生下列结果：

```
Value of var[0] = 10
Value of var[1] = 100
Value of var[2] = 200
```

### 指向字符的指针数组来存储一个字符串

字符串数组只能是对应一个字符串，而指针数组里每一个元素都是一个字符串

```
#include <iostream>
 
using namespace std;
const int MAX = 4;
 
int main ()
{
  const char* names[MAX] = {     
                   "Zara Ali",
                   "Hina Ali",
                   "Nuha Ali",
                   "Sara Ali",
  };
 
  for (int i = 0; i < MAX; i++){
      cout << "Value of names[" << i << "] = ";
      cout << names[i] << endl;
      cout << &names[i] << endl;  // 每个元素的地址
      cout << *(names+1) << endl;  // names是指向第一个元素的指针: const char* [4]
  }     
  return 0;    
}
```

### C++ 指向指针的指针（多级间接寻址）

```
int **var;
```

当一个目标值被一个指针间接指向到另一个指针时，访问这个值需要使用两个星号运算符

### 能接受指针作为参数的函数，也能接受数组作为参数

```
#include <iostream>
using namespace std;
 
// 函数声明
double getAverage(int *arr, int size);
 
int main ()
{
   // 带有 5 个元素的整型数组
   int balance[5] = {1000, 2, 3, 17, 50};
   double avg;
 
   // 传递一个指向数组的指针作为参数
   avg = getAverage( balance, 5 ) ;
 
   // 输出返回值
   cout << "Average value is: " << avg << endl; 
    
   return 0;
}
 
double getAverage(int *arr, int size)
{
  int    i, sum = 0;       
  double avg;          
 
  for (i = 0; i < size; ++i)
  {
    sum += arr[i];
   }
 
  avg = double(sum) / size;
 
  return avg;
}
```



### C++ 从函数返回指针

```
int * myFunction()
{
.
.
.
}
```

C++ 不支持在函数外返回局部变量的地址，除非定义局部变量为 **static** 变量

```
#include <iostream>
#include <ctime>
#include <cstdlib>
 
using namespace std;
 
// 要生成和返回随机数的函数
int * getRandom( )
{
  static int  r[10];
 
  // 设置种子
  srand( (unsigned)time( NULL ) );
  for (int i = 0; i < 10; ++i)
  {
    r[i] = rand();
    cout << r[i] << endl;
  }
 
  return r; // 返回数组名，即指向首元素的指针
}
 
// 要调用上面定义函数的主函数
int main ()
{
   // 一个指向整数的指针
   int *p;
 
   p = getRandom(); // 接收返回值
   for ( int i = 0; i < 10; i++ )
   {
       cout << "*(p + " << i << ") : ";
       cout << *(p + i) << endl;
   }
 
   return 0;
}
```

## C++ 引用 vs 指针

引用很容易与指针混淆，它们之间有三个主要的不同：

* 不存在空引用。引用必须连接到一块合法的内存。
* 一旦引用被初始化为一个对象，就不能被指向到另一个对象。指针可以在任何时候指向到另一个对象。
* 引用必须在创建时被初始化。指针可以在任何时间被初始化。


```
// 引用变量可以看作是变量的另一个标签，浅拷贝，指针则是指向内存的标签，

#include <iostream>
 
using namespace std;
 
int main ()
{
  // 声明简单的变量
  int    i;
  double d;
 
  // 声明引用变量
  int&    r = i;
  double& s = d;
   
  i = 5;
  r = 3;   // 同时会改变i
  int* p= &r;
  *p = 1;  // 通过改变r,来改变i
  

  cout << "*p value: " << p << " &*p " << &*&r << endl;  // int* p = &r; 表明是个指针，*p取值（等价于*(&r)）, &*P == p;
  cout << "Value of i : " << i << endl;
  cout << "Value of i reference : " << r  << endl;
 
  d = 11.7;
  cout << "Value of d : " << d << endl;
  cout << "Value of d reference : " << s  << endl;
   
  return 0;
}
```

### C++ 把引用作为返回值

```
#include <iostream>
 
using namespace std;
 
double vals[] = {10.1, 12.6, 33.1, 24.1, 50.0};
 
double& setValues( int i )
{
  return vals[i];   // 返回第 i 个元素的引用
}
 
// 要调用上面定义函数的主函数
int main ()
{
 
   cout << "改变前的值" << endl;
   for ( int i = 0; i < 5; i++ )
   {
       cout << "vals[" << i << "] = ";
       cout << vals[i] << endl;
   }
 
   setValues(1) = 20.23; // 改变第 2 个元素
   setValues(3) = 70.8;  // 改变第 4 个元素
 
   cout << "改变后的值" << endl;
   for ( int i = 0; i < 5; i++ )
   {
       cout << "vals[" << i << "] = ";
       cout << vals[i] << endl;
   }
   return 0;
}
```

当返回一个引用时，要注意被引用的对象不能超出作用域。所以返回一个对局部变量的引用是不合法的，但是，可以返回一个对静态变量的引用。

```
int& func() {
   int q;
   //! return q; // 在编译时发生错误
   static int x;
   return x;     // 安全，x 在函数作用域外依然是有效的
}
```

1）以引用返回函数值，定义函数时需要在函数名前加 &

（2）用引用返回一个函数值的最大好处是，在内存中不产生被返回值的副本。

引用作为返回值，必须遵守以下规则：

* 不能返回局部变量的引用。主要原因是局部变量会在函数返回后被销毁，因此被返回的引用就成为了"无所指"的引用，程序会进入未知状态。
* 不能返回函数内部new分配的内存的引用。虽然不存在局部变量的被动销毁问题，可对于这种情况（返回函数内部new分配内存的引用），又面临其它尴尬局面。例如，被函数返回的引用只是作为一 个临时变量出现，而没有被赋予一个实际的变量，那么这个引用所指向的空间（由new分配）就无法释放，造成memory leak。
* 可以返回类成员的引用，但最好是const。主要原因是当对象的属性是与某种业务规则（business rule）相关联的时候，其赋值常常与某些其它属性或者对象的状态有关，因此有必要将赋值操作封装在一个业务规则当中。如果其它对象可以获得该属性的非常 量引用（或指针），那么对该属性的单纯赋值就会破坏业务规则的完整性。

When a variable is returned by reference, a reference to the variable is passed back to the caller. The caller can then use this reference to continue modifying the variable, which can be useful at times. Return by reference is also fast, which can be useful when returning structs and classes.

我的理解：一个变量被返回其引用的意思是，给了返回变量的一个别名，如教程的例子显示函数给 val[i] 了一个别名。当调用这个函数 setValues(3) 时，返回了这个 val[3] 的别名， 那么我们就可以修改 val[3]，所以可以放到等号的左边。


## C++ 日期 & 时间

为了使用日期和时间相关的函数和结构，需要在 C++ 程序中引用 <ctime> 头文件。

有四个与时间相关的类型：clock_t、time_t、size_t 和 tm。类型 clock_t、size_t 和 time_t 能够把系统时间和日期表示为某种整数。

结构类型 tm 把日期和时间以 C 结构的形式保存，tm 结构的定义如下：

```
struct tm {
  int tm_sec;   // 秒，正常范围从 0 到 59，但允许至 61
  int tm_min;   // 分，范围从 0 到 59
  int tm_hour;  // 小时，范围从 0 到 23
  int tm_mday;  // 一月中的第几天，范围从 1 到 31
  int tm_mon;   // 月，范围从 0 到 11
  int tm_year;  // 自 1900 年起的年数
  int tm_wday;  // 一周中的第几天，范围从 0 到 6，从星期日算起
  int tm_yday;  // 一年中的第几天，范围从 0 到 365，从 1 月 1 日算起
  int tm_isdst; // 夏令时
}
```

### 当前日期和时间

```
#include <iostream>
#include <ctime>
 
using namespace std;
 
int main( )
{
   // 基于当前系统的当前日期/时间
   time_t now = time(0);
   
    cout << "now address: " << &now << " now : " << now <<endl;

   // 把 now 转换为字符串形式
   char* dt = ctime(&now);
 
    cout << "dt address: " << &dt << " dt : " << dt <<endl;

   cout << "本地日期和时间：" << dt << endl;
 
   // 把 now 转换为 tm 结构
   tm *gmtm = gmtime(&now);
   dt = asctime(gmtm);
   cout << "UTC 日期和时间："<< dt << endl;
}
```
















