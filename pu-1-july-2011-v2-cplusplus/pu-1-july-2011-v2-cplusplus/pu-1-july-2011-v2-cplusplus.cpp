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

            size = input;
            movies = new Movie[size];
        }

        void sort() {
            for (int i = 0; i < size - 1; i++) {
                for (int j = 0; j < size - 1; j++) {
                    if (movies[j].title > movies[j + 1].title) {
                        Movie tmp = movies[j];
                        movies[j] = movies[j + 1];
                        movies[j + 1] = tmp;
                    }
                }
            }
        }

        void doubleSort() {
            for (int i = 0; i < size - 1; i++) {
                for (int j = 0; j < size - 1; j++) {
                    if (
                        movies[j].year < movies[j + 1].year
                        || movies[j].year == movies[j + 1].year
                        && movies[j].tax > movies[j + 1].tax
                    ) {
                        Movie tmp = movies[j];
                        movies[j] = movies[j + 1];
                        movies[j + 1] = tmp;
                    }
                }
            }
        }

        void print(string artistCriteria) {
            for (int i = 0; i < size; i++) {
                string artists = movies[i].artists;

                if (movies[i].artists.find(artistCriteria) == string::npos) {
                    continue;
                }

                cout << movies[i].title << "; ";
                cout << movies[i].artists << "; ";
                cout << movies[i].year << "; ";
                cout << movies[i].tax << endl;
            }
        }

        double getAverageTax() {
            double sum = 0;

            for (int i = 0; i < size; i++) {
                sum += movies[i].tax;
            }

            return sum / size;
        }

        void listOrderedMovies() {
            sort();
            print("");
        }

        void listDoubleOrderedMovies() {
            doubleSort();
            print("Robert de Niro");
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

void menu(string option, FilmLibrary *filmLibrary)
{
    if (option.length() != 1) {
        wrongOptionError();
        return;
    }

    switch (option[0])
    {
		case '0':
			break;
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
    string option;
    FilmLibrary *filmLibrary = new FilmLibrary();

    do
    {
        cout << "Choose an option from 1 to 4" << endl << "Enter option: ";
        cin >> option;
        menu(option, filmLibrary);
    } while (option != "0");

    cout << "Good bye!" << endl;
}
