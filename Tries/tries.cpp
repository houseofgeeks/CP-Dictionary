#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Trie{
    public:
    bool isEnd;
    Trie* children[26];

    Trie(){
        isEnd = false;
        for(int i = 0; i < 25; ++i){
            children[i] = NULL;
        }
    }

    void insert(string word){
        Trie* root = this;
        for(int i = 0, len = word.length() ; i < len; ++i){
            if(root->children[word[i]-'a']==NULL){
                root->children[word[i]-'a'] = new Trie();
            }
            root = root->children[word[i]-'a'];
        }
        root->isEnd = true;
    }

    bool search(string word){
        Trie* root = this;
        for(int  i = 0, len = word.length(); i < len; ++i){
            if(root->children[word[i]-'a']==NULL){
                return false;
            }
            root = root->children[word[i]-'a'];
        }
        return root!=NULL && root->isEnd;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll numberStrings;
    cin >> numberStrings;
    string s;
    Trie root;
    for(ll i = 0; i < numberStrings; ++i){
        cin >> s;
        root.insert(s);
    }
    string toFindString;
    cin >> toFindString;
    cout << root.search(toFindString) << endl;
    return 0;
}