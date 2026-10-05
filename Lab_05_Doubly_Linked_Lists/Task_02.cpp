#include <iostream>
using namespace std;

// Node class
class Node {
public:
    string player;
    Node* next;

    Node(string name) {
        player = name;
        next = NULL;
    }
};

// Circular Linked List class
class Game {
private:
    Node* head;

public:
    Game() {
        head = NULL;
    }

    // Add player
    void addPlayer(string name) {
        Node* newNode = new Node(name);

        if (head == NULL) {
            head = newNode;
            newNode->next = head;
        }
        else {
            Node* temp = head;

            while (temp->next != head) {
                temp = temp->next;
            }

            temp->next = newNode;
            newNode->next = head;
        }
    }

    // Display players' turns
    void displayTurns() {
        Node* temp = head;

        cout << "Player Turns:\n";

        // Display each player once
        do {
            cout << temp->player << " -> ";
            temp = temp->next;
        } while (temp != head);

        cout << "Back to " << head->player << endl;
    }
};

int main() {
    Game game;

    // Add 5 players
    game.addPlayer("Ali");
    game.addPlayer("Ahmed");
    game.addPlayer("Sara");
    game.addPlayer("John");
    game.addPlayer("Hina");

    // Display turns
    game.displayTurns();

    return 0;
}
