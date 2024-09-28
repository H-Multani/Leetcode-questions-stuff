class MyCircularDeque {
    // vector<int> front,rear;
    vector<int> dq;
    int frntptr,rearptr;
    int maxsize;
public:
    MyCircularDeque(int k) {
        // front=new vector<int>(k);
        dq.resize((2*k)+1,0);

        maxsize=k;
        frntptr=k,rearptr=k;
    }
    
    bool insertFront(int value) {
        if(frntptr-rearptr>=maxsize) return false;

        dq[frntptr]=value;
        frntptr++;
        return true;
    }
    
    bool insertLast(int value) {
        if(frntptr-rearptr>=maxsize) return false;

        rearptr--;
        dq[rearptr]=value;
        return true;
    }
    
    bool deleteFront() {
        // front.pop_back();

        if(frntptr<rearptr || (frntptr==rearptr && dq[frntptr]==0)){return false;}
        frntptr--;
        dq[frntptr]=0;
        return true;
    }
    
    bool deleteLast() {
        // rear.pop_back();

        if(rearptr>frntptr || (frntptr==rearptr && dq[frntptr]==0)){return false;}

        dq[rearptr]=0;
        rearptr++;
        return true;
    }
    
    int getFront() {
        if(frntptr<rearptr || (frntptr==rearptr && dq[frntptr]==0)) return -1;
        return dq[frntptr-1];
    }
    
    int getRear() {
        if(frntptr<rearptr || (frntptr==rearptr && dq[frntptr]==0)) return -1;
        return dq[rearptr];
    }
    
    bool isEmpty() {

        if(frntptr==rearptr) return true;

        return false;
    }
    
    bool isFull() {
        if(frntptr-rearptr==maxsize) return true;

        return false;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */