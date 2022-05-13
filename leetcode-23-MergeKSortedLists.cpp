/*  https://leetcode.com/problems/merge-k-sorted-lists/

You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

 

Example 1:

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6
Example 2:

Input: lists = []
Output: []
Example 3:

Input: lists = [[]]
Output: []
 

Constraints:

k == lists.length
0 <= k <= 104
0 <= lists[i].length <= 500
-104 <= lists[i][j] <= 104
lists[i] is sorted in ascending order.
The sum of lists[i].length will not exceed 104
*/





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
        
    struct myGreater
    {
        inline bool operator() (const ListNode* node1, const ListNode* node2)
        {
            if(!node1) return false; 
            if(node1 && !node2) return true;
            return node1->val > node2->val;
        }
    };

    
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return NULL;
        // only one list
        if(lists.size() == 1) return lists[0];
        
                    // O(k * log k), sort by head's val
                    // sort(lists.begin(), lists.end(), myLess());
        
        // O(k), by complexity result of heap establish
        priority_queue<ListNode*, vector<ListNode*>, myGreater> 
            que(lists.begin(), lists.end());
        
        // delete empty
        // while(!lists[0] && lists.size() > 0) lists.erase(lists.begin());
        while(!que.top() && !que.empty()) que.pop();
        
        ListNode* head = que.top();
        ListNode* tail = head;
        
        // 
        while(!que.empty()){
            // [Inv: tail == que.top()]

            ListNode* top = que.top();
            que.pop();
            
            top = top -> next;
            if(top) 
                que.push(top);
            
            if(!que.empty()){
                tail -> next = que.top();
                tail = tail -> next;
            }
        }
        // tail -> next = NULL;
        
        return head;
    }
};