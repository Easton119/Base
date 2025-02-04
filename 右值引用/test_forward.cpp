#include<iostream>
#include<vector>
using namespace std;
// 容器里面元素的类型
class A
{
public:
	A(){}
	// 带左值引用参数的赋值函数
	A& operator=(const A &src)
	{
		cout << "operator=" << endl;
		return *this;
	}
	// 带右值引用参数的赋值函数
	A& operator=(A &&src)
	{
		cout << "operator=(A&&)" << endl;
		return *this;
	}
};
// 容器的类型
template<typename _Ty>
class Vector
{
public:
	// 引用左值的push_back函数
	void push_back(const _Ty &val)
	{
		// addBack(std::move(val));
        //这里直接move会得到const右值引用，要么去掉函数参数上的const，要么重载addBack接收const引用参数
	}
	// 引用右值的push_back函数
	void push_back(_Ty &&val)
	{
		// 这里传递val时，要用move转换成右值引用类型，
		// 因为val本身是左值，有名字有地址，见前面引用折叠部分的说明
        cout<<"push_back(_Ty &&val)"<<endl;
		addBack(std::move(val)); 
	}
private:
	enum { VEC_SIZE = 10 };
	_Ty mvec[VEC_SIZE];
	int mcur;
    
	void addBack(_Ty &&val)
	{
		/*
		这里val本身永远是左值，所以不可能调用
		容器内部对象的右值引用参数的operator=赋值函数
		*/
		mvec[mcur++] = val;

        // mvec[mcur++] = move(val);当然了若是使用move，那么可调用右值引用
	}

    /*用forword类型完美转换机制修改后的代码，使用到了引用折叠原理
    template<typename _Ty2>
    void addBack(_Ty2 &&val)
    {
        // 这里使用std::forward，可以获取val引用的实参的引用类型，是左引用，还是右引用，原理就是根据“引用折叠规则”
        int&+&&->int&     int&&+&&->int&&
        mvec[mcur++] = std::forward<_Ty2>(val);
    }
    */

};

int main()
{
	Vector<A> vec;
	A a;
	vec.push_back(a); // 调用A的左值引用的赋值函数
	vec.push_back(A()); // 理应调用A的右值引用参数的赋值函数，却调用了左值引用的赋值函数
	return 0;
}
