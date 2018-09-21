#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    int T;
    cin >> T;
    
    while(T--) {
        int n;
        cin >> n;
    
        int prime = 1;
        if (n == 2)
            prime = 1;
        else if (n == 1)
            prime = 0;
        else if (n % 2 == 0)
            prime = 0;
        else {
            for (int i=3; i <= sqrt(n); i+= 2) {
                if (n % i == 0)
                    prime = 0;
            }
        }
    
        if (prime)
            cout << "Prime" << endl;
        else
            cout << "Not prime" << endl;
    }
    
    return 0;
}
