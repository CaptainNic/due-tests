/* Serial Test
 *
 * Listens for pin numbers over Serial
 * and returns the current state of the pin.
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
      readPin( message );
    }
  }
}

void readPin( int pin ) {
  if( pin < 22 ) {          // Unsupported
    readUnsupported( pin );
  } else if ( pin < 54 ) {  // 22-53: Digital IO
    readDigitalPin( pin ); 
  } else {
   readUnsupported( pin );  // Unsupported 
  }
}

void readUnsupported( int pin ) {
  Serial.print( pin );
  Serial.println( ": Unsupported" );
}

void readDigitalPin( int pin ) {
  Serial.print( pin );
  Serial.print( " (Digital): " );
  if( HIGH == digitalRead( pin ) ) {
    Serial.println( "HIGH" ); 
  } else {
    Serial.println( "LOW" );
  }
}

void readAnalogPin( int pin ) {
  Serial.print( pin );
  Serial.print( " (Analog): " );
  Serial.println( analogRead( pin ) );
}
