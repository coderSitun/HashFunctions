#include<iostream>

using namespace std;

int main(int argc, char* argv[]){
    if(argc < 2){
        cout << "Usage: hash <option> <message>" << endl;
        cout << "options: sha160" << endl;
    }
    return 0;
}