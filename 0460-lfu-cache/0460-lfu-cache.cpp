class LFUCache {
public:

    class Node{
    public:
        int key;
        int value;
        int count;
        Node* next;
        Node* prev;

        Node(int key,int value)
        {
            this->key = key;
            this->value = value;
            next = NULL;
            prev = NULL;
            count = 1;
        }
    };

    class DLL{
    public:
        int size;
        Node* head;
        Node* tail;

        DLL()
        {
            size = 0;
            head = new Node(-1, -1);
            tail = new Node(-1, -1);
            head->next = tail;
            tail->prev = head;
        }

        void addnode(Node* node)
        {
            Node* temp = head->next;
            head->next = node;
            node->prev = head;

            node->next = temp;
            temp->prev = node;

            size++;
        }

        void deletenode(Node* node)
        {
            Node* prevv = node->prev;
            Node* nextt = node->next;

            prevv->next = nextt;
            nextt->prev = prevv;

            size--;
        }

    };

    int capacity;
    int minfreq;
    unordered_map<int, Node*> mpp;
    unordered_map<int, DLL*> freqmap;

    LFUCache(int capacity)
    {
        this->capacity = capacity;
        minfreq = 0;
    }

    void updatefreq(Node* node)
    {
        int freq = node->count;
        freqmap[freq]->deletenode(node);

        // if old freq list empty, update minfreq
        if (freqmap[freq]->size == 0)
        {
            if (minfreq == freq)
                minfreq++;
        }

        node->count++;

        if (freqmap.find(node->count) == freqmap.end())
        {
            freqmap[node->count] = new DLL();
        }

        freqmap[node->count]->addnode(node);
    }

    int get(int key)
    {
        if (capacity == 0) return -1;

        if (mpp.find(key) == mpp.end()) return -1;

        updatefreq(mpp[key]);
        return mpp[key]->value;
    }

    void put(int key, int value)
    {
        if (capacity == 0) return;

        // Key exists
        if (mpp.find(key) != mpp.end())
        {
            Node* node = mpp[key];
            node->value = value;
            updatefreq(node);
            return;
        }

        // Need eviction
        if (mpp.size() == capacity)
        {
            DLL* dll = freqmap[minfreq];
            Node* nodeToDelete = dll->tail->prev;

            mpp.erase(nodeToDelete->key);
            dll->deletenode(nodeToDelete);
        }

        // Insert new node
        Node* newNode = new Node(key, value);
        mpp[key] = newNode;
        minfreq = 1;

        if (freqmap.find(1) == freqmap.end())
        {
            freqmap[1] = new DLL();
        }

        freqmap[1]->addnode(newNode);
    }
};
