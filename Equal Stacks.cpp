#include <bits/stdc++.h>
#include <stack>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'equalStacks' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY h1
 *  2. INTEGER_ARRAY h2
 *  3. INTEGER_ARRAY h3
 */

int equalStacks(vector<int> h1, vector<int> h2, vector<int> h3) {
int s1=0,s2=0,s3=0;
if(h1.size()==0||h2.size()==0||h3.size()==0)
    return 0;
stack <int>stk1;
stack <int>stk2;
stack<int>stk3;

for(int i=h1.size()-1;i>=0;i--)
{
    s1+=h1[i];
    stk1.push(h1[i]);
 
}
for(int i=h2.size()-1;i>=0;i--)
{
    s2+=h2[i];
    stk2.push(h2[i]);
   
}
for(int i=h3.size()-1;i>=0;i--)
{
    s3+=h3[i];
    stk3.push(h3[i]);
    
}

int size1=stk1.size();
int size2=stk2.size();
int size3=stk3.size();
while(size1>0&&size2>0&&size3>0)
{
    
    if(s1==s2 && s2==s3)
        return s1;
    if(s1>=s2 && s1>s3)
    {
        s1-=stk1.top();
        stk1.pop();
        size1--;
    }
    else if(s1<s2 && s2>s3)
    {
        s2-=stk2.top();
       stk2.pop();
       size2--;
    }
    else
      {
          s3-=stk3.top();
       stk3.pop();
       size3--;
      }
}
return 0;
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n1 = stoi(first_multiple_input[0]);

    int n2 = stoi(first_multiple_input[1]);

    int n3 = stoi(first_multiple_input[2]);

    string h1_temp_temp;
    getline(cin, h1_temp_temp);

    vector<string> h1_temp = split(rtrim(h1_temp_temp));

    vector<int> h1(n1);

    for (int i = 0; i < n1; i++) {
        int h1_item = stoi(h1_temp[i]);

        h1[i] = h1_item;
    }

    string h2_temp_temp;
    getline(cin, h2_temp_temp);

    vector<string> h2_temp = split(rtrim(h2_temp_temp));

    vector<int> h2(n2);

    for (int i = 0; i < n2; i++) {
        int h2_item = stoi(h2_temp[i]);

        h2[i] = h2_item;
    }

    string h3_temp_temp;
    getline(cin, h3_temp_temp);

    vector<string> h3_temp = split(rtrim(h3_temp_temp));

    vector<int> h3(n3);

    for (int i = 0; i < n3; i++) {
        int h3_item = stoi(h3_temp[i]);

        h3[i] = h3_item;
    }

    int result = equalStacks(h1, h2, h3);

    fout << result << "\n";

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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
