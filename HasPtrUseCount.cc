#include <string>
#include <cstddef>
#include <iostream>
class HasPtr {
	friend void swap(HasPtr&, HasPtr&);
public:
	HasPtr(const std::string &s = std::string()): 
	  ps(new std::string(s)), i(0), use(new std::size_t(1)) {
	  	std::cout << "init" << *ps << std::endl;
	  }
	HasPtr(const HasPtr &p): 
		ps(p.ps), i(p.i), use(p.use) { 
			++*use;
			ps = new std::string("dfhgdfghdfghdfhj");
			std::cout << "here?" << std::endl;
		} 

	HasPtr& operator=(const HasPtr&);

	~HasPtr();

	// move constructor takes over the pointers from its argument
	// and makes the argument safe to delete
	HasPtr(HasPtr &&p): ps(p.ps), i(p.i), use(p.use) 
		{ p.ps = 0; p.use = 0; }

	HasPtr &operator=(HasPtr&&);
	std::string *ps;
private:
    
    int    i;
	std::size_t *use;
};

HasPtr::~HasPtr()
{
	if (--*use == 0) {   // if the reference count goes to 0
		std::cout << "delete" << std::endl;
		delete ps;       // delete the string
		delete use;      // and the counter
	}
}

HasPtr&
HasPtr::operator=(HasPtr &&rhs)
{
	std::cout << " = !" << std::endl;
	if (this != &rhs) {
		if (--*use == 0) {   // do the work of the destructor
			delete ps;
			delete use;
		}
		ps =  new std::string("sdfg");         // do the work of the move constructor
		i = rhs.i;
		use = rhs.use;
		ps = 0; use = 0;
	}
	return *this;
}
HasPtr& HasPtr::operator=(const HasPtr &rhs) 
{
	std::cout << " = const!" << std::endl;
	++*rhs.use;  // increment the use count of the right-hand operand
	if (--*use == 0) {   // then decrement this object's counter
		delete ps;       // if no other users 
		delete use;      // free this object's allocated members
	}
	ps = new std::string("dddddddddddddsdfg");         // copy data from rhs into this object
	i = rhs.i;
	use = rhs.use; 
	return *this;        // return this object
}
HasPtr f(HasPtr hp) // HasPtr passed by value, so it is copied
{
	HasPtr ret;
	ret = hp;        // assignment copies the given HasPtr
	// proces ret
	return ret;      // ret and hp are destroyed
}

inline
void swap(HasPtr &lhs, HasPtr &rhs)
{
	std::cout << "swap" << std::endl;
	using std::swap;
	swap(lhs.ps, rhs.ps); // swap the pointers, not the string data
	swap(lhs.i, rhs.i);   // swap the int members
}

int main()
{
	HasPtr hp("hp");
	HasPtr hp2("hp2");
	swap(hp, hp2);
	std::cout << *hp.ps << std::endl << *hp2.ps << std::endl;	
	hp = hp2; // hp2 is an lvalue; copy constructor used to copy hp2 
	std::cout << *hp.ps << std::endl << *hp2.ps << std::endl;
//	hp = std::move(hp2); // move constructor moves hp2
}