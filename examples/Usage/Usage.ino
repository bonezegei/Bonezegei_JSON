#include "Bonezegei_JSON.h"

Bonezegei_JSON json;
char response[128];

void setup() {
  Serial.begin(9600);

  sprintf(json.data, "{\"cmd\":\"serial commands  \",\"temp\":24.5}");

  Serial.println(json.data);
  Serial.println(json.get("cmd"));

  Serial.println(json.get("temp"));

  json.addData(response, "cmd", "application sdsad Hello ");
  json.addData(response, "coin", "1");
  json.addData(response, "temperature", 24.143);
  json.addData(response, "count", 24);
  Serial.println(response);

  Serial.println(json.get(response,"cmd"));


}

void loop() {
  // put your main code here, to run repeatedly:
}
