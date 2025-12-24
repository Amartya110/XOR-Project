#include <iostream>
#include <fstream>
#include <cstdint>

#pragma pack(push, 1)
struct Key {
    uint64_t a;
    uint64_t b;
};
#pragma pack(pop)

int main() {
    std::ifstream file("key.bin", std::ios::binary);
    if (!file) {
        std::cout << "ACCESS DENIED\n";
        return 1;
    }

    Key k{};
    if (!file.read(reinterpret_cast<char*>(&k), sizeof(k))) {
        std::cout << "ACCESS DENIED\n";
        return 1;
    }

    const uint64_t TARGET_SUM = 11111111101111111110;
    const uint64_t TARGET_XOR = 10966994397930884516;

    if ((k.a + k.b) != TARGET_SUM) {
        std::cout << "ACCESS DENIED\n";
        return 0;
    }

    if ((k.a ^ k.b) != TARGET_XOR) {;
        std::cout << "ACCESS DENIED\n";
        return 0;
    }

    std::cout << "ACCESS GRANTED\n";
    return 0;
}
