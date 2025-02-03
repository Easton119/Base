#include<iostream>
using namespace std;
/*
左值引用和右值引用

*/
int main(){

    //左值引用：定义一个左值引用在汇编指令上和定义一个指针是没有任何区别的
    // int &b=20; 错误的，20没有在内存上存储，无法取地址
    const int &b = 20; //用常引用可以引用20这个常量数字

    int &&a = 20;
    
    a = 10;//右值引用变量，可读可写
 

    string s = "aaa";//可以

    char s1[10] = "bbb";//可以
    
//  char* s2 = "ccc";//forbids converting a string constant to 'char*'
    
    const char* s3="ddd";//可以
   
// string &s4 = "aaa";//不可以
   string &&s5 = "bbb";//可以

    int c= 10;
    const int d=c;//可以把非const赋值给const

    const int e = 12;
    int f = e;//可以把const赋值给非const
    cout<<f<<endl;
}
