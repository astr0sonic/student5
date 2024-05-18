#include <iostream>
#include <string>
#include <map>
#include <queue>

using namespace std;

struct node
{
    char info;
    int freq;
    node* left;
    node* right;
    node(char ch, int frequ, node* l = nullptr, node* r = nullptr) : info(ch), freq(frequ), left(l), right(r) {}
};

struct comp
{
    bool operator()(const node* l, const node* r) const
    {
        return l->freq > r->freq;
    }
};

void generate_code(node* root, string str, map<char, string>& huffman_code);
std::string encode(const std::string& text);
std::string decode(const std::string& encoded, std::map<char, std::string>& codes);