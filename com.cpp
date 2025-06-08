#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int main(int argc, char* argv[]) {
    ofstream com;

    #if defined(_WIN32) || defined(_WIN64)
        const char* path = "\\\\.\\COM%d";
    #elif defined(__linux__)
        const char* path = "/dev/ttyACM%d";
    #else
        #error "Unknown OS"
    #endif

    char buffer[25];
    char** mess;
    switch (argc) {
        case 1:
            cout << "\n No arg \n\n";
            return 1;
        case 2:
            for (int i=0; i<=9; i++) {
                sprintf(buffer, path, i);
                com.open(buffer);
                if (com.is_open()) {
                    sprintf(buffer, "\n Port %d found \n\n", i);
                    cout << buffer;
                    break;
                }
            }
            mess = &argv[1];
        break;
        case 3: {
            int i = atoi(argv[1]);
            sprintf(buffer, path, i);
            com.open(buffer);
            if (com.is_open()) {
                sprintf(buffer, "\n Port %d open \n\n", i);
                cout << buffer;
            }
            mess = &argv[2];
        break; }
        default:
            cout << "\n Too match arg \n\n";
            return 2;
    }

    if (com.is_open()) {
        com << *mess << endl;
        com.close();
    } else {
        cout << "\n Сonnection error \n\n";
        return 3;
    }

    return 0;
}
