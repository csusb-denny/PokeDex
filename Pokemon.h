//
// Created by Denny on 11/20/24.
//

#ifndef POKEMON_H
#define POKEMON_H

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

    // Display information
    void displayInfo() const;
};

#endif // POKEMON_H
