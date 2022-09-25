

void tank(void){
  lcd.clear();
 while (wybor=true){   
    
 
if (digitalRead(18)==LOW) {//------------przycisk
    msg[5]=true;
    ok=false;
    while (!ok){
    ok=radio.write(msg, 5);
    }
   lcd.clear();
   msg[5]=false;
   mode=!mode;
   
  delay(400);
}//---------------------------------------przycisk

    if (mode==true ){//-----------------drive mode
      
    msg[0]=map(analogRead(A0),0,1023,0,255);
    msg[1]=map(analogRead(A1),0,1023,0,255);
    ok=false;
    while (!ok){
    ok=radio.write(msg, 2);
    
    }
   
    Serial.print(msg[0]);
    Serial.print("---");
    Serial.println(msg[1]);
    
    lcd.setCursor(3,0); //Ustawienie kursora
    lcd.print("drive mode"); //Wyswietlenie tekstu
     
   }//------------------------------------drive mode
   else {//-------------------------------arm mode
    
    msg[0]=map(analogRead(A0),0,1023,10,250);// silnik 2
    msg[1]=map(analogRead(A1),0,1023,10,250);//silnik 1, na boki
    msg[2]=map(analogRead(A3),0,1023,10,250);// do przodu silnik 3
    msg[3]=map(analogRead(A2),0,1023,10,250);// grip
      if (digitalRead(19)==LOW){
      msg[4]=msg[2];  
      msg[2]=128;// do przodu silnik 4
    } else {
      msg[4]=128;
    }
    

    ok=false;
    while (!ok){
    ok=radio.write(msg, 5);
    
    }
    
    Serial.print(msg[0]);
    Serial.print("---");
     Serial.print(msg[1]);
    Serial.print("---");
     Serial.print(msg[2]);
    Serial.print("---");
    Serial.print(msg[3]);
    Serial.print("---");
    Serial.println(msg[4]);
   
   lcd.setCursor(4,0); //Ustawienie kursora
   lcd.print("arm mode"); //Wyswietlenie tekstu
   
   }//-------------------------------------arm mode
   
}
  }
