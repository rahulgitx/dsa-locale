int i=0, j=s.length()-1;
    string temp;
    while( i<=j){
        if(s[i] == s[j]){
            if(ispalindrome(s.substr(i,j))){
                temp = (s.substr(i,j));
                break;
            }
            else{
                i++; j--;
            }
        }
        else if((j-i) == 1){
            temp = (s.substr(i,j));
            break;
        }
        else{
            i++; j--;
        }
    }
    return temp;
}