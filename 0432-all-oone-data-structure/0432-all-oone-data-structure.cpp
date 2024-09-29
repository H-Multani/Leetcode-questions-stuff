class AllOne {
    struct Node {
        int freq;
        list<string> keys;
        Node* prev;
        Node* next;

        Node(int x) {
            freq = x;
            prev = nullptr;
            next = nullptr;
        }
    };

    unordered_map<string, Node*>
        mpp; // string and at what node it is present

    Node* head; // head->next, will give us string with minm freq
    Node* last; // to get maxm freq string

public:
    AllOne() {
        // intialize head as dummy node
        head = new Node(0);
        last = head;
    }

    void addnode(Node* prevnode, int cnt) {
        Node* newnode = new Node(cnt);

        // jo previous node ka next tha vo ab new node ka next ho jaega
        newnode->next = prevnode->next;
        // aur newnode ka prev ab ye previous wala node hoga
        newnode->prev = prevnode;

        // chk if newnode ke aage wala node null toh nai hai?
        if (newnode->next != nullptr) {
            // means newnode ke aage bhi node hai

            // aage wale node ka prev ptr ko previous node se utha kar newnode
            // par laa do
            // aage wala node (newnode->next)
            // ka previous ptr ()->next
            // set to newnode
            newnode->next->prev = newnode;
        }

        // previous node ka next jod no newnode se
        prevnode->next = newnode;

        // possible ki prevnode hi last node tha, agar tha toh ab uske aage apan
        // new node laga diye hai abhi, toh ptr ko update kar ko new node par
        // laa do
        if (prevnode == last) {
            last = newnode;
        }
    }
    void removenode(Node* currnode) {
        // peeche wala node is
        Node* prevnode = currnode->prev;
        // aage wala node
        Node* nxtnode = currnode->next;

        // prev node ke next ko aage wale node par laga do
        prevnode->next = nxtnode;
        // aage wale node ke prev ko point kara do prevnode par
        if (nxtnode != nullptr) {
            nxtnode->prev = prevnode;
        }

        // node delete kar diye hai ab apan

        // last wale node ko dhyaan rakhna
        // if currnode was the last node(last ptr yehi hai abhi)
        // the new last node becomes the previous wala node, since currnode ko
        // delete kar diye hai apan, toh peeche wala new last node ban gyaa,
        // last ptr ko set kar dena prev node par
        if (currnode == last) {
            last = prevnode;
        }

        // sab kaam khatam ab, currnode par aana impossible hai ab(since no
        // nodes point to this node) toh ye node space na khaye , toh delete kar
        // do iss node ko
        delete currnode;
    }

    void inc(string key) {
        if (mpp.find(key) == mpp.end()) {
            // node doesnt exist yet fo this string

            // iss key ke liye freq=1 needed, chk if node with freq 1 already
            // exist
            // freq 1 wala node will be head ka next wale node pr(if it exists),

            // if head ke next pr node nai hai or if node is present the freq
            // isnt 1, means 1 freq walo k liye node nai mile hai
            if (head->next == nullptr || head->next->freq != 1) {
                // node of freq==1 doesnt exist, bana do node
                // 'head' ke aage node bana do freq '1' ke liye
                addnode(head, 1);
            }

            // now we have the node for curr wala key
            // curr wala key has freq 1, and freq 1 wala node is head ke next pr
            // toh curr wala key jo bhi hai, usko freq 1 wale node pr laga do
            // head->next , to get to freq 1 wala node
            // ()->keys , iss node ka keys list
            // ().push(key) , uss list me curr wale key(string) ko push kar do
            (head->next)->keys.push_front(key);
            // ab new key daal di, jis node me lagai hai ye key, uss node ka
            // address map me laga do, for easy access

            // head->next is freq 1 wala node
            mpp[key] = (head->next);
        } else {
            // key is already present in map
            // key wale node par jaa kar uska freq increase karo(ie move to +1
            // freq node)

            Node* currnode = mpp[key];
            int currfreq = currnode->freq;
            // ab current freq wale node par hai
            // chk if +1 freq wala node exists
            // the +1 freq wala node will be just ahead of current node

            // if +1 freq wala node doesnt exist, or node present hai lekin freq
            // +1 wala nai hai, in such case, node bana do +1 freq wala,and curr
            // node ke aage laga do
            if (currnode->next == nullptr ||
                currnode->next->freq != currfreq + 1) {
                // current wale ke aage koi node nai hai
                // new node bana do currnode ke aage and freq +1 wali laga dena
                addnode(currnode, currfreq + 1);
            }

            // ab naya node ban chuka hai
            // current wale key ko +1 freq wale node me push kar do
            // currnode->next , is the +1 freq wala node
            // (")->keys, is that node ka keys wala array
            // ->keys.push(key), current key ko push kar do
            currnode->next->keys.push_front(key);

            // ab curr string(key) new node me daal di hai, update in map, so
            // that current key ka freq updated wale node me mile
            mpp[key] = (currnode->next);

            // ab +1 freq wale node me laga diya key ko, toh current wale node
            // se alag karo,
            // ie if key originally tha freq 3 wale node me, toh apan ne
            // key ko 4 freq wale node me bhej diya, and current(3 freq) wale
            // node se remove kar diye key ko
            // vahi remove karna hai
            currnode->keys.remove(key);

            // now possible hai ki ab current key nikalne ke baad node me kuch
            // naa bache, ie currnet freq wala node is empty, in this case
            // remove the node
            if (currnode->keys.empty()) {
                // remove node
                removenode(currnode);
            }
        }
    }

    void dec(string key) {
        // given: curr key exist krti hai, ie iska node exist kr rha h
        Node* currnode = mpp[key];
        int currcnt = currnode->freq;

        // remove key if cnt bcomes 0, eg if currcnt=1 tha ab 0 kar diye, means
        // key should be removed frm the list itself
        if (currcnt - 1 == 0) {
            // remove kar do key ko map se hi
            mpp.erase(key);
        } else {
            // for curr freq 2,3,.. etc

            // first chk ki kya currfreq -1 wala node exist karta hai??
            if (currnode->prev->freq != currcnt - 1) {
                // means curr-1 freq wala node doesnt exist
                // bana do node
                // previous wale node par jao, uske aage node add kar do new
                // wala node, with curr-1 freq
                addnode(currnode->prev, currcnt - 1);
                // since apan jo node send karenge uske aage lagega new node toh
                // curr ke peeche node lagane ke liye prev wala node dena
                // padega, so that new node prev wale ke aage lag jaaye , and
                // currnode ke prev pr ab new node aa jaega
            }
            // now we have the currfreq-1 wala node
            // current key ko -1 freq wale node me daal do
            // (currnode->prev) is curr-1 freq wala node
            // ()->keys.push(key), uss node ke keys me key push kar do
            currnode->prev->keys.push_front(key);

            // map me update kar do ki current key ka new posn currfreq-1 freq
            // wale node me hai
            mpp[key] = (currnode->prev);
        }

        // remember to delete the key frm current node
        currnode->keys.remove(key);

        // ab erase karne ke baad ho skta ki keys list khatam ho gai ho, ie iss
        // node par koi keys nai hai, in such a case, remove current node
        if (currnode->keys.empty()) {
            // means curr node pr koi key nai hai
            // remove current node
            removenode(currnode);
        }
    }

    string getMaxKey() {
        // first chk if the last node exists or not, ie freq>0 wala node
        if (last == head) {
            // means koi bhi words nai hai map me(all word have freq 0)
            // in such case return empty string
            return "";
        }

        // we here means koi toh lastnode hai apne paas, simply uss lastnode ka
        // koi bhi string return kar do(maine yaha front wala string return kiya
        // hai)
        return last->keys.front();
    }

    string getMinKey() {
        // chk if minm freq wala node exists or not
        if (head->next == nullptr) {
            // means head ke aage koi node nai hai apne paas
            // ie map me koi words(keys) nai hai with freq>0, in such case
            // return empty string
            return "";
        }

        // we here means freq>0 wala node exist karta hai, toh just aage wale
        // node par jao(since that node will have the minm freq wale keys) and
        // waha jo keys hai usme se koi bhi ek string(key) return kar do

        return head->next->keys.front();
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */