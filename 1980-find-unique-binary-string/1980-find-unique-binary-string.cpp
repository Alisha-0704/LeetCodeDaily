class Solution {
public:
    string helper(map<string,int>s,int l,string p){
        if(l==p.length())
        {   if(s[p]==0)
                return p;
            else
                return "";
        }
            
        string st;
        
        // include 1
        p.push_back('1');
        st = helper(s,l,p);// means required string is found so no need for further calls
        if(st != "") return st;
        p.pop_back(); // backtrack
         
        // include 0
        p.push_back('0');
        st = helper(s,l,p);
        if(st != "") return st; // means required string is found so no need for 
        p.pop_back(); // backtrack
        
        return "";
       
    }
    string findDifferentBinaryString(vector<string>& nums) {
        map<string,int>s;
        for(int i=0;i<nums.size();i++)
            s[nums[i]]++;
        int l=nums[0].length();
        string p;
        return helper(s,l,p);
    }
};