#include <iostream>
#include <map>

using std::map;
using std::cout;
using std::endl;
class Solution {
public:
    int singleNumber2(int A[], int n) {
        map<int, size_t> num_count;
        for (int i = 0; i < n; i++) num_count[A[i]]++;
        for (map<int, size_t>::iterator it = num_count.begin(); it != num_count.end(); it++)
        	if (it->second == 1) return it->first;
        return 0; 
    }
    int singleNumber3(int A[], int n) {
        map<int, size_t> num_count;
        for (int i = 0; i < n; i++) num_count[A[i]]++;
        for (map<int, size_t>::iterator it = num_count.begin(); it != num_count.end(); it++)
        	if (it->second == 1) return it->first;
        return 0; 
    }
};

int main()
{
	//int i = 5 >? 4;
    std::cout << "Solution" << std::endl;
    return 0;
}