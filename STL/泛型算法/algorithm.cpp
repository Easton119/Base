#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;

/*
泛型算法 = template(用模板实现的) + 迭代器 + 函数对象(更改算法运行结果)
特点一：泛型算法的参数接收的都是迭代器
        (用迭代器遍历各个容器的方式都是一样)
特点二：泛型算法的参数还可以接收函数对象(c函数指针)
sort, find , find_if , binary_search , for_each

绑定器 + 二元函数对象 => 一元函数对象
bind1st：把二元函数对象的operator()(a,b)的第一个形参绑定起来
bind2nd：把二元函数对象的operator()(a,b)的第二个形参绑定起来
*/


int main(){
    int arr[] ={12,13,60,50,24};
    vector<int> vec(arr,arr+sizeof(arr)/sizeof(arr[0]));
    
    sort(vec.begin(),vec.end(),greater<int>()); //sort默认从小到大
    for(int i:vec){
        cout<<i<<" ";
    }

    cout<<endl;
    //二分查找，需要有序排列
    if(binary_search(vec.begin(),vec.end(),24,greater<int>())){
        cout<<"yes"<<endl;
    }


    //找第一个小于48的数字
    //把48按序插入到vector容器当中,找第一个小于48的数字
    //find_if需要的是一个一元函数对象
    //greater a>b
    auto it2 = find_if(vec.begin(),vec.end(),
        // bind1st(greater<int>(),48));
        // bind2nd(less<int>(),48));
        [](int val)->bool {return val<48;});

    vec.insert(it2,48);

    for(int i:vec){
        cout<<i<<" ";
    }
    cout<<endl;
    //for_each可以遍历容器的所有元素，可以自行添加合适的函数对象对容器的
    //元素进行过滤
    for_each(vec.begin(),vec.end(),
        [](int val)->void{
            if(val%2==0){
                cout<<val<<" ";
            }
        }    
    );


}