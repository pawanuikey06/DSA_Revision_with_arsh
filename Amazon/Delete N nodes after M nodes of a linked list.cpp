class Solution {
  public:
    Node* linkdelete(Node* head, int n, int m) {
        // code here
       if(head==NULL){
            return NULL;
        }
        Node*temp=head;
       while(temp!=NULL){
            for(int i=1;i<m&&temp!=NULL;i++){
                temp=temp->next;
            }
        
            if(temp==NULL)return head;
            Node*temp2=temp->next;
            for(int j=0;j<n&&temp2!=NULL;j++){
                Node*toDel=temp2;
                temp2=temp2->next;
                delete(toDel);
            }
            temp->next=temp2;
             temp = temp2;
       }
            return head;
    }
};
