#include "Admin.h"

Admin::Admin(const std::string& username, const std::string& password, const UserProfile& profile)
    : User(username, password, profile) {
}

Admin::Admin(int id, const std::string& username, const std::string& password, const UserProfile& profile)
    : User(id, username, password, profile) {
}

bool Admin::isAdmin() const {
    return true; 
}
std::string Admin::getType() const {
    return "Admin"; 
}