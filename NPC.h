#ifndef NPC_H
#define NPC_H
#include <string>
#include <vector>

class NPC{
    public:
    //Constructor
    NPC(std::string name, std::string description);

    // Getters
    std::string getName() const;
    std::string getDescription() const;
    std::string getMessage(int messageNumber);

    //Setters
    void addMessage(std::string message);

    //Functions
    void printNPC(NPC npc);

    private:
    std::string name;
    std::string description;
    int messageNumber;
    std::vector<std::string> messages;

};

#endif