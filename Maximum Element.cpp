#include <bits/stdc++.h>
#include <stack>
#include <cstring> 
using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'getMax' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts STRING_ARRAY operations as parameter.
 */

vector<int> getMax(vector<string> operations) {
stack <int> ss;

int s=operations.size();
vector<int>max;
vector<int>stk;
int m=0;
for(int i=0;i<s;i++)
{
  if(operations[i][0]=='1')
  {
      string t="";
      int s=operations[i].size();
      for(long j=2;j<s;j++)
        t+=operations[i][j];
      
      ss.push(stoi(t));
      stk.push_back(stoi(t));
      
  }
  else  if(operations[i][0]=='2')
  {
      ss.pop();
      stk.pop_back();
  }
  else 
  {int size=stk.size();
      if(size>0)
        m=stk[0];
      for(int i=1;i<stk.size();i++)
      {
          if(stk[i]>m)
          m=stk[i];
      }
      max.push_back(m);
      m=0;
  }
}
return max;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<string> ops(n);

    for (int i = 0; i < n; i++) {
        string ops_item;
        getline(cin, ops_item);

        ops[i] = ops_item;
    }

    vector<int> res = getMax(ops);

    for (size_t i = 0; i < res.size(); i++) {
        fout << res[i];

        if (i != res.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

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
