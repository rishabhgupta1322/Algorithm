#include <bits/stdc++.h>
using namespace std;

void createZarr(string conStr, int Zarr[]){
  Zarr[0]=0;
  int L=0,R=0,K=0;
  for(int i=1; i<conStr.size() ;i++){
    if(i>R){
      L = R = i;
      while(R<conStr.size() && conStr[R-L]==conStr[R])
        R++;
      Zarr[i] = R - L;
      R--;
    }else{
      K = i-L;
      if(Zarr[K] < R-i+1)
        Zarr[i] = Zarr[K];
      else{
        L=i;
        while(R<conStr.size() && conStr[R-L]==conStr[R])
          R++;
        Zarr[i]=R-L;
        R--;
      }
    }
  }
}

void Zsearch(string str, string patt){
  string conStr = patt + "$" + str;
  int Zarr[conStr.size()+1];
  createZarr(conStr, Zarr);
  for(int i=0;i<conStr.size();i++){
    if(Zarr[i]==patt.size())
      cout << "Pattern matched at index " << i - patt.size()-1 << endl;;
  }
}

int main(){
  string str,patt;
  cin >> str >> patt;
  Zsearch(str,patt);
  return 0;
}
