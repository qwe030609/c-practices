#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// pyramid
int main()
{
    // size of the pyramid
    int N = 10;
    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= N-i; j++){
            cout << " ";
        }
        
        for (int j = 1; j <= 2*i-1; j++){
            cout << "*";
        }
        
        cout << endl;
    }
    return 0;
}

