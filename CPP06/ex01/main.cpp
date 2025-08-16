#include "Serializer.hpp"
#include <iostream>

int main() {
    // Data nesnesi oluştur
    Data* originalData = new Data("John Doe", 30, 50000.0);
    
    std::cout << "Original Data:" << std::endl;
    originalData->display();
    std::cout << std::endl;
    
    // Serialize
    uintptr_t serialized = Serializer::serialize(originalData);
    std::cout << "Serialized value: " << serialized << std::endl;
    std::cout << std::endl;
    
    // Deserialize
    Data* deserializedData = Serializer::deserialize(serialized);
    
    std::cout << "Deserialized Data:" << std::endl;
    deserializedData->display();
    std::cout << std::endl;
    
    // Pointer karşılaştırması
    std::cout << "Pointer comparison:" << std::endl;
    std::cout << "Original pointer: " << originalData << std::endl;
    std::cout << "Deserialized pointer: " << deserializedData << std::endl;
    std::cout << "Are they equal? " << (originalData == deserializedData ? "Yes" : "No") << std::endl;
    
    // Memory temizliği
    delete originalData;
    
    return 0;
}
