#ifndef GAME_H
#define GAME_H
#include "Location.h"
#include "Item.h"
#include <string>
#include <map>

class Game{
    public:
    //Constructor
    Game(){
        currentWeight = 0;
        totalCalories = 0;
        gameStatus = true;
    }

    //Getters
    int getCurrentWeight();
    int getTotalCalories();
    bool getGameStatus();
    std::vector<Item> getCurrentItems();
    Location getCurrentLocation();

    //Setters
    void setGameStatus(bool gameSetter);
    void setCurrentLocations(Location location);
    void setTotalLocations(Location location);

    //Functions
    void setup_commands();
    void create_world(Game game);
    void addMessages();
    Location Game::randomLocations();

private:
    std::map<std::string, std::vector<std::string>> commandsMap;
    std::vector<Item> currentItems;
    std::vector<Location> totalLocations;
    int currentWeight;
    Location currentLocation;
    int totalCalories;
    bool gameStatus;
};

#endif