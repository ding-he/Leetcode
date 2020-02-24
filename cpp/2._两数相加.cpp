/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *retList = new ListNode(0);
        ListNode *tempList = retList;
        int next_val = 0;

        while(true)
        {
            int sum, ge, shi;
            int l1_val(0), l2_val(0);
            
            if(l1)
            {
                l1_val = l1->val;
                l1 = l1->next;
            }
            if(l2)
            {
                l2_val = l2->val;
                l2 = l2->next;
            }
            sum = l1_val + l2_val + next_val;

            ge = sum % 10;
            shi = sum / 10;

            tempList->val = ge;
            next_val = shi;

            if(l1 == NULL && l2 == NULL)
            {
                if(shi == 0)
                {
                    tempList->next = NULL;
                }
                else
                {
                    tempList->next = new ListNode(shi);
                }
                break;
            }
            
            tempList->next = new ListNode(0);
            tempList = tempList->next;

        }

        return retList;

    }

};