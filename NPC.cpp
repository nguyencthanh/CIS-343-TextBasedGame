#include "NPC.h"
#include <string>
#include <iostream>

//Constuctor
NPC::NPC(std::string name, std::string description){
    this->name = name;
    this->description = description;
    this->messageNumber = 0;
}

//Getters
std::string NPC::getName() const {
    return name;
}

std::string NPC::getDescription() const {
    return description;
}

std::string NPC::getMessage(int messageNumber){
    int size = messages.size();
    std::string message;

    if(messageNumber <= size){
        message = messages[messageNumber];
        if(messageNumber == size){
            this->messageNumber = 0;
        }
        else{
            this->messageNumber = messageNumber + 1;
        }
    }
    return message;
}

//Setters
void NPC::addMessage(std::string message){
    this->messages.push_back(message);
}

//Functions
void NPC::printNPC(NPC npc){
    std::cout << npc.getName() << std::endl;
}