void setup() {
  // Baud rate things
  Serial.begin(9600);
  
  // Waiting/delay
  while (!Serial) {
    ; 
  }
}

void loop() {
  // Print "Hello World!"
  Serial.println("Hello World!");
  
  // Wait 1 second ig
  delay(1000);
}
