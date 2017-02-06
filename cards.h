//
//  SieteyMedio.h
//  AssignmentOne
//
//  Created by Benjamin Dang on 1/28/17.
//  Copyright © 2017 Benjamin Dang. All rights reserved.
//

#include <string>
#include <vector>
#include <fstream>

#ifndef cards_h
#define cards_h

enum suit_t {OROS, COPAS, ESPADAS, BASTOS};
enum rank_t {AS, DOS, TRES, CUATRO, CINCO, SEIS, SIETE, SOTA = 9, CABALLO = 10, REY = 11};

class Card{
public:
    Card();
    std::string get_spanish_suit() const;
    std::string get_spanish_rank() const;
    std::string get_english_suit() const;
    std::string get_english_rank() const;
    double get_value();
private:
    suit_t suit;
    rank_t rank;
    
};

class Hand{
public:
    void add_card(Card randomCard);
private:
    std::vector<Card> hand;
    double total;
};

class Player{
public:
    Player(int m);
    void change_money(int m);
private:
    int money;
};
#endif
