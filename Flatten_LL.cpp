class Node {
   public:
 		int data;
 		Node *next;
  		Node *child;
 		Node() : data(0), next(nullptr), child(nullptr){};
 		Node(int x) : data(x), next(nullptr), child(nullptr) {}
 		Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
  };
 
Node* merge(Node* a, Node* b){
	if(a ==NULL) return b;
	if(b == NULL) return a;
	Node* temp=new Node(0);
	Node* res=temp;
	while(a!=NULL && b!=NULL){
		if(a->data < b->data){
			temp->child=a;
			temp=temp-> child;
			a = a->child;
		}else{
			temp->child=b;
			temp=temp->child;
			b=b->child;
		}
	}
	if(a) temp->child=a;
	else if(b) temp->child=b;

	return res->child;
}
Node* flattenLinkedList(Node* head) 
{
	if(head==NULL || head->next==NULL) return head;

	Node* root = head->next;
	head->next = NULL;
	root = flattenLinkedList(root);
	head = merge(head, root);
	return head;
}
