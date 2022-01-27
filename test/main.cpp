#include<iostream>
#include"hash.h"

using namespace std;

int main(int argc, char* argv[]){
    if(argc < 2){
        cout << "Usage: hash <option> <message>" << endl;
        cout << "options: sha160" << endl;
        return 0;
    }
    Hash::HashFunctionTypes type = Hash::GetHashFunctionType(string(argv[1]));
    return 0;
}