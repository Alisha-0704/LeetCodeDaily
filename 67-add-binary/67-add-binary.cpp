class Solution {
public:
	//This function will add 3 numbers (fnum+snum+carry) and returns carry
	//This function won't reach to the -1 case , because we covered all possible sum values 
    int binaryAddition(int a,int b,int carry,string &n){
        int sum=a+b+carry;
        if(sum==3){
            n.push_back('1');
            return 1;
        }
        else if(sum==2){
            n.push_back('0');
            return 1;
        }
        else if(sum==1){
            n.push_back('1');
            return 0;
        }
        else if(sum==0){
             n.push_back('0');
            return 0;
        }    
        return -1;
    }
    
    string addBinary(string a, string b) {
        string ans="";
		//since we will start adding from rightMost side , so we will reverse the strings
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        int carry{},n1{},n2{};
        
        while(n1<a.size() && n2<b.size()){
            carry=binaryAddition(a[n1]-'0',b[n2]-'0',carry,ans);
            n1++;
            n2++;
        }
        
        while(n1<a.size()){
            carry=binaryAddition(a[n1]-'0',0,carry,ans);
            n1++;
        }
        
        while(n2<b.size()){
            carry=binaryAddition(0,b[n2]-'0',carry,ans);
            n2++;
        }
        
        if(carry)
            ans.push_back('1');
        
        reverse(ans.begin(),ans.end());
        
        return ans;
        
    }
};