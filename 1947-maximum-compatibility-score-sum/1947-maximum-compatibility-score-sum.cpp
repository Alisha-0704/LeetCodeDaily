class Solution {
private:
    vector<vector<int>>scores;
    int compatScore(vector<int>&student,vector<int>&mentor){
        int ans=0;
        for(int i=0;i<student.size();i++){
            if(student[i]==mentor[i]){
                ans++;
            }
        }
        return ans;
    }
    void backtrack(vector<vector<int>>&students,vector<vector<int>>&mentors,vector<bool>&seen,int &ans,int curr,int sindex){
        if(sindex==students.size()){
            ans=max(ans,curr);
            return;
        } else {
            for(int i=0;i<mentors.size();i++){
                if(!seen[i]){
                    seen[i]=true;
                    backtrack(students,mentors,seen,ans,curr+scores[sindex][i],sindex+1);
                    seen[i]=false;
                }
            }
        }
    }
public:
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        int ans=0;
        int m=students.size();
        scores=vector<vector<int>>(m,vector<int>(m,0));
        for(int i=0;i<students.size();i++){
            for(int j=0;j<students.size();j++){
                scores[i][j]=compatScore(students[i],mentors[j]);
            }
        }
        vector<bool>seen(m,false);
        backtrack(students,mentors,seen,ans,0,0);
        return ans;
    }
};