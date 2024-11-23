//
// Created by Denny on 11/20/24.
//

#ifndef POKEMON_H
#define POKEMON_H
#include <iostream>
#include <string>

class Pokemon {

public:
    // Attributes
    std::string name;
    std::string elementType;
    std::string location;
    std::string kind;

    // Constructor
    Pokemon(const std::string& name, const std::string& type, const std::string& location, const std::string& kind);
    // Getters
    std::string getName() const {
        return name;
    }
    std::string getType() const {
        return elementType;
    }
    std::string getLocation() const {
        return location;
    }
    std::string getKind() const {
        return kind;
    }
    // Display information
    void displayInfo() const;
};

#endif // POKEMON_H
