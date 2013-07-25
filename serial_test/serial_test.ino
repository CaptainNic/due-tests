/* Serial Test
 *
 * This code listens for messages over serial
 * and when a newline is found parses the int
 * out of the message and send it back.
 *
 * Author: Nic Breidinger
 * Date: 2013/07/25
 */

int message = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin( 9600 );
  Serial.println( "Starting up Serial..." );
}

void loop() {
  // put your main code here, to run repeatedly: 
  while( Serial.available() > 0 ) {
     message = Serial.parseInt();
     if( Serial.read() == '\n' ) {
       Serial.print( "Parsed message: " );
       Serial.println( message );
     }
  }
}
