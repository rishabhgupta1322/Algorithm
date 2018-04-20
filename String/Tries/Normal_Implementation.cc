#include <bits/stdc++.h>
#define MAX_SIZE 26
using namespace std;

typedef struct triesNode{
  struct triesNode *child[MAX_SIZE];
  bool endOfString;
}tries;

tries* getnode(){
  tries *p = new tries;
  for(int i=0;i<MAX_SIZE;i++)
    p->child[i]=NULL;
  p->endOfString = false;
  return p;
}

void insert(tries *root, string str){
  tries *p = root;
  for(int i=0;i<str.size();i++){
    int index = str[i] % 'a';
    if(!p->child[index])
      p->child[index] = getnode();
    p = p->child[index];
  }
  p->endOfString = true;
}

bool search(tries *root, string str){
  tries *p = root;
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

int main(){
  string arr[]={"prakhar","manish","rishabh","ankit","varun"};
  int size = sizeof(arr)/sizeof(arr[0]);
  tries *root=getnode();
  for(int i=0;i<size;i++){
    insert(root,arr[i]);
  }
  cout << (search(root,"ankit") ? "YES\n" : "NO\n");
  cout << (search(root,"manish") ? "YES\n" : "NO\n");
  cout << (search(root,"manu") ? "YES\n" : "NO\n");
  return 0;
}
