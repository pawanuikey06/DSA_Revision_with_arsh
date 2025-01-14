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
    ListNode* sortList(ListNode*l1 ,ListNode* l2){
        if(!l1) return l2;
        if(!l2) return l1;
        
        ListNode* res ;
        if(l1->val<l2->val){
            res =l1;
            res->next =sortList(res->next,l2);
        }else{
            res=l2;
            res->next=sortList(l1,res->next);
        }
        return res;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return NULL;

        ListNode* dummy =lists[0];


        for(int i=1;i<lists.size();i++){
            dummy =sortList(dummy,lists[i]);
        }
        return dummy;
    }
};
