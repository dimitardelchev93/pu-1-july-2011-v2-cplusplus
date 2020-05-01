#include <iostream>
#include <string>

using namespace std;

class Movie {
    public:
        string title;
        string artists;
        int year;
        double tax;

        Movie() {
            do
            {
                std::cout << "Enter title (40 chars max): ";
                cin.ignore();
                getline(cin, title);
            }
            while (title.length() > 40);

            do
            {
                std::cout << "Enter artists (250 chars max, devided by ','): ";
                cin.ignore();
                getline(cin, artists);
            }
            while (artists.length() > 250);

            std::cout << "Enter year: ";
            std::cin >> year;
            std::cout << "License tax: ";
            std::cin >> tax;
        }
};

class FilmLibrary {
    public:
        int size;
        Movie *movies;

        void addMovies() {
            int input;

            do
            {
                std::cout << "Enter quantity of library movies (from 1 to 10000): ";
                std::cin >> input;
            }
            while (input > 10000);

            size = input;
            movies = new Movie[size];
        }
};

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
    FilmLibrary filmLibrary;

    if (option[1] != NULL) {
        wrongOptionError();
        return;
    }

    switch (option[0])
    {
        case '1':
            filmLibrary.addMovies();
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
