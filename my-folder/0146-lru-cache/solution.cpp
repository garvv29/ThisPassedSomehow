class LRUCache {
public:
    class Node{
        public:
        int key;
        int value;
        Node* next;
        Node* prev;
        Node(int key,int value)
        {
            this->key=key;
            this->value=value;
            this->next=NULL;
            this->prev=NULL;
        }
    };
    int capacity;
    unordered_map<int,Node*>mpp;
    Node* head=new Node(-1,-1);
    Node* tail=new Node(-1,-1);
    LRUCache(int capacity) {
        this->capacity=capacity;
        head->next=tail;
        tail->prev=head;
    }

    void addnode(Node* node)
    {
        Node* temp=head->next;
        head->next=node;
        node->next=temp;
        node->prev=head;
        temp->prev=node;
    }

    void deletenode(Node* node)
    {
        Node* prevv=node->prev;
        Node* next=node->next;

        prevv->next=next;
        next->prev=prevv;
    }
    
    int get(int key) {
        if(mpp.find(key)!=mpp.end())
        {
            deletenode(mpp[key]);
            addnode(mpp[key]);
            return mpp[key]->value;
        }
        else return -1;
    }
    
    void put(int key, int value) {
        if(mpp.find(key)!=mpp.end())
        {
            mpp[key]->value=value;
            deletenode(mpp[key]);
            addnode(mpp[key]);
        }
        else
        {
            Node* node= new Node(key,value);
            if(mpp.size()>=capacity)
            {
                mpp.erase(tail->prev->key);
                deletenode(tail->prev);
            }
            addnode(node);
            mpp[key]=node;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
