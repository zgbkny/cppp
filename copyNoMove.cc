#include <utility>
#include <iostream>

class Foo {
public:
	Foo() = default; //
	virtual void test();
private:
	Foo(const Foo&); // copy constructor
	Foo& operator= (const Foo&);
};

//Foo::Foo(const Foo&) { std::cout << "Foo copy" << std::endl; }
void Foo::test()
{
	
}

int main()
{
	Foo x;
	Foo w;
//	w = x;
//	Foo y(x);
//	Foo z(std::move(x));
}