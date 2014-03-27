#include <map>
using std::map;

#include <string>
using std::string;

#include <iostream>
using std::cin; using std::cout; using std::endl;

int main() 
{
    map<string, size_t> word_count;  // empty map from string to size_t
    string word;
    while (cin >> word)
      ++word_count[word];
  //	cout << map.size() << endl;
	string removal_word = "the";
	
	// two ways to remove an entry from a map
	// 1. by key
	// erase on a key returns the number of elements removed
	if (word_count.erase(removal_word))
	     cout << "ok: " << removal_word << " removed\n";
	else cout << "oops: " << removal_word << " not found!\n";
	
	// 2. by removing an iterator to the element we want removed
	removal_word = "The";  // strings are case sensitive
	map<string,size_t>::iterator where;
	where = word_count.find(removal_word);  // should be gone
	
	if (where == word_count.end())
	     cout << "oops: " << removal_word << " not found!\n";
	else {
	     word_count.erase(where);   // erase iterator returns void
	     cout << "ok: " << removal_word << " removed!\n";
	}
	return 0;
}
