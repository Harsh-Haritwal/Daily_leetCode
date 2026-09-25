class Node {
public:
    pair<int, int> part;
    Node* next;
    Node* prev;
    Node(int key, int value) {
        part.first = key;
        part.second = value;
        next = nullptr;
        prev = nullptr;
    }
};

class LRUCache {
public:
    int cap;
    unordered_map<int, Node*> mp;
    Node* head = new Node (-1,-1);
    Node* tail = new Node(-1,-1);
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void deleteNode(Node* oldNode) {
        oldNode->prev->next = oldNode->next;
        oldNode->next->prev = oldNode->prev;
    }
    void insertAfterHead(Node* oldNode) {
        oldNode->next = head->next;
        head->next = oldNode;
        oldNode->next->prev = oldNode;
        oldNode->prev = head;
    }

    int get(int key) {
        if (mp.find(key) == mp.end()) {
            return -1;
        }
        Node* oldNode = mp[key];
        deleteNode(oldNode);
        insertAfterHead(oldNode);
        return oldNode->part.second;;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
           Node* oldNode = mp[key];
           oldNode->part.second = value;
           deleteNode(oldNode);
           insertAfterHead(oldNode);
           return;
        }
        if(mp.size() == cap){
            mp.erase(tail->prev->part.first);
            deleteNode(tail->prev);
            Node* newNode = new Node(key,value);
            insertAfterHead(newNode);
            mp[key] = newNode;
            return;
        }else{
            Node* newNode = new Node(key,value);
            insertAfterHead(newNode);
            mp[key] = newNode;
            return;

        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */