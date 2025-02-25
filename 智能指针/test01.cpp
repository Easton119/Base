/*
智能指针：
不带引用计数的：auto_ptr,scoped_ptr,unique_ptr
带引用计数的：shared_ptr,weak_ptr
*/

#include<iostream>
#include<memory>
using namespace std;

int main(){
    //在堆上定义一个智能指针
    unique_ptr<int> *ptr = new unique_ptr<int>(new int(10));
    cout<< **ptr;
    //需要两次解引用
    delete ptr;
    //需要手动释放，先释放管理的int对象，再释放自身
}