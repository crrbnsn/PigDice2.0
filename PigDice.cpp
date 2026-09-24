#include <iostream>
#include <random>
using namespace std;

class Die {
private:
    int m_value;
    int m_numSides;

public:
    Die() {
        m_value = 0;
        m_numSides = 6;
    }

    void setValue() {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<int> dis(1, m_numSides);
        m_value = dis(gen);
    }

    int getValue() {
        return m_value;
    }

    void setNumSides(int numSides) {
        m_numSides = numSides;
    }

    int getNumSides() {
        return m_numSides;
    }
};

struct GameState {
    int gameScore;
    int turnCount;
    int scoreThisTurn;
    bool gameOver;
    bool turnOver;
};

void displayRules();
void playGame(GameState &g);
void takeTurn(GameState &g);
void roll(GameState &g);
void hold(GameState &g);

int main() {
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
    Die die;
    die.setValue();

    cout << "Die: " << die.getValue();

    if (die.getValue() == 1) {
        cout << endl;
        cout << "Turn over. No score." << endl;
        g.scoreThisTurn = 0;
        g.turnOver = true;
    } else {
        g.scoreThisTurn += die.getValue();
        cout << " - Running score this turn: " << g.scoreThisTurn << endl;
    }
}

void hold(GameState &g) {
    g.turnOver = true;
}
