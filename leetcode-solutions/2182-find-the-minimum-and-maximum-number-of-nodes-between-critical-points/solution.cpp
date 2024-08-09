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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> position;
        vector<int> ans(2, -1); // Initialize answer with [-1, -1]
        
        if (!head || !head->next || !head->next->next) {
            return ans; // Fewer than 3 nodes
        }
        
        int pos = 2; // Start from the third node (index 2)
        ListNode* first = head;
        ListNode* mid = head->next;
        ListNode* forward = mid->next;
        
        while (forward) {
            if ((mid->val > first->val && mid->val > forward->val) || 
                (mid->val < first->val && mid->val < forward->val)) {
                position.push_back(pos);
            }
            
            first = mid;
            mid = forward;
            forward = forward->next;
            pos++;
        }
        
        if (position.size() < 2) {
            return ans; // Fewer than 2 critical points
        }
        
        // Calculate minDistance and maxDistance
        int minDistance = INT_MAX;
        for (int i = 1; i < position.size(); i++) {
            minDistance = min(minDistance, position[i] - position[i - 1]);
        }
        int maxDistance = position.back() - position.front();
        
        ans[0] = minDistance;
        ans[1] = maxDistance;
        
        return ans;
    }
};
