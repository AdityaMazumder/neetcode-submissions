class LRUCache {
    struct Node {
        int key, val;
        Node *prev, *next;

        Node(int k, int v) {
            key = k;
            val = v;
            prev = next = nullptr;
        }
    };

    unordered_map<int, Node*> mp;
    Node *head, *tail;
    int cap;

    void remove(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void insert(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    void makeRecent(Node* node) {
        remove(node);
        insert(node);
    }

public:
    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(0, 0);
        tail = new Node(0, 0);

        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (mp.find(key) == mp.end())
            return -1;

        Node* node = mp[key];
        makeRecent(node);

        return node->val;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            Node* node = mp[key];
            node->val = value;
            makeRecent(node);
            return;
        }

        if (mp.size() == cap) {
            Node* lru = tail->prev;
            remove(lru);
            mp.erase(lru->key);
            delete lru;
        }

        Node* node = new Node(key, value);
        insert(node);
        mp[key] = node;
    }
};