#include <iostream>
#include <cmath>
#include <stack>
#include <string>

// define directions the mouse can move
#define EAST maze[x][y+1]
#define WEST maze[x][y-1]
#define SOUTH maze[x+1][y]
#define NORTH maze[x-1][y]
#define NORTHEAST maze[x-1][y+1]
#define NORTHWEST maze[x-1][y-1]
#define SOUTHEAST maze[x+1][y+1]
#define SOUTHWEST maze[x+1][y-1]

// entry location
#define ENTRY_X 1
#define ENTRY_Y 1

// maze size
#define MAZE_SIZE 12

// exit location
#define EXIT_X MAZE_SIZE-2
#define EXIT_Y MAZE_SIZE-2

// location of mouse
int x, y;

using namespace std;

int main() {

  // random numbers on every program run  
  // Use current time as seed for random generator
  srand(time(0));

  int maze[MAZE_SIZE][MAZE_SIZE];

  for (int i = 0; i < MAZE_SIZE; i++){
      for (int j = 0; j < MAZE_SIZE; j++){
          maze[i][j] = 1;
      }
  } 

  for (int i = ENTRY_X; i <= EXIT_X; i++){
      for (int j = ENTRY_Y; j <= EXIT_Y; j++){
          maze[i][j] = rand() % 2 ;
          if (i == ENTRY_X && j == ENTRY_Y)
              maze[i][j] = 2;     // 2 is the Entry
          if (i == EXIT_X && j == EXIT_Y)
              maze[i][j] = 3;     // 3 is the Exit
      }
  }    
  
  // print the maze with 0 (can go), 1(wall), 2(Entry), 3(Exit)
  for (int i = 0; i < MAZE_SIZE; i++){
      for (int j = 0; j < MAZE_SIZE; j++){
          cout << maze[i][j] << " ";
      }
      cout << endl;
  }

  cout << endl;
  
  // use stack to store the record route mouse go
  stack<int> mouse_locX;
  stack<int> mouse_locY;

  x = ENTRY_X; y = ENTRY_Y;
  // int mouse_loc[2] = {x, y};  

  // mouse go maze
  while (EAST != 3 && SOUTH != 3 && SOUTHEAST != 3) {
    if (NORTH == 0) {
      mouse_locX.push(x);
      mouse_locY.push(y);
      maze[x][y] = 6;         // 6 means mouse has passed by
      x--;
    } else if (SOUTH == 0) {
        mouse_locX.push(x);
        mouse_locY.push(y);
        maze[x][y] = 6;
        x++;            
    } else if (EAST == 0) {
        mouse_locX.push(x);
        mouse_locY.push(y);
        maze[x][y] = 6;
        y++;
    } else if (WEST == 0) {
        mouse_locX.push(x);
        mouse_locY.push(y);
        maze[x][y] = 6;
        y--;
    } else if (NORTHEAST == 0) {
        mouse_locX.push(x);
        mouse_locY.push(y);
        maze[x][y] = 6;
        x--;
        y++;
    } else if (NORTHWEST == 0) {
        mouse_locX.push(x);
        mouse_locY.push(y);
        maze[x][y] = 6;
        x--;
        y--;      
    } else if (SOUTHEAST == 0) {
        mouse_locX.push(x);
        mouse_locY.push(y);
        maze[x][y] = 6;
        x++;
        y++;      
    } else if (SOUTHWEST == 0) {
        mouse_locX.push(x);
        mouse_locY.push(y);
        maze[x][y] = 6;
        x++;
        y--;      
    } else {
        if ((x == ENTRY_X && y == ENTRY_Y) || mouse_locX.empty()) {
          cout << "no path can go!!" << endl;
          break;
        }

        cout << "Go Back!!" << endl;
        cout << x << maze[x][y] << y << endl;   
        maze[x][y] = 6;
        x = mouse_locX.top();
        y = mouse_locY.top();
        mouse_locX.pop();
        mouse_locY.pop();         
    }

    if (EAST == 3 || SOUTH == 3 || SOUTHEAST == 3) {
      maze[x][y] = 6;
    }
  }


  // cout << EXIT_X << endl;
  // cout << MAZE_SIZE << endl;

  // print the maze after mouse go
  for (int i = 0; i < MAZE_SIZE; i++){
      for (int j = 0; j < MAZE_SIZE; j++){
          cout << maze[i][j] << " ";
      }
      cout << endl;
  } 

  if (EAST == 3 || SOUTH == 3 || SOUTHEAST == 3) {
    cout << "exit found!!" << endl;
  } else {
    cout << "can't get out of this maze!!" << endl;
  }

  return 0; 
}