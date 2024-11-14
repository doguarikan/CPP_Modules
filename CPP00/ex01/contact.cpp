#include "Contact.hpp"

void Contact::setName(const std::string name) {
    this->name = name;
}

void Contact::setSurname(const std::string surname) {
    this->surname = surname;
}

void Contact::setNickName(const std::string nick_name) {
    this->nick_name = nick_name;
}

void Contact::setPhoneNumber(const std::string phone_number) {
    this->phone_number = phone_number;
}

void Contact::setDarkestSecret(const std::string darkest_secret) {
    this->darkest_secret = darkest_secret;
}

std::string Contact::getName() {
    return this->name;
}

std::string Contact::getSurname() {
    return this->surname;
}

std::string Contact::getNickName() {
    return this->nick_name;
}

std::string Contact::getPhoneNumber() {
    return this->phone_number;
}

std::string Contact::getDarkestSecret() {
    return this->darkest_secret;
}
