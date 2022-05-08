#include "Date.h"
#include "Helper.h"
#include <cmath>

enum dayOfWeek {
    MONDAY = 1,
    TUESDAY = 2,
    WEDNESDAY = 3,
    THURSDAY = 4,
    FRIDAY = 5,
    SATURDAY = 6,
    SUNDAY = 0
};

enum months {
    JANUARY = 1,
    FEBRUARY = 2,
    MARCH = 3,
    APRIL = 4,
    MAY = 5,
    JUNE = 6,
    JULY = 7,
    AUGUST = 8,
    SEPTEMBER = 9,
    OCTOBER = 10,
    NOVEMBER = 11,
    DECEMBER = 12
};
enum daysMonths {
    JANUARY_DAYS = 31,
    FEBRUARY_DAYS = 28,
    MARCH_DAYS = 31,
    APRIL_DAYS = 30,
    MAY_DAYS = 31,
    JUNE_DAYS = 30,
    JULY_DAYS = 31,
    AUGUST_DAYS = 31,
    SEPTEMBER_DAYS = 30,
    OCTOBER_DAYS = 31,
    NOVEMBER_DAYS = 30,
    DECEMBER_DAYS = 31
};

bool isValid(const Date &date) {
    months givenMonth = (months) (date.getMonth());
    unsigned int days = date.getDay();
    unsigned int year = date.getYear();
    bool isLeapYear = false;
    if ((year % 400 == 0 || year % 4 == 0) && year % 100 != 0 ) {
        isLeapYear = true;
    }
    else {
        isLeapYear = false;
    }
    switch (givenMonth) {
        case JANUARY:
            if (days > JANUARY_DAYS) return false;
            break;
        case FEBRUARY:
            if ((isLeapYear && days > FEBRUARY_DAYS + 1) || (!isLeapYear && days > FEBRUARY_DAYS)) return false;
            break;
        case MARCH:
            if (days > MARCH_DAYS) return false;
            break;
        case APRIL:
            if (days > APRIL_DAYS) return false;
            break;
        case MAY:
            if (days > MAY_DAYS) return false;
            break;
        case JUNE:
            if (days > JUNE_DAYS) return false;
            break;
        case JULY:
            if (days > JULY_DAYS) return false;
            break;
        case AUGUST:
            if (days > AUGUST_DAYS) return false;
            break;
        case SEPTEMBER:
            if (days > SEPTEMBER_DAYS) return false;
            break;
        case OCTOBER:
            if (days > OCTOBER_DAYS) return false;
            break;
        case NOVEMBER:
            if (days > NOVEMBER_DAYS) return false;
            break;
        case DECEMBER:
            if (days > DECEMBER_DAYS) return false;
            break;
        default:
            return false;
    }
    return true;
}

unsigned int getDayOfWeek(const Date &date) {
    unsigned int day = date.getDay();
    unsigned int month = date.getMonth();
    if (month >= MARCH)
        month -= Helper::MONTH_DIFFERENCE_CONST;
    else {
        month += 10;
    }
    int century = date.getYear() / 100;
    int year;
    if (month == 11 || month == 12)
        year = date.getYear() % 100 - 1;
    else
        year = date.getYear() % 100;
    int yearByFour = floor(year / 4);
    int centuryByFour = floor(century / 4);
    int monthManipulation = floor(2.6 * month - 0.2);

    return (day + monthManipulation - 2 * century + year + yearByFour + centuryByFour) % 7;

}

Date::Date() : day(1), month(1), year(2001) {}

Date::Date(unsigned int day, unsigned int month, unsigned int year) : day(day), month(month), year(year) {}


void Date::print(std::ostream &out) const {
    out << "date: ";
    this->printDayOfWeek(out);
    out << (this->day < 10 ? "0" : "") << this->day << Helper::DATE_SEPARATOR << (this->month < 10 ? "0" : "")
        << this->month << Helper::DATE_SEPARATOR << this->year << std::endl;
}

void Date::setDay(unsigned int _day) {
    this->day = _day;
}

void Date::setMonth(unsigned int _month) {
    this->month = _month;
}

void Date::setYear(unsigned int _year) {
    this->year = _year;
}

unsigned int Date::getDay() const {
    return this->day;
}

unsigned int Date::getMonth() const {
    return this->month;
}

unsigned int Date::getYear() const {
    return this->year;
}

bool Date::operator==(const Date &date1) const {
    return this->day == date1.getDay() && this->month == date1.getMonth() && this->year == date1.getYear();
}

Date &Date::operator=(const Date &other) {
    if (this != &other && isValid(other)) {
        this->setDay(other.getDay());
        this->setMonth(other.getMonth());
        this->setYear(other.getYear());
    }
    return *this;
}

std::istream &operator>>(std::istream &in, Date &date) {
    std::cout << Helper::DATE_INPUT_HELPER_MESSAGE << std::endl;
    in >> date.day;
    in.ignore(1);
    in >> date.month;
    in.ignore(1);
    in >> date.year;
    if (!isValid(date)) {
        std::cerr << Helper::INVALID_DATE_MESSAGE << std::endl;
    }
    return in;
}

void Date::printDayOfWeek(std::ostream &out) const {
    std::cout<<getDayOfWeek(*this)<<std::endl;
    switch (getDayOfWeek(*this)) {
        case MONDAY:
            out << "Mon ";
            break;
        case TUESDAY:
            out << "Tue ";
            break;
        case WEDNESDAY:
            out << "Wed ";
            break;
        case THURSDAY:
            out << "Thu ";
            break;
        case FRIDAY:
            out << "Fri ";
            break;
        case SATURDAY:
            out << "Sat ";
            break;
        case SUNDAY:
            out << "Sun ";
            break;
        default:
            out << "Invalid day of week ";
            break;
    }
}

bool Date::operator<=(const Date &date1) const {
    return this->year <= date1.getYear() && this->month <= date1.getMonth() && this->day <= date1.getMonth();
}

bool Date::operator>=(const Date &date1) const {
    return this->year >= date1.getYear() && this->month >= date1.getMonth() && this->day >= date1.getMonth();
}


