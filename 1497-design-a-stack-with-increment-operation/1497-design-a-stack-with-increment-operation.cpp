class CustomStack {
    vector<int> st;
    int idx;
public:
    CustomStack(int maxSize) {
        st.resize(maxSize);
        idx=0;
    }
    
    void push(int x) {
        if(idx<st.size()){
            st[idx]=x;
            idx++;
        }
    }
    
    int pop() {
        if(idx==0){
            return -1;
        }
        idx--;
        return st[idx];
    }
    
    void increment(int k, int val) {
        int minm=min(idx,k);

        for(int i=0;i<minm;i++){
            st[i]+=val;
        }

    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */