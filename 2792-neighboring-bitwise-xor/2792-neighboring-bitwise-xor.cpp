class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        // simple, hint 2 se dekho basss

        // lets assume array is {a,b,c,d}, toh apne paas derived array banega
        // like {a^b,b^c,c^d,d^a}, ab lets xor all of these values, we get
        // a^b^b^c^d^d^a which will become 0 in the end

        // so we XOR all values in the derived array, if in the end we get 0,
        // means the derived array was made frm actual values of a,b,c,d. and if
        // this overall XOR isnt equal to 0, means this derived array cant be
        // made

        // yehi hai logic, aur kuch nai aaya(hint 2 bhi yehi bolra)
        
        int ttl=0;
        for(auto it:derived){
            ttl=ttl^it;
        }

        if(ttl==0) return true;

        return false;
    }
};