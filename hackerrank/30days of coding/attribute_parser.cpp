#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

// class html{
//     public:
//         string tag;
//         int n;
//         int pairs[n];
        
//             html(string t, int p)
//             {
//                 tag=t;
//                 n=p;
//             }  
// };

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n, q;
    scanf("%d %d", &n, &q);
    string arr[n];
    string query[q];
    cin.ignore();
    for (int i=0; i<n; i++)
    {
        // cin.ignore();
        getline(cin, arr[i]);
    }
    // cout << arr[0];
    // for (int i=0; i<n; i++)
    // {
    //     cout << arr[i] << endl;
    // }
    
    for (int i=0; i<q; i++)
    {
        getline(cin, query[i]);
    }
    // for (int i=0; i<q; i++)
    // {
    //     cout << query[i] << endl;
    // }
    
    // char c;
    for (int i=0; i<q; i++)
    {

        // for (int j=0; query[i][j]!='\0'; j++ )
        // {
            // char temp;
            cout << endl<< endl;
            stringstream stilda(query[i]);
            string tildaslices[2];
            string tildaslice;
            for (int i=0; i<2; i++)
            {
                getline(stilda, tildaslice, '~');
                // cout << "tilda slices : " << tildaslice << endl;
                tildaslices[i]=tildaslice;
                
            }
            // cout << tildaslices[0] << " " << tildaslices[1] << endl;
            int posofdot = tildaslices[0].find(".");
            string tagstr;
            if (!(0<=posofdot && sizeof(tildaslices[0])))
            {
                cout << " dot not present" << endl;
                tagstr=tildaslices[0];
                cout << "tagstr to look in : " << tagstr << endl;
            }
            else
            {
                cout << "dot present" <<endl;
                stringstream sdot(tildaslices[0]);
                string dotslices;
                vector<string> v1;
                while(getline(sdot, dotslices, '.'))
                {
                    // cout << "dotsclices: " << dotslices << endl;
                    v1.push_back(dotslices);
                }
                cout << "tagstr to look in " << v1[v1.size()-1] <<  endl;
                tagstr=v1[v1.size()-1];
                // vector<string>::iterator iter = v1.end();
                // cout << "last of vector's : " << *iter << endl;
            }
            string attrstr = tildaslices[1];
            cout << "attrsts to look for: " << attrstr << endl;
           
            // int pos = query[i].find("~");
            
            // // cout << attrstr << " ";
            // string tagstr = query[i].substr(pos-4,4);
            // // cout << "tag: " << tagstr << endl;
            for (int j=0; j<n; j++)
            {
                stringstream scodelines(arr[j]);
                string codetag;
                vector<string> vcode;
                while((getline(scodelines, codetag, ' ')))
                {
                    vcode.push_back(codetag);
                }
                string codetagstr;
                if (vcode[0][1]!='/')
                {
                    codetagstr = vcode[0].substr(1);
                    cout << "codetag: " << codetagstr << endl;
                    
                    if (codetagstr==tagstr)
                    {
                        cout << "query and hrml match found!" << endl;
                        vector<string> attributenameofmatch;
                        vector<string> attributeofmatch;
                        int noattr=0;
                        for (int i=0; i<vcode.size(); i++)
                        {
                            if ("="==vcode[i])
                            {
                                noattr+=1;
                                stringstream sc(vcode[i-1]);
                                string word;
                                int p=0;
                                while(getline(sc, word, '"'))
                                {
                                    if (p==0)
                                    {
                                        // cout << "word: " << word <<endl;
                                        attributenameofmatch.push_back(word);
                                    }
                                    p+=1;
                                }
                                stringstream sc2(vcode[i+1]);
                                string word2;
                                int p2=0;
                                while(getline(sc2, word2, '"'))
                                {
                                    if (p2==1)
                                    {
                                        // cout << "word2 " << word2 << endl;
                                        attributeofmatch.push_back(word2);
                                    }
                                    p2+=1;
                                }
                                
                                
                                cout << "key: " << attributenameofmatch[noattr-1] << " value: " << attributeofmatch[noattr-1] << endl;
                            }
                        }
                        if (noattr>0)
                        {
                            cout<<"= found, no of attributes :  " << noattr << endl;
                            for (int i=0; i<attributenameofmatch.size(); i++)
                            {
                                cout << "attributenameofmatch[i]" << attributenameofmatch[i] << ", attrstr: " << attrstr <<endl;
                                if (attributenameofmatch[i]==attrstr)
                                {
                                    cout << " match found for attributes! at " << attributenameofmatch[i] <<" which is : " << attributeofmatch[i]<< endl;
                                    break;
                                }
                                else
                                {
                                    cout << "Not Found!" << endl;
                                }
                            }
                        }
                        else 
                        {
                            cout << "tag has no attribute: ";
                        }
                
                        
                        
                        cout << "************done with hrml line************\n";
                        break;
                    }
                } 
            }
            
           
        // }
    cout<<"\n*********done with query***********\n\n\n\n";
    }
    
    
    
    

    return 0;
}
