//#include <aJSON.h>

char* createPOST(unsigned long time, unsigned energy, unsigned power){
  char str[500];
  str[0]='\0';
  strcpy(str, "POST /SignalPublisherWS/v1/feed/tnunes@c3s.av.it.pt/sensor1 HTTP/1.1 \r\n");
  strcat(str, "X-EMPApiKey: ");
  strcat(str, "jpires-2ad385ad94d08fd6a556feaa95990647ab8097c3 \r\n");
  strcat(str, "Accept: application/json \r\n");
  strcat(str, "Content-type: application/json \r\n");
  strcat(str, createJSON(time, energy, power));
  strcat(str, "\r\n");
  return str;
}

char* createJSON(unsigned long time, unsigned energy, unsigned power){
  char str[200];
  char aux[20];
  strcpy(str,"{ ");
  strcat(str, "\"timestamp\": \"");
  strcat(str, ltoa(time, aux, 10));
  strcat(str, "\", \"energy\": \"");
  strcat(str, itoa(energy, aux, 10));
  strcat(str, "\", \"power\": \"");
  strcat(str, itoa(power, aux, 10));
  strcat(str,"\" }");
  return str;
}
