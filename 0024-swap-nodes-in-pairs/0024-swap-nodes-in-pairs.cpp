class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode* first = head;
        ListNode* second = head->next;

        head = second;

        ListNode* prev = nullptr;

        while (first != nullptr && second != nullptr) {
            ListNode* nextPair = second->next;

            second->next = first;

            if (prev != nullptr)
                prev->next = second;

            if (nextPair == nullptr) {
                first->next = nullptr;
                break;
            }

            first->next = nextPair;

            prev = first;
            first = nextPair;

            if (first->next == nullptr)
                break;

            second = first->next;
        }

        return head;
    }
};