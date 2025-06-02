class Solution {
public:
    int candy(vector<int>& ratings) {
        // by default give 1 candy to each child
        vector<int> candy(ratings.size(),1);
        int n=ratings.size();
        if(n==1) return 1;

        // a lil halp taken frm chatgpt

        for (int i = 1; i < n; ++i) {
            if (ratings[i] > ratings[i - 1]) {
                candy[i] = candy[i - 1] + 1;
            }
        }

        // Right to left
        for (int i = n - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i + 1]) {
                candy[i] = max(candy[i], candy[i + 1] + 1);
            }
        }



        int sum=0;
        for(auto it:candy){
            sum+=it;
        }

        return sum;
    }
};