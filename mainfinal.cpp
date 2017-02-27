//Project 3 Videogame
#include <iostream>
#include <fstream>
using namespace std;
#include <string>
#include <cstdlib>
//WINDOWS//////////////
//#include <Windows.h//	
///////////////////////
//LINUX////////////////
//#include <conio.h>///
//#include <ncurses.h>//
///////////////////////


//PROGRAM DATA
typedef enum {Free, Wall, GoalFree, GoalBox,
 GoalPlayer, Player,Box} tTile;

const int MAX = 50;
typedef tTile tBoard[MAX][MAX];

typedef struct{
	tBoard board;
	int nrows;
	int ncolumns; //Smaller than MAX like nrows
	int currentrow;
	int currentcolumn;
	int boxesCounter;
	int boxesPlaced;
} tSokoban; //Board Status

typedef struct{
	tSokoban state;
	int numVos; //Taken so far
	string nFileName;
	int level;
} tGame; //Global game Status

typedef enum{Up, Down, Right, Left, Exit, Nothing} tKey;

//BOARD DISPLAY 
void display(tSokoban board, tGame game); //You first clean
   void drawTile(tTile tile); //Title in the board
   		//WINDOWS void backgroundColor(int color); //WINDOWS
   void draw(const tGame &game); //Display board, file name, level, movements.

//LOADING GAME LEVELS 
void init(tGame &game); //MAX x MAX tiles to free, movements zero
 bool loadGame(tGame &game); //Ask file name and level, loads it
 bool loadLevel(ifstream &file, tSokoban &sokoban, int level);
//Searches choosen level in file, and loads board. True if found.

//READING FROM THE GAME
tKey readKey(); //returns tKey value (4 possibilities + Exit(Esc) + Nothing(Other))
void applyMove(tGame &game, tKey key); //If possible, after key.




int menu();

int main(){
	int option = menu();
	tGame game;
	do{
	 switch (option){
		case 0:
		 cout << "See you!" << endl;
		break;
		case 1: //Play match
			/// WINDOWS //////////////////////////
			// backgroundColor(15);
			init(game);
			loadGame(game);
			display(game.state,game);
			while(readKey() != Exit){
				applyMove(game, key);


				readkey();
			}
			option = menu();
		break;
		}
    } while(option != 0);
 return 0;
}
int menu(){
	int option = -1;
	while((option > 1) || (option < 0)){
		  cout << "1.Play match"<< endl;
		  cout << "0.Exit"<< endl;
		  cin >> option;
		if((option > 1) || (option < 0)){
			cerr << "Wrong option!" << endl;
		}
	}
	return option;
}

//BOARD DISPLAY 
void display(tSokoban board, tGame game){
  #ifdef WINDOWS
     system("cls");
  #else
     // Assume POSIX
     system("clear");
  #endif
}   

void drawTile(tTile tile){
	/// WINDOWS //////////////////////////
	// backgroundColor(15);



   void draw(const tGame &game); //Display board, file name, level, movements.
}

/*
void backgroundColor(int color) {
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, 15 | (color << 4));
}
*///////////// WINDOWS //////////////////////////////////////

//LOADING GAME LEVELS 
void init(tGame &game){
	game.numVos = 0;
	game.state.ncolumns = game.state.nrows = 0;
	for(int i = 0; i < MAX; i++){
		for(int s = 0; i < MAX ; i++){
			game.state.board[i][s] = Free;
		}
	}
}

bool loadGame(tGame &game){
 	 string fileName;
 	 int level;
 	 char t, x, t2, point;
     t = 'm';
 	    do { //Does it have .txt? If not you ask again
       		 cout << "Introduce the file name level with .txt" << endl;
       		 cin >> fileName;
        	 if(fileName.length() > 3){
         		t = fileName.at(fileName.length() - 1);
         		x = fileName.at(fileName.length() - 2);
         		t2 = fileName.at(fileName.length() - 3);
         		point = fileName.at(fileName.length() - 4);
     	     }
        } while ((t != 't') || (x != 'x') || (t2 != 't') || (point != '.'));
    do{
      cout << "What level you desire?" << endl;
      cout << "Level: ";
      cin >> level;
      } while(level < 0);

   ifstream file;
   file.open(fileName.c_str());
      if(!loadLevel(file, game.state, level)){
      	cout << "Error with the file!!" << endl;
      	cout << "---------------" << endl;
      }
     else
     {
    	file.close();
     }
}

bool loadLevel(ifstream &file, tSokoban &sokoban, int level){
 	string word;
 	int levelG, player;
 	bool found, end; 
 	end = found = false;
 	char cell;
 	player = 0;
 	if(file.is_open()){
 	 do{
 		do{
 			file >> word;
         } while (word != "Level");
        file >> levelG;
        if(levelG == level){
        	found = true;
        }
    } while((!found));

    for(int l = 0; l < MAX; l++){ //Lines
    	for(int c = 0; c < MAX; c++){ //Columns
    		cin >> cell;
    		switch(cell){
    			case '#':
    				sokoban.board[l][c] = Wall;
    				sokoban.ncolumns ++;
    				/// WINDOWS //////////////////////////
					// backgroundColor(0);
    			break;
    			case ' ':
    				sokoban.board[l][c] = Free;
    			break;
    			case '.':
    				sokoban.board[l][c] = GoalFree;
    			break;
    			case '$':
    				sokoban.board[l][c] = Box;
    				sokoban.boxesCounter++;
    			break;
    			case '@':
    				sokoban.board[l][c] = Player;
    				player ++;
    				if(player > 1){
    					cerr << "Error! More than one player!" << endl;
    					end = true;
    				}
    			break;
    			case '*':
    				sokoban.board[l][c] = GoalBox;
    				sokoban.boxesPlaced++;
    			break;
    			case '+':
    				sokoban.board[l][c] = GoalPlayer;
    			break;
    			default:
    				cerr << "Unknown element in the file!" << endl;
    				end = true;
    			break;
    		}
    	}
    }
}

return ((file.is_open()) && !(end));
}	

 //READING FROM THE GAME///////////////////////////////////////////
tKey readKey(){ //returns tKey value (4 possibilities + Exit(Esc) + Nothing(Other))
/* Detect the keypress of Esc(ASCII 27) and arrow keys (directions)
When arrow pressed, two codes are generated: One informing that it is a especial
char, other informing of which one is it. Ver código slide */

} 
void applyMove(tGame &game, tKey key);


//TODO
//check if user choose a non exiting level
//Cambiar variables de los for en init de i y s a l y c (linea, columna)
