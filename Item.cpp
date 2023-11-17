#include "Item.h"
#include <string>
#include <iostream>

//Constructor
Item::Item(std::string name, std::string description, int calories, float weight){
    this->name = name;
    this->description = description;
    this->calories = calories;
    this->weight = weight;
}

//Setters
void Item::setName(std::string name){
    this->name = name;
}

void Item::setDescription(std::string description){
    this->description = description;
}

void Item::setCalories(int calories){
    this->calories = calories;
}

void Item::setWeight(float weight){
    this->weight = weight;
}

//Getters
std::string Item::getName() const {
    return name;
}

std::string Item::getDescription() const {
    return description;
}

int Item::getCalories() const {
    return calories;
}

float Item::getWeight() const {
    return weight;
}

void Item::printItem(Item item){
    std::cout << item.getName() << " (" << item.getCalories() << ") " 
        << "- " << item.getWeight() << " - " << item.getDescription() << std::endl;
}