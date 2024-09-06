/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> delEle(nums.begin(), nums.end());
        ListNode temp(0,head);
        ListNode* curr = head;
        ListNode* prev = &temp;

        while(curr != NULL)
        {
            if(delEle.find(curr->val) != delEle.end())
                prev->next = curr->next;
            else
                prev = curr;
            curr = prev->next;
        }
        return temp.next;
    }
};