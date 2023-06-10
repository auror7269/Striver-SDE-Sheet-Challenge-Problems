 class Node
        {
        public:
            int data;
            Node *next;
            Node()
            {
                this->data = 0;
                next = NULL;
            }
            Node(int data)
            {
                this->data = data;
                this->next = NULL;
            }
            Node(int data, Node* next)
            {
                this->data = data;
                this->next = next;
            }
        };




bool detectCycle(Node *head)
{
	if(head==NULL) return false;
    Node *slow=head;
    Node *fast=head->next;
    while(slow!=NULL && fast!=NULL){
        fast=fast->next;
        if(fast!=NULL) fast=fast->next;

        slow=slow->next;
        if(slow==fast) return true;
    }
    return false;

}