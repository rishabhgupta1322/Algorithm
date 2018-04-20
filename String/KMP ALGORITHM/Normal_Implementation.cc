#include <bits/stdc++.h>
using namespace std;

void PrefixTable(string patt, int arr[]){
    int j=0;
    arr[0]=0;
    for(int i=1;i<patt.size();){
        if(patt[i]==patt[j])
            arr[i++] = ++j;
        else if(j>0)
            j = arr[j-1];
        else
            arr[i++] = 0;
    }
}

bool KMP(string str,string patt){
    int j=0;
    int arr[patt.size()];
    PrefixTable(patt,arr);
    for(int i=0;i<str.size();){
        if(str[i]==patt[j]){
            if(j==patt.size()-1)
                return true;
            else
                i++,  j++;
        }else if(j>0)
            j=arr[j-1];
        else i++;
    }
    return false;
}

int main(){
    string str,patt;
    cin >> str >> patt;
    if(KMP(str,patt))
        cout << "Matched" << endl;
    else
        cout << "Not Matched" << endl;
    return 0;
}
