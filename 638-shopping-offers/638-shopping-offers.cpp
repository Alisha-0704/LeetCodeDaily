class Solution {
public:
    map< pair<vector<int>,int>,int>mp;
    int shopping(vector<int>& price, vector<vector<int>>& special, vector<int>& needs,int j){
         if(mp[{needs,j}]!=0)
        {
            return mp[{needs,j}];
        }
        int res=0;
       for(int i=0;i<needs.size();i++)
       {
           res+=needs[i]*price[i];   
       }
        for(int k=0;k<special.size();k++)
        {
             int flag=0;
            
            
              if(mp[{needs,k}]!=0)
        {
            res=min(res,mp[{needs,k}]);
        }  
            
          else {vector<int>&x=special[k];
                vector<int>v;
            for(int i=0;i<x.size()-1;i++)
            {
                if(x[i]>needs[i])
                {
                    flag=1;
                    break;
                }
                else
                {
                    v.push_back(needs[i]-x[i]);
                }
            }
                 if(flag==0)
            {
               res=min(shopping(price,special,v,k)+x[x.size()-1],res);
            }
                
               }
        }
        
        
        return mp[{needs,j}]=res;
                
    }
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        return shopping(price,special,needs,0);
    }
};