//*****************
//Program Name: Tic-Tac-Toe game
//Author: Riyya Ahmed
//IDE Used: Repl-it
//Program description: Tic-Tac-Toe game
//*****************
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

// function prototypes
void drawBoard(int[][3]);
void getXpick(int[][3]);
void getOpick(int[][3]);
bool checkForWin(int[][3]);

int main() {
  cout << "\t\tWELCOME TO TIC TAC TOE GAME! \n\tARE YOU READY FOR A CHALLENGING GAME? \n";
  int board[3][3]= {{1,2,3},{4,5,6},{7,8,9}};
  char P1= 'X';
  bool xTurn , winner = false; 
  int turns = 0; 
  
  drawBoard(board);
  getXpick(board);
  drawBoard(board);
  getOpick(board);
  drawBoard(board);
  checkForWin(board);

  while(!winner and turns <10)
  {
    xTurn = true;
    cout << "X picks: \n";
    getXpick(board);
    drawBoard(board);
    winner = checkForWin(board);
    if (winner == true ) cout << "X won!\n";
    xTurn = false;

    if (winner == false)
    {
      getOpick(board);
      drawBoard(board);
      winner = checkForWin(board);
      if (winner == true ) cout << "O won!\n";
      xTurn = false;
    }

    // increment turns
    turns++;
  }

  if(turns >= 10 and !winner) cout << "Draw!! \n";

  return 0;
}

//function definitions
//function draws the playing board
void drawBoard(int tBoard[3][3])
{
  for (int r = 0; r<3 ;r++)
  {
   cout << "------------ \n";
    for (int c= 0; c<3; c++)
      { 
        if (tBoard[r][c] == 79 or tBoard[r][c] == 88) cout <<"| " << (char)tBoard[r][c] << " " ;
        else
          cout <<"| " << tBoard[r][c] << " " ;
      }
    cout << endl;
  }
  cout << "------------ \n";
}
 //function gets users pick
 void getXpick(int tBoard[3][3])// func for users pick
 { 
   int num, repeat= 0;
   
    cout << "User picks: ";
    cin >> num;

    //input validation for users choice
    while (num <1 and num >9)
    {
      cout << "Enter 1-9 only! ";
      cin >> num ;
    }

    //place x(88) in the box and check if box available
    for (int r = 0; r<3 ;r++)
    {
      for (int c= 0; c<3; c++)
      {
        if (tBoard[r][c] == num and tBoard[r][c] > 9)  
          cout << "Sorry, this square is taken!\n";
        if (tBoard[r][c] == num) tBoard[r][c] = 88;
       // if (tBoard[r][c] > 9) cout << (char)tBoard[r][c];
      }  
    }
  }

