#include <iostream>

using namespace std;

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

// Damjan Stojcev INKI999



// Se izvinuvam za nedorazbiranjeto na zadacata prviot pat.



// Definira struktura na kartata
struct Card {
    string face;
    string suit;
};

// Definira sturktura na shpil
class Deck {
private:
    Card cards[53];
    int cardIndex = 0;

public:
    Deck() {
        // Shpil od karti
        string suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
        string faces[] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};

        for (int i = 0; i < 52; i++) {
            cards[i].suit = suits[i / 13];
            cards[i].face = faces[i % 13];
        }
        
        // Ja dodavam kartata "Joker"
        cards[52].suit = "Joker";
        cards[52].face = "";
    }

    // So Random gi mesha kartite
    void shuffle() {
        srand(time(0));
        for (int i = 0; i < 52; i++) {
            int j = rand() % 52;
            Card temp = cards[i];
            cards[i] = cards[j];
            cards[j] = temp;
        }
        cardIndex = 0;
    }

    // Deli karti od shpilot i gi vrajka kako array
    Card* deal(int n) {
        Card* hand = new Card[n];
        for (int i = 0; i < n; i++) {
            hand[i] = cards[cardIndex++];
        }
        return hand;
    }

    // Ostanat broj na karti od shpilot
    int cardsLeft() {
        return 53 - cardIndex;
    }
        // Print na celiot shpil
        void printDeck() {
        for (int i = 0; i < 53; i++) {
            cout << cards[i].face << " of " << cards[i].suit << endl;
        }
    }
};

int main() {
    Deck deck;
    deck.shuffle();
    
    deck.printDeck();

    int numCards = 5;
    Card* hand = deck.deal(numCards);

    cout << "\nYour hand:\n";
    for (int i = 0; i < numCards; i++) {
        cout << hand[i].face << " of " << hand[i].suit << endl;
    }

    cout << "\nCards left in the deck: " << deck.cardsLeft() << endl;

    delete[] hand;
    return 0;
}