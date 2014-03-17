#include <utility>
#include <iostream>

class Foo {
public:
	Foo() = default; //
	virtual void test();
	void test_int() {
		static int test = 0;
		test++;
		std::cout << test << std::endl;
	}
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
	x.test_int();
	w.test_int();
//	w = x;

//	Foo y(x);
//	Foo z(std::move(x));
}