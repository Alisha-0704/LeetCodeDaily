class Solution {
public:
        vector<string> ans;
    void permute(string &s,vector<bool> &vis,string cur){
        if(cur.size()==s.size())
        {
            ans.push_back(cur);
            return;
        }
        for(int i=0;i<s.size();i++){
            if(vis[i]==false){
                vis[i]=true;
                permute(s,vis,cur+s[i]);
                vis[i]=false;
            }
        }
    }
    int nextBeautifulNumber(int n) {
        vector<string> nums{"1","22","122","333","1333","4444","14444","22333","55555","122333","155555","224444","666666","1224444"};
    for(int i=0;i<nums.size();i++){
          int n=nums[i].size();
          vector<bool> vis(n);
          for(int j=0;j<n;j++){
             vis[j]=false;
          }
          permute(nums[i],vis,"");
      }
        set<int> a;
      for(string x:ans)
      {
          if(x!=""){
              int y=stoi(x);
              a.insert(y);
          }
      }
      auto it=upper_bound(a.begin(),a.end(),n);
      int res=*it;
      return res;
    }
};