#include "AgendaUI.h"

AgendaUI::AgendaUI() {}

void AgendaUI::OperationLoop() {
  std::string op;
  startAgenda();
  while (1) {
    op = getOperation();
    executeOperation(op);
  }
  quitAgenda();
}

void AgendaUI::startAgenda() {
  std::cout << "--------------------- Agenda ----------------------"
            << "Action :\n"
            << "l   - log in Agenda by user name and password\n"
            << "r   - register an Agenda account\n"
            << "q   - quit Agenda\n"
            << "---------------------------------------------------\n\n";
}

std::string AgendaUI::getOperation() {
  std::string op;
  std::cin >> op;
  return op;
}

bool AgendaUI::executeOperation(std::string op) {
  if (op == "l") {
    userLogIn();
  } else if (op == "r") {
    userRegister();
  } else if (op == "o") {
    userLogOut();
  } else if (op == "dc") {
    deleteUser();
  } else if (op == "lu") {
    listAllUsers();
  } else if (op == "cm") {
    createMeeting();
  } else if (op == "la") {
    listAllMeetings();
  } else if (op == "las") {
    listAllSponsorMeetings();
  } else if (op == "lap") {
    listAllParticipateMeetings();
  } else if (op == "qm") {
    queryMeetingByTitle();
  } else if (op == "qt") {
    queryMeetingByTimeInterval();
  } else if (op == "dm") {
    deleteMeetingByTitle();
  } else if (op == "da") {
    deleteAllMeetings();
  }
  return true;
}

void AgendaUI::userLogIn() {
  std::cout << "\n[log in] [user name] [password]"
            << "\n[log in] ";
  std::cin >> userName_ >> userPassword_;
  if (!agendaService_.userLogIn(userName_, userPassword_)) {
    std::cout << "[error] log in fail!\n";
  } else {
    std::cout << "--------------------- Agenda ----------------------"
              << "Action :"
              << "o   - log out Agenda\n"
              << "dc  - delete Agenda account\n"
              << "lu  - list all Agenda user\n"
              << "cm  - create a meeting\n"
              << "la  - list all meeting\n"
              << "las - list all participate meetings\n"
              << "qm  - query meeting by title\n"
              << "qt  - query meeting by time interval\n"
              << "dm  - query meeting by title\n"
              << "da  - delete all meetings\n"
              << "---------------------------------------------------\n"
              << "\nAgenda@" << userName_ << " : # ";
  }
}

void AgendaUI::userRegister() {
  std::string userName, password, email, phone;
  std::cout << "\n[register] [user name] [password] [email] [phone]\n"
            << "[register] ";
  if (!agendaService_.userRegister(userName, password, email, phone)) {
    std::cout << "[error] register fail!\n";
  } else {
    std::cout << "[register] succeed!\n";
  }
}

void AgendaService::quitAgenda() {
  exit(0);
}

void AgendaUI::userLogOut() {

}

void AgendaUI::deleteUser() {
  agendaService_.deleteUser(userName_, userPassword_);
  std::cout << "\n[delete agenda account] succeed!\n";
}

void AgendaUI::listAllUsers() {
  std::cout << "\n[list all users]\n\n"
            << "name\temail\tphone\t\n";
  std::list<User> li = agendaService_.listAllUsers();
  for (std::list<User>::iterator it = li.begin();
       it != li.end(); ++it) {
    std::cout << it->getName() << "\t"
              << it->getEmail() << "\t"
              << it->getPhone() << std::endl;
  }
}

void AgendaUI::createMeeting() {
  std::cout << "\n[create meeting] [title] [participator] "
            << "[start time<yyyy-mm-dd/hh:mm>] "
            << "[<end time<yyyy-mm-dd/hh:mm>]\n"
            << "[create meeting] \n";
  std::string title, participator, startDate, endDate;
  std::cin >> title >> participator >> startDate >> endDate;
  if (agendaService_.createMeeting(userName_, title, participator,
                                   startDate, endDate)) {
    std::cout << "[create meeting] succeed!\n";
  } else {
    std::cout << "[error] create meeting fail!\n";
  }
}

void AgendaUI::listAllMeetings() {
  std::cout << "[list all meetings]\n\n";
  printMeetings(agendaService_.listAllMeetings(userName_));
}

void AgendaUI::listAllSponsorMeetings() {
  std::cout << "[list all sponsor meetings]\n\n";
  printMeetings(agendaService_.listAllSponsorMeetings(userName_));
}

void AgendaUI::listAllParticipateMeetings() {
  std::cout << "[list all participate meetings]\n\n";
  printMeetings(agendaService_.listAllParticipateMeetings(userName_));
}

void AgendaUI::printMeetings(std::list<Meeting> meetings) {
  std::cout << "title\tsponsor\tparticipator\tstart time\tend time\n";
  std::list<Meeting>::iterator it = meetings.begin();
  for (; it != meetings.end(); ++it) {
    std::cout << it->getTitle() << "\t"
              << it->getSponsor() << "\t"
              << it->getParticipator() << "\t"
              << Date::dateToString(it->getStartDate()) << "\t"
              << Date::dateToString(it->getEndDate()) << std::endl;
  }
}

void AgendaUI::queryMeetingByTitle() {
  std::cout << "\n[query meeting] [title]:\n"
            << "[query meeting] ";
  std::string meeting;
  std::cin >> meeting;
  printMeetings(agendaService_.meetingQuery(userName_, meeting));
}

void AgendaUI::queryMeetingByTimeInterval() {
  std::cout << "\n[query meetings] [start time<yyyy-mm-dd/hh:mm>] "
            << "[end time<yyyy-mm-dd/hh:mm>]\n"
            << "[query meetings]";
  std::string startDate, endDate;
  std::cin >> startDate >> endDate;
  std::cout << "\n[query meetings]\n";
  printMeetings(agendaService_.meetingQuery(userName_, startDate, endDate));
}

void AgendaUI::deleteMeetingByTitle() {
  std::cout << "\n[delete meeting] [title]\n"
            << "[delete meeting] ";
  std::string meeting;
  std::cin >> meeting;
  if (agendaService_.deleteUser(userName_, userPassword_)) {
    std::cout << "\n[delete meeting by title] succeed!\n";
  } else {
    std::cout << "\n[error] delete meeting fail!\n";
  }
}

void AgendaUI::deleteAllMeetings() {
  agendaService_.deleteAllMeetings(userName_);
  std::cout << "\n[delete all meetings] succeed!\n";
}
