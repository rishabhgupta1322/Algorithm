#include <bits/stdc++.h>
#define MAX_SIZE 26
using namespace std;

typedef struct triesNode{
  struct triesNode *child[MAX_SIZE];
  bool endOfString;
}triesNode;

class Tries{
  public :
    triesNode *root;

    Tries(){
      root = getnode();
    }

    triesNode* getnode(){
      triesNode *p = new triesNode;
      for(int i=0;i<MAX_SIZE;i++)
        p->child[i]=NULL;
      p->endOfString = false;
      return p;
    }

    void insert(string str){
      triesNode *p = root;
      for(int i=0;i<str.size();i++){
        int index = str[i] % 'a';
        if(!p->child[index])
          p->child[index] = getnode();
        p = p->child[index];
      }
      p->endOfString = true;
    }

    bool search(string str){
      triesNode *p = root;
      for(int i=0;i<str.size();i++){
        int index = str[i] % 'a';
        if(!p->child[index])
          return false;
        p = p->child[index];
      }
      if(p->endOfString)
        return true;
      return false;
    }
};

int main(){
  string arr[]={"prakhar","manish","rishabh","ankit","varun"};
  int size = sizeof(arr)/sizeof(arr[0]);
  Tries root;
  for(int i=0;i<size;i++){
    root.insert(arr[i]);
  }
  cout << (root.search("ankit") ? "YES\n" : "NO\n");
  cout << (root.search("manish") ? "YES\n" : "NO\n");
  cout << (root.search("manu") ? "YES\n" : "NO\n");
  return 0;
}
