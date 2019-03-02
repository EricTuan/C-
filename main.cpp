/******     引用     ******/

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
   cout << "Value of i : " << i << endl;
   cout << "Value of i reference : " << r  << endl;
 
   d = 11.7;
   cout << "Value of d : " << d << endl;
   cout << "Value of d reference : " << s  << endl;
   
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

