
#include<iostream>
#include<cstring>
using namespace std;
/*
OOP
类是实体的抽象数据类型(ADT,abstract data type)
实体  -> ADT
对象 <-(实例化)- 类（属性-成员变量，行为-成员方法）

OOP语言的四大特征：
抽象 ， 封装/隐藏 ， 继承 ， 多态
访问限定符：public private protected
*/

class CGoods{//商品的抽象数据类型
public:
    //类体内实现的方法，自动处理成inline内联函数
    const char* getName(){return _name;} //返回类型写const char*,然后接收的时候不能用char*来接收const char*
    void setName(char *name){//注意这里参数要const char*接收
        strcpy(_name,name);
    }
    void show();
private:
    char _name[20];
    double _price;
    int _amount;
};
//类体外实现方法
void CGoods::show(){
    cout<<"name:"<<_name<<endl;
}
int main(){
    //类不占空间，对象占空间，在栈上
    //对象内存大小，和成员变量相关，找最长的为对齐方式
    CGoods good;
    good.setName("面包");
    // 实际调用的setName(&good,"面包")
    // 类的成员方法一经编译，所有的方法参数，都会加一个this指针，接收调用该方法的对象的地址
    good.show();
}