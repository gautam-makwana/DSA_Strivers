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
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            }
            else{
                tail->next = l2;
                l2 = l2->next;
            }
        tail = tail -> next;
        }
        if(l1) tail->next = l1;
        else tail->next = l2;
        return dummy.next;
    }

    ListNode* mergeklisthelper(vector<ListNode*>& lists, int start, int end){
        if(start == end) return lists[start];
        else if(start + 1 == end) return merge(lists[start], lists[end]);
        else {
            int mid = start + (end - start) / 2;

            ListNode* left = mergeklisthelper(lists,start,mid);
            ListNode* right = mergeklisthelper(lists,mid+1,end);
            return merge(left, right);
        }
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;
        return mergeklisthelper(lists, 0, lists.size() - 1);
    }
};