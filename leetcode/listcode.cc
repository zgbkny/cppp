#include <iostream>
#include <map>

using std::map;
using std::cout;
using std::endl;
struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (!head) return head;
        map<RandomListNode *, RandomListNode *> mp;
        RandomListNode *node = head;
        while (node) {
            mp[node] = new RandomListNode(node->label);
            node = node->next;
        }
        node = head;
        while (node) {
            mp[node]->next = mp[node->next];
            mp[node]->random = mp[node->random];
            node = node->next;
        }
        return mp[head];
    }
};

int main()
{
    Solution s;
    RandomListNode *node = new RandomListNode(-1);
	//int i = 5 >? 4;
    cout << "test" << NULL << endl;
    std::cout << s.copyRandomList(node)->label << std::endl;
    return 0;
}