#include <iostream>
using namespace std;

//Default constructor

class Wall{
    private:
    double lenght;

    public:
    Wall(){
        lenght = 1;
        cout << "Create a Wall. " << endl;
        cout << "Lenght " << lenght << endl;
    }
};

int main() {
    Wall wall1;;
    return 0;
}