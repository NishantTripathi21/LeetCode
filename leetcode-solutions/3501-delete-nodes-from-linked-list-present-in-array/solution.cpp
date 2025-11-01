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
    ListNode* solve(unordered_set<int>& st, ListNode* temp) {
        if (!temp) return nullptr;

        if (st.count(temp->val)) {
            return solve(st, temp->next);
        } 
        else{
            temp->next = solve(st, temp->next);
            return temp;
        }
    }

    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> st(nums.begin(), nums.end());
        return solve(st, head);
    }
};
