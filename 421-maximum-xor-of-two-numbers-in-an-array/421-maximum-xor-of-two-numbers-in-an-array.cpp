class Trie{
    public:
    struct trie{
        vector<trie*>children{vector<trie*>(2,NULL)};
        bool iseow=false;
    }*Root,*curr;
    
    Trie(){
        Root=new trie();
    }
    void insert(int num){
        curr=Root;
        int bit;
        for(int i=31;i>=0;i--)
        {
            bit=(num>>i)&1;
            if(!curr->children[bit])
            {
                curr->children[bit]=new trie();
            }
            curr=curr->children[bit];
        } 
        curr->iseow=true;
    }
    
    int maxnum(int num){
        curr=Root;
        int maxNum=0;
        for(int i=31;i>=0;i--)
        {
            int bit;
            bit=(num>>i)&1;
            if(curr->children[!bit])
            {
                maxNum|=(1<<i);
                curr=curr->children[!bit];
            }
            else
            {
                curr=curr->children[bit];
            }
        }
        return maxNum;
    }
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        
        Trie trie=Trie();
       
        for(int i=0;i<nums.size();i++){
            trie.insert(nums[i]);
        }
        
        int ans=0;
        for(int i=0;i<nums.size();i++){
            ans=max(ans,trie.maxnum(nums[i]));
        }
        return ans;
    }
};