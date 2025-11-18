/* 
 * File:   main.cpp
 * Author: Matthew Madrigal
 * Created on October 31st, 2025, 3:52 pm,
 * Purpose:  To create an Uno game in C++ using what has been learned so far. These are the rules used for this game: https://service.mattel.com/instruction_sheets/42001pr.pdf
 *           The blank cards are not included since they are for custom rules or replacing lost cards.
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;

//User Libraries
#include "Card.h"
#include "Game.h"
#include "GameS.h"
enum colors {RED, GREEN, YELLOW, BLUE, WILD};
enum types {ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, PLUST, REV, SKIP, PLUSF, CARD};

//Global Constants - Math/Science/Conversions only

//Function Prototypes
void printDeck(int, Card **, Card *);
string printCard(Card *);
Card **getPlayable(int, Card **, Card *, int &);
bool challengeWin(Card *, Card **, int);
unsigned int calcPoints(Card **, int);
int strToCol(string);
int strToNm(string);
void removeCard(int &, Card **, Card *);
void removeCardInd(int &, Card **, int);
Card *playWild(int, Card **);
Card *drawCard(int &, Card **);
Card **genColor();
void copy(int, Card **, Card **);
void addCard(int &, int &, Card ***, Card *);
void setupGame(Game &);
Card *playCard(Game &, bool , bool &, bool &);
Card *playCom(Game &, bool, bool &);
void playGame(Game &, int, Card **);
Card **setupPile(Game &, fstream &);
Card **loadSave(Game &, GameS &, Card **, int);
void createSave(Game &, GameS &, Card **);


//Execution Begins Here
int main(int argc, char** argv) {
    //Set random seed
    srand(time(0));
    //Declare Variables
    Game game;
    GameS saved;
    Card **unique;
    Card **colors;
    fstream setup;
    fstream save;
    
    //Initialize Variables
    game.hand = nullptr;
    game.bHand = nullptr;
    game.drwPile = nullptr;
    game.drwSize = 0;
    game.drwMax = 0;
    game.plScore = 0;
    game.cpScore = 0;
    
    colors = genColor();
    
    //The Process -> Map Inputs to Outputs
    save.open("save.data", ios::in | ios::out | ios::binary);
    if(save.is_open()) {
        cout << "Save data found. Resuming using save data." << endl;
        save.read(reinterpret_cast<char *>(&saved), sizeof(saved));
        if(saved.cpScore > 500 || saved.plScore > 500) {
            cout << "Save data is from a completed game, creating new game." << endl;
            setup.open("start.txt", ios::in);
            unique = setupPile(game, setup);
            setup.close();
            setupGame(game);
        } else {
            unique = loadSave(game, saved, colors, 4);
        }
    } else {
        cout << "No save data found. Starting a new game." << endl;
        save.close();
        save.open("save.data", ios::out | ios::binary);
        save.close();
        save.open("save.data", ios::in | ios::out | ios::binary);
        setup.open("start.txt", ios::in);
        unique = setupPile(game, setup);
        setup.close();
        setupGame(game);
    }
    
    //Display Inputs/Outputs
    cout << "Welcome to Uno. When you are asked to play a card, you can either play one or draw. When you will have one card left, you must first type and enter uno before entering the card you wish to play. If the computer forgets to call uno, you can penalize them by entering uno before playing a card. To save and quit, type quit when asked to play a card." << endl;
    playGame(game, 4, colors);
    save.seekp(0L, ios::beg);
    createSave(game, saved, unique);
    save.write(reinterpret_cast<char*>(&saved), sizeof(saved));

    //Exit the Program
    for(int i = 0; i < 54; i++) {
        delete unique[i];
    }
    for(int i = 0; i < 4; i++) {
        delete colors[i];
    }
    delete []unique;
    delete []colors;
    delete []game.drwPile;
    delete []game.bHand;
    delete []game.hand;
    save.close();
    return 0;
}
void printDeck(int size, Card **deck, Card *active) {
    cout << "Cards in hand: ";
    for(int i = 0; i < size; i++) {
        cout << printCard(deck[i]) << "; ";
    }
    cout << endl;
    Card **play;
    int playS;
    play = getPlayable(size, deck, active, playS);
    cout << "Playable cards in hand: ";
    for(int i = 0; i < playS; i++) {
        cout << printCard(play[i]) << "; ";
    }
    cout << endl;
    delete []play;
}

string printCard(Card *card) {
    string display;
    switch(card->color) {
        case RED:
        display += "Red ";
        break;
        case GREEN:
        display += "Green ";
        break;
        case YELLOW:
        display += "Yellow ";
        break;
        case BLUE:
        display += "Blue ";
        break;
        case WILD:
        display += "Wild ";
        break;
        default:
        break;
    }
    switch(card->name) {
        case ZERO:
        case ONE:
        case TWO:
        case THREE:
        case FOUR:
        case FIVE:
        case SIX:
        case SEVEN:
        case EIGHT:
        case NINE:
        display += to_string(card->name);
        break;
        case PLUST:
        display += "Draw Two";
        break;
        case PLUSF:
        display += "Draw Four";
        break;
        case REV:
        display += "Reverse";
        break;
        case SKIP:
        display += "Skip";
        break;
        case CARD:
        default:
        display += "Card";
        break;
    }
    return display;

}

Card **getPlayable(int size, Card **deck, Card *active, int &plSize) {
    Card **play;     // Playable cards
    int playS = 0;      // Playable cards size
    for(int i = 0; i < size; i++) {
        Card *card = deck[i];
        if(card->color == WILD || card->color == active->color || card->name == active->name) {
            playS++;
        }
    }
    play = new Card*[playS];
    plSize = playS;
    int plIndex = 0;
    for(int i = 0; i < size; i++) {
        if(plIndex >= playS) {
            break;
        }
        Card *card = deck[i];
        if(card->color == WILD || card->color == active->color || card->name == active->name) {
            play[plIndex] = card;
            plIndex++;
        }
    }
    return play;
}

bool challengeWin(Card *check, Card **deck, int size) {
    for(int i = 0; i < size; i++) {
        Card *card = deck[i];
        if(check->color == card->color) {
            return true;
        }
    }
    return false;
}

unsigned int calcPoints(Card **deck, int size) {
    unsigned int points = 0;
    for(int i = 0; i < size; i++) {
        Card *card = deck[i];
        switch(card->name) {
            case ZERO:
            case ONE:
            case TWO:
            case THREE:
            case FOUR:
            case FIVE:
            case SIX:
            case SEVEN:
            case EIGHT:
            case NINE:
            points += card->name;
            break;
            case PLUST:
            case REV:
            case SKIP:
            points += 20;
            break;
            case CARD:
            case PLUSF:
            points += 50;
            break;
            default:
            break;
        }
    }
    return points;
}

Card *playCard(Game &game, bool uno, bool &unoed, bool &quit) {
    bool choosen = false;
    Card *usrCard = nullptr;
    while(!choosen) {
        int validS;
        Card **valid = getPlayable(game.handS, game.hand, game.rest, validS);
        if(validS != 0 || game.drwSize != 0) {
            printDeck(game.handS, game.hand, game.rest);
            cout << "Enter the card you would like to play (Type it as listed)" << ((game.drwSize > 0) ?" or type draw to draw a card" : "") << (uno? ". Since the computer didn't call uno, you can type uno to force them to draw" : "") << ": ";
            string input, wordF, wordS;
            getline(cin, input);
            bool next = false;
            for(int i = 0; i < input.length(); i++) {
                input[i] = tolower(input[i]);
            }
            if(input == "quit") {
                quit = true;
                delete []valid;
                return nullptr;
            }
            if(input == "draw") {
                usrCard = drawCard(game.drwSize, game.drwPile);
                if(usrCard == nullptr) {
                    cout << "There are no cards to draw." << endl;
                } else {
                    cout << "You got a " << printCard(usrCard) << endl;
                    if((usrCard->color == WILD) || (usrCard->color == game.rest->color || usrCard->name == game.rest->name)) {
                        cout << "Would you like to play it? (yes or No)" << endl;
                        string toPlay;
                        getline(cin, toPlay);
                        for(int i = 0; i < toPlay.length(); i++) {
                            toPlay[i] = tolower(toPlay[i]);
                        }
                        if(toPlay != "yes") {
                            addCard(game.handS, game.handM, &game.hand, usrCard);
                            usrCard = nullptr;
                        }
                    }
                    choosen = true;
                }
            } else if(input == "uno") {
                if(!uno) {
                    if(game.handS == 2 && validS >= 1) {
                        unoed = true;
                        cout << "You called uno!" << endl;
                    } else {
                        cout << "You can't call uno yet!" << endl;
                    }
                } else {
                    cout << "The computer will draw 4 cards" << endl;
                    int drawnC = 0;
                    for(int i = 0; i < 4; i++) {
                        Card *drawn = drawCard(game.drwSize, game.drwPile);
                        if(drawn != nullptr) {
                            drawnC++;
                            addCard(game.bHandS, game.bHandM, &game.bHand, drawn);
                        }
                    }
                    if(drawnC != 4) {
                        cout << "The computer could only draw " << drawnC << " cards." << endl;
                    }
                    if(game.drwSize == 0) {
                        cout << "The draw pile is now empty." << endl;
                    }
                }
            }else {
                for(int i = 0; i < input.length(); i++) {
                    if(input[i] == ' ' && !next) {
                        next = true;
                    } else {
                        if(!next) {
                            wordF += input[i];
                        } else {
                            wordS += input[i];
                        }
                    }
                }
                int color, name;
                color = strToCol(wordF);
                name = strToNm(wordS);
                if(color != -1 && name != -1) {
                    for(int i = 0; i < validS; i++) {
                        Card *card = valid[i];
                        if(card->color == color && card->name == name) {
                            choosen = true;
                            usrCard = card;
                            removeCard(game.handS, game.hand, card);
                            break;
                        }
                    }
                }
                if(!choosen) {
                    cout << "Can not play card" << endl;
                }
            }
        } else {
            cout << "You have no playable cards and the draw pile was empty. Your turn will be skipped." << endl;
            choosen = true;
        }
        delete []valid;
    }
    return usrCard;
    
}

int strToCol(string input) {
    if(input == "red") {
        return RED;
    }
    if(input == "green") {
        return GREEN;
    }
    if(input == "yellow") {
        return YELLOW;
    }
    if(input == "blue") {
        return BLUE;
    }
    if(input == "wild") {
        return WILD;
    }
    return -1;
}

int strToNm(string input) {
    if(input.length() == 1 && isdigit(input[0])) {
        return static_cast<int>(input[0] - '0');
    } else {
        if(input == "draw two") {
            return PLUST;
        }
        if(input == "draw four") {
            return PLUSF;
        }
        if(input == "reverse") {
            return REV;
        }
        if(input == "skip") {
            return SKIP;
        }
        if(input == "card") {
            return CARD;
        }
    }
    return -1;
}

void removeCard(int &size, Card **hand, Card *card) {
    int index = 0;
    for(int i = 0; i < size; i++) {
        if(hand[i] == card) {
            index = i;
            break;
        }
    }
    for(int i = index+1; i < size; i++) {
        hand[i-1] = hand[i];
    }
    size--;
}

void removeCardInd(int &size, Card **hand, int index) {
    for(int i = index+1; i < size; i++) {
        hand[i-1] = hand[i];
    }
    size--;
}

Card *playWild(int size, Card **colors) {
    bool picked = false;
    Card *cardR;    // Card used to restrict to a color
    while(!picked) {
        cout << "Choose a color (Red, Green, Yellow, Blue): ";
        string input;
        getline(cin, input);
        for(int i = 0; i < input.length(); i++) {
            input[i] = tolower(input[i]);
        }
        int color;
        color = strToCol(input);
        if(color != -1 && color != WILD) {
            for(int i = 0; i < size; i++) {
                Card *card = colors[i];
                if(card->color == color) {
                    picked = true;
                    cardR = card;
                    break;
                }
            }
        } else {
            cout << "Invalid input" << endl;
        }
    }
    return cardR;
}

Card *drawCard(int &size, Card **draw) {
    if(size == 0) {
        return nullptr;
    }
    int index = rand() % size;
    Card *card = draw[index];
    removeCard(size, draw, card);
    return card;
}

Card **genColor() {
    Card **colors = new Card*[4];
    colors[0] = new Card{RED, CARD};
    colors[1] = new Card{GREEN, CARD};
    colors[2] = new Card{YELLOW, CARD};
    colors[3] = new Card{BLUE, CARD};
    return colors;
}

void copy(int size, Card **arr1, Card **arr2) {
    for(int i = 0; i < size; i++) {
        arr2[i] = arr1[i];
    }
}

void addCard(int &size, int &maxSize, Card ***hand, Card *card) {
    if(size >= maxSize) {
        maxSize += 10;
        Card **handN = new Card*[maxSize];
        copy(size, *hand, handN);
        delete [](*hand);
        *hand = handN;
    }
    (*hand)[size] = card;
    size++;
}

void setupGame(Game &game) {
    const int start = 7;
    game.handS = start;
    if(game.hand == nullptr) {
        game.handM = start;
        game.hand = new Card*[start];
    }
    game.bHandS = start;
    if(game.bHand == nullptr) {
        game.bHandM = start;
        game.bHand = new Card*[start];
    }
    for(int i = 0; i < start; i++) {
        Card *card = drawCard(game.drwSize, game.drwPile);
        game.hand[i] = card;
        card = drawCard(game.drwSize, game.drwPile);
        game.bHand[i] = card;
    }
    Card *card = drawCard(game.drwSize, game.drwPile);
    while(card->color == WILD) {
        addCard(game.drwSize, game.drwMax, &game.drwPile, card);
        card = drawCard(game.drwSize, game.drwPile);
    }
    game.lastPl = card;
    game.rest = card;
    game.turn = true;
}

Card *playCom(Game &game, bool uno, bool &unoed) {
    if(uno) {
        if(rand()%2 == 1) {
            cout << "The computer caught you with one card!" << endl;
            int drawnC = 0;
            for(int i = 0; i < 4; i++) {
                Card *drawn = drawCard(game.drwSize, game.drwPile);
                if(drawn != nullptr) {
                    drawnC++;
                    addCard(game.handS, game.handM, &game.hand, drawn);
                }
            }
            if(drawnC != 4) {
                cout << "You could only draw " << drawnC << " cards." << endl;
            }
            if(game.drwSize == 0) {
                cout << "The draw pile is now empty." << endl;
            }
        }
    }
    Card *usrCard = nullptr;
    int validS;
    Card **valid = getPlayable(game.bHandS, game.bHand, game.rest, validS);
    if(validS != 0 || game.drwSize != 0) {
        if(validS != 0) {
            int index = rand()%validS;
            usrCard = valid[index];
            removeCard(game.bHandS, game.bHand, usrCard);
            cout << "The computer played the card " << printCard(usrCard) << endl;
        } else {
            cout << "The computer drawed a card" << endl;
            Card *drawn = drawCard(game.drwSize, game.drwPile);
            addCard(game.bHandS, game.bHandM, &game.bHand, drawn);
        }
    } else {
        cout << "The computer couldn't play anything and the draw pile was empty." << endl;
        unoed = true;
    }
    delete []valid;
    return usrCard;
}

void playGame(Game &game, int colorS, Card **colors) {
    bool uno = false, unoed = false, quit = false;
    while(game.plScore < 500 && game.cpScore < 500) {
        Card *card;
        Card *res;
        if(game.turn) {
            cout << "Current card at play: " << printCard(game.lastPl) << endl;
            card = playCard(game, uno, unoed, quit);
            if(quit) {
                break;
            }
            res = card;
            game.turn = false;
            if(card != nullptr) {
                if(card->color == WILD) {
                    res = playWild(colorS, colors);
                }
                if(card->name == PLUST) {
                    cout << "The computer will draw 2 cards now" << endl;
                    game.turn = true;
                    int drawnC = 0;
                    for(int i = 0; i < 2; i++) {
                        Card *drawn = drawCard(game.drwSize, game.drwPile);
                        if(drawn != nullptr) {
                            drawnC++;
                            addCard(game.bHandS, game.bHandM, &game.bHand, drawn);
                        }
                    }
                    if(drawnC < 2) {
                        cout << "Only " << drawnC << " cards were drawn." << endl;
                    }
                    if(drawnC == 0) {
                        cout << "The draw pile is now empty." << endl;
                    }

                }
                if(card->name == PLUSF) {
                    if(rand()%2 == 1) {
                        cout << "The computer choose to not challenge you and will draw 4 cards now" << endl;
                        game.turn = true;
                        int drawnC = 0;
                        for(int i = 0; i < 4; i++) {
                            Card *drawn = drawCard(game.drwSize, game.drwPile);
                            if(drawn != nullptr) {
                                drawnC++;
                                addCard(game.bHandS, game.bHandM, &game.bHand, drawn);
                            }
                        }
                        if(drawnC < 4) {
                            cout << "Only " << drawnC << " cards were drawn." << endl;
                        }
                        if(drawnC == 0) {
                            cout << "The draw pile is now empty." << endl;
                        }
                    } else {
                        cout << "The computer has choosen to challenge you." << endl;
                        if(challengeWin(game.rest, game.hand, game.handS)) {
                            cout << "The computer won since you had a matching color card. You now need to draw 4 cards" << endl;
                            int drawnC = 0;
                            for(int i = 0; i < 4; i++) {
                                Card *drawn = drawCard(game.drwSize, game.drwPile);
                                if(drawn != nullptr) {
                                    drawnC++;
                                    cout << "You drew a " << printCard(drawn) << endl;
                                    addCard(game.handS, game.handM, &game.hand, drawn);
                                }
                            }
                            if(drawnC < 4) {
                                cout << "Only " << drawnC << " cards were drawn." << endl;
                            }
                            if(drawnC == 0) {
                                cout << "The draw pile is now empty." << endl;
                            }
                        } else {
                            cout << "The computer has lost. The computer now needs to draw 6 cards" << endl;
                            game.turn = true;
                            int drawnC = 0;
                            for(int i = 0; i < 6; i++) {
                                Card *drawn = drawCard(game.drwSize, game.drwPile);
                                if(drawn != nullptr) {
                                    drawnC++;
                                    addCard(game.bHandS, game.bHandM, &game.bHand, drawn);
                                }
                            }
                            if(drawnC < 6) {
                                cout << "Only " << drawnC << " cards were drawn." << endl;
                            }
                            if(drawnC == 0) {
                                cout << "The draw pile is now empty." << endl;
                            }
                        }
                    }
                }
                if(card->name == SKIP) {
                    game.turn = true;
                }
                if(card->name == REV) {
                    game.turn = true;
                }
                if(game.handS == 1 && !unoed && !game.turn) {
                    uno = true;
                } else {
                    uno = false;
                }
                unoed = false;
                addCard(game.drwSize, game.drwMax, &game.drwPile, game.lastPl);
                game.lastPl = card;
                game.rest = res;
            } else {
                uno = false;
                unoed = false;
            }
        } else {
            card = playCom(game, uno, unoed);
            res = card;
            game.turn = true;
            if(card != nullptr) {
                if(card->color == WILD) {
                    res = colors[rand()%colorS];
                    cout << "The next played card now must be a " << printCard(res) << endl;
                }
                if(card->name == PLUST) {
                    cout << "You will draw 2 cards now" << endl;
                    game.turn = false;
                    int drawnC = 0;
                    for(int i = 0; i < 2; i++) {
                        Card *drawn = drawCard(game.drwSize, game.drwPile);
                        if(drawn != nullptr) {
                            drawnC++;
                            cout << "You drew a " << printCard(drawn) << endl;
                            addCard(game.handS, game.handM, &game.hand, drawn);
                        }
                    }
                    if(drawnC < 2) {
                        cout << "Only " << drawnC << " cards were drawn." << endl;
                    }
                    if(drawnC == 0) {
                        cout << "The draw pile is now empty." << endl;
                    }

                }
                if(card->name == PLUSF) {
                    string input;
                    while(input != "yes" && input != "no") {
                        cout << "Would you like to challenge the card? (Yes or No)" << endl;
                        getline(cin, input);
                        for(int i = 0; i < input.size(); i++) {
                            input[i] = tolower(input[i]);
                        }
                        if(input != "yes" && input != "no") {
                            cout << "Invalid input" << endl;
                        }
                    }
                    if(input == "no") {
                        cout << "You choose to not challenge the computer and will draw 4 cards now" << endl;
                        game.turn = false;
                        int drawnC = 0;
                        for(int i = 0; i < 4; i++) {
                            Card *drawn = drawCard(game.drwSize, game.drwPile);
                            if(drawn != nullptr) {
                                drawnC++;
                                cout << "You drew a " << printCard(drawn) << endl;
                                addCard(game.handS, game.handM, &game.hand, drawn);
                            }
                        }
                        if(drawnC < 4) {
                            cout << "Only " << drawnC << " cards were drawn." << endl;
                        }
                        if(drawnC == 0) {
                            cout << "The draw pile is now empty." << endl;
                        }
                    } else {
                        cout << "You have choosen to challenge the computer." << endl;
                        cout << "The computer hand is: ";
                        for(int i = 0; i < game.bHandS; i++) {
                            cout << printCard(game.bHand[i]) << "; ";
                        }
                        cout << endl;
                        if(challengeWin(game.rest, game.bHand, game.bHandS)) {
                            cout << "You won since the computer had a matching color card. The computer now needs to draw 4 cards" << endl;
                            int drawnC = 0;
                            for(int i = 0; i < 4; i++) {
                                Card *drawn = drawCard(game.drwSize, game.drwPile);
                                if(drawn != nullptr) {
                                    drawnC++;
                                    addCard(game.bHandS, game.bHandM, &game.bHand, drawn);
                                }
                            }
                            if(drawnC < 4) {
                                cout << "Only " << drawnC << " cards were drawn." << endl;
                            }
                            if(drawnC == 0) {
                                cout << "The draw pile is now empty." << endl;
                            }
                        } else {
                            cout << "You lost the challenge. You now needs to draw 6 cards" << endl;
                            game.turn = false;
                            int drawnC = 0;
                            for(int i = 0; i < 6; i++) {
                                Card *drawn = drawCard(game.drwSize, game.drwPile);
                                if(drawn != nullptr) {
                                    drawnC++;
                                    cout << "You drew a " << printCard(drawn) << endl;
                                    addCard(game.handS, game.handM, &game.hand, drawn);
                                }
                            }
                            if(drawnC < 6) {
                                cout << "Only " << drawnC << " cards were drawn." << endl;
                            }
                            if(drawnC == 0) {
                                cout << "The draw pile is now empty." << endl;
                            }
                        }
                    }
                }
                if(card->name == SKIP) {
                    game.turn = false;
                }
                if(card->name == REV) {
                    game.turn = false;
                }
                if(game.handS == 1 && !unoed && game.turn) {
                    uno = true;
                } else {
                    uno = false;
                }
                unoed = false;
                addCard(game.drwSize, game.drwMax, &game.drwPile, game.lastPl);
                game.lastPl = card;
                game.rest = res;
            }
        }
        if(game.bHandS == 0) {
            cout << "Computer has won!" << endl;
            game.cpScore += calcPoints(game.hand, game.handS);
            for(int i = 0; i < game.handS; i++) {
                addCard(game.drwSize, game.drwMax, &game.drwPile, game.hand[i]);
            }
            game.handS = 0;
            cout << "Current Score" << endl << "Player: " << game.plScore << endl << "Computer: " << game.cpScore << endl;
            setupGame(game);
        } else if(game.handS == 0) {
            cout << "You have won!" << endl;
            game.plScore += calcPoints(game.bHand, game.bHandS);
            for(int i = 0; i < game.bHandS; i++) {
                addCard(game.drwSize, game.drwMax, &game.drwPile, game.bHand[i]);
            }
            game.bHandS = 0;
            cout << "Current Score" << endl << "Player: " << game.plScore << endl << "Computer: " << game.cpScore << endl;
            setupGame(game);
        }
    }
    if(game.plScore >= 500 || game.cpScore >= 500) {
        cout << "Game Complete! " << ((game.cpScore >= 500) ? "Computer" : "Player") << " won!" << endl;
    }
    cout << "Game will save" << endl;
}

Card **setupPile(Game &game, fstream &setup) {
    if(game.drwPile == nullptr) {
        const int cardLimit = 54;
        long int indexes[cardLimit] = {};
        Card **cardTypes = new Card*[cardLimit]; 
        int total = 0;
        for(int i = 1; i < cardLimit; i++) {
            string line;
            getline(setup, line);
            indexes[i] = setup.tellg();
        }
        for(int i = 0; i < cardLimit; i++) {
            setup.seekg(indexes[i], ios::beg);
            Card *card = new Card;
            int num = 0;
            setup >> card->color;
            setup >> card->name;
            setup >> num;
            total += num;
            cardTypes[i] = card;
        }
        game.drwMax = total;
        game.drwSize = total;
        game.drwPile = new Card*[total];
        int drwInd = 0;
        for(int i = 0; i < cardLimit; i++) {
            setup.seekg(indexes[i], ios::beg);
            int num = 0;
            setup >> num;
            setup >> num;
            setup >> num;
            for(int j = 0; j < num; j++) {
                game.drwPile[drwInd] = cardTypes[i];
                drwInd++;
            }
        }
        return cardTypes;
    }
    return nullptr;
}

Card **loadSave(Game &game, GameS &save, Card **colors, int colorS) {
    game.plScore = save.plScore;
    game.cpScore = save.cpScore;
    game.bHandS = save.bHandS;
    game.bHandM = save.bHandS;
    game.handS = save.handS;
    game.handM = save.handS;
    game.drwSize = save.drwSize;
    game.drwMax = save.handS + save.bHandS + save.drwSize;
    game.drwPile = new Card*[game.drwMax];
    game.bHand = new Card*[game.bHandM];
    game.hand = new Card*[game.handM];
    game.turn = save.turn;
    Card **unique = new Card*[54];
    int indexDr = 0;
    int indexPl = 0;
    int indexCp = 0;
    for(int i = 0; i < 54; i++) {
        unique[i] = new Card;
        unique[i]->color = save.cards[i].color;
        unique[i]->name = save.cards[i].name;
        for(int j = 0; j < save.draw[i]; j++) {
            game.drwPile[indexDr] = unique[i];
            indexDr++;
        }
        for(int j = 0; j < save.play[i]; j++) {
            game.hand[indexPl] = unique[i];
            indexPl++;
        }
        for(int j = 0; j < save.bot[i]; j++) {
            game.bHand[indexCp] = unique[i];
            indexCp++;
        }
        if(unique[i]->color == save.lastPl.color && unique[i]->name == save.lastPl.name) {
            game.lastPl = unique[i];
        }
        if(unique[i]->color == save.rest.color && unique[i]->name == save.rest.name) {
            game.rest = unique[i];
        }
    }
    for(int i = 0; i < colorS; i++) {
        if(colors[i]->color == save.rest.color && colors[i]->name == save.rest.name) {
            game.rest = colors[i];
        }
    }
    return unique;
}

void createSave(Game &game, GameS &save, Card **unique) {
    save.plScore = game.plScore;
    save.cpScore = game.cpScore;
    save.bHandS = game.bHandS;
    save.handS = game.handS;
    save.drwSize = game.drwSize;
    save.turn = game.turn;
    save.lastPl.color = game.lastPl->color;
    save.lastPl.name  = game.lastPl->name;
    save.rest.color = game.rest->color;
    save.rest.name  = game.rest->name;
    for (int i = 0; i < 54; i++) {
        save.draw[i] = 0;
        save.play[i] = 0;
        save.bot[i]  = 0;
        save.cards[i].color = unique[i]->color;
        save.cards[i].name = unique[i]->name;
        for(int j = 0; j < game.drwSize; j++) {
            if((game.drwPile[j]->color == unique[i]->color) && (game.drwPile[j]->name == unique[i]->name)) {
                save.draw[i]++;
            }
        }
        for(int j = 0; j < game.handS; j++) {
            if((game.hand[j]->color == unique[i]->color) && (game.hand[j]->name == unique[i]->name)) {
                save.play[i]++;
            }
        }
        for(int j = 0; j < game.bHandS; j++) {
            if((game.bHand[j]->color == unique[i]->color) && (game.bHand[j]->name == unique[i]->name)) {
                save.bot[i]++;
            }
        }
    }
}