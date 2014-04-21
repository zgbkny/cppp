#include <unordered_map>
using std::unordered_map;

#include <unordered_set>
using std::unordered_set; using std::unordered_multiset;

#include <string>
using std::string; 

using std::hash;

#include <iostream>
using std::cin; using std::cout; using std::endl;

#include <cstddef>
using std::size_t;

#include "Sales_data.h"

// unordered_map version of the word count program
int main() 
{
	// count occurrences, but the words won't be in alphabetical order
    unordered_map<string, size_t> word_count;  
    string word;
    while (cin >> word)
		++word_count[word]; // fetch and increment the counter for word

	for (const auto &w : word_count) // for each element in the map
		// print the results
		cout <<  w.first << " occurs " << w.second 
		     << ((w.second > 1) ? " times" : " time") << endl;

	return 0;
}

// how to override default hash and equality operator on key_type
size_t hasher(const Sales_data &sd) 
{
	return hash<string>()(sd.isbn());
}
bool eqOp(const Sales_data &lhs, const Sales_data &rhs)
{
	return lhs.isbn() == rhs.isbn();
}

// type alias using our functions in place of hash<key_type> and ==
using SD_multiset = unordered_multiset<Sales_data, 
                    decltype(hasher)*, decltype(eqOp)*>;

// bookstore can hold multiple Sales_data with the same ISBN
// arguments are the bucket size 
// and pointers to the hash function and equality operator
SD_multiset bookstore(42, hasher, eqOp);

// how to override just the hash function;
// Foo must have ==
struct Foo { string s; };

// we'll see how to define our own operators in chapter 14
bool operator==(const Foo& l, const Foo&r) { return l.s == r.s; }

size_t FooHash(const Foo& f) { return hash<string>()(f.s); }

// use FooHash to generate the hash code; Foo must have an == operator
unordered_set<Foo, decltype(FooHash)*> fooSet(10, FooHash);

