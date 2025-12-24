#include <iostream>
#include <fstream>
#include <cstdint>//for unit64_t

#pragma pack(push,1)
struct Key{
    unint64_t a;
    unint64_t b;
};
#pragma pack(pop)

int main(){
    std::ifstream file("key.bin",std::ios::binary);
    Key k;
    if(!file ||!file.read((char*)&k, sizeof(k))){
        std::cout<<"ACCESS DENIED: key.bin missing or invalid."<<std::endl;
        return 1;
    }
    const uint64_t TARGET_SUM=16988065061902050250ULL;
    const uint64_t TARGET_XOR=7765935306893693898ULL;
    uint64_t actual_sum=k.a+k.b;
    uint64_t actual_xor=k.a^k.b;

    if(actual_sum!=TARGET_SUM){
        std::cout<<"ACCESS DENIED: Sum Incorrect."<<std::endl;
        std::cout<<"Expected: "<<TARGET_SUM<<"\nGot: "<<actual_sum<<std::endl;
        return 0;
    }
    if(actual_xor!=TARGET_XOR){
        std::cout<<"ACCESS DENIED: Xor Incorrect."<<std::endl;
        std::cout<<"Expected: "<<TARGET_XOR<<"\nGot: "<<actual_xor<<std::endl;
        return 0;
    }
    std::cout<<"ACCESS GRANTED"<<std::endl;
    return 0;

}