#include "Storage.h"
#include <fstream>
#include <iostream>

Storage *Storage::instance_ = NULL;

// remove " from the string
void convert(std::string &str) {
    std::string ans;
    ans.reserve(str.size());
    for (size_t i = 0; i < str.size(); ++i) {
        if (str[i] == '\"' && str[i + 1] == '\"') {
            ans += str[i];
            ++i;
        } else {
            ans += str[i];
        }
    }
    str = ans;
}

bool Storage::readFromFile(const char *fpath) {
  std::string path(fpath);
  std::ifstream fs(fpath);

  if (!fs) return false;

  if (path == "User.csv") {
    std::string temp;
    std::getline(fs, temp);
    if (temp.size() == 0) return false;  // File is empty

    while (std::getline(fs, temp)) {
      size_t pre = 1, post = 0;
      std::string userInfo[4];
      int count = 0, numOfYinhao = 0;

      // cut string from temp
      for (; post < temp.size(); ++post) {
          if (temp[post] == '"') ++numOfYinhao;
        if (count == 3) {
          pre = post + 1;
          post = temp.size() - 1;
          userInfo[count] = temp.substr(pre, post - pre);
          break;
        }
        if (temp[post] == ',' && numOfYinhao % 2 == 0) {
          userInfo[count++] = temp.substr(pre, post - pre - 1);
          pre = post + 2;
        }
      }

      // create a new User
      for (int i = 0; i < 4; ++i)
          convert(userInfo[i]);
      User user(userInfo[0], userInfo[1], userInfo[2], userInfo[3]);
      userList_.push_back(user);
    }

  }

  if (path == "Meeting.csv") {
    std::string temp;
    std::getline(fs, temp);
    if (temp.size() == 0) return false;  // File is empty

    while (std::getline(fs, temp)) {
      size_t pre = 1, post = 0;
      std::string mInfo[5];
      int count = 0, numOfYinhao = 0;

      for (; post < temp.size(); ++post) {
          if (temp[post] == '\"') ++numOfYinhao;
        if (count == 4) {
          pre = post + 1;
          post = temp.size() - 1;
          mInfo[count] = temp.substr(pre, post - pre);
          break;
        }
        if (temp[post] == ',' && numOfYinhao % 2 == 0) {
          mInfo[count++] = temp.substr(pre, post - pre - 1);
          pre = post + 2;
        }
      }

      // create a new User
      for (int i = 0; i < 5; ++i)
          convert(mInfo[i]);
      Meeting meeting(mInfo[0], mInfo[1], Date::stringToDate(mInfo[2]),
                      Date::stringToDate(mInfo[3]), mInfo[4]);
      meetingList_.push_back(meeting);
    }
  }

  fs.close();
  return true;
}

// insert " to fix the string
std::string fix(std::string str) {
    std::string ans;
    std::string::iterator it;
    for (it = str.begin(); it != str.end(); ++it) {
        if (*it == '"') {
            ans += '"';
        }
        ans += *it;
    }
    return ans;
}

bool Storage::writeToFile(const char *fpath) {
    std::string path(fpath);
    std::ofstream fs(fpath, std::ios::out);

    if (!fs.is_open()) return false;

    // write to User.csv
    if (path == "User.csv") {
        fs << "\"name\",\"password\",\"email\",\"phone\"\n";
        std::list<User>::iterator it = userList_.begin();
        for (; it != userList_.end(); ++it) {
            fs << '"' << fix(it->getName()) << "\","
               << '"' << fix(it->getPassword()) << "\","
               << '"' << fix(it->getEmail()) << "\","
               << '"' << fix(it->getPhone()) << "\"\n";
        }
    } else {
        // write to Meeting.csv
        fs << "\"sponsor\",\"participator\",\"sdate\",\"edate\",\"title\"\n";
        std::list<Meeting>::iterator it = meetingList_.begin();
        for (; it != meetingList_.end(); ++it) {
            fs << '"' << fix(it->getSponsor()) << "\","
               << '"' << fix(it->getParticipator()) << "\","
               << '"' << fix(Date::dateToString(it->getStartDate())) << "\","
               << '"' << fix(Date::dateToString(it->getEndDate())) << "\","
               << '"' << fix(it->getTitle()) << "\"\n";
        }
    }
    fs.close();

    return true;
}

Storage::Storage() {
    sync();
}

Storage *Storage::getInstance() {
  if (instance_ == NULL)
    instance_ = new Storage();
  return instance_;
}

Storage::~Storage() {
    delete instance_;
    instance_ = NULL;
}

void Storage::createUser(const User& user) {
  userList_.push_back(user);
  writeToFile("User.csv");
}

std::list<User> Storage::queryUser(std::function<bool(const User&)> filter) {
  std::list<User> ans;
  std::list<User>::iterator it = userList_.begin();
  for (; it != userList_.end(); ++it) {
      if (filter(*it)) {
          ans.push_back(*it);
      }
  }
  return ans;
}

int Storage::updateUser(std::function<bool(const User&)> filter,
               std::function<void(User&)> switcher) {
  std::list<User>::iterator it = userList_.begin();
  int count = 0;
  for (; it != userList_.end(); ++it) {
    if (filter(*it)) {
      switcher(*it);
      ++count;
    }
  }
  writeToFile("User.csv");
  return count;
}

int Storage::deleteUser(std::function<bool(const User&)> filter) {
  std::list<User>::iterator it = userList_.begin();
  int count = 0;
  for (; it != userList_.end(); ++it) {
    if (filter(*it)) {
      userList_.erase(it);
      ++count;
    }
  }
  writeToFile("User.csv");
  return count;
}

void Storage::createMeeting(const Meeting& meeting) {
  meetingList_.push_back(meeting);
  writeToFile("Meeting.csv");
}

std::list<Meeting> Storage::queryMeeting(
                std::function<bool(const Meeting&)> filter) {
  std::list<Meeting>::iterator it = meetingList_.begin();
  std::list<Meeting> ans;
  for (; it != meetingList_.end(); ++it) {
    if (filter(*it))
      ans.push_back(*it);
  }
  return ans;
}

int Storage::updateMeeting(std::function<bool(const Meeting&)> filter,
                  std::function<void(Meeting&)> switcher) {
  std::list<Meeting>::iterator it = meetingList_.begin();
  int count = 0;
  for (; it != meetingList_.end(); ++it) {
    if (filter(*it)) {
      switcher(*it);
      ++count;
    }
  }
  writeToFile("Meeting.csv");
  return count;
}

int Storage::deleteMeeting(std::function<bool(const Meeting&)> filter) {
  std::list<Meeting>::iterator it = meetingList_.begin();
  int count = 0;
  for (; it != meetingList_.end(); ++it) {
    if (filter(*it))
      meetingList_.erase(it);
  }
  writeToFile("Meeting.csv");
  return count;
}

bool Storage::sync() {
    readFromFile("User.csv");
    readFromFile("Meeting.csv");
    return true;
}
