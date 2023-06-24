#include <bits/stdc++.h>

struct Node {
  Node * links[26];
  int cw = 0;
  int cp = 0;
};

class Trie {
  Node * root;
  public:

    Trie() {
      root = new Node();
    }
  bool insert(string & word) {
    Node * node = root;
    bool t = true;
    for (int i = 0; i < word.size(); i++) {
      int c = word[i] - 'a';
      if (!node -> links[c]) {
        node -> links[c] = new Node();
      }
      node = node -> links[c];
      if (i < (word.size() - 1) && node -> cw == 0)
        t = false;
      node -> cp++;
    }
    node -> cw++;
    return t;
  }
};
string completeString(int n, vector < string > & a) {
  Trie * obj = new Trie();
  pair < string, int > p = {
    "None",
    0
  };
  sort(a.begin(), a.end());
  for (auto i: a) {
    if (obj -> insert(i)) { //cout<<i<<" ";           
      if (p.second < i.size() || (p.second == i.size() && p.first > i)) {
        p.first = i;
        p.second = i.size();
      }
    }
  }
  return p.first;
}