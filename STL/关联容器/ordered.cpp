#include<iostream>
#include<set>
#include<map>
#include<vector>
#include<string>
using namespace std;
/*
有序关联容器：红黑树
set , map
multiset , multimap
*/

class Student{
    public:
        Student(int _id,string _name):id(_id),name(_name){}
        bool operator<(const Student &stu)const{
            return id<stu.id;
        }
    private:
        int id;
        string name;
        friend ostream& operator<<(ostream &out,const Student &stu);
};
ostream& operator<<(ostream &out,const Student &stu){
    out<<"id:"<<stu.id<<" name:"<<stu.name<<endl;
    return out;
}

int main(){
    set<Student> set1;
    //打印输出时是有序的，默认是从小到大
    set1.insert(Student{10,"zhangsan"});
    set1.insert(Student{2,"lisi"});
    for(auto it=set1.begin();it!=set1.end();it++){
        cout<<*it<<endl;
    }

    map<int,string> map1;
    map1.insert({1,"lisi"});
    map1[1]="zhangsan";
    cout<<map1[1]<<endl;

    vector<int> vec;
    vector<int>::const_iterator it2 = vec.begin();
    vector<int>::reverse_iterator rit = vec.rbegin();
    //rbegin():返回的是最后一个元素的反向迭代器的表示
    //rend():返回的是首元素前驱位置的迭代器的表示
    vector<int>::const_reverse_iterator rit2 = vec.rbegin();
}