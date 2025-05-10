#include "Bonezegei_JSON.h"

void Bonezegei_JSON::addData(char ar[], char *keyword, char *value) {
  uint16_t size = strlen(ar);

  if (size > 2) {
    ar[size - 1] = 0;  // set the last character to null
    sprintf(ar, "%s,\"%s\":\"%s\"}", ar, keyword, value);
  } else {
    ar[0] = '{';
    sprintf(ar, "%s\"%s\":\"%s\"}", ar, keyword, value);
  }
}

void Bonezegei_JSON::addData(char ar[], char *keyword, double value) {
  uint16_t size = strlen(ar);

  char buffer[16];
  dtostrf(value, 6, 4, buffer);  // Width: 6, Precision: 4

  if (size > 2) {
    ar[size - 1] = 0;  // set the last character to null
    sprintf(ar, "%s,\"%s\":%s}", ar, keyword, buffer);
  } else {
    ar[0] = '{';
    sprintf(ar, "%s\"%s\":%s}", ar, keyword, buffer);
  }
}

void Bonezegei_JSON::addData(char ar[], char *keyword, int  value){
  uint16_t size = strlen(ar);

  if (size > 2) {
    ar[size - 1] = 0;  // set the last character to null
    sprintf(ar, "%s,\"%s\":%d}", ar, keyword, value);
  } else {
    ar[0] = '{';
    sprintf(ar, "%s\"%s\":%d}", ar, keyword, value);
  }
}

char *Bonezegei_JSON::get(char ar[], char *keyword) {

  for (int a = 0; a < strlen(ar); a++) {
    if (src(ar, keyword, a) == 0) {
      a += strlen(keyword) + 2;
      if (ar[a] == '\"') {
        a += 1;
        src2(ar, '\"', a);
      } else {
        src2(ar, ',', '}', a);
      }
      return src2data;
      a += strlen(ar);
    }
  }
  return 0;
}

char *Bonezegei_JSON::get(char *keyword) {

  for (int a = 0; a < strlen(data); a++) {
    if (src(data, keyword, a) == 0) {
      a += strlen(keyword) + 2;
      if (data[a] == '\"') {
        a += 1;
        src2(data, '\"', a);
      } else {
        src2(data, ',', '}', a);
      }
      return src2data;
      a += strlen(data);
    }
  }
  return 0;
}

int Bonezegei_JSON::src(char ar[], const char *cmp, int n) {
  int a;
  char tmp[32];
  for (a = 0; a < 32; a++) {
    tmp[a] = 0;
  }
  for (a = 0; a < strlen(cmp); a++) {
    tmp[a] = ar[a + n];
  }
  return strcmp(tmp, cmp);
}

void Bonezegei_JSON::src2(char ar[], int n) {
  src2cnt = 0;
  int a = 0;
  for (a = 0; a < 64; a++) src2data[a] = 0;
  a = 0;
  while (ar[n + a] != ',') {
    src2data[a] = ar[n + a];
    a++;
    src2cnt++;
  }
}

void Bonezegei_JSON::src2(char ar[], char enD, int n) {
  src2cnt = 0;
  int a = 0;
  for (a = 0; a < SRC_MEM; a++) src2data[a] = 0;
  a = 0;
  while (ar[n + a] != enD) {
    src2data[a] = ar[n + a];
    a++;
    src2cnt++;
  }
}

void Bonezegei_JSON::src2(char ar[], char enD1, char enD2, int n) {
  src2cnt = 0;
  int a = 0;
  for (a = 0; a < SRC_MEM; a++) src2data[a] = 0;
  a = 0;
  while ((ar[n + a] != enD1) & (ar[n + a] != enD2)) {
    src2data[a] = ar[n + a];
    a++;
    src2cnt++;
  }
}

void Bonezegei_JSON::src2copy(char ar1[], char ar2[]) {
  int a = 0;
  for (a = 0; a < strlen(ar1) + 1; a++) {
    ar2[a] = ar1[a];
  }
}

void Bonezegei_JSON::src2clear(char arr[]) {
  int a = 0;
  for (a = 0; a < strlen(arr); a++) {
    arr[a] = 0;
  }
}
