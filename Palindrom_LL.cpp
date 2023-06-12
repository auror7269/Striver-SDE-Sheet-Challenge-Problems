#include <bits/stdc++.h> 
    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };


LinkedListNode<int> *reverse(LinkedListNode<int> *curr){
    LinkedListNode<int> *prev=NULL;
    LinkedListNode<int> *next1=NULL;
    while(curr!=NULL){
        next1=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next1;
    }
    return prev;
}
bool isPalindrome(LinkedListNode<int> *head) {
  if (head == NULL || head->next == NULL) {
    return true;
  }
    LinkedListNode<int> *slow=head;
    LinkedListNode<int> *fast=head;
    while(fast->next!=NULL&& fast->next->next!=NULL){
       
        slow=slow->next;
         fast=fast->next->next;
    }
    slow->next=reverse(slow->next);
    slow=slow->next;
    while(slow!=NULL){
        if(head->data!=slow->data){
            return false;
        }
        head=head->next;
        slow=slow->next;
    }
    return true;

}