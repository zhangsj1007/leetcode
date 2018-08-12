class LRUCache{
public:
    class Node{
    public:
        int key_;
        int value_;
        Node * prev_;
        Node * next_;
    public: 
        Node(int key, int value): key_(key), value_(value), prev_(NULL), next_(NULL){
            
        }
    };
public:
    LRUCache(int capacity):capacity_(capacity), size_(0) {
        dummy_ = new Node(0, 0);
        dummy_->prev_ = dummy_;
        dummy_->next_ = dummy_;
    }
    
    int get(int key) {
        Node *p = NULL;
        if (_get(key, &p)){
            setAdjust(p, false);
            return p->value_;
        }else
            return -1;
    }
    
    void set(int key, int value) {
        Node *p = NULL;
        if (_get(key, &p)){
            setAdjust(p,false);
            p->value_ = value;
        }else{
            Node * p = new Node(key, value);
            setAdjust(p, true);
        }
    }
    
private:
    bool _get(int key, Node ** p){
        map<int, Node*>::iterator iter = nodes_.find(key);
        if (iter == nodes_.end())
            return false;
        else{
            *p = iter->second;
            return true;
        }
    }

    void setAdjust(Node * p, bool isNew){
        if (isNew){
            p->next_ = dummy_->next_;
            p->next_->prev_ = p;
            dummy_->next_ = p;
            p->prev_ = dummy_;
            
            nodes_[p->key_] = p;
            
            size_++;
            
            if (size_ > capacity_){
                Node * t = dummy_->prev_;
                dummy_->prev_ = t->prev_;
                t->prev_->next_ = dummy_;
                nodes_.erase(t->key_);
                delete(t);
            }
        }else {
            p->prev_->next_ = p->next_;
            p->next_->prev_ = p->prev_;
            
            p->next_ = dummy_->next_;
            p->next_->prev_ = p;
            dummy_->next_ = p;
            p->prev_ = dummy_;
            
        }
    }
    
private:
    map<int, Node*> nodes_;
    Node * dummy_;
    int capacity_;
    int size_;
};
