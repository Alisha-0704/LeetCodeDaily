class Solution {
public:
    string capitalizeTitle(string title) {
        
        if(title=="")
            return "";
        string value="";
        string result="";
        for(int i=0;i<title.length();i++){ 
            if(title[i]!=' ' )
                value+=title[i];
            if(title[i]==' ' ||  i==title.length()-1){
                if(value.length()<=2)
                {
                  for(int j=0;j<value.length();j++){
                    value[j]=tolower(value[j]);
                }
                }
                else
                    {
                    value[0]=toupper(value[0]);
                    for(int j=1;j<value.length();j++){
                    value[j]=tolower(value[j]);
                }
                }
                if(title[i]==' ')
                result+=value+' ';
                else
                if(i==title.length()-1)
                result+=value;
                
                value="";
            }
        }
        return result;
    }
};
//I waNt to go TO MOviE toDAY
