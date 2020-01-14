/************************************************************************************
* Author: Moritz Makowski
* Lecture: MSE Informatik I - WS19/20
* Session: Tutorial 10
************************************************************************************/


#include "../car_dealer.h"




/* Dealer Initialization/Manipulation -------------------------------------------- */

struct Dealer *init_dealer(int account_balance) {
    // YOUR CODE HERE
    return 0;
}

void add_car(struct Dealer *dealer, char brand[20], char model[20], int price) {
    // YOUR CODE HERE
}

void remove_car(struct Dealer *dealer, struct Car *car) {
    // YOUR CODE HERE
}




/* Dealer Analysis --------------------------------------------------------------- */

int car_count(struct Dealer *dealer) {
    // YOUR CODE HERE
    return 0;
}

int total_dealer_value(struct Dealer *dealer) {
    // YOUR CODE HERE
    return 0;
}

int mean_car_price(struct Dealer *dealer) {
    // YOUR CODE HERE
    return 0;
}




/* Customer Initialization ------------------------------------------------------- */

struct Customer *init_customer(int account_balance, char desired_brand[20], char desired_model[20]) {
    // YOUR CODE HERE
    return 0;
}




/* Customer-Dealer Analysis ------------------------------------------------------ */

int customer_car_rating(struct Customer *customer, struct Car *car) {
    // YOUR CODE HERE
    return 0;
}

int car_available(struct Dealer *dealer, struct Customer *customer) {
    // YOUR CODE HERE
    return 0;
}

int buy_car(struct Dealer *dealer, struct Customer *customer) {
    // YOUR CODE HERE
    return 0;
}




/* Printing functions ------------------------------------------------------------ */

void print_car(struct Car *car) {
    // YOUR CODE HERE
}

void print_dealer(struct Dealer *dealer) {
    // YOUR CODE HERE
}

void print_customer(struct Customer *customer) {
    // YOUR CODE HERE
}




/* Memory Deallocation Functions ------------------------------------------------- */

void free_dealer(struct Dealer *dealer) {
    // YOUR CODE HERE
}

void free_customer(struct Customer *customer) {
    // YOUR CODE HERE
}
