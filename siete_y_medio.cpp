//
//  main.cpp
//  AssignmentOne
//
//  Created by Benjamin Dang on 1/27/17.
//  Copyright © 2017 Benjamin Dang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "cards.h"

int main() {
    std::ofstream outputLog("gamelog.txt");
    Player user(100);
    bool play = true;
    while(play){
        Hand hand_player;
        Hand hand_dealer;
        int bet_amount;
        std::cout << "You have $" << user.get_money() << std::endl;
        std::cout << "Please enter your bet amount(must be a whole numer): ";
        std::cin >> bet_amount;
        if(bet_amount > user.get_money()){
            std::cout << "Please enter a bet amount less than your current money: ";
            std::cin >> bet_amount;
        }
        bool draw = true;
        while(draw){
            std::string another_card;
            Card card;
            hand_player.add_card(card);
            std::cout << "Your cards:" << std::endl;
            hand_player.print_cards();
            std::cout << "Your total is " << hand_player.get_total() << ". Do you want another card? (Enter Y or N): ";
            std::cin >> another_card;
            if(another_card == "N")
                draw = false;
        }
        bool winner = false;
        while(!winner){
            Card card;
            hand_dealer.add_card(card);
            std::cout << "Dealer's cards:" << std::endl;
            hand_dealer.print_cards();
            std::cout << "The dealer's total is " << hand_dealer.get_total() << "." << std::endl;
            if(hand_dealer.get_total() > hand_player.get_total() && hand_dealer.get_total() <= 7.5){
                std::cout << "Too bad. You lose " << bet_amount << "." << std::endl;
                user.change_money(bet_amount * -1);
                winner = true;
            }
            else if(hand_dealer.get_total() == 7.5 && hand_player.get_total() == 7.5){
                std::cout << "Tied! Bet is returned. " << std::endl;
                winner = true;
            }
            else if(hand_dealer.get_total() > 7.5){
                std::cout << "You win " << bet_amount << "." << std::endl;
                user.change_money(bet_amount);
                winner = true;
            }
        }
        if(user.get_money() == 0){
            std::cout << "You have $0. GAME OVER!" << std::endl << "Come back when you have more money." << std::endl << std::endl << "Bye!" << std::endl;
            play = false;
        }
        
        if(user.get_money() >= 1000){
            std::cout << "Congratulations. You beat the casino!" << std::endl << std::endl << "Bye!" << std::endl;
        }
    }
    
    
    
    
    
    
    
    
    
    return 0;
}
