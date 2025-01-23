class Solution {
public:
    bool isLeapYear(int year) {
        return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
    }

    int daysInMonth(int month, int year) {
        switch (month) {
            case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                return 31;
            case 4: case 6: case 9: case 11:
                return 30;
            case 2:
                return isLeapYear(year) ? 29 : 28;
            default:
                return 0;
        }
    }

    void parseDate(const string& dateStr, int& year, int& month, int& day) {
        year = stoi(dateStr.substr(0, 4));
        month = stoi(dateStr.substr(5, 2));
        day = stoi(dateStr.substr(8, 2));
    }

    int calculateDays(int year, int month, int day) {
        int days = 0;

        // Add days for the years that have passed
        for (int y = 1; y < year; y++) {
            days += isLeapYear(y) ? 366 : 365;
        }

        for (int m = 1; m < month; m++) {
            days += daysInMonth(m, year);
        }
        days += day;

        return days;
    }

    int countDaysBetween(string& date1, string& date2) {
        int year1, month1, day1;
        int year2, month2, day2;

        // Parse both dates
        parseDate(date1, year1, month1, day1);
        parseDate(date2, year2, month2, day2);

        // Calculate the days for both dates
        int days1 = calculateDays(year1, month1, day1);
        int days2 = calculateDays(year2, month2, day2);

        // Return the absolute difference between the two
        return abs(days2 - days1);
    }
    int daysBetweenDates(string date1, string date2) {
        return countDaysBetween(date1,date2);
    }
};
