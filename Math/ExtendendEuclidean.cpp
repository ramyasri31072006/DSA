#include <bits/stdc++.h>
using namespace std;

int x,y,g;
void extendedEculidian(int a,int b){
    if(b == 0){
        x=1;
        y=0;
        g = a;
        return;
    }
    extendedEculidian(b,a%b);
    int cx = y;
    int cy = x - (a/b)*y;
    x = cx;
    y= cy;
    
}
int main() {
	// your code goes here
extendedEculidian(38,12);
cout<<x<<" "<<y;

}
