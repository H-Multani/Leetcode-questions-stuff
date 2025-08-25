class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        // diagonal ke har bande ke indexes ka sum same hai, like {3,5,7} ke
        // indexes ka sum is same which is 2

        // toh ek vector<vector<int>> me sab store karlo index ke sum ke hisaab
        // se, then end me usme iterate kar lena
        int m = mat.size();
        int n = mat[0].size();

        // indexes can go at max =m-1+n-1, itne+1 size ka hi bana do fir just to
        // be safe
        vector<vector<int>> elements(m + n - 1, vector<int>());

        // ab iterate karo mat par
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // current element ko i+j wale idx ke vector me daal do
                elements[i + j].push_back(mat[i][j]);
            }
        }

        // ab bas elements vector par iterate karke saare internal vectors ko ek
        // sath laga do and ans bana do
        vector<int> ans;

        // iterate karte time ek cheez ka dhyan rakhna, arrows konse side jaa
        // rahe hai, like order kya hai, eg1 me 1 ke baad 2,4 then apne order ke
        // hisab se 3,5,7 milega lekin arrow kaise jara dekho, toh reverse karke
        // daalna padega, toh keep that in mind

        // baically har second vector ko daalne se pehle reverse kar dena

        // to keep track ki konsa wala diagonal hai, har even diagonal ko
        // reverse karke daalna hai
        int i = 0;
        for (auto it : elements) {
            if(i%2==0){
                // reverse order me dalo ans me
                for(int j=it.size()-1;j>=0;j--){
                    ans.push_back(it[j]);
                }
            }
            else{
                // normal order me dalo
                for(auto it2:it){
                    ans.push_back(it2);
                }
            }

            i++;
        }

        return ans;
    }
};