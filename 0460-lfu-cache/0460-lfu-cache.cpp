class LFUCache {
public:
    struct Node {
        int key;
        int value;
        int freq;

        Node* prev;
        Node* next;

        Node(int k, int v) {
            key = k;
            value = v;
            freq = 1;
            prev = NULL;
            next = NULL;
        }
    };

    int capacity;
    int minFreq;

    unordered_map<int, Node*> mp;

    unordered_map<int, pair<Node*, Node*>> freqList;

    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 0;
    }

    void addNode(Node* node) {
        int freq = node->freq;

        if (freqList.find(freq) == freqList.end()) {
            Node* head = new Node(-1, -1);
            Node* tail = new Node(-1, -1);

            head->next = tail;
            tail->prev = head;

            freqList[freq] = {head, tail};
        }

        Node* head = freqList[freq].first;
        Node* nextNode = head->next;

        head->next = node;
        node->prev = head;

        node->next = nextNode;
        nextNode->prev = node;
    }

    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void increaseFreq(Node* node) {
        int oldFreq = node->freq;

        removeNode(node);

        node->freq++;

        addNode(node);

        // If old frequency list became empty
        Node* head = freqList[oldFreq].first;
        Node* tail = freqList[oldFreq].second;

        if (head->next == tail && minFreq == oldFreq) {
            minFreq++;
        }
    }

    int get(int key) {
        if (mp.find(key) == mp.end()) {
            return -1;
        }

        Node* node = mp[key];

        increaseFreq(node);

        return node->value;
    }

    void put(int key, int value) {
        if (capacity == 0) {
            return;
        }

        // Key already exists
        if (mp.find(key) != mp.end()) {
            Node* node = mp[key];

            node->value = value;

            // put() also increases frequency
            increaseFreq(node);

            return;
        }

        // Cache is full
        if (mp.size() == capacity) {
            Node* head = freqList[minFreq].first;
            Node* tail = freqList[minFreq].second;

            // Least recently used among minimum frequency
            Node* lru = tail->prev;

            removeNode(lru);
            mp.erase(lru->key);

            delete lru;
        }

        // Insert new node
        Node* node = new Node(key, value);

        mp[key] = node;

        minFreq = 1;

        addNode(node);
    }
};