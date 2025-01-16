
#include<iostream>
#include<stack> //stack
#include<queue> //queue 和 priority_queue
using namespace std;
/*
怎么理解适配器？
1. 适配器底层没有自己的数据结构，它是另外一个容器的封装，它的方法全部由底层依赖的容器进行实现
	（说适配器模式比较勉强，可以说是简单的代理模式） 	
2. 没有实现自己的迭代器
template<typename T ,typename Container=deque<T>>
class Stack{
public:
    void push(const T &val){con.push_back(val);}
    void pop(){con.pop_back();}
    T top()const{return con.back();}
private:
    Container con;
};
*/
/*
stack:push入栈 pop出栈 empty判断栈空 size返回元素个数
queue:push队尾入 pop队头出 front查看队头元素 back查看队尾元素 empty判断队空 size元素个数
stack = > deque 为什么不依赖vector???
queue = > deque  为什么不依赖vector???
    1.vector的初始内存使用效率太低了，没有deque好
    vector 0-1-2-4-8   deque  4096/sizeof(int) = 1024
    2.对于queue来说，需要支持尾部插入，头部删除，O(1),如果依赖vector,出队效率很低
    3.vector需要大片的连续内存，而deque只需要分段的内存，当存储大量数据时，显然deque对于内存的利用率更好


priority_queue(大根堆):push入队 pop出队 top查看队顶元素 empty判断队空 size个数
priority_queue = > vector 为什么依赖vector???
    底层默认把数据组成一个大根堆结构，
    父节点下标i，左右子节点分别为 2i+1,2i+2
    需要在一个内存连续的数组上构建一个大根堆或小根堆，才能便于通过下标访问

top-k问题
*/
int main(){
    stack<int> s1;

    queue<int> que;

    priority_queue<int> pq;
    for(int i=0;i<10;i++){
        pq.push(rand()%100+1);
    }
    while(!pq.empty()){
        cout<<pq.top()<<" ";
        pq.pop();
    }
 
}