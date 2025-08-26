class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& d) {
        int maxdiag=0;
        // diagonal is sqrt((l^2)+(b^2));, apan sqrt wala part nai lenge
        int maxdiagidx=-1;

        int maxarea=0;

        for(auto it:d){
            // current bande ka diagonal nikalo
            int curr=pow(it[0],2)+pow(it[1],2);

            // curr=sqrt(curr);
            
            cout<<curr<<endl;

            if(curr>maxdiag){
                // new diagonal bigger, update

                // update max
                maxdiag=curr;

                // current bande ka area nikal lo
                maxarea=it[0]*it[1];
            }
            else if(curr==maxdiag){
                // new diagonal same as previous one, take the one with bigger area
                maxarea=max(maxarea,it[0]*it[1]);
            }
        }

        return maxarea;
    }
};