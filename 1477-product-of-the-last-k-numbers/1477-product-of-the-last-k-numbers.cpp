class ProductOfNumbers {
    // prefix sum use karenge,
    vector<int> prefix;

public:
    ProductOfNumbers() {
        // nothing to do here really
    }

    void add(int num) {
        // new number add kardo prefix list me
        // 2 cheez hai yaha par ab

        // thing 1
        // agar number 0 hai toh yaha se kitna bhi peeche chale jao k leke, end
        // me product 0 hi aayega
        // like if prefix becomes like [2,4,12,0], toh ab yaha se k=1,2,3,4
        // sabke liye product 0 hi hai toh iss case me peehche waale jinte
        // numbers products the faltu ban jayenge, hence no use storing those
        // now, clear the prefix array(hint 2 me bhi yehi likha hai)
        if (num == 0) {
            prefix.clear();
            return;
        }

        // thing 2
        // agar list empty hai prefix waali toh seedhe add kardo
        if (prefix.empty()) {
            prefix.push_back(num);
            return;
        }

        // now agar list empty bhi nai hai and num 0 bhi nai hai toh last number
        // leke multiply krke add kardo
        // basically prefix[n-1]*num karke add kardo prefix vector me
        prefix.push_back(prefix[prefix.size() - 1] * num);
    }

    int getProduct(int k) {

        // ab yaha 3 case hai either k<n or k>n or k==n

        // case 1
        // agar k>n means peeche kahi 0 aaya hoga uss time apan ne array clear
        // kar diya hoga, toh vo 0 agar hota yaha toh overall product 0 hi aata
        // numbers ka since questn always says ki elements always rahenge,
        // nothing to really thing abt, just ek adh example par run krke dekh
        // lena aa jaega samajh me(2 vector maintain krna, prefix wala and
        // element wala aur kaat te jana aa jaega samajh me )

        // uss case me 0 return krdo
        if (prefix.size() < k)
            return 0;

        int n = prefix.size();
        // case 2
        // edge case, if n==k, simply return prefix[n-1]
        if (n == k)
            return prefix[n - 1];

        // case 3
        // otherwise, product of last k elements is prefix[n-1]/prefix[n-k-1],
        // since prefix[n-k-1] is product of all elements frm start upto n-k-1
        // th idx, and prefix[n-1] is product of all elements frm start to n-1
        // th idx. toh product of only k elements frm end will be product of all
        // frm 0 to n-1 / product of all frm 0 to n-k-1
        // isko dry run karna aa jayega samajh me


        // for(auto it:prefix){
        //     cout<<it<<" ";
        // }
        // cout<<endl<<k<<" "<<endl;
        // cout<<prefix[n-1]<<" "<<prefix[n-k-1]<<endl;
        // cout<<endl;

        return prefix[n - 1] / prefix[n - k - 1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */