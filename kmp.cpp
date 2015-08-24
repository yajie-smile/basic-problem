#include <iostream>
#include <string>
using namespace std;

void getNext(string& substr, int* next) {
    int n = substr.length();
    int p = -1;
    next[0] = -1;
    for(int i = 1; i < n; i++) {
        while(p >= 0 && substr[p + 1] != substr[i])
            p = next[p];
        if(substr[p + 1] == substr[i])
            p++;
        next[i] = p;
    }
}

void kmp(string& str, string& substr) {
    if(str.length() < 1) return;
    
    int n1 = str.length(), n2 = substr.length();
    
    int* next = new int(n2);
    getNext(substr, next);
    for(int i = 0; i < n2; i++)
        cout<<next[i]<<" ";
    cout<<endl;
    
    int p = -1, count = 0;
    for(int i = 0; i < n1; i++) {
        while(p >= 0 && substr[p + 1] != str[i])
            p = next[p];
        if(substr[p + 1] == str[i])
            p++;
        if(p == n2 - 1) {
            count++;
            p = next[p];
        }
    }
    cout<<count<<endl;
}

int main() {
    string substr = "BABABB";
    string str = "ADDAADAADDAAADAAD";
    kmp(str, substr);
}