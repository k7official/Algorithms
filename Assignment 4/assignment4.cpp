#include<bits/stdc++.h>

using namespace std;



string solve(vector<string>& A) {
        const int n = A.size();
        vector<vector<int> > g(n, vector<int>(n));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++){
                g[i][j] = A[j].length();
                for(int k = 1; k <= min(A[i].length(), A[j].length()); k++){
                    if(A[i].substr(A[i].length()- k) == A[j].substr(0, k)){
                        g[i][j] = A[j].length() - k;
                    }
                }
            }
        
        vector<vector<int> > dp(1<<n, vector<int>(n, INT_MAX/2));
        vector<vector<int> > parent(1<<n, vector<int>(n, -1));
        for(int i = 0; i < n; i++){ dp[1<<i][i] = A[i].length();}        
        
        for(int s = 1; s < (1<<n); s++){
            for(int j = 0; j < n; j++){
                if(!s&(1<<j)) continue;
                //if(!(s&(1<<j))) continue;
                int ps = s & ~(1<<j);
                for(int i = 0; i < n; i++){
                    if(dp[s][j] > dp[ps][i] + g[i][j]){
                        dp[s][j] = dp[ps][i] + g[i][j];
                        parent[s][j] = i;
                    }
                }
            }
        }
        
        string res;
        auto it = min_element(begin(dp.back()), end(dp.back()));
        int j = it - begin(dp.back()); // cur
        int s = (1 << n) - 1;
        while(s){
            int i = parent[s][j]; // pre
            if(i < 0) res = A[j] + res;
            else res = A[j].substr(A[j].length() - g[i][j]) + res;            
            s &= ~(1<<j);
            j = i;
        }
        return res;        
    }

  int main(){

      vector<string> wordDict = {"hello", "low", "owl"};
      vector<string> wordDict2 = {"hello", "owl", "low"};
      vector<string> wordDict3 = {"low", "hello", "owl"};
      vector<string> wordDict4 = {"low", "owl", "hello"};
      vector<string> wordDict5 = {"owl", "hello", "low"};
      vector<string> wordDict6 = {"owl", "low", "hello"};
      
      cout << solve(wordDict) << endl;
      cout << solve(wordDict2) << endl;
      cout << solve(wordDict3) << endl;
      cout << solve(wordDict4) << endl;
      cout << solve(wordDict5) << endl;
      cout << solve(wordDict6) << endl;
      return 0;
}
