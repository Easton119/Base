
#include<iostream>
using namespace std;

template<typename T=int> //int默认的类型参数
class SeqStack
{
public:
    //构造和析构函数名不用加<T>,其他出现模板的地方都加上类型参数列表
    SeqStack(int size=10)
        :pstack(new T[size])
        ,top(0)
        ,size(size){}
    ~SeqStack(){
        delete[] pstack;
        pstack = nullptr;
    }
    SeqStack(const SeqStack<T> &stack);//拷贝构造
    SeqStack<T>& operator=(const SeqStack<T> &stack);//拷贝赋值
    void push(const T &val);
    void pop();
    T top()const;
    bool full()const;
    bool empty()const;

private:
    T* pstack;
    int top;
    int size;
    //顺序栈底层数组按2倍扩容
    void expand(){}
};
int main(){
    //从模板实例化的类型————模板类 class SeqStack<int>{}
    SeqStack<int> s1;
    //类模板的选择性实例化
    //调用了才实例化
    s1.push(11);
    SeqStack<> s2;//因为由默认类型参数，可以空着不用传
}