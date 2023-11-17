#ifndef Location_H
#define Location_H
#include "NPC.h"
#include "Item.h"
#include <string>
#include <functional>
#include <vector>
#include <map>

class Location{
    public:
    //Constructor
    Location(std::string name, std::string description);

    //Getters
    std::string getName() const;
    std::string getDescription() const;

    //Functions 
    std::map<std::string, std::reference_wrapper<Location> > getLocations() const;
    void addLocation(std::string direction, Location& location);
    void addNpc(NPC npc);
    std::vector<NPC> getNpc() const;
    void addItem(Item item);
    std::vector<Item> getItems() const;
    void setVisited();
    bool getVisited() const;
    void printLocation(Location& location);

    private:
    std::string name;
    std::string description;
    bool isVisited;
    std::map<std::string, std::reference_wrapper<Location> > locations;
    std::vector<NPC> npcs;
    std::vector<Item> items;
};


#endif