#include "stdio.h"
#include <iostream>
#include "defs.h"
using namespace std;

void PrintBitBoard(U64 bb) {

	U64 shiftMe = 1ULL;

	int rank = 0;
	int file = 0;
	int sq = 0;
	int sq64 = 0;

	cout << "\n";
	for (rank = RANK_8; rank >= RANK_1; --rank) {
		for (file = FILE_A; file <= FILE_H; ++file) {
			sq = FR2SQ(file, rank);	// 120 based		
			sq64 = SQ64(sq); // 64 based

			if ((shiftMe << sq64) & bb)
				cout << "X";
			else
				cout << "-";

		}
		cout << "\n";
	}
	cout << "\n\n";
}
