#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class ChessGame {
private:
    char board[8][8];
    bool whiteTurn;

public:
    ChessGame() {
        initializeBoard();
        whiteTurn = true;
    }

    void initializeBoard() {
       
        char startingBoard[8][8] = {
            {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
            {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
            {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
            {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
            {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
            {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
            {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
            {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}
        };
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                board[i][j] = startingBoard[i][j];
            }
        }
    }

    void displayBoard() {
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    }

    void play() {
        while (true) {
            displayBoard();
            string player = whiteTurn ? "White" : "Black";
            cout << player << " player's turn. Enter move (e.g., a2 a4): ";
            string move;
            getline(cin, move);
            if (isValidMove(move)) {
                makeMove(move);
                whiteTurn = !whiteTurn;
            } else {
                cout << "Invalid move. Try again." << endl;
            }
        }
    }

    bool isValidMove(string move) {
        char fromFile, toFile;
        int fromRank, toRank;
        istringstream iss(move);
        if (!(iss >> fromFile >> fromRank >> toFile >> toRank)) {
            return false;
        }
        int fromCol = fromFile - 'a';
        int toCol = toFile - 'a';
        int fromRow = 8 - fromRank;
        int toRow = 8 - toRank;
        if (fromRow < 0 || fromRow >= 8 || fromCol < 0 || fromCol >= 8 ||
            toRow < 0 || toRow >= 8 || toCol < 0 || toCol >= 8) {
            return false;
        }
       
        return true;
    }

    void makeMove(string move) {
        char fromFile, toFile;
        int fromRank, toRank;
        istringstream iss(move);
        iss >> fromFile >> fromRank >> toFile >> toRank;
        int fromCol = fromFile - 'a';
        int toCol = toFile - 'a';
        int fromRow = 8 - fromRank;
        int toRow = 8 - toRank;
        char piece = board[fromRow][fromCol];
        board[fromRow][fromCol] = ' ';
        board[toRow][toCol] = piece;
    }
};

int main() {
    ChessGame game;
    game.play();
    return 0;
}
