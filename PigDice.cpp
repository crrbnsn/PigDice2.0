#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct GameState {
    int gameScore;      // total banked score for the game
    int turnCount;      // how many turns have been completed
    int scoreThisTurn;  // running score for the current turn
    bool gameOver;       // controls the main game loop
    bool turnOver;        // controls the loop inside a single turn
};

void displayRules();
void playGame(GameState &g);
void takeTurn(GameState &g);
void roll(GameState &g);
void hold(GameState &g);

int main() {
    //SRAND + time(NULL) so we don't get the same sequence of rolls every time the program runs.
  
    srand(static_cast<unsigned int>(time(nullptr)));

    GameState game;
    game.gameScore = 0;
    game.turnCount = 0;
    game.scoreThisTurn = 0;
    game.gameOver = false;
    game.turnOver = false;

    displayRules();
    playGame(game);

    cout << endl;
    cout << "You finished with a final score of " << game.gameScore
         << " in " << game.turnCount << " turns!" << endl;
    cout << "Thanks for playing PIG Dice!" << endl;

    return 0;
}

void displayRules() {
    cout << "Let's Play PIG Dice!" << endl;
    cout << "* See how many turns it takes you to get to 20 points." << endl;
    cout << "* Turn ends when you hold or roll a 1." << endl;
    cout << "* If you roll a 1, you lose all points for the turn." << endl;
    cout << "* If you hold, you bank all points for the turn to the game score." << endl;
}

void playGame(GameState &g) {
    while (!g.gameOver) {
        takeTurn(g);
        g.gameScore += g.scoreThisTurn;

        if (g.gameScore >= 20) {
            g.gameOver = true;
        } else {
            // Reset for the next turn.
            g.turnOver = false;
            g.scoreThisTurn = 0;
        }
    }
}

void takeTurn(GameState &g) {
    g.turnCount++;

    cout << endl;
    cout << "TURN " << g.turnCount << " - Game Score: " << g.gameScore << endl;

    char choice;

    while (!g.turnOver) {
        cout << "roll or hold? (r/h): ";
        cin >> choice;

        if (choice == 'r') {
            roll(g);
        } else if (choice == 'h') {
            hold(g);
        } else {
            cout << "Invalid choice. Please enter r or h." << endl;
        }
    }

    cout << "Score Banked This Turn: " << g.scoreThisTurn << endl;
}


void roll(GameState &g) {
    int die = (rand() % 6) + 1;

    cout << "Die: " << die;

    if (die == 1) {
        cout << endl;
        cout << "Turn over. No score." << endl;
        g.scoreThisTurn = 0;
        g.turnOver = true;
    } else {
        g.scoreThisTurn += die;
        cout << " - Running score this turn: " << g.scoreThisTurn << endl;
    }
}

void hold(GameState &g) {
    g.turnOver = true;
}
