// Thanh Nguyen and Hunter Sutton
#include "Item.h"
#include "Game.h"
#include "NPC.h"
#include "Location.h"
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <sstream>
#include <iterator>

//Getters
int Game::getCurrentWeight(){
    return this->currentWeight;
}
int Game::getTotalCalories(){
    return this->totalCalories;
}
bool Game::getGameStatus(){
    return this->gameStatus;
}
std::vector<Item> Game::getCurrentItems(){
    return this->currentItems;
}
Location Game::getCurrentLocation(){
    return this->currentLocation;
}

//Setters
void Game::setGameStatus(bool gameSetter){
    this->gameStatus = gameSetter;
}
void Game::setCurrentLocations(Location location){
    this->currentLocation = location;
}


//Functions
void create_world(Game game){
    //Creating NPCS (5)
    //Creating Kevin Hart
    NPC kevin("Kevin Hart", "A really short actor");
    //Messages are created by ChatGPT
    kevin.addMessage("You know you\'re getting old when you\'re excited about a new sponge. \
        I mean, I got a whole collection now! Sponge game strong, baby!");
    kevin.addMessage("I tried adulting once... worst 5 minutes of my life. Bills, \
        responsibilities, and a broken dishwasher? Nah, I'm good, thanks!");
    kevin.addMessage("Have you ever tried to put fitted sheets on a king-sized bed? \
        It's like wrestling an octopus with a bad attitude. I don't even bother anymore. Just throw 'em on and hope for the best!");

    //Creating The Rock
    //Messages are created by ChatGPT
    NPC rock("The Rock", "A piece of rock");
    rock.addMessage("Just finished leg day at the gym. The weights didn\'t stand a chance. \
        They tried, but I said, \'Not today, weights, not today!\'");
    rock.addMessage("Success isn\'t about the destination; it\'s about the journey and \
        the amount of weight you can deadlift along the way. Lift heavy, dream bigger.");
    rock.addMessage("You know you\'re a beast when your cheat meals have cheat meals. Cheatception!");

    //Creating Justin Bieber
    //Messages are created by ChatGPT
    NPC justin("Justin Bieber", "A singer known for the song Baby");
    justin.addMessage("Life\'s a melody, and we\'re all just trying to find the right chords. \
        Sometimes you hit a few off-notes, but hey, that\'s what remixes are for, right?");
    justin.addMessage("Being real and authentic is the key to making connections. Let\'s all be ourselves \
        and find harmony in our differences. Music, after all, is a beautiful tapestry of voices.");
    justin.addMessage("Life\'s about finding the rhythm that makes your heart beat faster. Mine? \
        It\'s the beat of the music and the love from my fans. Can\'t ask for more.");

    //Creating Taylor Swift
    //Messages are created by ChatGPT
    NPC taylor("Taylor Swift", "A singer known for making songs about her exs");
    taylor.addMessage("Embrace your uniqueness, just like every song has its own tune. \
        You\'re one of a kind, and your melody is what makes the world sing.");
    taylor.addMessage("In a world full of noise, sometimes all you need is the quiet melody \
        of your thoughts. Embrace the silence, and let the lyrics of your dreams write themselves.");
    taylor.addMessage("Life\'s like a concert - sometimes you\'re in the spotlight, and other times \
        you\'re in the shadows. But every performance shapes who you are, and the applause comes from within.");
    
    //Creating Ira Woodring
    //Messages are created by ChatGPT
    NPC ira("Ira Woodring", "A non-famous CS teacher");
    ira.addMessage("ChatGPT\'s attempts at programming are like watching a comedy movie with bad timing. \
        It\'s almost painful, but I can\'t help but laugh.");
    ira.addMessage("ChatGPT keeps trying to predict the next big tech trend. Meanwhile, \
        I\'m here still trying to figure out how to program my coffee maker. Priorities, right?");
    ira.addMessage("I asked ChatGPT to explain recursion. It responded with, \'Recursion is like recursion, \
        but it's like recursion, you know?\' Ah yes, crystal clear. Thanks for the enlightenment.");

    //Creating Locations (8)
    Location MAK("Mackinac Hall", "Freshman and Computer Science");
    Location FH("FIELDHOUSE", "Place to be if your athletic.");
    Location KHS("Kindschi Hall of Science", "Classrooms and Labs for science rellated fields.");
    Location KS("Kirkhof Center", "Many fast food places and hangouts for students.");
    Location CAC("Calder Fine Arts Center", "Art and stuff.");
    Location NMH("Honors College", "Extraordinary opportunities for academically motivated students.");
    Location MAN("Manitou Hall", "General computer lab and lecture halls for many subjects.");
    Location PAD("Padnos Hall of Science", "Classrooms and Labs for science rellated fields.");
    

    //Creating Items (10)
    Item cookie("Cookie", "A baked snack", 5, 1.5);
    Item goldenApple("Golden Apple", "A shiney fruit", 100, 15);
    Item goldenRock("Golden Rock", "The rock", 0, 12);
    Item goldenMicrophone("Golden Microphone", "Taylor or Justin", 0, 8);
    Item cCode("C language Code", "A weird programming code maybe Ira would like it", 0, 1);
    //These 5 were generated by ChatGPT
    Item textbook("Textbook", "An academic book for studying", 0, 15);
    Item laptop("Golden Laptop", "A shining portable computer for academic use", 0, 60);
    Item sandwich("Sandwich", "A quick and filling meal", 500, 2);
    Item salad("Salad", "A healthy option for a meal", 10, 1);
    Item energyDrink("Energy Drink", "Provides a quick energy boost", 50, 0.5);

    //Creating the Items, NPC, and Locations for MAK
    MAK.addNpc(ira);
    MAK.addLocation("east", FH);
    MAK.addLocation("west", KHS);
    MAK.addItem(cookie);
    MAK.addItem(textbook);
    game.setTotalLocations(MAK);

    //Creating the Items, NPC, and Locations for FH
    FH.addNpc(kevin);
    FH.addLocation("west", MAK);
    FH.addItem(cCode);
    FH.addItem(sandwich);
    game.setTotalLocations(FH);

    //Creating the Items, NPC, and Locations for KHS
    KHS.addLocation("east", MAK);
    KHS.addLocation("north", KS);
    KHS.addItem(goldenApple);
    KHS.addItem(laptop);
    game.setTotalLocations(KHS);

    //Creating the Items, NPC and Locations for KS
    KS.addLocation("south", KHS);
    KS.addLocation("north", CAC);
    KS.addLocation("east", NMH);
    KS.addLocation("west", MAN);
    KS.addNpc(justin);
    KS.addItem(goldenRock);
    KS.addItem(salad);
    game.setTotalLocations(KS);

    //Creating the Items, NPC, and Locations for CAC
    CAC.addLocation("south", KS);
    CAC.addLocation("west", PAD);
    CAC.addItem(energyDrink);
    game.setTotalLocations(CAC);

    //Creating the Items, NPC, and Locations for NMH
    NMH.addLocation("west", KS);
    NMH.addItem(goldenMicrophone);
    game.setTotalLocations(NMH);

    //Creating the Items, NPC, and Locations for MAN
    MAN.addLocation("east", KS);
    MAN.addItem(salad);
    MAN.addItem(energyDrink);
    MAN.addNpc(taylor);
    game.setTotalLocations(MAN);

    //Creating the Items, NPC, and Locations for PAD
    PAD.addLocation("east", CAC);
    PAD.addNpc(rock);
    PAD.addItem(cookie);
    game.setTotalLocations(PAD);

}