// func for comps pick
  void getOpick (int b[3][3])
 { 
   int randNum, pick; 
  
  // stretegic pick/ computers AI strategy
  bool strategic = false;

  cout << "\nO Picks: " ;
  if ((b[0][0] == 1) and (b[0][1] == 79) and (b[0][2] == 79)) {cout << b[0][0] ;pick =1; b[0][0] = 79; strategic = true;}
  if ((b[0][0] == 1) and (b[1][0] == 79) and (b[2][0] == 79)) { pick =1; b[0][0] = 79; strategic = true;}
  if ((b[0][0] == 1) and (b[1][1] == 79) and (b[2][2] == 79)) {pick =1; b[0][0] = 79; strategic = true;}

  if ((b[0][1] == 2) and (b[0][0] == 79) and (b[0][2] == 79)) {pick =2; b[0][1] = 79; strategic = true;}
  if ((b[0][1] == 2) and (b[1][1] == 79) and (b[2][1] == 79)) {pick =2; b[0][1] = 79; strategic = true;}

  if ((b[0][2] == 3) and (b[0][1] == 79) and (b[0][0] == 79)) {pick =3; b[0][2] = 79; strategic = true;}
  if ((b[0][2] == 3) and (b[1][2] == 79) and (b[2][2] == 79)) {pick =3; b[0][2] = 79; strategic = true;}
  if ((b[0][2] == 3) and (b[1][1] == 79) and (b[2][0] == 79)) {pick =3; b[0][2] = 79; strategic = true;}

  if ((b[1][0] == 4) and (b[1][1] == 79) and (b[1][2] == 79)) {pick =4; b[1][0] = 79; strategic = true;}
  if ((b[1][0] == 4) and (b[0][0] == 79) and (b[2][0] == 79)) {pick =4; b[1][0] = 79; strategic = true;}

  if ((b[1][1] == 5) and (b[1][0] == 79) and (b[1][2] == 79)) {pick =5; b[1][1] = 79; strategic = true;}
  if ((b[1][1] == 5) and (b[0][1] == 79) and (b[2][1] == 79)) {pick =5; b[1][1] = 79; strategic = true;}
  if ((b[1][1] == 5) and (b[0][0] == 79) and (b[2][2] == 79)) {pick =5; b[1][1] = 79; strategic = true;}
  if ((b[1][1] == 5) and (b[0][2] == 79) and (b[2][0] == 79)) {pick =5; b[1][1] = 79; strategic = true;}

  if ((b[1][2] == 6) and (b[1][0] == 79) and (b[1][1] == 79)) {pick =6; b[1][2] = 79; strategic = true;}
  if ((b[1][2] == 6) and (b[0][2] == 79) and (b[2][2] == 79)) {pick =6; b[1][2] = 79; strategic = true;}
  
  if ((b[2][0] == 7) and (b[2][1] == 79) and (b[2][2] == 79)) {pick =7; b[2][0] = 79; strategic = true;}
  if ((b[2][0] == 7) and (b[0][0] == 79) and (b[1][0] == 79)) {pick =7; b[2][0] = 79; strategic = true;}
  if ((b[2][0] == 7) and (b[0][2] == 79) and (b[1][1] == 79)) {pick =7; b[2][0] = 79; strategic = true;}

  if ((b[2][1] == 8) and (b[2][0] == 79) and (b[2][2] == 79)) {pick =8; b[2][1] = 79; strategic = true;}
  if ((b[2][1] == 8) and (b[0][1] == 79) and (b[1][1] == 79)) {pick =8; b[2][1] = 79; strategic = true;}

  if ((b[2][2] == 9) and (b[0][2] == 79) and (b[1][2] == 79)) {pick =9; b[2][2] = 79; strategic = true;}
  if ((b[2][2] == 9) and (b[2][0] == 79) and (b[2][1] == 79)) {pick =9; b[2][2] = 79; strategic = true;}
  if ((b[2][2] == 9) and (b[0][0] == 79) and (b[1][1] == 79)) {pick =9; b[2][2] = 79; strategic = true;}

   //random picks
   if(!strategic)
   {
     vector <int> vals;
     for (int r = 0; r<3 ;r++)
    {
      for (int c= 0; c<3; c++)
      {
        if (b[r][c] < 10) vals.push_back(b[r][c]);
      }
    } 
    srand(time(0));
    bool alr = false ; 

     randNum = rand() % (9 - 1 +1 ) +1;
     pick = randNum;

    while (alr == false)
    {
      for (int a = 0; a<3 ;a++)
      {
        for (int d = 0; d<3; d++)
          if (b[a][d] == pick) alr = true;
      }
      if (alr == false)
      {
        randNum = rand() % (9 - 1 +1 ) +1;
        pick = randNum;
      }
    }

     for (int r = 0; r<3 ;r++)
    {
      for (int c= 0; c<3; c++)
      {
        if (b[r][c] == pick) 
        {
         cout << b[r][c] << endl ;
          b[r][c] =79;

        }
      } 
    }
   }
    
 }
//checks for users and computers wins
 bool checkForWin(int tBoard[3][3])
 {
   bool status = false;
   //check rows
   for (int r = 0 ; r<2; r++)
   {
     if (tBoard[r][0] == tBoard[r][1] and tBoard[r][0] == tBoard[r][2]) status = true;
   }
   // check columns
   for (int c = 0 ; c<2; c++)
   {
     if (tBoard[0][c] == tBoard[1][c] and tBoard[0][c] == tBoard[2][c]) status = true;
   }

  // check diagonals (hard code)
  if (tBoard[0][0] == tBoard[1][1] and tBoard[0][0] == tBoard[2][2]) status = true;
  if (tBoard[0][2] == tBoard[1][1] and tBoard[0][2] == tBoard[2][0]) status = true;
   
   return status;
 }
