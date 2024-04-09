import java.util.Scanner;

public class Main {
    private char[][] board;
    private boolean whiteTurn;

    public Main() {
        board = new char[8][8];
        initializeBoard();
        whiteTurn = true;
    }

    private void initializeBoard() {
        // Initialize the board with starting positions of pieces
        char[][] startingBoard = {
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
            System.arraycopy(startingBoard[i], 0, board[i], 0, 8);
        }
    }

    public void displayBoard() {
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                System.out.print(board[i][j] + " ");
            }
            System.out.println();
        }
    }

    public void play() {
        Scanner scanner = new Scanner(System.in);
        while (true) {
            displayBoard();
            String player = whiteTurn ? "White" : "Black";
            System.out.println(player + " player's turn. Enter move (e.g., a2 a4): ");
            String move = scanner.nextLine();
            if (isValidMove(move)) {
                makeMove(move);
                whiteTurn = !whiteTurn;
            } else {
                System.out.println("Invalid move. Try again.");
            }
        }
    }

    private boolean isValidMove(String move) {
        String[] parts = move.split(" ");
        if (parts.length != 2) {
            return false;
        }
        String[] fromCoords = parts[0].split("");
        String[] toCoords = parts[1].split("");
        if (fromCoords.length != 2 || toCoords.length != 2) {
            return false;
        }
        int fromRow = 8 - (fromCoords[1].charAt(0) - '0');
        int fromCol = fromCoords[0].charAt(0) - 'a';
        int toRow = 8 - (toCoords[1].charAt(0) - '0');
        int toCol = toCoords[0].charAt(0) - 'a';
        char piece = board[fromRow][fromCol];
        if (Character.isLowerCase(piece) && whiteTurn) {
            return false;
        }
        if (Character.isUpperCase(piece) && !whiteTurn) {
            return false;
        }
        // Implement more detailed move validation logic here
        return true;
    }

    private void makeMove(String move) {
        String[] parts = move.split(" ");
        String[] fromCoords = parts[0].split("");
        String[] toCoords = parts[1].split("");
        int fromRow = 8 - (fromCoords[1].charAt(0) - '0');
        int fromCol = fromCoords[0].charAt(0) - 'a';
        int toRow = 8 - (toCoords[1].charAt(0) - '0');
        int toCol = toCoords[0].charAt(0) - 'a';
        char piece = board[fromRow][fromCol];
        board[fromRow][fromCol] = ' ';
        board[toRow][toCol] = piece;
    }

    public static void main(String[] args) {
       Main game = new Main();
        game.play();
    }
}
