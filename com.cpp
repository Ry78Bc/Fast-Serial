#include <iostream>
#include <fstream>
#include <cstring>

#if defined(_WIN32) || defined(_WIN64)
    #include <windows.h>
    const char* path = "\\\\.\\COM%d";
#elif defined(__linux__)
    #include <unistd.h>
    const char* path = "/dev/ttyACM%d";
#else
    #error "Unknown OS"
#endif

using namespace std;

int main(int argc, char* argv[]) {
    fstream com;

    char buffer[20];
    char** mess;
    switch (argc) {
        case 1:
            cout << "\n No arg \n\n";
            return -1;
        case 2:
            for (int i=0; i<=9; i++) {
                sprintf(buffer, path, i);
                com.open(buffer, ios::out | ios::in | ios::trunc);
                if (com.is_open()) {
                    sprintf(buffer, "\n COM%d", i);
                    mess = &argv[1];
                    break;
                }
                else {
                    cout << "\n No ports available \n\n";
                    return -2;
                }
            }
        break;
        case 3: {
            int i = atoi(argv[1]);
            sprintf(buffer, path, i);
            com.open(buffer, ios::out | ios::in | ios::trunc);
            if (com.is_open()) {
                sprintf(buffer, "\n COM%d", i);
                mess = &argv[2];
            }
            else {
                cout << "\n Сonnection error \n\n";
                return -3;
            }
        break; }
        default:
            cout << "\n Too match arg \n\n";
            return -4;
    }

    cout << buffer << " << " << *mess << endl;

    // очистить файл открытый потоком com

    com.clear();
    com << *mess << endl;
    com.flush();

    string response;
    while (getline(com, response)) {
        if (response.empty()) continue;
        cout << buffer << " >> " << response << "\n\n";
        break;
    }

    com.close();
    return 0;
}