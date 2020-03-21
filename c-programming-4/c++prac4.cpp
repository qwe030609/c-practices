#include <iostream>
#include <string>
#include <cmath>
#include <stack>

using namespace std;

int main()
{
    // int n = 4;
    // string fruits[n] = {"Apple","Banana","Mango","Pear"};
    // int Nums[n];
    // for (int i = 0; i < n; i++){
    //     Nums[i] = 2*(i+1);
    // }
    // cout << fruits[0] << endl;
    // for (int i = 0; i < n; i++)
    //     cout << Nums[i] << endl;
    
    // random numbers on every program run  
    // Use current time as seed for random generator
    srand(time(0));
    
    // size of the maze N
    int N = 10;    
    int maze[N][N];
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            maze[i][j] = rand() % 2;
            if (i == 0 && j == 0)
                maze[i][j] = 2;     // 2 is the Entry
            if (i == N-1 && j == N-1)
                maze[i][j] = 3;     // 3 is the Exit
        }
    }    
    
    // print the maze with 0 (can go), 1(wall), 2(Entry), 3(Exit)
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cout << maze[i][j] << " ";
        }
        cout << endl;
    }     
    
    // transform decimal to binary number using stack
    stack<int> stack1;      // must include stack header
    int n;
    cin >> n;
    
    while (n > 0)          // n > 0 
    {
        stack1.push(n % 2);
        n = floor(n/2);
        cout << n << " "; 
    }
    
    // total digits of binary
    cout << "binary digits: " << stack1.size() << endl;
    
    while (stack1.size() > 0)          // n > 0 
    {
        cout << stack1.top();
        stack1.pop();
        n--;
    }    
    
    return 0;
}

