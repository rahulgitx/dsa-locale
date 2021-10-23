#include <bits/stdc++.h>
using namespace std;

typedef pair<int, char> pi;

void heapify(){

}

int findanagram(string a, string b){
    int count = 0;

    unordered_map<char, int> mym;
    for(int i=0; i<b.length(); i++){
        if(mym.count(b[i])>0){
            mym[b[i]]++;
        }
        else{
            mym[b[i]] = 1;
        }
    }
    unordered_map<char, int>::iterator it;
    for(it=mym.begin(); it!=mym.end(); it++){
        cout << it->first << ":" << it->second << " ";
    }
    cout << endl << endl;

    
    for(int i=0; i<(a.length()-b.length())+1; i++){
        unordered_map<char, int> tmym;
        int flag = 1;
        for(int j=i; j<i+b.length(); j++){
            if( !(mym.count(a[j])>0) ){
                flag = 0;
                break;
            }
            else{
               
                if(tmym.count(a[j])>0){
                    tmym[a[j]]++;
                }
                else{
                    tmym[a[j]] = 1;
                }
                // cout << "inserted: " << a[j] << " : " << tmym[a[j]] << "  ";
            }
        }
        // cout << "flag: " << flag << endl;
        

        if(tmym.size() != mym.size()){
                // cout << "size not matched!            " << endl;
                flag = 0; 
            }
        else{
            cout << "size matched !           ";
            flag = 1;
        }
        if(flag == 1){  
            it = mym.begin();
            for(it = mym.begin(); it != mym.end(); it++){
                // cout << "mym[it->first]: " << mym[it->first] << " tmym[it-first]: " << tmym[it->first] << " " ;
                if(mym[it->first] == tmym[it->first]){
                    flag = 1;
                }
                else{
                    flag = 0;
                }
            }  
            cout << endl;         
        }
        if(flag == 1){
            count++;
            // cout << "  --->count increased!" << endl;
        }
        

    }
    return count;
}

int main(){
    string s1 ;
    string s2 ;
    getline(cin, s1);
    getline(cin, s2);

    int output = findanagram(s1, s2);
    cout << output ;
}