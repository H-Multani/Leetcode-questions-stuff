class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(),skill.end());

        int l=0,r=skill.size()-1;
        int reqdttl=skill[l]+skill[r];
        long long ans=0;
        while(l<r){
            if(skill[l]+skill[r]!=reqdttl) return -1;

            ans+=(skill[l]*skill[r]);
            l++;r--;
        }

        return ans;

    }
};