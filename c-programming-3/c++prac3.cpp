#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    int kind;
    bool stop = false;
    
    // switch practice
    while (stop == false){
        cout << "choose a fruit! (1, 2, 3, 4)" << endl;
        cin >> kind;
        switch (kind){
            case 1:
            cout << "You choose apple!!" << endl;
            break;
            
            case 2:
            cout << "You choose banana!!" << endl;
            break;
            
            case 3:
            cout << "You choose orange!!" << endl;
            break;
            
            case 4:
            cout << "You choose berry!!" << endl;
            break;        
            
            default:
            cout << "Bad luck!!" << endl;
            stop = true;
        }
    }
    return 0;
}
