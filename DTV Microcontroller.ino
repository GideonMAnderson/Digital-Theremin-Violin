#include <CapacitiveSensor.h>
CapacitiveSensor   cap0 = CapacitiveSensor(A0,0);
CapacitiveSensor   cap1 = CapacitiveSensor(A0,1);
CapacitiveSensor   cap2 = CapacitiveSensor(A0,2); 
CapacitiveSensor   cap3 = CapacitiveSensor(A0,3); 
CapacitiveSensor   cap4 = CapacitiveSensor(A0,4); 
CapacitiveSensor   cap5 = CapacitiveSensor(A0,5); 
CapacitiveSensor   cap6 = CapacitiveSensor(A0,6); 
CapacitiveSensor   cap7 = CapacitiveSensor(A0,7); 
CapacitiveSensor   cap8 = CapacitiveSensor(A0,8); 
CapacitiveSensor   cap9 = CapacitiveSensor(A0,9); 
CapacitiveSensor   cap10 = CapacitiveSensor(A0,10); 
CapacitiveSensor   cap11 = CapacitiveSensor(A0,11); 
CapacitiveSensor   cap12 = CapacitiveSensor(A0,12); 
CapacitiveSensor   cap13 = CapacitiveSensor(A0,13); 
String tri,saw,sine,touch;
String tableSize = "401";
String switchVal;
long threshKey;
int reset;
void setup()               
{
   cap0.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate on channel 1 - just as an example  
   cap1.set_CS_AutocaL_Millis(0xFFFFFFFF);
   cap2.set_CS_AutocaL_Millis(0xFFFFFFFF); 
   cap3.set_CS_AutocaL_Millis(0xFFFFFFFF); 
   cap4.set_CS_AutocaL_Millis(0xFFFFFFFF); 
   cap5.set_CS_AutocaL_Millis(0xFFFFFFFF);
   cap6.set_CS_AutocaL_Millis(0xFFFFFFFF);
   cap7.set_CS_AutocaL_Millis(0xFFFFFFFF);
   cap8.set_CS_AutocaL_Millis(0xFFFFFFFF);
   cap9.set_CS_AutocaL_Millis(0xFFFFFFFF);
   cap10.set_CS_AutocaL_Millis(0xFFFFFFFF);
   cap11.set_CS_AutocaL_Millis(0xFFFFFFFF);
   cap12.set_CS_AutocaL_Millis(0xFFFFFFFF);
   cap13.set_CS_AutocaL_Millis(0xFFFFFFFF);
   
   Serial.begin(9600);

   reset = 1;

   threshKey = 100;
}

void loop()                   

{
  saw = analogRead(1);
  sine = analogRead(2);
  tri = analogRead(3);

  int switcher = digitalRead(A5);
  
  long start = millis();  
  long key0 =  cap0.capacitiveSensor(30);
  long key1 = cap1.capacitiveSensor(30);  
  long key2 =  cap2.capacitiveSensor(30);
  long key3 = cap3.capacitiveSensor(30);  
  long key4 =  cap4.capacitiveSensor(30);
  long key5 =  cap5.capacitiveSensor(30);
  long key6 = cap6.capacitiveSensor(30);  
  long key7 =  cap7.capacitiveSensor(30);
  long key8 = cap8.capacitiveSensor(30);  
  long key9 =  cap9.capacitiveSensor(30);
  long key10 =  cap10.capacitiveSensor(30);
  long key11 = cap11.capacitiveSensor(30);  
  long key12 =  cap12.capacitiveSensor(30);
  long key13 = cap13.capacitiveSensor(30);  
  
  if ((key0 > threshKey) && (key1 > threshKey)){
    tableSize = "317";
  }
  else if (key0 > threshKey){
    tableSize = "337";
  }
  else if ((key1 > threshKey) && (key2 > threshKey)){
    tableSize = "285";
  }
  else if (key1 > threshKey){
    tableSize = "300";
  }
  else if ((key2 > threshKey) && (key3 > threshKey)){        //empty
    tableSize = "401";
  }
  else if (key2 > threshKey){
    tableSize = "267";
  }
  else if ((key3 > threshKey) && (key4 > threshKey)){
    tableSize = "238";
  }
  else if (key3 > threshKey){
    tableSize = "255";
  }
  else if ((key4 > threshKey) && (key5 > threshKey)){
    tableSize = "212";
  }
  else if (key4 > threshKey){
    tableSize = "225";
  }
  else if ((key5 > threshKey) && (key6 > threshKey)){
    tableSize = "189";
  }
  else if (key5 > threshKey){
    tableSize = "200";
  }
  else if (key6 > threshKey){
    tableSize = "179";
  }
  else if ((key7 > threshKey) && (key8 > threshKey)){
    tableSize = "159";
  }
  else if (key7 > threshKey){
    tableSize = "169";
  }
  else if ((key8 > threshKey) && (key9 > threshKey)){
    tableSize = "142";
  }
  else if (key8 > threshKey){
    tableSize = "150";
  }
  else if ((key9 > threshKey) && (key10 > threshKey)){        //empty
    tableSize = "401";
  }
  else if (key9 > threshKey){
    tableSize = "134";
  }
  else if ((key10 > threshKey) && (key11 > threshKey)){
    tableSize = "119";
  }
  else if (key10 > threshKey){
    tableSize = "126";
  }
  else if ((key11 > threshKey) && (key12 > threshKey)){
    tableSize = "106";
  }
  else if (key11 > threshKey){
    tableSize = "113";
  }
  else if ((key12 > threshKey) && (key13 > threshKey)){
    tableSize = "95";
  }
  else if (key12 > threshKey){
    tableSize = "100";
  }
  else if (key13 > threshKey){
    tableSize = "89";
  }
  else{
    tableSize = "401";
  }

  if (switcher){
    switchVal = "1";
  }
  else{
    switchVal = "0";
  }
  String message = saw + "." + sine + "." + tri + "." + switchVal + "." + tableSize;
  Serial.println(message);
}
