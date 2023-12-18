#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cryptopp/sha.h>

using namespace CryptoPP;

std::string calculatefilehash(const std::string& filepath)
{
    SHA256 hash;
    std::ifstream file(filepath, std::ios::binary);
    std::stringstream hashstream;

    const int buffersize = 4096;
    byte buffer[buffersize];

    while (file.read(reinterpret_cast<char*>(buffer), buffersize))
    {
        hash.Update(buffer, buffersize); // заменяем hash.update() на hash.Update()
    }

    hash.Update(buffer, file.gcount()); // handle remaining bytes
    hash.Final(buffer); // заменяем hash.final() на hash.Final()

    for (int i = 0; i < SHA256::DIGESTSIZE; i++) // заменяем cryptopp::sha256::digestsize на SHA256::DIGESTSIZE
    {
        hashstream << std::hex << std::setw(2) << std::setfill('0') << (int)buffer[i];
    }

    return hashstream.str();
}

int main()
{
    std::string filepath = "/home/stud/Desktop/MiSP/Praktika4/hi.txt";
    std::string hash = calculatefilehash(filepath);

    std::cout << "file hash (sha-256): " << hash << std::endl;

    return 0;
}
