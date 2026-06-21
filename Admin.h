#pragma once
#include "User.h"

class Admin : public User {
public:
    Admin(const std::string& username, const std::string& password, const UserProfile& profile);
    Admin(int id, const std::string& username, const std::string& password, const UserProfile& profile);

    bool isAdmin() const override;
    std::string getType() const override;
};
