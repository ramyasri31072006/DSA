#include<iostream>
using namespace std;
void dnf(string & s){
    int n = s.size();
    int low =0;
    int high =n-1;
    int mid =0;
    while(mid<=high){
        if(s[mid]=='0'){
            swap(s[low],s[mid]);
            low++;
            mid++;
        }
        else if(s[mid]=='1'){
            mid++;
        }
        else{
            swap(s[high],s[mid]);
            high--;
        }
    }
   
}
 int main(){
        string s;
        cin>>s;
        dnf(s);
        cout<<s<<"\n";
    }