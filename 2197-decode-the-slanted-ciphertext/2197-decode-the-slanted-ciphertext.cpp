class Solution {
public:
    string decodeCiphertext(string s, int rows) {
        // edge case agar s is empty then return khali
        if(s=="") return "";

        // ek kaam karte hai matrix bana hi dete hai,
        // no of rows ka dikkat nai hai
        // no of cols ka dikkat,formula banana padega, enc text me saare spaces
        // and all bhi diye hai,toh pure string ko matrix me daalne par matrix
        // pura bhar jana chahiye, so that means string ka size =cols*rows, toh
        // cols=size/rows
        int n = s.size();
        int cols = n/rows;

        // matrix bana lo
        vector<vector<char>> mat(rows, vector<char>(cols));

        // string par chal kar bhar do matrix ko
        for (int i = 0; i < n; i++) {
            // i th char par hai toh ye kaha baithega

            // reqd row will be i/cols
            // reqd col will be i%cols
            mat[i / cols][i % cols] = s[i];
        }

        // ab chal lo matrix par simulate kardo, and sab char strings me daalne
        // ke baad trailing spaces nikal lena since logic apan aisa likhenge ki trailing spaces aaye maybe

        // diagonal par chalna hai starting (0,0)

        // toh first diagonal (0,0),(1,1),(2,2)...
        // toh second diagonal (0,1),(1,2),(2,3)...
        string ans="";

        int i=0;
        while(i<cols){
            // (0,i) se start hone wale diagonal par chalo

            // diagonal will be (0,i),(1,i+1),(2,i+2).....

            for(int j=0;j<rows && j+i<cols;j++){
                // jab tak valid mil raha pahuchte chalo and add karte chalo

                // reqd character at (j,i+j) kardo add ans me
                ans+=mat[j][i+j];
            }

            // ab next i se start karo uske diagonal par chalo
            i++;
        }


        // trailing spaces alag kardo
        while(ans.back()==' ') ans.pop_back();

        return ans;
    }
};