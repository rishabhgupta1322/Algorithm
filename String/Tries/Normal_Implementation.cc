#include <bits/stdc++.h>
#define MAX_SIZE 26
using namespace std;

//Creating Structure for Trie for words
//Used in Dictionary implementation
typedef struct triesNode{
  //Creating possible childs of max_size
  struct triesNode *child[MAX_SIZE];
  //Indicate existing of word
  bool endOfString;
}tries;

//Function to create new node
//Setting default of values
tries* getnode(){
  tries *p = new tries;
  for(int i=0;i<MAX_SIZE;i++)
    p->child[i]=NULL;
  p->endOfString = false;
  return p;
}

//Function to insert values in Trie
void insert(tries *root, string str){
  tries *p = root;
  for(int i=0;i<str.size();i++){
    //Finding index of character in given trie
    int index = str[i] % 'a';
    //Checking if there is node in given index or not
    if(!p->child[index])
      p->child[index] = getnode();
    //Setting parent node to child
    p = p->child[index];
  }
  //Indicating word is stored
  //Completion of word entry
  p->endOfString = true;
}

//Function to Search Values in Trie
bool search(tries *root, string str){
  tries *p = root;
  for(int i=0;i<str.size();i++){
    //Finding index of character in given trie
    int index = str[i] % 'a';
    //Checking if there is node in given index or not
    if(!p->child[index])
      return false;
    //Setting parent node to child
    p = p->child[index];
  }
  //Checking word found or not
  if(p->endOfString)
    return true;
  return false;
}

//Driver Function
int main(){
  //Array of strings
  string arr[]={"prakhar","manish","rishabh","ankit","varun"};
  int size = sizeof(arr)/sizeof(arr[0]);
  //Creating Root node
  tries *root=getnode();
  //Inserting value in Trie
  for(int i=0;i<size;i++){
    insert(root,arr[i]);
  }
  //Searching Values in Trie
  cout << (search(root,"ankit") ? "YES\n" : "NO\n");
  cout << (search(root,"manish") ? "YES\n" : "NO\n");
  cout << (search(root,"manu") ? "YES\n" : "NO\n");
  return 0;
}
