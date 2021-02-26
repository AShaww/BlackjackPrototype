//@Author NiQQuittle
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

enum Rank { ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE };
enum Suit { HEARTS, DIAMOND, SPACES, CLUBS };

struct Card {   //Own data type of Card
    Rank rank;
    Suit suit;
    int num_suits = 4;
    int num_rank = 13;
};

struct Deck {   //Own data type of Deck
    vector<Card> cards;
    string card_back;
    int max_deck_size = 52; //Sets deck size to 52 (0 - 51) Dont need this as im doing a loop count of 52
};

//List of Prototypes
void initialise(Deck&);
void print_deck(const Deck&);
void print_card(const Card&);

int main()
{
    Deck my_deck;
    initialise(my_deck);

    vector<Card> dealer_hand;
    vector<Card> player_hand;
    print_deck(my_deck);
}

void initialise(Deck& deck)
{
    Card card;
    for (int suit = 0; suit < card.num_suits; suit++)
    {
        for (int rank = 0; rank < card.num_rank; rank++)
        {
            card.suit = Suit(suit); //(Suit/Rank is casted from ENUM type (changes int into value of enum))
            card.rank = Rank(rank);
            deck.cards.push_back(card); //Declaring a new card and adding it to the deck
        }
    }
}

void print_deck(const Deck& deck)
{
   for (Card c : deck.cards) // cards is member of deck. So referred to as cards and not card
    {
        print_card(c);
    }
}

void print_card(const Card& card)
{
        cout << "Rank " << card.rank << " of " << "Suit " << card.suit << '\n';
}

