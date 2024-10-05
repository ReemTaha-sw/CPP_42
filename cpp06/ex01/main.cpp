#include <iostream>
#include "Serializer.hpp"

int main() {
    Data data;
    data.id = 42;
    data.name = "Reem";

    uintptr_t serializedData = Serializer::serialize(&data);

    Data* deserializedData = Serializer::deserialize(serializedData);

    // Check original pointer = deserialized pointer
    if (deserializedData == &data) {
        std::cout << "Serialization and deserialization successful!" << std::endl;
        std::cout << "Data ID: " << deserializedData->id << std::endl;
        std::cout << "Data Name: " << deserializedData->name << std::endl;
    } else {
        std::cout << "Error: Pointers do not match!" << std::endl;
    }

    return 0;
}
