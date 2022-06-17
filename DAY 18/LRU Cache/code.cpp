class LRUCache {
public:
    class node {
        public:
            int key;
            int val;
            node* next;
            node* prev;
            node(int _key, int _val) {
            key = _key;
            val = _val; 
        }
    };
    
    node* head = new node(-1,-1);
    node* tail = new node(-1,-1);
    
    int capa;
    unordered_map<int, node*>m;
    
    LRUCache(int capacity) {
        capa = capacity;    
        head->next = tail;
        tail->prev = head;
    }
    
    void addnode(node* newnode) {
        node* temp = head->next;
        newnode->next = temp;
        newnode->prev = head;
        head->next = newnode;
        temp->prev = newnode;
    }
    
    void deletenode(node* delnode) {
        node* delprev = delnode->prev;
        node* delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }
    
    int get(int key) {
        if (m.find(key) != m.end()) {
            node* resnode = m[key];
            int res = resnode->val;
            m.erase(key);
            deletenode(resnode);
            addnode(resnode);
            m[key] = head->next;
            return res; 
        }
    
        return -1;
    }
    
    void set(int key, int value) {
        if(m.find(key) != m.end()) {
            node* existingnode = m[key];
            m.erase(key);
            deletenode(existingnode);
        }
        if(m.size() == capa) {
          m.erase(tail->prev->key);
          deletenode(tail->prev);
        }
        
        addnode(new node(key, value));
        m[key] = head->next; 
    }
};
