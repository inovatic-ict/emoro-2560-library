/************************************************************************************************************/
/*      Inovatic-ICT d.o.o                                                                                  */
/*                                                                                                          */
/*      EMoRo Example:      Bluetooth.changePasskey                                                         */
/*      Board name:         EMoRo 2560 v3.2                                                                 */
/*      MCU name:           ATMEGA2560-16                                                                   */
/*      Clock:              16 MHz                                                                          */
/*      File description:                                                                                   */
/*            This sketch shows usage of function Bluetooth.changePasskey(<new passkey>); which change      */
/*            Bluetooth pass_key. New passkey will be valid for Bluetooth connection of EMoRo 2560          */
/*            controller with pairing device.                                                               */
/*            Any time it is possible to restore initial settings of Bluetooth name and password by         */
/*            resetting EMoRo 2560 controller and holding SW_1 while restarting the controller.             */
/*            Initial Bluetooth name is: "EMoRo 2560", initial passkey is: "0000".                         */
/*      The circuit:                                                                                        */
/*            * Attach GLAM module to EMoRo 2560 controller                                                 */
/*                                                                                                          */
/*      Necessary equipment:                                                                                */
/*                          EMoRo 2560 controller                                                           */
/*                          GLAM module with Bluetooth option                                               */
/*      More info: www.emoro.eu                                                                             */
/************************************************************************************************************/

char new_passkey[16]="1234";                                    // initialize variable - new passkey of Bluetooth device

void setup(){                      
  int res;

  Serial.begin(9600);                                           // initialize serial communication
  Serial.println("Example: Bluetooth.changePasskey");           // send example name to console

  if(ReadEmoroHardware() & BLUETOOTH_AVAILABLE)                 // if Bluetooth available
    Serial.println("Bluetooth Available");                      // print constant string
  else
    Serial.println("Bluetooth Not Available");                  // print constant string

  res=Bluetooth.changePasskey(new_passkey);                     // change Bluetooth passkey to new_passkey

  if(res == 0){                                                 // if passkey changed successfully 
    Serial.print("Passkey successfully changed to: \"");        // print constant string
    Serial.print(new_passkey);                                  // print Bluetooth's new name
    Serial.println("\"");                                       // print constant string
  }
  else
    Serial.println("Failed");                                   // print constant string

  // print status on LCD:
  if(ReadEmoroHardware() & LCD_AVAILABLE){                      // if LCD is available
    Lcd.locate(0, 0);                                           // set LCD cursor position (row, column)
    Lcd.print("changePasskey();");                              // print constant string
    Lcd.locate(1, 0);                                           // set LCD cursor position (row, column)
    if(res == 0)                                                // if passkey changed successfully
      Lcd.print("Successfully");                                // print constant string
    else
      Lcd.print("Failed");                                      // print constant string
  }
}

void loop(){         
  if(Bluetooth.connection()){                                   // if Bluetooth connection is established with partner device
    Serial1.println("Hello from Bluetooth");                    // send a message via bluetooth
  }
  delay(500);                                                   // wait for 500ms
}

/************************************************************************************************************/
/*                                              end of file                                                 */
/************************************************************************************************************/

