/*
  Simple JSON encoder and decoder
  Author: Bonezegei (Jofel Batutay)
  Date : May 2025

  Note!: it only works on the serialize format like in this example
*/

#include <Bonezegei_JSON.h>
Bonezegei_JSON json;

char decode[128];
char encode[128];

void setup() {
  Serial.begin(9600);

  // set decode array
  sprintf(decode, "{\"cmd\":\"serial commands  \",\"temp\":24.5}");
  Serial.println(decode);
  // Decode 
  // param 1 location of the json string
  // param 2 keyword
  // get will return the value of the keyword
  Serial.println(json.get(decode, "cmd"));
  Serial.println(json.get(decode, "temp"));
  Serial.println();


  // Encode
  // param 1 array 
  // param 2 keyword
  // param 3 value
  json.addData(encode, "cmd", "Hello World");
  json.addData(encode, "coin", "1");
  json.addData(encode, "temperature", 24.143);
  json.addData(encode, "count", 24);
  Serial.print("encoded json: ");
  Serial.println(encode);

  // 
  Serial.println(json.get(encode,"cmd"));
}

void loop() {
}
