#pragma once
#include <string>
#include "UserProfile.h"

class User {
protected:
    static int nextId;
    int userId;
    std::string username;
    std::string password;
    UserProfile profile;

public:

    User(const std::string& username, const std::string& password, const UserProfile& profile);
    User(int id, const std::string& username, const std::string& password, const UserProfile& profile);
    virtual ~User() = default;

    int getUserId() const;
    std::string getUsername() const;
    std::string getPassword() const;
    UserProfile getProfile() const;

    void setPassword(const std::string& password);
    void setProfile(const UserProfile& profile);

    virtual bool isAdmin() const;
    virtual std::string getType() const;

    virtual std::string toFileString() const;
};
