

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



Node * cycleexist(Node *curr){
    Node *slow=curr;
    Node *fast=curr;
    while(fast!=NULL){
        fast=fast->next;
        if(fast!=NULL) fast=fast->next;
        slow=slow->next;

        if(slow==fast){
            return fast;
        }
    }
    return NULL;
}
Node *firstNode(Node *head)
{
    if(head==NULL || head->next==NULL) return NULL;

    Node *inter=cycleexist(head);
    if(inter!=NULL){
        Node *slow=head;
        while(slow!=inter){
            slow=slow->next;
            inter=inter->next;
        }
        return slow;
    }
    return NULL;
}