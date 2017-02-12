# AssignmentOne

## Description
This program implements the spanish version of Blackjack, Siete y Medio. Utilizing three classes, called card, hand, and player, the program allows a user to fully play the game, including betting amounts of money of their choice(fake of course!). Please read below a description of the functionality of each class.

## Functions

### Card Class:
The card class is designed so that each object represents individual cards of a random suit and number. The class has a default constructor that initializes and creates the card object with these random attributes. Furthermore, the only further functionality of the class are several accessor functions that return the member variable values of the class.

### Hand Class:
The Hand class is designed to keep track of two things, the cards the player has in their hand and the total amount of points that the cards add up to. As such, it has a vector of cards as one of its private variables and a double as the other. Functions for the class include adding a card to the vector, accessing the private double variable, and printing out each of the cards by rank and suit.

### Player Class:
The Player class only functionality is to keep track of the players money. As such, its only private member variable is an int that represents the amount of money the player has, and its only functions are a function to change this value, and an accessor to return this value.
