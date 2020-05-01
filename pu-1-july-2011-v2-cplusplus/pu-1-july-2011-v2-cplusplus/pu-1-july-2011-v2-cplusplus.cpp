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
                cout << "Enter title (40 chars max): ";
                cin.ignore();
                getline(cin, title);
            }
            while (title.length() > 40);

            do
            {
                cout << "Enter artists (250 chars max, devided by ', '): ";
                cin.ignore();
                getline(cin, artists);
            }
            while (artists.length() > 250);

            cout << "Enter year: ";
            cin >> year;
            cout << "License tax: ";
            cin >> tax;
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
                cout << "Enter quantity of library movies (from 1 to 10000): ";
                cin >> input;
            }
            while (input > 10000);

            this->size = input;
 			this->movies = new Movie[this->size];
        }

        void sort() {
            for (int i = 0; i < this->size - 1; i++) {
                for (int j = 0; j < this->size - 1; j++) {
                    if (this->movies[j].title > this->movies[j + 1].title) {
                        Movie tmp = this->movies[j];
						this->movies[j] = this->movies[j + 1];
						this->movies[j + 1] = tmp;
                    }
                }
            }
        }

        void print() {
            for (int i = 0; i < this->size; i++) {
                cout << this->movies[i].title << "; ";
                cout << this->movies[i].artists << "; ";
                cout << this->movies[i].year << "; ";
                cout << this->movies[i].year << endl;
            }
        }
};

void listOrderedMovies(FilmLibrary *filmLibrary) {
    filmLibrary->sort();
    filmLibrary->print();
}

void listDoubleOrderedMovies() {
    char artistCriteria[] = "Robert de Niro";
    cout << "Show an ordered (double) list by all the movies with predetermined criteria " << artistCriteria << endl;
}

void combinedThreeTimesAndTaxAverages() {
    cout << "Do 1 three times, do 2 and 3 based on that and show average tax for each, after that print the highest average tax" << endl;
}

void wrongOptionError() {
    cout << "Wrong option!" << endl;
}

void menu(char option[], FilmLibrary *filmLibrary)
{
    if (option[1] != NULL) {
        wrongOptionError();
        return;
    }

    switch (option[0])
    {
        case '1':
            filmLibrary->addMovies();
            break;
        case '2':
            listOrderedMovies(filmLibrary);
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
    FilmLibrary *filmLibrary = new FilmLibrary();

    do
    {
        cout << "Choose an option from 1 to 4" << endl << "Enter option: ";
        cin >> option;
        menu(option, filmLibrary);
    } while (option != 0);

    cout << "Good bye!" << endl;
}
