#include <iostream>
#include <string>
 
using namespace std;
 
int main ()
{
   string str1 = "Hello";
   string str2 = "World";
   string str3;
   int  len ;
 
   // 复制 str1 到 str3
   str3 = str1;
   cout << "str3 : " << str3 << endl;
 
   // 连接 str1 和 str2
   str3 = str1 + " " + str2;
   cout << "str1 + str2 : " << str3 << endl;
 
   // 连接后，str3 的总长度
   len = str3.size();
   cout << "str3.size() :  " << len << endl;
 
   return 0;
}


/******     extern 类     ******/

// #include <iostream>
// using namespace std;
// int count = 5;
// extern void write_extern(); // extern用于当有两个或多个文件共享相同的全局变量或函数的时候
 
// int main()
// {
//     count = 5;
//     while(count--){
//         write_extern();
//     }
    
//     // count = 5;
//     // write_extern();
// }

// #include <iostream>
// using namespace std;

/******     条件语句     ******/
// #include <iostream>
// using namespace std;
// int main()
// {
//    int i, j;
//    j = 10;
//    i = j-- == 10 ? j : 1;   // 条件语句执行后再进行...
//    cout << i << endl;
//    return 0;
// }

