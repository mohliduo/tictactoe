#include <iostream>
#include <string>
#include <sl.h>

using namespace std;

// Inisiasi Nama Fungsi
void DrawBoard(int board, int font);
void SetBoardValue(int index, int board, int font);
void CheckWinner();
bool CheckDraw();

// Inisiasi Player
const int PLAYER_X = 1;
const int PLAYER_O = 2;

// Inisiasi Array Board
char boardValue[9] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };

int isWin = false;
int isDraw = false;
int player = PLAYER_X;

int main() {
	// Membuat layar window 800x800
	slWindow(800, 800, "TicTacToe Kelompok 10", false);

	// Inisiasi Gambar Papan
	int board = slLoadTexture("./assets/img/board.png");

	// Inisiasi Font
	int font = slLoadFont("./assets/font/font.ttf");

	while (!slShouldClose()) {
		slSetBackColor(1, 1, 1);

		// Mereset game ketika menekan tombol enter
		if ((isWin || isDraw) && slGetKey(SL_KEY_ENTER)) {
			isDraw = false;
			isWin = false;
			player = PLAYER_X;

			boardValue[0] = '1';
			boardValue[1] = '2';
			boardValue[2] = '3';
			boardValue[3] = '4';
			boardValue[4] = '5';
			boardValue[5] = '6';
			boardValue[6] = '7';
			boardValue[7] = '8';
			boardValue[8] = '9';
		}

		// Mengecek apakah status win atau draw
		if (!isWin && !isDraw) {
			// Membuat papan
			DrawBoard(board, font);

			// Menangkap triger nomor
			if (slGetKey('1')) {
				SetBoardValue(0, board, font);
			}
			else if (slGetKey('2')) {
				SetBoardValue(1, board, font);
			}
			else if (slGetKey('3')) {
				SetBoardValue(2, board, font);
			}
			else if (slGetKey('4')) {
				SetBoardValue(3, board, font);
			}
			else if (slGetKey('5')) {
				SetBoardValue(4, board, font);
			}
			else if (slGetKey('6')) {
				SetBoardValue(5, board, font);
			}
			else if (slGetKey('7')) {
				SetBoardValue(6, board, font);
			}
			else if (slGetKey('8')) {
				SetBoardValue(7, board, font);
			}
			else if (slGetKey('9')) {
				SetBoardValue(8, board, font);
			}
		}
		else {
			slSetForeColor(0, 0, 0, 1);
			slSetTextAlign(SL_ALIGN_CENTER);

			// Mengecek apakah draw atau win
			if (isDraw) {
				slSetFont(font, 270);

				slText(450, 500, "Game\nDraw");
			}
			else if (isWin) {
				slSetFont(font, 150);

				if (player == PLAYER_O) {
					slText(450, 500, "Player X\nWin!");
				}
				else if (player == PLAYER_X) {
					slText(450, 500, "Player O\nWin!");
				}
			}
		}

		slRender();
	}

	slClose();

	return 0;
}

void DrawBoard(int board, int font)
{
	slSetForeColor(0, 0, 0, 1);
	slSprite(board, 400, 400, 800, 800);

	slSetForeColor(0, 0, 0, 1);
	slSetFont(font, 270);
	slSetTextAlign(SL_ALIGN_CENTER);

	slText(125, 570, string(1, boardValue[0]).c_str());
	slText(385, 570, string(1, boardValue[1]).c_str());
	slText(645, 570, string(1, boardValue[2]).c_str());
	slText(125, 310, string(1, boardValue[3]).c_str());
	slText(385, 310, string(1, boardValue[4]).c_str());
	slText(645, 310, string(1, boardValue[5]).c_str());
	slText(125, 50, string(1, boardValue[6]).c_str());
	slText(385, 50, string(1, boardValue[7]).c_str());
	slText(645, 50, string(1, boardValue[8]).c_str());
}

void SetBoardValue(int index, int board, int font)
{
	if (boardValue[index] != 'X' && boardValue[index] != 'O') {
		if (player != PLAYER_X) { 
			boardValue[index] = 'O'; 
			player = PLAYER_X; 
		} else {
			boardValue[index] = 'X';
			player = PLAYER_O;
		}

		CheckWinner();
		DrawBoard(board, font);
	}
}

bool CheckDraw()
{
	for (int i = 0; i < 9; ++i) {
		if (boardValue[i] >= '1' && boardValue[i] <= '9') {
			return false;
		}
	}

	return true;
}

void CheckWinner()
{
	isDraw = CheckDraw();

	if (!isDraw) {
		// Check Vertically Wins
		if (boardValue[0] == boardValue[1] && boardValue[1] == boardValue[2]) isWin = true;
		else if (boardValue[3] == boardValue[4] && boardValue[4] == boardValue[5]) isWin = true;
		else if (boardValue[6] == boardValue[7] && boardValue[7] == boardValue[8]) isWin = true;

		// Check Horizontally Wins
		else if (boardValue[0] == boardValue[3] && boardValue[3] == boardValue[6]) isWin = true;
		else if (boardValue[1] == boardValue[4] && boardValue[4] == boardValue[7]) isWin = true;
		else if (boardValue[2] == boardValue[5] && boardValue[5] == boardValue[8]) isWin = true;

		// Check Diagonals
		else if (boardValue[0] == boardValue[4] && boardValue[4] == boardValue[8]) isWin = true;
		else if (boardValue[2] == boardValue[4] && boardValue[4] == boardValue[6]) isWin = true;
	}
}