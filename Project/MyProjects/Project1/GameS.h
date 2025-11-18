/* 
 * File:   GameS.h
 * Author: Matthew Madrigal
 * Purpose:  This structure is used to save the game state to a file
 */

#ifndef GAMES_H
#define GAMES_H

#include "Card.h"

struct GameS{
    bool turn;      // True is for the player, false is for the computer
    int plScore;    // The score for the player
    int cpScore;    // The score for the computer
    int drwSize;    // Size of draw pile array
    int handS;      // The size of the array of the cards the player currently has
    int bHandS;     // The size of the array of the cards the computer currently has
    Card rest;
    Card lastPl;
    Card cards[54];
    int draw[54];
    int play[54];
    int bot[54];
};

#endif /* Game_S_H */