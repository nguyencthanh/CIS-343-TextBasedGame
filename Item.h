#ifndef Item_H
#define Item_H
#include <string>

class Item{
    public:
    //Constructor
    //if calories = 0 then it is not edible
    Item(std::string name, std::string description, int calories, float weight);

    //Setters
    void setName(std::string name);
    void setDescription(std::string description);
    void setCalories(int calories);
    void setWeight(float weight);

    //Getters
    std::string getName() const;
    std::string getDescription() const;
    int getCalories() const;
    float getWeight() const;

    //Functions
    void printItem(Item item);

private:
    std::string name;
    std::string description;
    int calories;
    float weight;
};

#endif 
