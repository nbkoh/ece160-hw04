#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
  NAME_ONLY = 0,
  MAJOR_AND_NAME = 1, 
  YEAR_AND_NAME = 2,
  YEARS_LEFT_AND_NAME = 3
} Mode;

typedef struct {
  char *first_name;
  char *last_name;
  // TODO: add fields here for major and year
  char *major;
  int year;

} Student;

void print_student(Mode m, Student s) {
  switch (m) {
    case NAME_ONLY:
      printf("%s %s ", s.first_name, s.last_name);
      break;
	// TODO: handle other cases
    case MAJOR_AND_NAME:
      printf("%s %s %s ", s.major, s.first_name, s.last_name);
      break;
    case YEAR_AND_NAME:
      printf("%d %s %s ", s.year, s.first_name, s.last_name);
      break;
     case YEARS_LEFT_AND_NAME:
       printf("%d %s %s\n", (s.year-2017), s.first_name, s.last_name);
       break;
  }
}

/*
	argv[1] will be the Mode integer
	argv[2...] will be student info in the form [first_name, last_name, major, year]
	the fields are all strings (char[])
	except year is a number (int)
*/
int main(int argc, char* argv[]) {
  // TODO: parse argv to populate student structs 
  // for now, here's two hardcoded students:

 	FILE *fp = fopen(argv[1], "r");
  FILE *fpp = fopen(argv[2], "r");

 	if(fp == NULL || fpp == NULL)
 	{
    printf("Check the Files \n");
 		return -1;
 	}

 	char buffer[256];
  Student studentstring[256];
  char first_name[256];
  char last_name[256];
  char major[256];
  int year;
  int index;
  int mode;


  while(fgets(buffer, sizeof(buffer), fpp) != NULL)
  {
    int i = 0;
    sscanf(buffer, "%d %d", &index, &mode);
    int loop = index;
    FILE *fp = fopen(argv[1], "r");
    while(loop >= 0)
    {
      if(fgets(buffer, sizeof(buffer), fp) != NULL)
      {
        sscanf(buffer, "%s %s %s %d", first_name, last_name, major, &year);
        studentstring[i].first_name = first_name;
        studentstring[i].last_name = last_name;
        studentstring[i].major = major;
        studentstring[i].year = year;
        i++;
      }
      loop--;
    }
    print_student(mode,studentstring[index]);
    printf("\n");
  }
  
  return 0;
}
