#include "Array.hpp"
#include <sstream>  // Nécessaire pour convertir int en string en C++98

int main()
{
    std::cout << "===== Test tableau d'entiers =====" << std::endl;
    Array<int> intArray(5);
    
    // Initialisation du tableau d'entiers
    for (unsigned int i = 0; i < intArray.size(); i++)
        intArray[i] = i * 10;

    // Affichage
    for (unsigned int i = 0; i < intArray.size(); i++)
        std::cout << "intArray[" << i << "] = " << intArray[i] << std::endl;

    std::cout << "\n===== Test tableau de strings =====" << std::endl;
    Array<std::string> stringArray(3);
    
    // Initialisation du tableau de strings (sans `std::to_string()`)
    for (unsigned int i = 0; i < stringArray.size(); i++)
    {
        std::stringstream ss;
        ss << i;
        stringArray[i] = "string" + ss.str();
    }

    // Affichage
    for (unsigned int i = 0; i < stringArray.size(); i++)
        std::cout << "stringArray[" << i << "] = " << stringArray[i] << std::endl;

    std::cout << "\n===== Test accès hors limites =====" << std::endl;
    try
    {
        std::cout << intArray[10] << std::endl;  // Devrait lancer une exception
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception attrapée: " << e.what() << std::endl;
    }

    std::cout << "\n===== Test de la copie =====" << std::endl;
    Array<int> copyArray = intArray;  // Test du constructeur de copie

    copyArray[0] = 99;  // Modifie la copie, pas l'original

    std::cout << "Original intArray[0]: " << intArray[0] << std::endl;
    std::cout << "Copy intArray[0]: " << copyArray[0] << std::endl;

    return 0;
}
