#include <bits/stdc++.h>
using namespace std;

class Zsearch{
  public :
    string str,conStr;
    int *Zarr;

  Zsearch(){
    cin >> str;
  }

  Zsearch(string str){
    this->str = str;
  }

  Zsearch(string str, string patt){
    this->str = str;
    search(patt);
  }

  void createZarr(){
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

  void search(string patt){
    conStr = patt + "$" + str;
    Zarr = new int[conStr.size()+1];
    createZarr();
    for(int i=0;i<conStr.size();i++)
      cout << Zarr[i] << " ";
    cout << endl;
    for(int i=0;i<conStr.size();i++){
      if(Zarr[i]==patt.size())
        cout << "Pattern matched at index " << i - patt.size()-1 << endl;;
    }
  }
};

int main(){
  Zsearch s("manishman","man");
  return 0;
}
