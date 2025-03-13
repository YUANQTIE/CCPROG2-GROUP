#include <stdio.h>
#include <string.h>

#define MAX_CANDIDATES 20
#define MAX_BILLS 10

typedef char str[50];

typedef struct {
  str lastName;
  str firstName;
  char middleInitial;
} Name;

typedef struct {
  int month;
  int day;
  int year;
} Date;

typedef struct {
  str bill;
  Date passedBills;
} Bill;

typedef struct {
    float confidence;
    str organization;
    int date; //input should be MMDDYYYY
} Rating;

typedef struct {
  Name candidate_name;
  Date candidate_birthday;
  str candidate_position;
  Bill candidate_bills[MAX_BILLS];
  int candidate_nBills;
  Rating candidate_rating;

} Candidate;

Candidate Candidate_List[MAX_CANDIDATES];