Location Game::randomLocations() {
    int size = this->totalLocations.size();
    int randomIndex = rand() % size;
    return this->totalLocations[randomIndex];
}

std::map<std::string, void(*)(std::vector<std::string>, Game)> setup_commands(){
    std::map<std::string, void(*)(std::vector<std::string>, Game)> settingCommands;
    settingCommands["talk"] = talk;
    settingCommands["give"] = give;
    settingCommands["?"] = showHelp;
    settingCommands["help"] = showHelp;
    settingCommands["meet"] = meet;
    settingCommands["take"] = take;
    settingCommands["go"] = go;
    settingCommands["show"] = showItems;
    settingCommands["items"] = showItems;
    settingCommands["look"] = look;
    settingCommands["quit"] = quit;
    settingCommands["eat"] = eat;
    settingCommands["dance"] = dance;
    
    return settingCommands;
}


void play(Game game) {
    while (game.getGameStatus()) {
        // Set the current location to a random location
        game.setCurrentLocations(game.randomLocations());

        std::cout << "Welcome to GVZork Game" << std::endl;
        std::cout << "Enter a command (? for help): ";

        std::string input;
        std::getline(std::cin, input);

        // Tokenize the input
        std::istringstream iss(input);
        std::istream_iterator<std::string> start(iss), end;
        std::vector<std::string> tokens(start, end);

        // Check if no tokens were provided
        if (tokens.empty()) {
            std::cout << "Invalid command. Please try again.\n";
            continue;
        }

        std::string mainCommand = tokens[0];

        // Remove the main command from the tokens
        tokens.erase(tokens.begin());

        // Call the appropriate function based on the main command
        std::map<std::string, void(*)(std::vector<std::string>, Game)> commands = setup_commands();
        auto it = commands.find(mainCommand);
        if (it != commands.end()) {
            it->second(tokens, game);
        }
        else {
            std::cout << "Unknown command. Type '?' for help." << std::endl;
        }
    }
}


