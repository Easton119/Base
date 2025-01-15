
#include <iostream>
#include <vector>
using namespace std;

/*
vector 向量容器
底层数据结构：动态开辟的数组，每次以原来空间大小的2倍进行扩容
vector<int> vec
增加：
vec.push_back(20); 末尾添加元素O(1) ,导致容器扩容
vec.insert(it,20); 在it迭代器指定的位置添加一个元素 O(n)  导致容器扩容

删除：
vec.pop_back(); 末尾删除元素 O(1)
vec.erase(it);  删除it迭代器指向的元素 O(n)

查询：
operator[] 下标的随机访问vec[5]  O(1)  中括号运算符重载函数
iterator 迭代器进行遍历
find,for_each
foreach=> 通过iterator来实现

注意：对容器进行连续插入或删除（insert/erase），一定要更新迭代器，否则第一次insert或者
erase完成，迭代器就失效了。

常用方法介绍:
size()
empty()
reserve(20);   vector预留空间
resize(20);   容器扩容用的
swap : 两个容器进行元素交换

*/
int main(){
    vector<int> vec;
    for(int i=0;i<20;++i){
        vec.push_back(rand()%100+1);
    }

    //
    int size = vec.size();
    for(int i=0;i<size;i++){
        cout<<vec[i]<<" ";
    }
    cout<<endl;

    //删除全部偶数
    auto it2 = vec.begin();
    // for(;it2!=vec.end();++it2){
    //     if(*it2%2==0){
    //         vec.erase(it2); //这样做有问题，因为it2失效了
    //     }
    // }

    //while方法
    // while(it2!=vec.end()){
    //     if(*it2%2==0){
    //         it2 = vec.erase(it2);
    //     }else{
    //         it2++;
    //     }
    // }

    // auto it1 = vec.begin();  //迭代器遍历vector容器
    // for(;it1!=vec.end();++it1){
    //     cout<<*it1<<" ";
    // }

    //给vector容器中所有的奇数前面都加一个小于奇数1的数
    auto it3 = vec.begin();
    while(it3!=vec.end()){
        if(*it3%2==1){
            it3 = vec.insert(it3,*it3-1);
            it3+=2;
        }else{
            it3++;
        }
    }
    auto it1 = vec.begin();  //迭代器遍历vector容器
    for(;it1!=vec.end();++it1){
        cout<<*it1<<" ";
    }
}