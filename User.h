#pragma once
#include "UserProfile.h"
#include <string>

class User {
private:
	static int nextUserId;
protected:
	int userId;
	std::string name;
	std::string password;
	UserProfile profile;
public: 
	User();
	User(const std::string& name, const std::string& password, const UserProfile& profile);

	int getUserId() const;
	const std::string& getName() const;
	const std::string& getPassword() const;
	const UserProfile& getProfile() const;

	virtual void help() const = 0;
	virtual void print() const;

};
