//
//  cards.cpp
//  AssignmentOne
//
//  Created by Benjamin Dang on 1/28/17.
//  Copyright © 2017 Benjamin Dang. All rights reserved.
//

#include "cards.h"
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <fstream>
#include <ctime>

Card::Card(){
    int r = 1 + rand() % 4;//error fixed by classmate
    switch(r){
        case 1: suit = OROS; break;
        case 2: suit = COPAS; break;
        case 3: suit = ESPADAS; break;
        case 4: suit = BASTOS; break;
    }
    
    r = 1 + rand() % 10;
    switch(r){
        case 1: rank = AS; break;
        case 2: rank = DOS; break;
        case 3: rank = TRES; break;
        case 4: rank = CUATRO; break;
        case 5: rank = CINCO; break;
        case 6: rank = SEIS; break;
        case 7: rank = SIETE; break;
        case 8: rank = SOTA; break;
        case 9: rank = CABALLO; break;
        case 10: rank = REY; break;
        defualt: break;
    }
}

std::string Card::get_spanish_suit() const{
    std::string suitName;
    switch (suit) {
        case OROS:
            suitName = "oros";
            break;
        case COPAS:
            suitName = "copas";
            break;
        case ESPADAS:
            suitName = "espadas";
            break;
        case BASTOS:
            suitName = "bastos";
            break;
        default: break;
    }
    return suitName;
}

std::string Card::get_spanish_rank() const{
    std::string rankName;
    switch(rank){
        case AS:
            rankName = "As";
            break;
        case DOS:
            rankName = "Dos";
            break;
        case TRES:
            rankName = "Tres";
            break;
        case CUATRO:
            rankName = "Cuatro";
            break;
        case CINCO:
            rankName = "Cinco";
            break;
        case SEIS:
            rankName = "Seis";
            break;
        case SIETE:
            rankName = "Siete";
            break;
        case SOTA:
            rankName = "Sota";
            break;
        case CABALLO:
            rankName = "Caballo";
            break;
        case REY:
            rankName = "Rey";
            break;
        default: break;
    }
    return rankName;
}

std::string Card::get_english_suit() const{
    std::string suitName;
    switch (suit) {
        case OROS:
            suitName = "golds";
            break;
        case COPAS:
            suitName = "cups";
            break;
        case ESPADAS:
            suitName = "swords";
            break;
        case BASTOS:
            suitName = "clubs";
            break;
        default: break;
    }
    return suitName;
}

std::string Card::get_english_rank() const{
    std::string rankName;
    switch(rank){
        case AS:
            rankName = "One";
            break;
        case DOS:
            rankName = "Two";
            break;
        case TRES:
            rankName = "Three";
            break;
        case CUATRO:
            rankName = "Four";
            break;
        case CINCO:
            rankName = "Five";
            break;
        case SEIS:
            rankName = "Six";
            break;
        case SIETE:
            rankName = "Seven";
            break;
        case SOTA:
            rankName = "Ten";
            break;
        case CABALLO:
            rankName = "Eleven";
            break;
        case REY:
            rankName = "Twelve";
            break;
        default: break;
    }
    return rankName;
}

double Card::get_value(){
    double value;
    switch(rank){
        case AS:
            value = 1;
            break;
        case DOS:
            value = 2;
            break;
        case TRES:
            value = 3;
            break;
        case CUATRO:
            value = 4;
            break;
        case CINCO:
            value = 5;
            break;
        case SEIS:
            value = 6;
            break;
        case SIETE:
            value = 7;
            break;
        case SOTA:
            value = 0.5;
            break;
        case CABALLO:
            value = 0.5;
            break;
        case REY:
            value = 0.5;
            break;
        default: break;
    }
    return value;
}

Hand::Hand(){
    total = 0;
}
void Hand::add_card(Card randomCard){
    hand.push_back(randomCard);
    total+= randomCard.get_value();
}

double Hand::get_total() const{
    return total;
}

void Hand::print_cards() const{
    for(int i = 0; i < hand.size(); i++){
        std::cout<< "    " << hand[i].get_spanish_rank() << " de " << hand[i].get_spanish_suit() << " (" << hand[i].get_english_rank() << " " << hand[i].get_english_suit() << ")." << std::endl;
    }
}


Player::Player(int m){
    money = m;
}

void Player::change_money(int m){
    money += m;
}

int Player::get_money(){
    return money;
}
