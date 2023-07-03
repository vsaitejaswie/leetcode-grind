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

 //My previous solution (implemented a couple of months ago)

// class Solution {
// public:
//     ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
//         ListNode *head = new ListNode();
//         ListNode *hold = new ListNode();
//         hold->next = head;
//         //main->next = head;
//         while(list1!=NULL && list2!=NULL){
//             if(list1->val<list2->val){
//                 head->next = list1;
//                 list1 = list1->next;
//             } else{
//                 head->next = list2;
//                 list2 = list2->next;
//             }
//             head = head->next;
//         }
//         if(list1!=NULL) head->next = list1;
//         else if(list2!=NULL) head->next = list2;
//         if(hold->next->next!=NULL) return hold->next->next;
//         return NULL;
//     }
// };

// Current solution

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode* newList = new ListNode();

        ListNode* iter;
        iter = newList; 

        while(list1!=NULL && list2!=NULL){
            if(list1->val<=list2->val){
                iter->next = list1;
                list1 = list1->next;
            } else {
                iter->next = list2;
                list2 = list2->next;
            }
            iter = iter->next;
        }
        if(list1){
            iter->next = list1;
        } else {
            iter->next = list2;
        }

        return newList->next;
    }
};