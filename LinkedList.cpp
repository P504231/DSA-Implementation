class MyLinkedList {
public:
    struct node{
        int data;
        node* next;
        node* prev;
    };
    
    node* head;
    node* tail;
    int size;
    
    MyLinkedList() {
        head = new node();
        tail = new node();
        head->next = tail;
        tail->prev = head;
        size = 0;
    }
    
    int get(int index) {
         if(index >= size)
            return -1;
        else{
            node* curr = head->next;
            while(index != 0){
                curr = curr->next;
                index--;
            }
            return curr->data;
        }
    }
    
    void addAtHead(int val) {
        node* next = head->next;
        node* addNode = new node();
        addNode->data = val;
        addNode->next = next;
        addNode->prev = head;
        head->next = addNode;
        next->prev = addNode;
        size++;
    }
    
    void addAtTail(int val) {
        node* prev = tail->prev;
        node* addNode = new node();
        addNode->data = val;
        addNode->next = tail;
        addNode->prev = prev;
        prev->next = addNode;
        tail->prev = addNode;
        size++;
    }
    
    void addAtIndex(int index, int val) {
         if(index > size)
            return;
        else if(index == size)
            addAtTail(val);
        else if(index == 0)
            addAtHead(val);
        else{
            node* curr = head;
            while(index != 0){
                curr = curr->next;
                index--;
            }
            node* next = curr->next;
            node* addNode = new node();
            addNode->data = val;
            addNode->next = next;
            addNode->prev = curr;
            curr->next = addNode;
            next->prev = addNode;
            size++;
        }
    }
    
    void deleteAtIndex(int index) {
         if(index >= size)
            return;
        else{
            node* curr = head;
            while(index != 0){
                curr = curr->next;
                index--;
            }
            node* del = curr->next;
            del->next->prev = del->prev;
            del->prev->next = del->next;
            delete del;
            size--;
        }
    }
};
