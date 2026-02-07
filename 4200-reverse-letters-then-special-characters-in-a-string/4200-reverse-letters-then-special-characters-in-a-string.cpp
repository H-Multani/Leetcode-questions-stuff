class Solution {
public:
    string reverseByType(string s) {
        // normal characters ke index nikal kar rakh lo
        int n=s.size();

        // store idx of normal chars
        vector<int> idx;
        // store idx of special chars
        vector<int> idx2;

        for(int i=0;i<n;i++){
            if(s[i]>='a' && s[i]<='z'){
                // lowercase store karlo
                idx.push_back(i);
            }else{
                idx2.push_back(i);
            }
        }

        // ab iterate over idx array and swap karte chalo
        int m=idx.size();
        for(int i=0;i<m/2;i++){
            swap(s[idx[i]],s[idx[m-i-1]]);
        }
        // ab iterate over idx array and swap karte chalo
        m=idx2.size();
        for(int i=0;i<m/2;i++){
            swap(s[idx2[i]],s[idx2[m-i-1]]);
        }

        return s;
    }
};