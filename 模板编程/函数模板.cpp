#include<iostream>
#include<cstring>
using namespace std;
/*

模板的意义：对类型也可以进行参数化

注意下面概念：
函数模板  <=不进行编译的，因为类型还不知道
模板的实例化 <=函数调用点进行实例化
模板函数  <=这个才是要被编译器所编译的

模板类型参数  可以用typename/class
模板非类型参数

模板的实参推演 -->根据用户传入的实参的类型，来推导出模板类型参数的具体类型
模板的特例化（专用化） 特殊的实例化（不是编译器提供的，而是用户提供的）

函数模板、模板的特例化、非模板函数的重载关系
————重载是函数名相同，参数列表不同
但是这里函数名并不相同
*/
template<typename T>// 定义一个模板参数列表
bool compare(T a,T b){  //compare是一个函数模板
    cout<<"template"<<endl;
    return a>b;
}

//在函数调用点，编译器用用户指定的类型，从原模板实例化一份函数代码
/*
    得到模板函数
    bool compare<int>(int a,int b){
        return a>b;
    }
 */

//编译器提供的实例化不满足需求
//自己提供const char*类型的特例化版本
template<> //注意这句别丢
bool compare<const char*>(const char* a,const char* b){
    cout<<"compare<const char*>"<<endl;
    return strcmp(a,b)>0;
}
//非模板函数-普通函数
bool compare(const char* a,const char* b){
    cout<<"normal compare"<<endl;
    return strcmp(a,b)>0;
}
int main(){

    //compare是模板名，compare<int>是函数名=模板名+类型
    //函数调用点
    compare<int>(10,20);
    compare(20,30);//不会产生重复的模板函数

    compare("aa","bb");//优先调用非模板函数
    compare<const char*>("aa","bb");//优先调用模板的特例化
}

/*
项目中的位置：
模板代码是不能在一个文件中定义，在另一个文件中使用的
模板代码调用之前，一定要看到模板定义的地方，这样的话模板
才能够进行正常的实例化,产生能够被编译器编译的代码
所以，模板代码都是放在头文件中的，然后在源文件中#include
*/