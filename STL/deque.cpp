#include<iostream>
#include<list>
using namespace std;


/*
deque:双端队列容器
底层数据结构：动态开辟的二维数组，一维数组从2开始，以2倍的方式进行扩容。每次扩容后，
原来第二维的数组，从新的第一维数组的下标oldsize/2开始存放，上下都预留相同的空行，
方便支持deque的首尾元素添加

deque<int> deq;
增加：
deq.push_back(20); 从末尾添加元素 O(1)
deq.push_front(20);从首部添加元素 O(1) //vec.insert(vec.begin(),20) O(n)
deq.insert(it,20);  it指向的位置添加元素 O(n)

删除：
deque.pop_back(); 从末尾删除 O(1)
deque.pop_front(); 从首部删除 O(1)
deque.erase(it);  从it指向的位置删除 O(n)

查询搜索：
iterator(连续的insert erase，一定要考虑迭代器失效的问题)


list: 链表容器
底层数据结构：双向的循环链表 pre data next
list<int> mylist;
增加：
mylist.push_back(20); 从末尾添加元素 O(1)
mylist.push_front(20);从首部添加元素 O(1) //vec.insert(vec.begin(),20) O(n)
mylist.insert(it,20);  it指向的位置添加元素 O(1)  
    链表中进行insert时，要先query查询，查询操作较慢

删除：
mylist.pop_back(); 从末尾删除 O(1)
mylist.pop_front(); 从首部删除 O(1)
mylist.erase(it);  从it指向的位置删除 O(1)

查询搜索：
iterator(连续的insert erase，一定要考虑迭代器失效的问题)

deque和list比vector多出来的增加删除函数接口
push_front 和 pop_front
*/


int main(){
    list<int> mylist;
    // mylist.resize(20);
    // cout<<mylist.empty()<<endl;
    // cout<<mylist.size()<<endl;

    for (int i = 0; i < 10; i++)
    {
        mylist.push_back(rand()%100+1);
    }
    

    auto it = mylist.begin();
    while(it!=mylist.end())
    {
        cout<<*it<<" ";
        it++;
    }
    cout<<endl;

    auto it2 = mylist.begin();
    while(it2!=mylist.end())
    {
        if(*it2%2==0){
            it2= mylist.erase(it2);
        }else{
            it2++;
        }
    }
    it = mylist.begin();
    while(it!=mylist.end())
    {
        cout<<*it<<" ";
        it++;
    }
    cout<<endl;
    cout<<mylist.back()<<endl;
}