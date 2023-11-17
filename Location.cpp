#include "Location.h"
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <functional>

//Constuctor
Location::Location(std::string name, std::string description){
    this->name = name;
    this->description = description;
}

//Getters
std::string Location::getName() const {
    return name;
}

std::string Location::getDescription()const {
    return description;
}

//Functions
std::map<std::string, std::reference_wrapper<Location> > Location::getLocations() const{
    return locations;
}

void Location::addLocation(std::string direction, Location& location){
    if(direction.empty()){
        throw std::invalid_argument( "Need Direction" );
    }
    if(this->locations.find(direction) == this->locations.end()){
        throw std::invalid_argument("Already exist");
    }
    this->locations.emplace(direction, location);
    
}

void Location::addNpc(NPC npc){
    this->npcs.push_back(npc);
}

std::vector<NPC> Location::getNpc() const {
    return npcs;
}

void Location::addItem(Item item){
    items.push_back(item);
}

std::vector<Item> Location::getItems() const {
    return items;
}

void Location::setVisited(){
    this->isVisited = true;
}

bool Location::getVisited() const {
    return isVisited;
}

void Location::printLocation(Location& location){
    std::vector<NPC> locationsNPC = location.getNpc();
    std::vector<Item> locationsItem = location.getItems();
    std::map<std::string, std::reference_wrapper<Location> > locationsLocat = location.getLocations();

    std::cout << location.getName() << " - " << location.getDescription() << "." << std::endl;
    std::cout << " " << std::endl;
    std::cout << "You will see the following NPC:" << std::endl;
    
    for(auto i = locationsNPC.begin(); i != locationsNPC.end(); ++i){
        std::cout << i->getName() << std::endl;
    }

    std::cout << " " << std::endl;
    std::cout << "You will the following Items:" << std::endl;
    
    for(auto j = locationsItem.begin(); j != locationsItem.end(); ++j){
        std::cout << j->getName() << " (" << j->getCalories() << ") " << " - " << j-> getWeight() \
            << " pounds" << " - " << j->getDescription() << "." << std::endl;

    std::cout << " " << std::endl;
    std::cout << "You can go in the following Directions:" << std::endl;

    for(auto k = locationsLocat.begin(); k != locationsLocat.end(); ++k){
        std::cout << " - " << k->first << std::endl;
    }
    }
}

/*
Map:
std::map <std::string, Item> items; //To create a map
items["rusty sword"] = Item("Rusty"); //To add element to map
std::cout << items["rusty sword"] << std::endl; //To print a map
*/