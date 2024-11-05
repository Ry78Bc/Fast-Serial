#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {

    ofstream com;

    char** mess;
    switch (argc) {
        case 1:
            cout << "\n No arg \n";
            return 0; 
        break;
        case 2:
            for (int i=2; i<=9;i++) {
                com.open("\\\\.\\COM" + to_string(i));
                if (com.is_open()) break;
            }
            mess = &argv[1];
        break;
        case 3:
            com.open("\\\\.\\COM" + (string) argv[1]);
            mess = &argv[2];
        break;
        default:
            cout << "\n Too match arg \n";
            return 0;
        break;
    }


    if (com.is_open()) {
        com << *mess << endl;
        com.close();
    }
    else {
        cout << "\n No available ports \n";
    }

	return 0;
}