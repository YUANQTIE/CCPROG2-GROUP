#include "struct.h"

// NOTE: use camelCase for variable and function names for naming convention

// (1) SEE: struct.h 
// Define the struct to represent an array of at most 20 candidates where each contains the name, birthday, position, party, a list of at most 10 bills passed, the number of bills passed, and a rating.

// (2) Create a function getName() that will get the name of the candidate. (Myka)
void getName(Name *name) {
    printf("Last Name: ");
    scanf("%s", *name->lastName);
    printf("First Name: ");
    scanf("%s", *name->firstName);
    printf("Middle Initial: ");
    scanf(" %c", &name->middleInitial);
}


// (3) Create a function getDate() that will get the date information. (Arwen)
void getDate(Date *date) {
    printf("Enter the date in numeric format (ex. 1/20/25)");
    printf("Month: ");
    scanf("%d", &date->month);
    printf("Day: ");
    scanf("%d", &date->day);
    printf("Year: ");
    scanf("%d", &date->year);
}

// (4) Call the functions getName() to get the name of the candidate and getDate() 
// to get the birthday and the date the bill was passed. (Arwen)

void getInput(Candidate *candidate) {
    printf("Enter candidate name: ");
    getName(&candidate->candidate_name);
    
}

// (5) (Michael) Create a function displayDate() that will display the date information 
// in the format of <Month in word form> <day>, <year>. For example: March 3, 2018
void displayDate(Date date) {
    str Month;

    switch(date.month){
        case 1:
        strcpy(Month, "January");
        break;
        case 2:
        strcpy(Month, "February");
        break;
        case 3:
        strcpy(Month, "March");
        break;
        case 4:
        strcpy(Month, "April");
        break;
        case 5:
        strcpy(Month, "May");
        break;
        case 6:
        strcpy(Month, "June");
        break;
        case 7:
        strcpy(Month, "July");
        break;
        case 8:
        strcpy(Month, "August");
        break;
        case 9:
        strcpy(Month, "September");
        break;
        case 10:
        strcpy(Month, "October");
        break;
        case 11:
        strcpy(Month, "November");
        break;
        case 12:
        strcpy(Month, "December");
        break;        
    }

    printf("%s %d, %d", Month, date.day, date.year);
}

// (6) (Michael) Create a function display() that will display all information of 1 candidate. Whenever appropriate, call displayDate()


// (7) (Myka)

void displayByParty(Candidate candidates[], str party) {
    int found = 0;
    char choice;
    int stop = 0; // Loop control variable

    for (int i = 0; i < MAX_CANDIDATES && !stop; i++) {
        if (strcmp(candidates[i].candidate_party, party) == 0) {
            found = 1;
            display(candidates[i]);

            printf("Press 'Y' to see the next candidate in same party and any other key to stop: ");
            scanf(" %c", &choice);
            printf("\n");

            if (choice != 'Y' && choice != 'y') {
                stop = 1; // Set flag to stop the loop
            }
        }
    }

    if (!found) {
        printf("No candidates found for the party: %s\n", party);
    }
}



// (8) (Myka)

void swap(Candidate *a, Candidate *b) {
    Candidate temp = *a;
    *a = *b;
    *b = temp;
}

// (9) (UNASSIGNED))

void sortAlphabetical(Candidate Candidate_List[], int nCandidates)
{
    int i, j, min, temp;

    for (i = 0; i < nCandidates - 1; i++)
    {
        min = i;
        
        for (int j = i + 1; j < nCandidates; j++)
        {
            if (strcmp(Candidate_List[i].candidate_name.lastName, Candidate_List[j].candidate_name.lastName) > 0)
            {
                min = j;
            }
        }
        
        if (min != i)
        {  
            swap(Candidate_List[i], Candidate_List[j]);
        }

    }
}

// (11) (Yuan)


int main(void) {
  
    int nCandidates = 0, nChoice;

    for (int i = 0; i < MAX_CANDIDATES; i++)
    {
        Candidate_List[i].candidate_nBills = 0;
    }
            

    printf("MENU\n\n");

    printf("1] Add Candidate Info\n");
    printf("2] Display All Candidates\n");
    printf("3] Display by Rating\n");
    printf("4] Display by Party\n");
    printf("5] Exit\n");

    do
    {
        printf("Choice: ");
        scanf("%d", &nChoice);
    } while (nChoice < 1 || nChoice > 5);

    switch (nChoice)
    {
    case 1:
        printf("Add Candidate Info\n\n");

        getInput(Candidate_List, nCandidates);

        nCandidates++;

        break;
    
    case 2:
        printf("Display All Candidatesn\n\n");

        sortAlphabetical(Candidate_List, nCandidates);

        char next;
        int i = 0;

        do
        {
            display(Candidate_List, nCandidates);

            printf("To stop, enter 'N'");
            scanf(" %c", &next);

            i++;

        } while (i < nCandidates && next != 'N');
        
    break;

    case 3:
        printf("Display by Rating\n\n");

        sortByRating(Candidate_List, nCandidates);

        char next;
        int i = 0;

        do
        {
            display(Candidate_List, nCandidates);

            printf("To stop, enter 'N': ");
            scanf(" %c", &next);

            i++;

        } while (i < nCandidates && next != 'N');

    break;

    case 4:
        printf("Display by Party\n\n");

        str Party;

        printf("Which party do you want to look for?: ");
        scanf("%s", Party);

        displayByParty(Party);
        
    break;

    case 5:
        
        printf("Thank you for your patronage :)");
        return 0;
    }
}
