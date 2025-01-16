

#include<iostream>
#include<string>
#include<set>
#include<map>
#include<unordered_map>
#include<unordered_set>


/*
关联容器：
有序关联容器：红黑树 增删查O(logN,以2为底)
set，multiset
map, multimap
无序关联容器:链式哈希表 增删查O(1)
unordered_set,unordered_multiset
unordered_map,unordered_multimap

常用增删查方法
增加：insert(val)
遍历：iterator自己搜索，调用find成员方法
删除：erase(key),erase(it)
*/

using namespace std;
#if 0
int main(){
    unordered_set<int> set1;
    //单重，不允许key重复
    //多重，允许key重复

    for(int i=0;i<10;i++){
        set1.insert(rand()%20+1);
    }
    cout<<set1.size()<<endl;
    for(int val:set1){
        cout<<val<<" ";
    }
    cout<<endl;
    for(auto it = set1.begin();it!=set1.end();){
        if(*it%2==0){
            it = set1.erase(it);
        }else{
            it++;
        }
    }
    for(int val:set1){
        cout<<val<<" ";
    }
}

int main(){
    unordered_map<int,string> mp1;
    // unordered_multimap<int,string> mp1;
    //单重映射表,多重映射表

    /*struct pair{
        first;=>key
        second;=>value
    }
    */
    mp1.insert(make_pair(1000,"张三"));
    mp1.insert({1010,"李四"});
    mp1.insert({1000,"王五"});//insert方法不会覆盖原来的值

    // operator[] : 
    //1.查询
    //2.如果key不存在，他会插入一对数据[key,string()]
    mp1[2000];
    mp1[2001]= "lisi";
    // mp1[1000]="zhangsan"; //operator[]会覆盖原来的值。

    cout<<mp1[1000]<<endl;
    cout<<mp1.size()<<endl;

    mp1.erase(1010);
}
#endif

int main(){
    //哈希表应用————海量数据查重，去重

    //查重，查出大于1次的数的个数
    unordered_map<int,int> map1;
    for (int i = 0; i < 20; i++)
    {
        int v = rand()%10+1;
        cout<<v<<' ';
        //方法1
        // auto it = map1.find(v);
        // if(it!=map1.end()){
        //     it->second++;
        // }else{
        //     map1.insert({v,1});
        // }
        //方法2
        map1[v]++;
    }
    cout<<endl<<"打印出现次数大于1的数:"<<endl;
    for(const pair<int,int> p:map1){
        if(p.second>1){
            cout<<"key:"<<p.first<<" 次数:"<<p.second<<endl;
        }
    }
    cout<<endl<<"打印出现次数大于1的数:"<<endl;
    for(auto it = map1.begin();it!=map1.end();it++){
        if(it->second>1){
            cout<<"key:"<<it->first<<" 次数:"<<it->second<<endl;
        }
    }

    //去重
    unordered_set<int> set1;
    for(int i=0;i<20;i++){
        set1.insert(rand()%10+1);
    }
    for(int i:set1){
        cout<<i<<" ";
    }
}