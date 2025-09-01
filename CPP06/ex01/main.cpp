#include "Serializer.hpp"
#include <iostream>

int main() {
    Data* data = new Data;
    data->name = "Rafa Silva";
    data->age = 32;
    data->weight = 62.5;
    data->height = 1.72;
    data->isGoat = true;

    unsigned long raw = Serializer::serialize(data);
    std::cout << "Data adress: " << data << std::endl;
    std::cout << "Raw value: " << raw << std::endl;
    Data* data2 = Serializer::deserialize(raw);
    std::cout << "Data2 adress: " << data2 << std::endl;

    std::cout << std::endl;
    std::cout << "Before serialization" << std::endl;
    std::cout << "----------------------------" << std::endl;
    std::cout << "data->name = " << data->name << std::endl;
    std::cout << "data->age = " << data->age << std::endl;
    std::cout << "data->weight = " << data->weight << std::endl;
    std::cout << "data->height = " << data->height << std::endl;
    std::cout << "data->isGoat = " << (data->isGoat ? "true" : "false") << std::endl;

    std::cout << std::endl;
    std::cout << "After serialization" << std::endl;
    std::cout << "----------------------------" << std::endl;
    std::cout << "data2->name = " << data2->name << std::endl;
    std::cout << "data2->age = " << data2->age << std::endl;
    std::cout << "data2->weight = " << data2->weight << std::endl;
    std::cout << "data2->height = " << data2->height << std::endl;
    std::cout << "data2->isGoat = " << (data2->isGoat ? "true" : "false") << std::endl;

    delete data;
    return 0;
}
