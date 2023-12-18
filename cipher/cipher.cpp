#include <iostream>
#include <fstream>
#include <iomanip>
#include <cryptopp/sha.h>
#include <cryptopp/hex.h>

using namespace CryptoPP;
using namespace std;

string calculateFileHash(const string& filePath) {
    ifstream file(filePath, ios::binary);
    if (!file.is_open()) {
        std::cerr << "Error: Cannot open file: " << filePath << std::endl;
        return "";
    }

    SHA256 hash;
    byte buffer[1024];
    while (!file.eof()) {
        file.read(reinterpret_cast<char*>(buffer), sizeof(buffer));
        hash.Update(buffer, file.gcount());
    }

    file.close();

    size_t size = hash.DigestSize();
    byte digest[size];
    hash.Final(digest);

    std::string hexHash;
    HexEncoder encoder(new StringSink(hexHash));
    encoder.Put(digest, size);
    encoder.MessageEnd();

    return hexHash;
}

int main() {
    string filePath; 
    cout<<"Введите путь к файлу:"<<endl;
    cin>>filePath;
    std::string fileHash = calculateFileHash(filePath);

    if (!fileHash.empty()) {
        std::cout << "File Hash (SHA-256): " << fileHash << std::endl;
        cout<<endl;
    }

    return 0;
}
