## C++ 异常处理

```
try
{
   // 保护代码
}catch( ExceptionName e1 )
{
   // catch 块
}catch( ExceptionName e2 )
{
   // catch 块
}catch( ExceptionName eN )
{
   // catch 块
}
```

## 抛出异常

您可以使用 throw 语句在代码块中的任何地方抛出异常。throw 语句的操作数可以是任意的表达式，表达式的结果的类型决定了抛出的异常的类型。


## 捕获异常

如果您想让 catch 块能够处理 try 块抛出的任何类型的异常，则必须在异常声明的括号内使用省略号 ...，如下所示：

```
try
{
   // 保护代码
}catch(...)
{
  // 能处理任何异常的代码
}
```

下面是一个实例，抛出一个除以零的异常，并在 catch 块中捕获该异常。

```
#include <iostream>
using namespace std;
 
double division(int a, int b)
{
   if( b == 0 )
   {
      throw "Division by zero condition!";
   }
   return (a/b);
}
 
int main ()
{
   int x = 50;
   int y = 0;
   double z = 0;
 
   try {
     z = division(x, y);
     cout << z << endl;
   }catch (const char* msg) {
     cerr << msg << endl;
   }
 
   return 0;
}
```

由于我们抛出了一个类型为 const char* 的异常，因此，当捕获该异常时，我们必须在 catch 块中使用 const char*。当上面的代码被编译和执行时，它会产生下列结果：

```
Division by zero condition!
```

## 定义新的异常

通过**继承和重载 exception 类**来定义新的异常。下面的实例演示了如何使用 std::exception 类来实现自己的异常：

```
#include <iostream>
#include <exception>
using namespace std;
 
struct MyException : public exception
{
  const char * what () const throw ()
  {
    return "C++ Exception";
  }
};
 
int main()
{
  try
  {
    throw MyException();
  }
  catch(MyException& e)
  {
    std::cout << "MyException caught" << std::endl;
    std::cout << e.what() << std::endl;
  }
  catch(std::exception& e)
  {
    //其他的错误
  }
}
```

```
在这里，what() 是异常类提供的一个公共方法，它已被所有子异常类重载。这将返回异常产生的原因。
```

## const throw()

const throw() 不是函数，这个东西叫异常规格说明，表示 what 函数可以抛出异常的类型，类型说明放到 () 里，这里面没有类型，就是声明这个函数不抛出异常，通常函数不写后面的就表示函数可以抛出任何类型的异常。

### 异常规格说明

1、异常规格说明的目的是为了让函数使用者知道该函数可能抛出的异常有哪些。 可以在函数的声明中列出这个函数可能抛掷的所有异常类型。例如：

```
void fun() throw(A，B，C，D);
```

2、若无异常接口声明，则此函数可以抛掷任何类型的异常。

### C++ Primer 中关于 what（）的解释：

在之前的例子里，我们使用了一个 throw 表达式以避免把两个代表不同书籍的 Sales_item 相加。我们假设执行 Sales_item 对象加法的代码是与用户交互的代码分离开的。其中与用户交互的代码负责处理发生的异常，它的形式可能如下所示：

```
while (cin >> item1 >> item2){
  try{
    //执行添加两个Sales_item对象的代码
    //如果添加失败，代码抛出一个runtime_error异常
  } catch (runtime_error err){
      //提醒用户两个ISBN必须一致，询问是否重新输入
      cout << err.what()
           << "\nTry Again? Enter y or n" << endl;
      char c;
      cin >> c;
      İf (!cin || c == 'n')
          break;//跳出while循环
    }
}
```

程序本来要执行的任务出现在 try 语句块中，是因为这段代码可能会抛出一个 runtime_error 类型的异常。

try 语句块对应一个 catch 子句。该子句负责处理类行为 runtime_error 的异常。如果 try 语句块的代码抛出了runtime_error 异常，接下来执行 catch 块内的语句。在我们书写的 catch 子句中，数出一段提示信息要求用户指定程序是否继续。如果用户输入 n，执行 break 语句并退出 while 循环；否则，直接执行 while 循环的右侧花括号，意味着程序控制权条回到 while 条件部分准备下一次迭代。

给用户的提示信息中输出了 err.what() 的返回值。我们知道 err 的类型是 runtime_error，因此能推断 what 是 runtime_error 类的一个成员函数。每个标准库异常类都定义了名为 what 的成员函数。这些函数没有参数，返回值是 C 风格字符串（即 const char *）其中，runtime_error 的 what 成员函数返回的是初始化一个具体对象所用的 string 对象的副本。如果上一节编写的代码抛出异常，则本节的 catch 子句输出:

```
Data must refer to same ISBN
Try Again? Enter y or n
```

* 在 C++11 中，声明一个函数不可以抛出任何异常使用关键字 noexcept。

```
void mightThrow(); // could throw any exceptions.
void doesNotThrow() noexcept; // does not throw any exceptions.
```

* 下面两个函数声明的异常规格在语义上是相同的，都表示函数不抛出任何异常。

```
void old_stytle() throw();
void new_style() noexcept;
```
