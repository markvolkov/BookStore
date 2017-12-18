//
// Created by Mark Volkov on 12/5/17.
//

#include "Customer.h"

Customer::Customer() {
    this->name = "()";
    this->phoneNumber = "()";
    this->email = "()";
    this->contactPref = "()";

}

Customer::Customer(std::string name, std::string phoneNumber, std::string email) {
    this->name = name;
    this->phoneNumber = phoneNumber;
    this->email = email;
    this->contactPref = "()";
}

Customer::Customer(std::string name, std::string phoneNumber, std::string email, std::string contactPref) {
    this->name = name;
    this->phoneNumber = phoneNumber;
    this->email = email;
    this->contactPref = contactPref;
}

std::string Customer::getName() {
    return this->name;
}

std::string Customer::getPhoneNumber() {
    return this->phoneNumber;
}

std::string Customer::getEmail() {
    return this->email;
}

std::string Customer::getContactPreference() {
    return this->contactPref;
}

void Customer::setName(std::string name) {
    this->name = name;
}

void Customer::setPhoneNumber(std::string phoneNumber) {
    this->phoneNumber = phoneNumber;
}

void Customer::setEmail(std::string email) {
    this->email = email;
}

void Customer::setContactPreference(std::string contactPref) {
    this->contactPref = contactPref;
}
