#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximumGain(string s, int x, int y) {
        if(x<y){
            for(auto& c:s){
                if(c=='a') c='b';
                else if(c=='b') c='a';
            }
            swap(x,y);
        }
        stack<char> st;
        int ans=0;
        string re="";
        for(auto& c:s){
            if(!st.empty()&& st.top()=='a' && c=='b'){
                ans+=x;
                st.pop();
            }
            else st.push(c);
        }
        while(!st.empty()){
            re+=st.top();
            st.pop();
        }
         reverse(re.begin(), re.end());
         for(auto& c:re){
            if(!st.empty()&& st.top()=='b' && c=='a'){
                ans+=y;
                st.pop();
            }
            else st.push(c);
        }
return ans;
    }
};