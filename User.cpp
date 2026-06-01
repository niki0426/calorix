#include <iostream>
#include "User.h"

int User::nextUserId = 1;

User::User()
	:userId(nextUserId++), name(""), password(""), profile() {}

User::User(const std::string& name, const std::string& password, const UserProfile& profile)
	:userId(nextUserId++), name(name), password(password), profile(profile) {}

int User::getUserId() const
{
	return userId;
}

const std::string& User::getName() const
{
	return name;
}

const std::string& User::getPassword() const
{
	return password;
}

const UserProfile& User::getProfile() const
{
	return profile;
}

void User::print() const
{
	std::cout << "User [" << userId << "] " << name << "\n";
	profile.print();
}
