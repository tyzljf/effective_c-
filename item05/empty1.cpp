/********************************************
	一个空类编译器为其做的事情包括:
	default构造函数
	析构函数
	copy构造函数
	copy assignment操作符

	编译器在生成空类的copy构造函数和copy assignment操作符时，注意点:
	1. copy构造函数单纯的将来源对象中non-static成员拷贝到目标对象
	2. copy assignment操作符与copy构造函数类似行为
********************************************/
/**********************
version 1.0 --- 可以执行copy和copy assignment操作符

#include<iostream>

template<typename T>
class NameObject
{
public:
	NameObject(const std::string& name, const T& value);
	NameObject(const char* name, const T& value);
	
private:
	std::string nameValue;
	T objectValue;
};

template<typename T>
NameObject<T>::NameObject(const char* name,const T& value)
{
	nameValue = name;
	objectValue = value;
}

template<typename T>
NameObject<T>::NameObject(const std::string& name,const T& value)
{
	nameValue = name;
	objectValue = value;
}

int main()
{
	NameObject<int> no1("tanzixi", 18); //类型T为int型，可以执行copy构造函数
	NameObject<int> no2("tanzimo", 18);

	no2 = no1; //类型T为int型，可以执行copy assignment操作符
	
	return 0;
}

*************************/

#include<iostream>

template<typename T>
class NameObject
{
public:
	NameObject(std::string& name, T& value);
	
private:
	std::string& nameValue; //引用不能被copy assignment操作符使用
	const T& objectValue;
};

template<typename T>
NameObject<T> :: NameObject(std::string& name, T& value):
	nameValue(name), 
	objectValue(value)
{
}

int main()
{
	std::string big("tanzixi");
	std::string small("tanzimo");

	int age1 = 12;
	int age2 = 13;
	
	NameObject<int> no1(big, age1); 
	NameObject<int> no2(small, age2);

	no1 = no2;

	return 0;
}



