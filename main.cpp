#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

int anagram(string s)
{
    if(s.length() % 2 == 1)
        return -1;

    string word1 = s.substr(0, s.length() / 2);
    string word2 = s.substr(s.length() / 2, s.length() / 2);

    int retValue = 0;

    for(size_t i = 0; i < word1.length(); i++)
    {
        if (word2.find(word1.substr(i, 1)) != string::npos)
            word2 = word2.replace(word2.find(word1.substr(i, 1)), 1, "");
        else
            retValue++;
    }

    return retValue;
}

int main()
{
    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = anagram(s);

        cout << result << endl;
    }

    return EXIT_SUCCESS;
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
