#include<iostream>
using namespace std;

/*
内存开辟、释放
对象构造、析构
*/
template<typename T>
struct Allocator{
    T* allocate(size_t size){ // 负责内存开辟
        return (T*)malloc(sizeof(T)*size);
    }
    void deallocate(void *p){ // 负责内存释放
        free(p);
    }
    void construct(T *p,const T &val){ // 负责对象构造
        new (p) T(val);//定位new
    }
    void destroy(T *p){// 负责对象析构
        p->~T(); //~T()代表了T类型的析构函数
    }
};


int main(){

}