void talk(std::vector<std::string> target, Game game) {
    const std::vector<NPC>& npcs = game.getCurrentLocation().getNpc();
    bool npcFound = false;

    // Iterate through the target NPCs
    for ( auto targetNpc : target) {
        for (auto npc : npcs) {
            if (targetNpc == npc.getName()) {
                npcFound = true;
                std::cout << "You are talking to " << npc.getName() << ":\n";

                // Print NPC's messages
                
                std::cout << "- " << npc.getMessage(1) << "\n";

                break;  // Stop searching for this target NPC
            }
        }
    }

    if (!npcFound) {
        std::cout << "NPC(s) not found in the room." << std::endl;
    }
}

void give(std::vector<std::string> target, Game game) {
    const std::vector<NPC>& npcs = game.getCurrentLocation().getNpc();
    bool npcFound = false;

    // Iterate through the target NPCs
    for (const auto& targetNpc : target) {
        for (const auto& npc : npcs) {
            if (targetNpc == npc.getName()) {
                npcFound = true;

                // Perform giving action here (e.g., increase NPC's satisfaction or modify game state)

                std::cout << "You gave an item to " << npc.getName() << ".\n";
                // Modify game state or perform any actions related to giving

                break;  // Stop searching for this target NPC
            }
        }
    }

    if (!npcFound) {
        std::cout << "NPC(s) not found in the room." << std::endl;
    }
}

void meet(std::vector<std::string> target, Game game) {
    const std::vector<NPC>& npcs = game.getCurrentLocation().getNpc();
    bool npcFound = false;

    // Iterate through the target NPCs
    for (const auto& targetNpc : target) {
        for (const auto& npc : npcs) {
            if (targetNpc == npc.getName()) {
                npcFound = true;

                // Perform meeting action here (e.g., start a conversation or perform a specific action)

                std::cout << "You meet " << npc.getName() << npc.getDescription() << ".\n";
                // Modify game state or perform any actions related to meeting

                break;  // Stop searching for this target NPC
            }
        }
    }

    if (!npcFound) {
        std::cout << "NPC(s) not found in the room." << std::endl;
    }
}

void take(std::vector<std::string> target, Game game) {
    const std::vector<Item>& items = game.getCurrentLocation().getItems();
    bool itemFound = false;

    // Iterate through the target items
    for (const auto& targetItem : target) {
        for (const auto& item : items) {
            if (targetItem == item.getName()) {
                itemFound = true;

                // Perform the action to take the item (e.g., add it to the player's inventory)
                // Modify game state or perform any actions related to taking the item
                std::cout << "You took " << item.getName() << ".\n";
                // Remove the item from the current location or handle it according to your game logic

                break;  // Stop searching for this target item
            }
        }
    }

    if (!itemFound) {
        std::cout << "Item(s) not found in the room." << std::endl;
    }
}

