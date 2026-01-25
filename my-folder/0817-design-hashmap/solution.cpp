class MyHashMap {
public:
    vector<pair<int,int>> hm; 

    MyHashMap() {}

    void put(int key, int value) {
        for (auto &i : hm) { 
            if (i.first == key) {
                i.second = value;
                return;
            }
        }
        hm.push_back({key, value}); 
    }

    int get(int key) {
        for (auto &i : hm) {
            if (i.first == key)
                return i.second;
        }
        return -1;
    }

    void remove(int key) {
        for (auto it = hm.begin(); it != hm.end(); ++it) {
            if (it->first == key) {
                hm.erase(it);
                return;
            }
        }
    }
};

