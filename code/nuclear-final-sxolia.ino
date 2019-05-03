//Δήλωση μεταβλητών
 const int sensorPin=A0;
 int sensorVal=0;
 float baselineTemp=0;
 float temperature=0;
 float voltage=0;


   // Include the Servo library
  #include <Servo.h> 
  
  // Create a servo object
  Servo Servo1;
  Servo Servo2;

void setup() {

   // Αποσύνδεση των servo motors
    Servo1.detach();
    Servo2.detach();

   // Η αναλογική pin AO στην οποία συνδέεται ο ανιχνευτής θερμότητας δίνει τιμές από 0 (αντιστοιχεί σε 0V) έως 1024 (αντιστοιχεί σε 5V) 
    sensorVal = analogRead(sensorPin);
    voltage = (sensorVal/1024.0)*5.0;  //  Άρα η τιμή που δίνει η Α0 σε volts είναι η διπλανή (sensorVal/1024.0)*5.0
    //Μετατροπή της τιμής των Volts που δίνει η  ΑΟ σε θερμοκρασία σε  βαθμούς C
    // Αντιστοιχούν 10mV σε 1 βαθμό κελσίου και διορθώνουμε και με ένα offset
    baselineTemp = (voltage - .5)*100;  // Η Θερμοκρασία περιβάλλοντος

    //στο pin 8 θα συνδεθούν τα ηχεία
    pinMode(8, OUTPUT);
  
    // put your setup code here, to run once:
    Serial.begin(9600);//open serial port

    //όλα τα LEDs αρχικά είναι σβηστά
    for (int pinNumber=2;pinNumber<5;pinNumber++){
      pinMode(pinNumber,OUTPUT);
      digitalWrite(pinNumber, LOW);
    }

    //συνδέονται τα servos στα pins 12 και 13
    delay(1000);
    Servo1.attach(12);
    Servo2.attach(13);
    Servo1.write(0);
    Servo2.write(0);
}

    void loop() {
      // κάθε στιγμή  - μέσα στο loop
   
      // put your main code here, to run repeatedly:
      sensorVal = analogRead(sensorPin);
      Serial.print("Sensor Value: ");
      Serial.print(sensorVal);
      Serial.print(", baselineTemp: ");
      Serial.print(baselineTemp);

      // μέτρηση της τιμής σε volts που δίνει ο ανιχνευτής θερμότητας
      voltage = (sensorVal/1024.0)*5.0;

      // Τύπωση της τιμής 
      Serial.print(", Volts: ");
      Serial.print(voltage);

      //Μετατροπη της τιμής των volts σε θερμοκρασία
      Serial.print (" ,degrees C: ");
       temperature = (voltage - .5)*100;
      Serial.println(temperature);

    // αν η θερμοκρασία είναι μικρότερη από τη θερμοκρασία περιβάλλοντος όλα τα LEDs σβηστά 
     if (temperature < baselineTemp){
        digitalWrite(2, LOW);
        digitalWrite(3, LOW);
        digitalWrite(4, LOW);

        
    // αν η θερμοκρασία είναιαπό 2 έως 4 μονάδες μεγαλύτερη από τη θερμοκρασία περιβάλλοντος ανάβει το ένα  LED
     }else if (temperature >= baselineTemp+2 && temperature < baselineTemp+4){
        digitalWrite(2, HIGH);
        digitalWrite(3, LOW);
        digitalWrite(4, LOW);

              // αν η θερμοκρασία είναιαπό 4 έως 6 μονάδες μεγαλύτερη από τη θερμοκρασία περιβάλλοντος ανάβει και το δεύτερο  LED
           }else if (temperature >= baselineTemp+4 && temperature < baselineTemp+6){
              digitalWrite(2, HIGH);
              digitalWrite(3, HIGH);
              digitalWrite(4, LOW);
       
          
                            // Make servo go to 90 degrees

                            //ταυτόχρονα οι servo motors στρέφουν με βήμα 12μοίρες σε κάθε βήμα τους βραχίονες τους και μαζί και τους σωλήνες με νερό που είναι προσαρτημένοι σε αυτούς
                              for (int i=1;i<130;i+=12){
                                Servo1.write(i);
                                Servo2.write(i);
                                digitalWrite(3, LOW); //σβήνει το δεύτερο LED
                                delay(250);
                                i=i+3;

                                Servo1.write(i);
                                Servo2.write(i);
                                delay(250);
                                i=i+3;

                                Servo1.write(i);
                                Servo2.write(i);
                                delay(250);
                                 digitalWrite(3, HIGH);  //ανάβει το δεύτερο LED  δηλ. αναβοσβήνει
                                i=i+3;

                                 Servo1.write(i);
                                Servo2.write(i);
                                delay(250);
                                i=i+3;

                                //Ακούγεται ήχος κάθε 1 sec
                                tone(8,1000,500);
                                //delay(1000);

                                
                              }
              
                                 Servo1.detach();
                                 Servo2.detach();
                       
               }else if (temperature >= baselineTemp+6){
                  digitalWrite(2, HIGH);
                  digitalWrite(3, HIGH);
                  digitalWrite(4, HIGH);
               }
                
              
                delay(1);

        }
