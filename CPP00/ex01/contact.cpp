#include "Contact.hpp"

void Contact::setName(const std::string name) {
    this->name = name;
}

void Contact::setSurname(const std::string surname) {
    this->surname = surname;
}

void Contact::setNickName(const std::string nickName) {
    this->nickName = nickName;
}

void Contact::setPhoneNumber(const std::string phoneNumber) {
    this->phoneNumber = phoneNumber;
}

void Contact::setDarkestSecret(const std::string darkestSecret) {
    this->darkestSecret = darkestSecret;
}

std::string getName() const {
    return name;
}

std::string getSurname() const {
    return surname;
}

std::string getNickName() const {
    return nickName;
}

std::string getPhoneNumber() const {
    return phoneNumber;
}

std::string getDarkestSecret() const {
    return darkestSecret;
}
