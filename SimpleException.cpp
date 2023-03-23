#include <iostream>
#include <string>
#include <exception>
using namespace std;

class bad_length : public exception {
public:
    const char* what() const noexcept override {
        return "Вы ввели слово запретной длины!";
    }
};

int function(std::string str, int forbidden_length) {
    int length = str.length();
    if (length == forbidden_length) {
        throw bad_length();
    }
    return length;
}

int main() {

    setlocale(LC_ALL, "Russian");

    int forbidden_length;
    string word;

    cout << "Введите запретную длину: ";
    cin >> forbidden_length;

    
    while (true) {
        cout << "Введите слово: ";
        cin >> word;
        try {
            int length = function(word, forbidden_length);
            cout << "Длина слова \"" << word << "\" равна " << length << endl;
        }
        catch (const bad_length& ex) {
            cout << ex.what() << " До свидания." << endl;
            break;
        }
    }
}