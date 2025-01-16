
#include<iostream>
#include<set>
using namespace std;
template<typename T>
class MyGreater{
public:
    bool operator()(T a,T b){
        return a > b;
    }
};
template<typename T>
class MyLess{
public:
    bool operator()(T a,T b){
        return a < b;
    }
};
template<typename T,typename Compare>
bool compare(T a,T b,Compare comp)
{
    return comp(a,b);
}
int main(){
    cout<<compare(20,30,MyGreater<int>())<<endl;
    cout<<compare(20,30,MyLess<int>())<<endl;


    //通过函数对象修改set，priority_queue的底层排序方式
   set<int> set1;
   set<int,greater<int>> set2;
   for(int i=0;i<10;i++){
        set1.insert(rand()%10);
        set2.insert(rand()%10);
   }
   for(int i:set1){
    cout<<i<<" "; //默认从小到大
   }
   cout<<endl;
   for(int i:set2){
    cout<<i<<" "; //从大到小
   }

}