#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using std::map;
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::min;
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

    vector<int> twoSum(vector<int> &numbers, int target) {
        int size = numbers.size(), i = 0;
        vector<int> ret;
        map<int, int> mp;
        for ( ; i < size; i++) {
            mp[numbers[i]] = i + 1;
        }
        for (i = 0; i < size; i++) {
            if (mp[target - numbers[i]] && mp[target - numbers[i]] != i + 1) {
                ret.push_back(i + 1);
                ret.push_back(mp[target - numbers[i]]);
                return ret;
            }
        }
        return ret;
    }

    vector<int> twoSum1(vector<int> &numbers, int target) {
        int size = numbers.size(), i = 0, j = i + 1;
        vector<int> ret;
        for ( ; i < size; j = ++i + 1) 
            for ( ; j < size; j++)
                if (numbers[i] + numbers[j] == target) {
                    ret.push_back(i+1);
                    ret.push_back(j+1);
                    return ret;
                }
        return ret;
    }

    int findKthSortedArrays(int A[], int m, int B[], int n, int k) {
        if (m > n) return findKthSortedArrays(B, n, A, m, k);
        if (m == 0) return B[k-1];
        if (k == 1) return min(A[0], B[0]);

        int ia = min(k / 2, m), ib = k - ia;
        if (A[ia - 1] < B[ib - 1])
            return findKthSortedArrays(A + ia, m - ia, B, n, k - ia);
        else if (A[ia - 1] > B[ib - 1])
            return findKthSortedArrays(A, m, B + ib, n - ib, k - ib);
        else
            return A[ia - 1];


    }
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int total = m + n;
        if (total % 2 == 1) {
            return findKthSortedArrays(A, m, B, n, total / 2 + 1);
        } else {
            return (findKthSortedArrays(A, m, B, n, total / 2) + 
                    findKthSortedArrays(A, m, B, n, total / 2 + 1)) / 2.0;
        }
    }
    int candy(vector<int> &ratings) {
        int candys[ratings.size()];
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
    vector<vector<int>> threeSum(vector<int> &num) {
        vector<vector<int>> ret;
        if (num.size() < 3) return ret;
        sort(num.begin(), num.end());
        int i = 0, j = 0, k = 0, tmp = 0;
        tmp = num[0] - 1;
        for (i = 0; i < num.size(); i++) {
            if (tmp == num[i]) continue; 
            for (j = i + 1, k = num.size() - 1; j < k; ) {
                if(j > i + 1 && num[j] == num[j - 1]){ 
                    j++;
                    continue;
                }
                if(k < num.size() - 1 && num[k] == num[k + 1]){
                    k--;
                    continue;
                }
                tmp = num[i] + num[j] + num[k];
                if (tmp > 0) k--;
                else if (tmp < 0) j++;
                else {
                    vector<int> item;
                    item.push_back(num[i]);
                    item.push_back(num[j]);
                    item.push_back(num[k]);
                    ret.push_back(item);
                    k--; j++;
                }
            }
            tmp = num[i];
        }
        return ret;   
    }
    int threeSumClosest(vector<int> &num, int target) {
        int ret;
        sort(num.begin(), num.end());
        ret = num[0] + num[1] + num[2];
        int i = 0, j = 0, k = 0, tmp = 0, last = 0;
        for (i = 0; i < num.size(); i++) {
            for (j = i + 1, k = num.size() - 1; j < k; ) {
                tmp = num[i] + num[j] + num[k];
                if (tmp > target) k--;
                else if (tmp < target) j++;
                else {
                    ret = target;
                    break;
                }
                if (j < k) {
                    if (abs(num[i] + num[j] + num[k] - target) > abs(tmp - target)) break;
                }
            }
            if (abs(ret - target) > abs(tmp - target)) ret = tmp;
        }
        return ret;   
    }
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int>> ret;
        if (num.size() < 4) return ret;
        sort(num.begin(), num.end());
        int i = 0, j = 0, h = 0, k = 0, tmp = 0;
        tmp = num[0] - 1;
        for (i = 0; i < num.size(); i++) {
            if (i > 0 && num[i] == num[i - 1]) continue; 
            for (j = i + 1; j < num.size() - 2; j++) {
                if (j > i + 1 && num[j] == num[j - 1]) continue;
                for (h = j + 1, k = num.size() - 1; h < k; ) {
                    if(h > j + 1 && num[h] == num[h - 1]){ 
                        h++;
                        continue;
                    }
                    if(k < num.size() - 1 && num[k] == num[k + 1]){
                        k--;
                        continue;
                    }
                    tmp = num[i] + num[j] + num[h] + num[k];
                    if (tmp > target) k--;
                    else if (tmp < target) h++;
                    else {
                        vector<int> item;
                        item.push_back(num[i]);
                        item.push_back(num[j]);
                        item.push_back(num[h]);
                        item.push_back(num[k]);
                        ret.push_back(item);
                        k--; h++;
                    }
                }
            }
        }
        return ret;   
    }
    int removeElement(int A[], int n, int elem) {
        int i = 0, ret = n, idx = 0;
        bool flag = false;
        sort(A, &A[n]);
        for (i = 0; i < n; i++) 
            if (elem == A[i]) {
                ret--;
                if (!flag) {
                    flag = true;
                    idx = i;
                }
            }
        if (flag) {
            for (i = 0; i < ret - idx; i++) {
                A[i + idx] = A[i + n - ret + idx];
            }
        }
        return ret;
    }
    void nextPermutation(vector<int> &num) {
        int i = num.size() - 1, tmp = 0, idx = 0;
        for ( ; i > 0; i--) {
            if (num[i] > num[i - 1]) {
                idx = i - 1;
                for (i = num.size() - 1; ; i--) {
                    if (num[i] > num[idx]) break;
                }
                tmp = num[idx];
                num[idx] = num[i];
                num[i] = tmp;
                sort(num.begin() + idx + 1, num.end());
                return;
            }
        }    
        if (i == 0) {
            sort(num.begin(), num.end());
        }
    }
    vector<vector<int> > threeSumWrong(vector<int> &num) {
        map<int, int> mp;
        vector<vector<int>> ret;
        if (num.size() < 3) return ret;
        sort(num.begin(), num.end());
        int i = 0, j = 0, tmp = 0;
        for ( ; i < num.size(); i++) {
            mp[num[i]] = i;
        }
        tmp = num[0] - 1;
        for (i = 0; i < num.size(); i++) {
            if (tmp == num[i]) continue; 
            for (j = i + 1; j < num.size(); j++) {
                if (j < num.size() - 1 && num[j] == num[j + 1]) {
                    j++;
                    continue;
                }
                tmp = 0 - num[i];
                tmp -= num[j]; 
                if (mp[tmp] > j) {
                    vector<int> item;
                    item.push_back(num[i]);
                    item.push_back(num[j]);
                    item.push_back(tmp);
                    ret.push_back(item);
                }
            }
            tmp = num[i];
        }
        return ret;   
    }
    void findInLow(vector<int> &data, int n, int product, int k) {
        int i = 0, tmp = k;
        for ( ; n > 0; n--, i++) {
            if (k >= product) break;
            else product /= n;
        }
        tmp = k - product;
        if (tmp > 2) {

        } else if (tmp > 0) {
            if (tmp == 2) {

            } else {

            }
        } else {
            
        }
    }
    string getPermutation(int n, int k) {
        vector<int> data;
        string ret(n);
        int i = 0, product = 0, tmp = 0;   
        for ( ; i < n; i++) {
            data.push_back(i + 1);
            product *= (i + 1);
        }
        findInLow(data, n, product, k);
        
    }
 /* vector<vector<int> > threeSum(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
       
        vector<vector<int> > ret;
         ret.clear();
        sort(num.begin(),num.end());
        for(int i=0; i!=num.size();i++){
            if(i > 0 && num[i]==num[i-1])
                continue;
            int j,k;
            j=i+1;
            k=num.size()-1;
            while(j<k){
                if(j>i+1&&num[j]==num[j-1]){ 
                    j++;
                    continue;
                }
                if(k<num.size()-1&& num[k]==num[k+1]){
                    k--;
                    continue;
                }
                int sum = num[i] + num[j] + num[k];
                if(sum>0){
                    k--;
                }else if(sum<0){
                    j++;
                }else{
                    vector<int> tmp;
                    tmp.push_back(num[i]);
                    tmp.push_back(num[j]);
                    tmp.push_back(num[k]);
                    ret.push_back(tmp);
                    j++;
                }
            }
        }
        return ret;
            
    }*/

};

int main()
{
    vector<int> num;
    int number;
    while (cin >> number)
    {
        if (number == 999) break;
        num.push_back(number);
    }
    vector<vector<int> > result;
    Solution s;
    result = s.threeSum(num);

    for (size_t i = 0; i < result.size(); i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            cout << result[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}