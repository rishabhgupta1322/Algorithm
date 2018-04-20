#include <bits/stdc++.h>
using namespace std;

class KMP{
    public :
        string str;
        int size;
        int *arr = NULL;

    KMP(){
        cin >> str;
    }

    KMP(string str){
        this->str=str;
    }

    void PrefixTable(string patt){
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

    bool kmpSearch(string patt){
        int j=0;
        size=patt.size();
        arr = new int[size];
        PrefixTable(patt);
        for(int i=0;i<str.size();){
            if(str[i]==patt[j]){
                if(j==size-1)
                    return true;
                else
                    i++,  j++;
            }else if(j>0)
                j=arr[j-1];
            else i++;
        }
        return false;
    }

    void search(string patt){
        if(kmpSearch(patt))
            cout << "Matched" << endl;
        else
            cout << "Not Matched" << endl;
    }
};

int main(){
    KMP obj;
    string patt;
    cin >> patt;
    obj.search(patt);
    return 0;
}