void go(std::vector<std::string> target, Game game) {
    if (target.empty()) {
        std::cout << "Please specify a location to go to." << std::endl;
        return;
    }

    std::string locationName = target[0];

    // Check if the specified location is a valid location in the current location's connections
    Location currentLocation = game.getCurrentLocation();
    std::map<std::string, std::reference_wrapper<Location> > connections = currentLocation.getLocations();

    auto it = connections.find(locationName);
    if (it != connections.end()) {
        // Valid location, update the current location
        game.setCurrentLocations(it->second);
        std::cout << "You have moved to " << locationName << "." << std::endl;
        currentLocation.setVisited();
    } else {
        std::cout << "Location " << locationName << " is unreachable from here." << std::endl;
    }
}


void showItems(std::vector<std::string> target, Game game){
    std::vector<Item> currItems = game.getCurrentItems();
    std::cout << "Your Items:" << std::endl;
    
    for(auto i = currItems.begin(); i != currItems.end(); ++i){
        std::cout << i->getName() << std::endl;
    }
}

void look(std::vector<std::string> target, Game game){
    // Assuming target is the direction to look (e.g., "north", "south", "east", "west")
    // Here, we are simply printing the description of the current location.
    std::string direction = target.empty() ? "around" : target[0];

    std::cout << "You look " << direction << " and see:\n";
    std::cout << game.getCurrentLocation().getDescription() << std::endl;
}

void eat(std::vector<std::string> target, Game game){
    // Assuming the target is the item the user wants to eat
    std::string itemToEat = target.empty() ? "" : target[0];

    // Get the current items in the game
    std::vector<Item> currItems = game.getCurrentItems();

    // Check if the item to eat is in the current items
    bool itemFound = false;
    for(const auto& item : currItems) {
        if (item.getName() == itemToEat) {
            std::cout << "You eat " << item.getName() << ". It has " << item.getCalories() << " calories." << std::endl;
            itemFound = true;
            break;
        }
    }

    if (!itemFound)
        std::cout << "The item is not edible or not in the room." << std::endl;
}

void dance(std::vector<std::string> target, Game game){
    std::cout << "I'm dancing" << std::endl;
    std::cout << "But you can't see me" << std::endl;
    std::cout << "You have broken your leg" << std::endl;
    std::cout << "Game over" << std::endl;
    exit(1);
}

void showHelp(std::vector<std::string> target, Game game){
    std::cout << "=== Help ===\n";
    std::cout << "Available commands:\n";

    // print out all the commands
    std::cout << "talk <NPC>\t\t- Talk to the specified NPC" << std::endl;
    std::cout << "give <NPC> <item>\t- Give an item to the specified NPC" << std::endl;
    std::cout << "meet <NPC>\t\t- Meet the specified NPC" << std::endl;
    std::cout << "take <item>\t\t- Take the specified item" << std::endl;
    std::cout << "go <location>\t\t- Go to the specified location" << std::endl;
    std::cout << "show items\t\t- Show your items" << std::endl;
    std::cout << "look\t\t\t- Look around the current location" << std::endl;
    std::cout << "quit\t\t\t- Quit the game" << std::endl;
    std::cout << "help\t\t\t- Show this help message" << std::endl;
    std::cout << "eat <item>\t\t- Eat the specified item" << std::endl;
    std::cout << "dance\t\t\t- Dance (ends the game)" << std::endl;
    std::cout << "?\t\t\t- Show help" << std::endl;


    std::time_t now = std::time(nullptr);
    std::tm* current_time = std::localtime(&now);

    char time_buffer[80];
    strftime(time_buffer, 80, "%Y-%m-%d %H:%M:%S", current_time);
    std::cout << "\nCurrent time: " << time_buffer << "\n";
}

void quit(std::vector<std::string> target, Game game){
    std::cout << "Game over!\n";
    exit(1);
}

int main(){
    Game g;
    create_world(g);
    play(g);
}