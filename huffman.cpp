#include "huffman.h"
struct comp
{
    bool operator()(const node* l, const node* r) const
    {
        return l->freq > r->freq;
    }
};

void generate_code(node* root, string str, map<char, string>& huffman_code)
{
    if (root == NULL)
    {
        return;
    }
    if (root->left == NULL && root->right == NULL)
    {
        if (!str.empty())
        {
            huffman_code[root->info] = str;
        }
        else
        {
            huffman_code[root->info] = "1";
        }
    }
    generate_code(root->left, str + "0", huffman_code);
    generate_code(root->right, str + "1", huffman_code);
}

std::string encode(const std::string& text) {
    string encoded = "";
    priority_queue<node*, vector<node*>, comp> pq;
    map<char, int> mapa;
    for (char c : text)
    {
        mapa[c] += 1;
    }
    for (auto i : mapa)
    {
        pq.push(new node{ i.first, i.second, NULL, NULL });
    }
    while (pq.size() != 1)
    {
        node* left = pq.top();
        pq.pop();
        node* right = pq.top();
        pq.pop();
        pq.push(new node{ '\0', left->freq + right->freq, left, right });
    }
    node* root = pq.top();
    map<char, string> huffman_code;
    generate_code(root, encoded, huffman_code);
    for (char ch : text)
    {
        encoded += huffman_code[ch];
    }
    return encoded;
}

std::string decode(const std::string& encoded, std::map<char, std::string>& codes) {
    string decoded = "";
    map<string, char> new_codes;
    for (auto i : codes)
    {
        new_codes[i.second] = i.first;
    }
    string t = "";
    for (char ch : encoded)
    {
        t += ch;
        if (new_codes.find(t) != new_codes.end())
        {
            decoded += new_codes[t];
            t.clear();
        }
    }
    return decoded;
}