//
// Created by Denny on 11/20/24.
//


#include "Pokedex.h"
#include <iostream>
#include <algorithm>
#include <cctype>
#include <fstream>
#include <sstream>

// Add a Pokémon to the Pokedex ****DANIEL******
void Pokedex::addPokemon(const Pokemon& pokemon) {
        // Open the file
    std::ofstream file("PokemonList.txt", std::ios::app);
    
    // Will store information on a new line
    file << "\n" 
         << pokemon.getName() << "," 
         << pokemon.getType() << "," 
         << pokemon.getLocation() << "," 
         << pokemon.getKind() << "";
        
    file.close();
}

// Remove a Pokémon by name *******DANIEL********
bool Pokedex::removePokemon(const std::string& name) {
    // Will open the file
    std::ifstream inputFile("PokemonList.txt");
    std::vector<std::string> lines;
    std::string line;
    bool found = false;

    while (std::getline(inputFile, line)) {
        // Check if the line has the name of the Pokemon
        if (line.find(name) == std::string::npos) {
            lines.push_back(line); 
        } 
        else {
            found = true;
        }
    }

    inputFile.close();

    // Will return false if the pokemon wasn't found
    if (!found) {
    return false;
    }

    // Will rewrite the lines back into the file
    std::ofstream outputFile("PokemonList.txt", std::ios::trunc);

    for (size_t i = 0; i < lines.size(); ++i) {
        outputFile << lines[i];
        if (i < lines.size() - 1) {
            outputFile << std::endl;
        }
    }

    outputFile.close();
    return true;
}

// Search Pokémon by name  by ******OMAR******
Pokemon* Pokedex::searchByName(const std::string& name) {
    // convert the pokemon name lower case
    std::string searchName = name;
    std::transform(searchName.begin(), searchName.end(), searchName.begin(), [](unsigned char c) {
        return std::tolower(c);
    });

    for (auto& pokemon : pokemons) {
        //Convert Pokémon's name to lowercase
        std::string pokemonName = pokemon.getName();
        std::transform(pokemonName.begin(), pokemonName.end(), pokemonName.begin(), [](unsigned char c) {
            return std::tolower(c);
        });
        //Compare names in lowercase
        if (pokemonName == searchName) {
            return &pokemon;   // return a pointer to the found pokemon
        }
    }
    std::cout << "Invalid pokemon name.\n"; // no name matches are found
    return nullptr;
}

// Search Pokémon by type  *****OMAR******
void Pokedex::searchByType(const std::string& type) const {
    // convert the pokemon type to lower case
    std::string searchType = type;
    std::transform(searchType.begin(), searchType.end(), searchType.begin(), [](unsigned char c) {
        return std::tolower(c);
    });

    bool found = false; // to track if any matches are found

    for (const auto& pokemon : pokemons) {
        //Convert Pokémon's type to lowercase
        std::string pokemonType = pokemon.getType();
        std::transform(pokemonType.begin(), pokemonType.end(), pokemonType.begin(), [](unsigned char c) {
            return std::tolower(c);
        });

        //Compare types in lowercase
        if (pokemonType == searchType) {
            pokemon.displayInfo(); // Display Pokémon type details
            std::cout << "----------------------------\n";
            found = true;
        }
    }
    //if no pokemon type is found 
    if (!found) {
        std::cout << "No Pokémon type: " << type << " found. \n";
    }
}

// Search Pokémon by location   ****OMAR*****
void Pokedex::searchByLocation(const std::string& location) const {
    // convert the input location to lower case
    std::string searchLocation = location;
    std::transform(searchLocation.begin(), searchLocation.end(), searchLocation.begin(), [](unsigned char c) {
        return std::tolower(c);
    });

    bool found = false; // to track if any matches are found

    for (const auto& pokemon : pokemons) {
        //Convert Pokémon's location to lowercase
        std::string pokemonLocation = pokemon.getLocation();
        std::transform(pokemonLocation.begin(), pokemonLocation.end(), pokemonLocation.begin(), [](unsigned char c) {
            return std::tolower(c);
        });

        //Compare locations in lowercase
        if (pokemonLocation == searchLocation) {
            pokemon.displayInfo(); // Display Pokémon type details
            std::cout << "----------------------------\n";
            found = true;
        }
    }
    //if no pokemon location is found 
    if (!found) {
        std::cout << "No Pokémon found in: " << location << ". \n";
    }  
}

// Search Pokémon by kind   *****DENNY******
void Pokedex::searchByKind(const std::string& kind) const {
    bool found = false; // Track if any matches are found

    //Convert user input to lowercase
    std::string searchKind = kind;
    std::transform(searchKind.begin(), searchKind.end(), searchKind.begin(), [](unsigned char c) {
        return std::tolower(c);
    });

    for (const auto& pokemon : pokemons) {
        //Convert Pokémon's kind to lowercase
        std::string pokemonKind = pokemon.getKind();
        std::transform(pokemonKind.begin(), pokemonKind.end(), pokemonKind.begin(), [](unsigned char c) {
            return std::tolower(c);
        });

        //Compare in lowercase
        if (pokemonKind == searchKind) {
            pokemon.displayInfo(); //Display Pokémon details
            std::cout << "------------\n";
            found = true;
        }
    }

    if (!found) {
        std::cout << "Invalid Kind\n"; // no matches are found
        return;
    }
}

// Display all Pokémon *****DANIEL******
void Pokedex::displayAll() const {
    // File is opened
    std::ifstream file("PokemonList.txt");

    // Displays the text
    std::string line;
    while (std::getline(file, line)) {
        if (!line.empty()) {
            std::cout << line << std::endl;
        }
    }

    file.close();
}
//**DENNY***
void Pokedex::loadPokemonFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if(!file.is_open()) {
        std::cout << "File unable to open";
        return;
    }
    std::string line;
    while(std::getline(file, line)) {
        //        std::cout << "Line Load: " << line << std::endl;              //debugging purposes

        std::stringstream ss(line);
        std::string name, type, location, kind;

        std::getline(ss, name, ',');
        std::getline(ss, type, ',');
        std::getline(ss, location, ',');
        std::getline(ss, kind);
        Pokemon pokemon(name, type, location, kind);
        pokemons.emplace_back(name, type, location, kind);
        pokemon.displayInfo();
        std::cout << "-------";
    }
    file.close();


}
