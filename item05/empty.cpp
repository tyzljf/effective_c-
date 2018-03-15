/********************************************
	一个空类编译器为其做的事情包括:
	default构造函数
	析构函数
	copy构造函数
	copy assignment操作符

	编译器在生成空类的构造函数和析构函数时，注意点:
	1. 编译器为空类生成default构造函数
	2. 编译器在生成空类的析构函数时，virtual属性需看空类的基类是否具有virtual属性
		如果有，则生成virtual析构函数
		如果没有，则生成non-virtual析构函数
********************************************/

class Empty
{
};

int main()
{
	Empty empty;  //编译器会默认生成default构造函数和non-virtual析构函数

	Empty e1;
	Empty e2(e1); //编译器会生成拷贝构造函数 ---拷贝对象内non-static成员变量
	e2 = e1; //编译器会生成copy assignment操作符  ---实现与拷贝构造函数一致的事情
	
	return 0;
}
