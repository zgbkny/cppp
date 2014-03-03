#include <string>
#include <cstddef>
class HasPtr {
public:
	HasPtr(const std::string &s = std::string()): 
	  ps(new std::string(s)), i(0), use(new std::size_t(1)) {}
	HasPtr(const HasPtr &p): 
		ps(p.ps), i(p.i), use(p.use) { ++*use; }

	HasPtr& operator=(const HasPtr&);

	~HasPtr();

	// move constructor takes over the pointers from its argument
	// and makes the argument safe to delete
	HasPtr(HasPtr &&p): ps(p.ps), i(p.i), use(p.use) 
		{ p.ps = 0; p.use = 0; }

	HasPtr &operator=(HasPtr&&);
private:
    std::string *ps;
    int    i;
	std::size_t *use;
};

HasPtr::~HasPtr()
{
	if (--*use == 0) {   // if the reference count goes to 0
		delete ps;       // delete the string
		delete use;      // and the counter
	}
}

HasPtr&
HasPtr::operator=(HasPtr &&rhs)
{
	if (this != &rhs) {
		if (--*use == 0) {   // do the work of the destructor
			delete ps;
			delete use;
		}
		ps = rhs.ps;         // do the work of the move constructor
		i = rhs.i;
		use = rhs.use;
		ps = 0; use = 0;
	}
	return *this;
}