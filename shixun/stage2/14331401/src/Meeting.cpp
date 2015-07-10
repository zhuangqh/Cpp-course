#include "Meeting.h"

using std::string;

Meeting::Meeting() {}

Meeting::Meeting(string sponsor, string participator,
        Date startTime, Date endTime, string title) {
    sponsor_ = sponsor;
    participator_ = participator;
    startDate_ = startTime;
    endDate_ = endTime;
    title_ = title;
}

string Meeting::getSponsor() const {
    return sponsor_;
}

void Meeting::setSponsor(string sponsor) {
    sponsor_ = sponsor;
}

string Meeting::getParticipator() const {
    return participator_;
}

void Meeting::setParticipator(string participator) {
    participator_ = participator;
}

Date Meeting::getStartDate() const {
    return startDate_;
}

void Meeting::setStartDate(Date startTime) {
    startDate_ = startTime;
}

Date Meeting::getEndDate() const {
    return endDate_;
}

void Meeting::setEndDate(Date endDate) {
    endDate_ = endDate;
}

string Meeting::getTitle() const {
    return title_;
}

void Meeting::setTitle(string title) {
    title_ = title;
}
