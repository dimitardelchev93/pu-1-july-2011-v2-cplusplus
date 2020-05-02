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
                getline(cin, title);
            }
            while (title.length() > 40);

            do
            {
                cout << "Enter artists (250 chars max, devided by ', '): ";
                getline(cin, artists);
            }
            while (artists.length() > 250);

            cout << "Enter year: ";
            cin >> year;
            cout << "License tax: ";
            cin >> tax;
            cin.ignore();
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
                cin.ignore();
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

        void doubleSort() {
            for (int i = 0; i < this->size - 1; i++) {
                for (int j = 0; j < this->size - 1; j++) {
                    if (
                        this->movies[j].year < this->movies[j + 1].year
                        || this->movies[j].year == this->movies[j + 1].year
                        && this->movies[j].tax > this->movies[j + 1].tax
                    ) {
                        Movie tmp = this->movies[j];
                        this->movies[j] = this->movies[j + 1];
                        this->movies[j + 1] = tmp;
                    }
                }
            }
        }

        void print(string artistCriteria) {
            for (int i = 0; i < this->size; i++) {
                string artists = this->movies[i].artists;

                if (this->movies[i].artists.find(artistCriteria) == string::npos) {
                    continue;
                }

                cout << this->movies[i].title << "; ";
                cout << this->movies[i].artists << "; ";
                cout << this->movies[i].year << "; ";
                cout << this->movies[i].tax << endl;
            }
        }

        double getAverageTax() {
            double sum = 0;

            for (int i = 0; i < this->size; i++) {
                sum += this->movies[i].tax;
            }

            return sum / this->size;
        }

        void listOrderedMovies() {
            this->sort();
            this->print("");
        }

        void listDoubleOrderedMovies() {
            this->doubleSort();
            this->print("Robert de Niro");
        }

        void combinedThreeTimesAndTaxAverages() {
            double maxAverageTax = 0;

            for (int i = 0; i < 3; i++) {
                FilmLibrary* filmLibrary = new FilmLibrary();

                filmLibrary->addMovies();
                filmLibrary->listOrderedMovies();
                filmLibrary->listDoubleOrderedMovies();

                double averageTax = filmLibrary->getAverageTax();

                cout << "Average tax is " << averageTax << endl;

                if (averageTax > maxAverageTax) {
                    maxAverageTax = averageTax;
                }
            }

            cout << "Max average tax is " << maxAverageTax << endl;
        }
};

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
            filmLibrary->listOrderedMovies();
            break;
        case '3':
            filmLibrary->listDoubleOrderedMovies();
            break;
        case '4':
            filmLibrary->combinedThreeTimesAndTaxAverages();
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
