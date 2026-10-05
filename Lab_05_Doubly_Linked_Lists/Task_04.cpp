#include <iostream>
using namespace std;

// Node class
class Node {
public:
    string song;
    Node* next;

    Node(string name) {
        song = name;
        next = NULL;
    }
};

// Circular Linked List class
class Playlist {
private:
    Node* head;

public:
    Playlist() {
        head = NULL;
    }

    // Add song
    void addSong(string name) {
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

    // Display all songs once
    void displaySongs() {
        Node* temp = head;

        cout << "Songs:\n";

        do {
            cout << temp->song << endl;
            temp = temp->next;
        } while (temp != head);
    }

    // Play playlist for 2 rounds
    void playPlaylist() {
        Node* temp = head;

        cout << "\nPlaying Playlist for 2 Rounds:\n";

        for (int round = 1; round <= 2; round++) {
            cout << "\nRound " << round << ":\n";

            for (int i = 1; i <= 5; i++) {
                cout << "Playing: " << temp->song << endl;
                temp = temp->next;
            }
        }
    }
};

int main() {
    Playlist playlist;

    // Store 5 songs
    playlist.addSong("Song 1");
    playlist.addSong("Song 2");
    playlist.addSong("Song 3");
    playlist.addSong("Song 4");
    playlist.addSong("Song 5");

    // Display songs once
    playlist.displaySongs();

    // Play for 2 complete rounds
    playlist.playPlaylist();

    return 0;
}
