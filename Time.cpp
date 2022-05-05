#include "Time.h"
#include "Helper.h"

unsigned int Time::getHour() const {
    return this->hour;
}

unsigned int Time::getMinutes() const {
    return this->minutes;
}

void Time::setHour(const unsigned int _hour) {
    this->hour = _hour;
}

void Time::setMinutes(const unsigned int _minutes) {
    this->minutes = _minutes;
}

Time::Time() {
    this->minutes = 0;
    this->hour = 0;
}

Time::Time(unsigned int hour, unsigned int minutes) {
    this->hour = hour;
    this->minutes = minutes;
}

void Time::print(std::ostream &out) const {
    out << (this->hour < 10 ? "0" : "") << this->hour << Helper::HOUR_SEPARATOR << (this->minutes < 10 ? "0" : "")
        << this->minutes;
}

bool Time::operator==(const Time &hour1) const {
    return this->hour == hour1.getHour() && this->minutes == hour1.getMinutes();
}

Time &Time::operator=(const Time &other) {
    if (this != &other) {
        this->hour = other.hour;
        this->minutes = other.minutes;
    }
    return *this;
}

bool Time::operator<(const Time &hour1) const {
    return this->hour < hour1.getHour() || (this->hour == hour1.getHour() && this->minutes < hour1.getMinutes());
}

bool Time::operator>(const Time &hour1) const {
    return this->hour > hour1.getHour() || (this->hour == hour1.getHour() && this->minutes > hour1.getMinutes());
}

std::istream &operator>>(std::istream &in, Time &hour) {
    std::cout<< Helper::HOUR_INPUT_HELPER_MESSAGE<<std::endl;
    in >> hour.hour;
    in.ignore(1);
    in >> hour.minutes;

    return in;
}