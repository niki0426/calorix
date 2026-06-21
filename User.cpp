#include "User.h"

int User::nextId = 1;

User::User(const std::string& username, const std::string& password, const UserProfile& profile)
    : userId(nextId++), username(username), password(password), profile(profile) {
}

int User::getUserId() const {
    return userId; 
}
std::string User::getUsername() const {
    return username; 
}
std::string User::getPassword() const {
    return password; 
}
UserProfile User::getProfile() const {
    return profile; 
}
void User::setPassword(const std::string& p) {
    password = p; 
}
void User::setProfile(const UserProfile& p) {
    profile = p; 
}

bool User::isAdmin() const {
    return false; 
}
std::string User::getType() const {
    return "User"; 
}

std::string User::toFileString() const {
    return std::to_string(userId) + "|" + username + "|" + password + "|" + getType() + "|" + profile.toString();
}