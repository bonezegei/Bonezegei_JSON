/*
  Bonezegei JSON parser
  Derived from Bonezegei Search
  Author: Bonezegei (Jofel Batutay)
  Date : May 8 2025
*/

#include <Arduino.h>

#ifndef _BONEZEGEI_JSON_H_
#define _BONEZEGEI_JSON_H_
#define SRC_MEM 64
#define BZ_JSON_SIZE 128

class Bonezegei_JSON {
public:
  Bonezegei_JSON() {
    src2cnt = 0;
  }

  // param1 destination array
  // param2 keyword to add
  // param3 value to keyword
  void addData(char ar[], char *keyword, char *value);   // add data to the json
  void addData(char ar[], char *keyword, double value);  // add data to the json array with float value
  void addData(char ar[], char *keyword, int value);     // add data to the json array with integer value
  
  // returns a value based on the keyword
  char *get(char ar[], char *keyword);
  char *get(char *keyword);


  char data[BZ_JSON_SIZE];
  //Bonezegei search SRC functions

  int src2cnt;                                 // search data
  char src2data[SRC_MEM];                      // src data array
  int src(char ar[], const char *cmp, int n);  // search to array
  void src2(char ar[], int n);
  void src2(char ar[], char enD, int n);
  void src2(char ar[], char enD1, char enD2, int n);
  void src2copy(char ar1[], char ar2[]);
  void src2clear(char arr[]);
};

#endif
