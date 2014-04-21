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
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        if (m == 0 && n == 0) return 0;
        int d1, d2, a1, a2, i = m/2, j = n/2;
        d1 = (m + n)%2 ? (m + n)/2 + 1: (m + n)/2; 
        d2 = (m + n)%2 ? d1: d1 + 1;
        cout << d1 << endl << d2 << endl;
        while (1) {
            if (i < m && j < n) {
                
            }
        }
    }
    int candy(vector<int> &ratings) {
        int candys[ratings.size()] = {0};
        int i = 0, sum = 0;
        for (; i < ratings.size(); i++) {
            candys[i] = 0;
            if (i > 0 && ratings[i] > ratings[i - 1]) 
                candys[i] = candys[i - 1] + 1;
        }
        for (i = ratings.size() - 1; i >= 0; i--) 
            if (i < ratings.size() - 1 && ratings[i] > ratings[i + 1]) 
                candys[i] = candys[i + 1] + 1 > candys[i] ? candys[i + 1] + 1 : candys[i];
        for (i = 0; i < ratings.size(); i++) 
            sum += candys[i];
        return sum + ratings.size();
    }
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int total = 0;
        int j = -1;
        for (int i = 0, sum = 0; i < gas.size(); ++i) {
            sum += gas[i] - cost[i];
            total += gas[i] - cost[i];
            if (sum < 0) {
                j = i;
                sum = 0;
            }
        }
        return total >= 0 ? j + 1 : -1;
    }
    int search(int A[], int n, int target) {
        int i = 0;   
        for (i; i < n; i++) {
            if (target == A[i]) return i;
        }
        return -1;
    }
    bool searchDup(int A[], int n, int target) {
        int i = 0;   
        for (i; i < n; i++) {
            if (target == A[i]) return true;
        }
        return false;
    }
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        
    }
};

int main()
{
    Solution s;
    s.findMedianSortedArrays(NULL, 0, NULL, 2);
	//int i = 5 >? 4;
    std::cout << "Solution" << std::endl;
    return 0;
}