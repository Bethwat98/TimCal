//#define debug = true;

const int secinhr = 3600;
const int secinmin = 60;

int userInput() {
   while(!Serial.available()){}
   return Serial.parseInt();
}

void cal(){
  int hours;
  int mins;
  int secs;
  int calSize;
  unsigned int tempsecs = 0;
  unsigned int endsecs = 0;

  Serial.println("Enter the number of times you want to add up (Max 5)");
  do{
    calSize = userInput();}
  while (calSize < 1 || calSize > 5);
  
  #ifdef debug
    Serial.println(calSize);
  #endif
  
  Serial.println("Hours: Min 0, Max 23");
  Serial.println("Mins & Secs: Min 0, Max 59");
  
  for (int l = 0; l < calSize; l++){
    
    #ifdef debug
      Serial.print("Current End Time: ");
      Serial.println(endsecs);
    #endif
    
    Serial.print("Enter Hours : ");
    
    do{
      hours = userInput();}
    while (hours < 0 || hours > 23);
    tempsecs = hours * secinhr;
    Serial.println(hours);
    
    #ifdef debug
      Serial.print("Current Temp Time: ");
      Serial.println(tempsecs);
    #endif
    
    Serial.print("Enter Minutes : ");
    do{
      mins = userInput();}
    while (mins < 0 || mins > 59);
    tempsecs = tempsecs + (mins * secinmin);
    Serial.println(mins);
    
    #ifdef debug
      Serial.print("Current Temp Time: ");
      Serial.println(tempsecs);
    #endif
    
    Serial.print("Enter Seconds : ");
    do{
      secs = userInput();}
    while (secs < 0 || secs > 59);
    tempsecs = tempsecs + secs;
    Serial.println(secs);
    
    #ifdef debug
      Serial.print("Current Temp Time: ");
      Serial.println(tempsecs);
    #endif
    
    endsecs = endsecs + tempsecs;

    Serial.print("Inputed time is: ");
    Serial.print(hours);
    Serial.print(" Hr ");
    Serial.print(mins);
    Serial.print(" Mins and ");
    Serial.print(secs);
    Serial.println(" Secs");

    #ifdef debug
      Serial.print("Current End Time: ");
      Serial.println(endsecs);
    #endif
  }
  printend(endsecs);
}


void printend(int endtime){
  int endhr = endtime / secinhr;
  int endmin = (endtime / secinmin) % secinmin;
  int endsec = endtime % secinmin;

 Serial.print("Calculated time is: ");
    Serial.print(endhr);
    Serial.print(" Hr ");
    Serial.print(endmin);
    Serial.print(" Mins and ");
    Serial.print(endsec);
    Serial.println(" Secs");
  
}

void setup() {
  Serial.begin(9600);
  cal();
  Serial.println("Thank you for using me! Bye :)");
}
void loop() {
}
