class NumArray {

    vector<int> segtree;
    int n;
    void buildtree(int i, int l, int r,vector<int>&nums){
        // base case
        if(l==r){
            segtree[i]=nums[l];
            return;
        }

        // mid nikalo
        int mid=(l+r)/2;

        // left bharo
        buildtree((2*i)+1,l,mid,nums);
        // right bharo
        buildtree((2*i)+2,mid+1,r,nums);

        // curr node update karo
        segtree[i]=segtree[(2*i)+1]+segtree[(2*i)+2];
    }

    void updatesegtree(int idx, int val, int i, int l, int r){
        if(l==r){
            segtree[i]=val;
            return;
        }

        int mid=(l+r)/2;

        if(idx<=mid){
            // left update krdo
            updatesegtree(idx,val,(2*i)+1,l,mid);
        }
        else{
            // right update krdo
            updatesegtree(idx,val,(2*i)+2,mid+1,r);
        }

        // segtree update krdo
        segtree[i]=segtree[(2*i)+1]+segtree[(2*i)+2];
    }
    int query(int start, int end, int i, int l, int r){
        if(l>end || r<start){
            // out of range 
            return 0;
        }
        else if(l>=start && r<=end){
            // pura in range h, value return krdo
            return segtree[i];
        }

        // we here means partial overlap hora hai, left and right jao
        int mid=(l+r)/2;

        // jo bhi ans aaye bhej dena total
        return query(start,end,(2*i)+1,l,mid)+query(start,end,(2*i)+2,mid+1,r);
    }
public:
    NumArray(vector<int>& nums) {
        // seg tree bana do
        n=nums.size();
        segtree.resize(4*n);

        buildtree(0,0,n-1,nums);
    }
    
    void update(int index, int val) {
        

        // update logic funcn likho
        updatesegtree(index,val,0,0,n-1);
        // (idx,val,i,l,r);
        
    }
    
    int sumRange(int left, int right) {
        // query karo ab
        return query(left,right,0,0,n-1);
        // (start,end,i,l,r)
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */