#include "kmp.h"

vector<int> prefix_func(const string& s)
{
    int n = s.length();
    vector<int> pref_f(n, 0);
    for (int i = 1; i < n; i++)
    {
        int j = pref_f[i - 1];
        while (j > 0 && s[i] != s[j]) 
        {
            j = pref_f[j - 1];
        }
        if (s[i] == s[j])
        {
            j++;
        }
        pref_f[i] = j;
    }
    return pref_f;
}

std::vector<int> getIndices(const std::string& my_template, const std::string& text)
{
    vector<int> result;
    string s = my_template + '#' + text;
    vector<int> pref_f = prefix_func(s);
    int temp_len = my_template.length();
    for (int i = template_length + 1; i < s.length(); ++i) 
    {
        if (pref_f[i] == temp_len)
        {
            result.push_back(i - 2 * temp_len);
        }
    }
    return result;
}