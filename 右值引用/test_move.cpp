#include<iostream>
#include<vector>
using namespace std;
// std::move移动语义
class A
{
public:
	A(int data=10):ptr(new int(data)) {
        cout<<"A(int data)"<<endl;
    }
	~A() { delete ptr; ptr = nullptr; }
	A(const A &src)
	{
		cout << "A(const A&)" << endl;
		ptr = new int(*src.ptr);
	}
	A(A &&src)
	{
		cout << "A(A&&)" << endl;
		ptr = src.ptr;
		src.ptr = nullptr;
	}
private:
	int *ptr;
};
int main()
{
	vector<A> vec;
	vec.reserve(10);
	for (int i = 0; i < 5; ++i)
	{
		A a(i);
		/*
		这里a是一个左值，因此vec.push_back(a)会调用左值的
		拷贝构造函数，用a拷贝构造vector底层数组中的对象
		*/
		// vec.push_back(a);

        vec.push_back(move(a));//带移动语义的std::move函数,调用移动构造

        // vec.push_back(A(20));//调用移动构造
	}
	return 0;
}
