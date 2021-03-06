class Solution {
public:
    bool isAdditiveNumber(string num) {
        if(num.length()<3) return false;
        vector<double> arr{};
        return checkNum(num,0,-1,-1,0,arr);
    }
    
        bool checkNum(string num, int start, double first, double second, int count, vector<double>& arr) {
        if(start==num.length()) {
            if(arr.size()>=3) {
                for(int i=0;i<arr.size()-2;i++) {
                    if(arr[i]+arr[i+1]!=arr[i+2]) {
                        return false;
                    }
                }
                return true;
            } else{
                return false;
            }
        }
            
            else if(start<num.length()) {
            for(int i=start;i<num.length();i++) {
                string generatedString = num.substr(start,(i-start+1));
                if(generatedString.length()>1 && generatedString[0]=='0') break;
                double temp = stod(generatedString);
                if((count<2) || first+second==temp) {
                    arr.push_back(temp);
                    if(checkNum(num,i+1,second,temp,count+1,arr)) return true;
                    arr.pop_back();
                }
            }
        }
        return false;
    }
};
