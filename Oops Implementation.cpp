#include <iostream>
#include <vector>

using namespace std;

class studyTonight {

    //variable declaration- can be used only within the class as it's declared private
    private:
        int value;

    //Public methods can be called from anywhere- inside as well as outside the class
    public:
        void input() {
            cout << "Entering the input() function\n";
            cout << "Enter an integer you want to display: ";
            cin >> value;
            cout << "Exiting the input() function\n\n";
        }

    void display() {

        cout << "\nEntering the display() function\n";
        cout << "The value entered is: ";
        cout << value;
        cout << "\nExiting the display() function\n\n";
    }
};

int main() {
    cout << "\n\nWelcome to Studytonight :-)\n\n\n";
    cout << " =====  Program to demonstrate the concept of Class, in CPP  ===== \n\n";

    //Declaring class object to access class members from outside the class
    studyTonight object;

    cout << "\n\nCalling the input() function from the main() method\n\n\n";
    object.input();

    cout << "\nCalling the display() function from the main() method\n\n\n";

    object.display();

    cout << "\n\nExiting the main() method\n\n\n";

    //object.value- This will produce an error because variable is declared to be private and hence cannot be accessed from outside the class

    return 0;
}
