#include <iostream>

using namespace std;

void swap(char *a , char  *b){
    char temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void perm(char s[] , int l , int h){
    if (l == h){
        cout<<s<<endl;
    }
    else{
        for (int i=l ; i<=h ; i++){
            swap(s[l] , s[i]);
            perm(s ,l+1 , h);
            swap(s[l] , s[i]);
        }
    }
}

int main() {
    char s[] = "abc";
    perm(s , 0 , 2);
    return 0;
}


