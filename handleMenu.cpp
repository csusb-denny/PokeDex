//
// Created by Denny on 11/20/24.
//
#include "handleMenu.h"
#include <iostream>
#include <string>

void handleMenu(Pokedex& pokedex) {
    int choice;

    do {
        // Display the menu
        std::cout << "Pokedex Menu:\n"
                  << "1. Add Pokémon\n"
                  << "2. Remove Pokémon\n"
                  << "3. Search Pokémon by Name\n"
                  << "4. Search Pokémon by Type\n"
                  << "5. Search Pokémon by Location\n"
                  << "6. Search Pokémon by Kind\n"
                  << "7. Filter Pokémon by Type\n"
                  << "8. Filter Pokémon by Location\n"
                  << "9. Display All Pokémon\n"
                  << "10. Exit\n"
                  << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::string name, type, location, kind;
                std::cout << "Enter Pokémon name: ";
                std::cin.ignore();
                std::getline(std::cin, name);
                std::cout << "Enter element type: ";
                std::getline(std::cin, type);
                std::cout << "Enter location: ";
                std::getline(std::cin, location);
                std::cout << "Enter kind: ";
                std::getline(std::cin, kind);
                pokedex.addPokemon(Pokemon(name, type, location, kind));
                break;
            }
            case 2: {
                std::string name;
                std::cout << "Enter Pokémon name to remove: ";
                std::cin.ignore();
                std::getline(std::cin, name);
                if (pokedex.removePokemon(name)) {
                    std::cout << name << " removed successfully.\n";
                } else {
                    std::cout << "Pokémon not found.\n";
                }
                break;
            }
            case 3: {
                std::string name;
                std::cout << "Enter Pokémon name to search: ";
                std::cin.ignore();
                std::getline(std::cin, name);
                Pokemon* found = pokedex.searchByName(name);
                if (found) {
                    found->displayInfo();
                } else {
                    std::cout << "Pokémon not found.\n";
                }
                break;
            }
            case 4: {
                std::string type;
                std::cout << "Enter Pokémon type to search: ";
                std::cin.ignore();
                std::getline(std::cin, type);
                pokedex.searchByType(type);
                break;
            }
            case 5: {
                std::string location;
                std::cout << "Enter location to search: ";
                std::cin.ignore();
                std::getline(std::cin, location);
                pokedex.searchByLocation(location);
                break;
            }
            case 6: {
                std::string kind;
                std::cout << "Enter Pokémon kind to search: ";
                std::cin.ignore();
                std::getline(std::cin, kind);
                pokedex.searchByKind(kind);
                break;
            }
            case 7: {
                std::string type;
                std::cout << "Enter type to filter: ";
                std::cin.ignore();
                std::getline(std::cin, type);
                pokedex.filterByType(type);
                break;
            }
            case 8: {
                std::string location;
                std::cout << "Enter location to filter: ";
                std::cin.ignore();
                std::getline(std::cin, location);
                pokedex.filterByLocation(location);
                break;
            }
            case 9:
                pokedex.displayAll();
                break;
            case 10:
                std::cout << "Exiting Pokedex. Goodbye!\n";
                break;
            default:
                std::cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 10);
}