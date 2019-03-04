## C++ 文件和流

到目前为止，我们已经使用了 iostream 标准库，它提供了 cin 和 cout 方法分别用于从标准输入读取流和向标准输出写入流。

本教程介绍如何从文件读取流和向文件写入流。这就需要用到 C++ 中另一个标准库 fstream，它定义了三个新的数据类型：

* ofstream：输出文件流，用于创建文件并向文件写入信息。
* ifstream：输入文件流，用于从文件读取信息。
* fstream：	表示文件流，且同时具有 ofstream 和 ifstream 两种功能，这意味着它可以创建文件，向文件写入信息，从文件读取信息。

要在 C++ 中进行文件处理，必须在 C++ 源代码文件中包含头文件 <iostream> 和 <fstream>

## 打开文件

在从文件读取信息或者向文件写入信息之前，必须先打开文件。ofstream 和 fstream 对象都可以用来打开文件进行写操作，如果只需要打开文件进行读操作，则使用 ifstream 对象。

下面是 open() 函数的标准语法，open() 函数是 fstream、ifstream 和 ofstream 对象的一个成员。

```
void open(const char *filename, ios::openmode mode);
```

在这里，open() 成员函数的第一参数指定要打开的文件的名称和位置，第二个参数定义文件被打开的模式。

模式标志	描述
* ios::app	追加模式。所有写入都追加到文件末尾。
* ios::ate	文件打开后定位到文件末尾。
* ios::in	打开文件用于读取。
* ios::out	打开文件用于写入。
* ios::trunc	如果该文件已经存在，其内容将在打开文件之前被截断，即把文件长度设为 0。

您可以把以上两种或两种以上的模式结合使用。例如，如果您想要以写入模式打开文件，并希望截断文件，以防文件已存在，那么您可以使用下面的语法：

```
ofstream outfile;
outfile.open("file.dat", ios::out | ios::trunc );  // 覆盖write模式
```

类似地，您如果想要打开一个文件用于读写，可以使用下面的语法：

```
ifstream  afile;
afile.open("file.dat", ios::out | ios::in );
```

### 关闭文件

在程序终止前关闭所有打开的文件。

下面是 close() 函数的标准语法，close() 函数是 fstream、ifstream 和 ofstream 对象的一个成员。

```
void close();
```

### 写入文件

在 C++ 编程中，我们使用流插入运算符（ << ）向文件写入信息，就像使用该运算符输出信息到屏幕上一样。唯一不同的是，在这里您使用的是 ofstream 或 fstream 对象，而不是 cout 对象。

### 读取文件

在 C++ 编程中，我们使用流提取运算符（ >> ）从文件读取信息，就像使用该运算符从键盘输入信息一样。唯一不同的是，在这里您使用的是 ifstream 或 fstream 对象，而不是 cin 对象。

## 文件位置指针

istream 和 ostream 都提供了用于重新定位文件位置指针的成员函数。这些成员函数包括关于 istream 的 seekg（"seek get"）和关于 ostream 的 seekp（"seek put"）。

seekg 和 seekp 的参数通常是一个长整型。第二个参数可以用于指定查找方向。查找方向可以是 ios::beg（默认的，从流的开头开始定位），也可以是 ios::cur（从流的当前位置开始定位），也可以是 ios::end（从流的末尾开始定位）。

文件位置指针是一个整数值，指定了从文件的起始位置到指针所在位置的字节数。下面是关于定位 "get" 文件位置指针的实例：

```
// 定位到 fileObject 的第 n 个字节（假设是 ios::beg）
fileObject.seekg( n );
 
// 把文件的读指针从 fileObject 当前位置向后移 n 个字节
fileObject.seekg( n, ios::cur );
 
// 把文件的读指针从 fileObject 末尾往回移 n 个字节
fileObject.seekg( n, ios::end );
 
// 定位到 fileObject 的末尾
fileObject.seekg( 0, ios::end );
```

### 关于 cin.ignore()

完整版本是 cin.ignore(int n, char a), 从输入流 (cin) 中提取字符，提取的字符被忽略 (ignore)，不被使用。

每抛弃一个字符，它都要计数和比较字符：如果计数值达到 n 或者被抛弃的字符是 a，则 cin.ignore()函数执行终止；否则，它继续等待。

它的一个常用功能就是用来清除以回车结束的输入缓冲区的内容，消除上一次输入对下一次输入的影响。

比如可以这么用：`cin.ignore(1024,'\n')`，通常把第一个参数设置得足够大，这样实际上总是只有第二个参数 \n 起作用，所以这一句就是把回车(包括回车)之前的所以字符从输入缓冲(流)中清除出去。

如果cin.ignore()不给参数，则默认参数为cin.ignore(1,EOF) 其中 EOF是end of file的缩写，表示"文字流"(stream)的结尾。


### 对于 cin 的操作 

使用 getline(cin，str)往往可以实现更加简单以及安全的字符串操作,

不同于 cin.getline(char*, int a)，前者可以直接对字符串进行操作。

```
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
int main()
{
    fstream iofile;
    iofile.open("D:\\t.txt", ios::out | ios::in | ios::trunc);
    string bookname;
    string bookwriter;
    cout << "input the bookname:" << endl;
    getline(cin, bookname);
    iofile << bookname << endl;
    cout << "input the bookwriter:" << endl;
    getline(cin, bookwriter);
    iofile << bookwriter << endl;
    iofile.close();
    cout << "read the input file:" << endl;
    iofile.open("D:\\t.txt");
    while (getline(iofile, bookname))
    {
        cout << bookname << endl;

    }
 
    system("pause");
    return 0;

}
```

由于 eof 指示是在读取文件到结尾的时候，才会改变有效的状态。但是，再下一次没有读到数据的时候，eof 才会改变；

但是如果此时还是用 eof 标志位来判断文件是否读到了 end（下图while循环），就会导致此时的 infile>>data 语句还会流入数据（文件的最后一行数据），导致复制的文件中，会多出一行。

```
while (!infile.eof())
{
    infile >> data;
    cout << data << endl;
    outfile << data << endl;
}
```

为消除多与的读取、复制，我们只需要在还能读取文件数据的时候，才将数据复制到新文件中即可，即代码可以改成：

```
while (infile >> data)
{
    cout << data << endl;
    outfile << data << endl;
}
```

