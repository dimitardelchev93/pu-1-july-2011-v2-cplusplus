#include <iostream>

void enterMovies() {
    std::cout << "Add chosen amount of movies with validation" << std::endl;
}

void listOrderedMovies() {
    std::cout << "Show an ordered list of all the movies" << std::endl;
}

void listDoubleOrderedMovies() {
    char artistCriteria[] = "Robert de Niro";
    std::cout << "Show an ordered (double) list by all the movies with predetermined criteria " << artistCriteria << std::endl;
}

void combinedThreeTimesAndTaxAverages() {
    std::cout << "Do 1 three times, do 2 and 3 based on that and show average tax for each, after that print the highest average tax" << std::endl;
}

void wrongOptionError() {
    std::cout << "Wrong option!" << std::endl;
}

void menu(char option[])
{
    if (option[1] != NULL) {
        wrongOptionError();
        return;
    }

    switch (option[0])
    {
        case '1':
            enterMovies();
            break;
        case '2':
            listOrderedMovies();
            break;
        case '3':
            listDoubleOrderedMovies();
            break;
        case '4':
            combinedThreeTimesAndTaxAverages();
            break;

        default:
            wrongOptionError();
            break;
    }
}

int main()
{
    char option[1];

    do
    {
        std::cout << "Choose an option from 1 to 4" << std::endl << "Enter option: ";
        std::cin >> option;
        menu(option);
    } while (option != 0);

    std::cout << "Good bye!" << std::endl;
}
