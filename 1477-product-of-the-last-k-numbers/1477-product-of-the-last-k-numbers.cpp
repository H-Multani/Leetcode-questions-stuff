class ProductOfNumbers {
    // vector bana do store karlo
    vector<int> stuff;
public:
    ProductOfNumbers() {
        // nothing to do here really
    }
    
    void add(int num) {
        // new number add kardo array me
        stuff.push_back(num);
    }
    
    int getProduct(int k) {
        // start frm n-k th posn, and products lete jao
        int n=stuff.size();
        int prod=1;
        for(int i=n-1;i>=n-k;i--) prod*=stuff[i];

        return prod;
        
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */