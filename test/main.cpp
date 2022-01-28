#include<iostream>
#include<string>
#include"hash.h"

using namespace std;

int main(int argc, char* argv[]){
    if(argc < 2){
        cout << "Usage: hash <option> <message>" << endl;
        cout << "options: sha160" << endl;
        return 0;
    }
    Hash::HashFunctionEnumTypes eType = Hash::GetHashFunctionType(string(argv[1]));
    Hash *hash = Hash::GetHashFunction(eType);
    if(hash->checkValidity() == false){
        cout << "Please enter valid options: sha160" << endl;
        return 0;
    }
    if(argc < 3){
        cout << "Usage: hash " << argv[1] << " <message>" << endl;
        return 0;
    }
    cout << hash->getHash(string(argv[2])) << endl;
    return 0;
}