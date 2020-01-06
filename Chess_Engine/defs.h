#pragma once
#ifndef DEFS_H
#define DEFS_H
#include<stdlib.h>


#define DEBUG

#ifndef DEBUG
#define ASSERT(n)
#else
#define ASSERT(n) \
if(!(n)) { \
printf("%s - Failed",#n); \
printf("On %s ",__DATE__); \
printf("At %s ",__TIME__); \
printf("In File %s ",__FILE__); \
printf("At Line %d\n",__LINE__); \
exit(1);}
#endif


typedef unsigned long long  U64;


#define NAME "White Dog Chess 1.0"
#define BOARD_SQUARE_NUMBERS 120

#define MAXGAMEMOVES 2048
/* 
// @ wP = White Pawn
// ...
*/
enum {EMPTY,wP, wN,wB,wR,wQ,wK,bP,bN,bB,bR,bQ,bK}; 
enum {FILE_A, FILE_B, FILE_C, FILE_D,FILE_E,FILE_F,FILE_G,FILE_H,FILE_NONE};
enum {RANK_1, RANK_2,RANK_3,RANK_4,RANK_5,RANK_6,RANK_7,RANK_8,RANK_NONE};
enum {WHITE,BACK,BOTH};
enum {
	A1 = 21, B1, C1, D1, E1, F1, G1, H1,
	A2 = 31, B2, C2, D2, E2, F2, G2, H2,
	A3 = 41, B3, C3, D3, E3, F3, G3, H3,
	A4 = 51, B4, C4, D4, E4, F4, G4, H4,
	A5 = 61, B5, C5, D5, E5, F5, G5, H5,
	A6 = 71, B6, C6, D6, E6, F6, G6, H6,
	A7 = 81, B7, C7, D7, E7, F7, G7, H7,
	A8 = 91, B8, C8, D8, E8, F8, G8, H8, NO_SQ
};
enum {FALSE,TRUE};

enum castle {wKCA=1,wQCA=2,bKCA=4,bQCA=8};

struct UndoMove {
	int move;
	int availableCastle;
	int enPas; //en Passant 
	int fiftyMove;
	U64 positionKey;
	
	
};
class Board {
public:
	int pieces[BOARD_SQUARE_NUMBERS];
	U64 pawns[3];
	int kingSquare;
	int side;
	int enPas;
	int fifty;
	int ply;
	int hisPlay;
	U64 posKey;
	int pceNum[13];  // piece numbers

	//   @ availableCastle INTEGER type 
	//   beacause of 4 bytes 0 0 0 0 means castle is available both side for both color
	//                       0 0 0 1 means castle is available only black and queen side (long castle)
	//                       1 0 0 1 means castle is available for white at king side (short castle) and black at queen side
	//                       0 1 0 0 means castle is available for only white at queen side
	//                       and so on... 
	                         
	int availableCastle;
	
    //[3] means BLACK, WHITE, BOTH
	int bigPiece[3]; 
	int majorPiece[3];
	int minPiece[3];


	//  @at whatever move number were at in the game we will store
	// move about to made @move;
	// castle permission  @availableCastle;
	// fifty move status  @fiftyMove;
	UndoMove history[MAXGAMEMOVES];   
	int pList[13][10];


};



/* MACROS */

#define FR2SQ(f,r) ( (21 + (f) ) + ( (r) * 10 ) ) 
#define SQ64(sq120) Sq120ToSq64[BOARD_SQUARE_NUMBERS]

/* GLOBALS */

extern int Sq120ToSq64[BOARD_SQUARE_NUMBERS];
extern int Sq64ToSq120[64];


/* FUNCTIONS */

// init.c
extern void init();

// bitboards.c
extern void PrintBitBoard(U64 bb);

#endif

