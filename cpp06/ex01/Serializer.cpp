#include "Serializer.hpp"

Serializer::Serializer()
{
	std::cout << "Serializer constructor called!\n";
}

Serializer::~Serializer()
{
	std::cout << "Serializer destructor called!\n";
}

Serializer::Serializer(Serializer &obj)
{
	*this = obj;
}

Serializer& Serializer::operator=(Serializer &obj)
{
	(void)obj;
	return *this;
}

uintptr_t Serializer::serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}