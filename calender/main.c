// The program can determines whether the date is valid according to the 
//    Gregorian Calendar, finds the day of the week, and print a specified
//    month calendar.


#include <stdio.h>
#include <stdbool.h>
#include <assert.h>


const int SUNDAY = 0;
const int base_year = 1589;

const int BASE_YEARJAN_1 = 0;
const int max_year = 2999;


// print_header(year, month) prints the calendar "header" 
//   for the given year/month
// notes: if month is invalid, no month line is printed
//        header is aligned for 4-digit years
// effects: produces output
void print_header(const int year, const int month) {
  if (month == 1) {
    printf("====January %d====\n", year);
  } else if (month == 2) {
    printf("===February %d====\n", year);
  } else if (month == 3) {
    printf("=====March %d=====\n", year);
  } else if (month == 4) {
    printf("=====April %d=====\n", year);
  } else if (month == 5) {
    printf("======May %d======\n", year);
  } else if (month == 6) {
    printf("=====June %d======\n", year);
  } else if (month == 7) {
    printf("=====July %d======\n", year);
  }else if (month == 8) {
    printf("====August %d=====\n", year);
  } else if (month == 9) {
    printf("===September %d===\n", year);
  } else if (month == 10) {
    printf("====October %d====\n", year);
  } else if (month == 11) {
    printf("===November %d====\n", year);
  } else if (month == 12) {
    printf("===December %d====\n", year);
  }
  printf("Su Mo Tu We Th Fr Sa\n");
}


/////////////////////////////////////////////////////////////////////////////


// valid_date(year, month, day) determines if the provided date is a valid date,
//    according to the Gregorian Calendar.
bool valid_date(int year, int month, int day) {
  if (year >= base_year && year <= max_year) {
    if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 ||
         month == 10 || month == 12) && (day > 0 && day < 32)) {
      return true;
    } else if ((month == 4 || month == 6 || month == 9 || month == 11) &&  
               (day > 0 && day < 31)) {
      return true;
    } else if (month == 2) {
      if ((year % 400 == 0 || (year % 100 != 0 && year % 4 == 0)) && 
          (day > 0 && day < 30)) {
        return true;
      } else if ((year % 400 != 0 && (year % 100 == 0 || year % 4 != 0)) &&
                 (day > 0 && day < 29)) {
        return true;
      }
    }
  }
  return false;
}


// day_of_the_week(year, month, day) finds the "day of the week" for the given 
//    date.
// requires: 1588 < year < 3000
//           0 < month < 13
//           0 < day < 32
int day_of_the_week(int year, int month, int day) {
  assert(valid_date(year, month, day));
  int cur_year = base_year;
  int cur_month = 1;
  int total_day = 0;
  while (cur_year != year || cur_month != month) {
    if (cur_month == 1 || cur_month == 3 || cur_month == 5 || cur_month == 7 ||
        cur_month == 8 || cur_month == 10 || cur_month == 12) {
      cur_month += 1;
      total_day += 31;
    } else if (cur_month == 4 || cur_month == 6 || cur_month == 9 || 
               cur_month == 11) {
      cur_month += 1;
      total_day += 30;
    } else if (cur_month == 2) {
      if (cur_year % 400 == 0 || (cur_year % 100 != 0 && cur_year % 4 == 0)) {
        cur_month += 1;
        total_day += 29;
      } else if (cur_year % 400 != 0 && 
                 (cur_year % 100 == 0 || cur_year % 4 != 0)) {
        cur_month += 1;
        total_day += 28;
      }
    }
    if (cur_month > 12) {
      cur_month = 1;
      cur_year += 1;
    }
  }
  return SUNDAY + (total_day + day - 1) % 7;
}


// print_calendar(year, month) prints a formatted calendar for the given month.
// requires: 1588 < year < 3000
//           0 < month < 13
// effects: produces output
void print_calendar(int year, int month) {
  assert((year >= base_year && year <= max_year) &&
         (month >= 1 && month <= 12));
  int week_day = day_of_the_week(year, month, 1);
  int day = 1;
  int max_day;
  if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 ||
      month == 10 || month == 12) {
    max_day = 31;
  } else if (month == 4 || month == 6 || month == 9 || month == 11) {
    max_day = 30;
  } else if (month == 2) {
    if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0)) {
      max_day = 29;
    } else if (year % 400 != 0 && (year % 100 == 0 || year % 4 != 0)) {
      max_day = 28;
    }
  }
  print_header(year, month);
  for (int i = 0; i < week_day; ++i) {
    if (i == 0) {
      printf("  ");
    } else {
      printf("   ");
    }
  }
  while (day <= max_day) {
    if (week_day == 6) {
      if (day == max_day) {
        printf(" %2d", day);
        day += 1;
      } else {
        printf(" %2d\n", day);
        day += 1;
        week_day = 0;
      }
    } else if (week_day == 0) {
      printf("%2d", day);
      day += 1;
      week_day += 1;
    } else {
      printf(" %2d", day);
      day += 1;
      week_day += 1;
    }
  }
  printf("\n");
}


// assertion_tests() tests written asserted cases
void assertion_tests(void) {
  // Due date is a valid date and a Thursday 
  assert(valid_date(2021, 1, 28));
  assert(day_of_the_week(2021, 1, 28) == 4);

  // Add your own assertion-based tests below
  assert(valid_date(1588, 12, 31) == false);
  assert(valid_date(1589, 1, 1) == true);
  assert(valid_date(2999, 12, 31) == true);
  assert(valid_date(3000, 1, 1) == false);
  assert(valid_date(1589, 12, 32) == false);
  assert(valid_date(1589, 12, 0) == false);
  assert(valid_date(1589, 0, 32) == false);
  assert(valid_date(1589, 0, 31) == false);
  assert(valid_date(1589, 1, 31) == true);
  assert(valid_date(1589, 2, 29) == false);
  assert(valid_date(1592, 2, 29) == true);
  assert(valid_date(1589, 2, 28) == true);

  assert(day_of_the_week(2021, 1, 28) == 4);
  assert(day_of_the_week(2021, 6, 14) == 1);
  assert(day_of_the_week(2021, 2, 16) == 2);
  assert(day_of_the_week(2021, 2, 28) == 0);
  assert(day_of_the_week(2021, 4, 10) == 6);
  assert(day_of_the_week(2021, 5, 28) == 5);
  assert(day_of_the_week(2021, 3, 17) == 3);
}


int main(void) {
  assertion_tests();
  while (1) {
    int year, month;
	scanf("%d%d", &year, &month);
	
    if (month == EOF) {
      break;
    }
    print_calendar(year, month);
  }
}
