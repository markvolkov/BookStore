//
// Created by Mark Volkov on 12/5/17.
//

#ifndef BOOKSTORE_CUSTOMER_H
#define BOOKSTORE_CUSTOMER_H


#include <iostream>

class Customer {

private:
    std::string name;
    std::string phoneNumber;
    std::string email;
    std::string contactPref;
public:
    Customer();
    Customer(std::string name, std::string phoneNumber, std::string email);
    Customer(std::string name, std::string phoneNumber, std::string email, std::string contactPref);
    std::string getName();
    std::string getPhoneNumber();
    std::string getEmail();
    std::string getContactPreference();
    void setName(std::string name);
    void setPhoneNumber(std::string phoneNumber);
    void setEmail(std::string email);
    void setContactPreference(std::string contactPref);
};


#endif //BOOKSTORE_CUSTOMER_H
