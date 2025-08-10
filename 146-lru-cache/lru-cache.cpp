class LRUCache {
private:
    struct Node{
        int key, value;
        Node* prev;
        Node* next;
        Node(int K, int V) : key(K), value(V), prev(nullptr), next(nullptr){}
    };
    int capacity;
    unordered_map<int, Node*>cache;
    Node* head;
    Node* tail;
    void removeNode(Node* node){
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
        }
    void addToFront(Node* node){
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
        }
public:
    LRUCache(int capacity) : capacity(capacity){
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
        }
    int get(int key){
        if(cache.find(key)== cache.end())return -1;
        Node* node = cache[key];
        removeNode(node);
        addToFront(node);
        return node->value;
        }
    void put(int key, int value){
        if(cache.find(key) != cache.end()){
            Node* node = cache[key];
            node->value = value;
            removeNode(node);
            addToFront(node);
            }else{
                if(cache.size()==capacity){
                    Node* lru = tail->prev;
                    cache.erase(lru->key);
                    removeNode(lru);
                    delete lru;
                }
                Node* newNode = new Node(key, value);
                cache[key] = newNode;
                addToFront(newNode);
            }
                   }
            };


/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */