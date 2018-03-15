/********************************************
	һ�����������Ϊ�������������:
	default���캯��
	��������
	copy���캯��
	copy assignment������

	�����������ɿ����copy���캯����copy assignment������ʱ��ע���:
	1. copy���캯�������Ľ���Դ������non-static��Ա������Ŀ�����
	2. copy assignment��������copy���캯��������Ϊ
********************************************/
/**********************
version 1.0 --- ����ִ��copy��copy assignment������

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
	NameObject<int> no1("tanzixi", 18); //����TΪint�ͣ�����ִ��copy���캯��
	NameObject<int> no2("tanzimo", 18);

	no2 = no1; //����TΪint�ͣ�����ִ��copy assignment������
	
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
	std::string& nameValue; //���ò��ܱ�copy assignment������ʹ��
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



