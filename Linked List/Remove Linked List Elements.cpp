/*
 * Problems:
 * Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.
 *
 * Example 1:
 * Input: head = [1,2,6,3,4,5,6], val = 6
 * Output: [1,2,3,4,5]
 *
 * Example 2:
 * Input: head = [], val = 1
 * Output: []
 *
 * Example 3:
 * Input: head = [7,7,7,7], val = 7
 * Output: []
 *
 * Constraints:
 * The number of nodes in the list is in the range [0, 104].
 * 1 <= Node.val <= 50
 * 0 <= k <= 50
 *
 * *
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * ListNode *next;
 * ListNode() : val(0), next(nullptr) {}
 * ListNode(int x) : val(x), next(nullptr) {}
 * ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 * 
 * 
 * Iterative Solution:
 */

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(!head)
            return head;
        while(head && head->val == val){
            ListNode* del = head;
            head = head->next;
            delete del;
        }
        ListNode* temp = head;
        while(temp && temp->next){
            if(temp->next->val == val){
                ListNode* del = temp->next;
                temp->next = temp->next->next;
                delete del;
            }
            else
             temp = temp->next;
        }
        return head;
    }
};

//Recursive Solution:

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (head == null) 
            return null;
        head->next = removeElements(head->next, val);
        return head->val == val ? head->next : head;
    }
}
