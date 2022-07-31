class LRUCache {
     class node{
        public:
        int key;
        int val;
        node* next;
        node* prev;
        
        node( int key , int val)
        {
            this->key = key;
            this->val=val;
            this->next=NULL;
            this->prev=NULL; 
        }
    };
    int capacity;
    unordered_map<int,node*>mp;
    node * head = new node(0,0);
    node * tail = new node(0,0);
public:
    LRUCache(int capacity) {
        this->capacity=capacity;
        head->next=tail;
        tail->prev= head;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end())
          return -1;
      
        node *curnode=mp[key];
        remove(curnode);
        insert(curnode);
      
        return curnode->val;
        
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end())
        {
            remove(mp[key]);
        }
        
        // if size is full then we have to remove the least recently used node
        if(mp.size()==capacity)
        {
            remove(tail->prev);
        }
        insert(new node(key,value));
    }
    void insert(node*curnode){
        curnode->next=head->next;
        head->next->prev=curnode;
        head->next=curnode;
        curnode->prev=head;
        mp[curnode->key]=curnode;
    }
    void remove(node*curnode){
        mp.erase(curnode->key);
        curnode->next->prev=curnode->prev;
        curnode->prev->next=curnode->next;
    }
};
