// Question link
// https://www.hackerrank.com/challenges/abbr/problem

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'abbreviation' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. STRING a
 *  2. STRING b
 */

bool isLower(string a){
    for(int i=0;i<a.length();i++) if(toupper(a[i])==a[i]) return false;
    return true;
}

int tabulation(string a, string b){
    int n = a.length(), m = b.length();
    int dp[n+1][m+1];
    for(int i=0;i<n+1;i++){
        for(int j=0;j<m+1;j++){
            if(j==0){
                if(isLower(a.substr(0,i))) dp[i][j] = 1;
                else dp[i][j] = 0;
            }
            else if(i==0) dp[i][j] = 0;
            else if(a[i-1]==b[j-1]) dp[i][j] = dp[i-1][j-1];
            else if(toupper(a[i-1])==b[j-1]) dp[i][j] = dp[i-1][j-1] or dp[i-1][j];
            else if(toupper(a[i-1])==a[i-1]) dp[i][j] = 0;
            else dp[i][j] = dp[i-1][j];
        }
    }
    for(int i=0;i<n+1;i++){
        for(int j=0;j<m+1;j++) cout<<dp[i][j]<<"\t";
        cout<<endl;
    }
    
    return dp[n][m];
}

string abbreviation(string a, string b) {
    int bit = tabulation(a,b);
    if(bit==1) return "YES";
    return "NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string a;
        getline(cin, a);

        string b;
        getline(cin, b);

        string result = abbreviation(a, b);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
