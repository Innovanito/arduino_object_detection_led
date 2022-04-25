#include <Pixy2.h>

// 시스템 동작 설명서
// sig_3을 발견하면 LED_R이 켜짐
// sig_1을 발견하면 LED_G가 켜짐


#define LED_R 13
#define LED_G 7

Pixy2 pixy;

void setup ()  
{ 
  Serial.begin(115200);
  Serial.print("Starting...\n");

  pixy.init();
  
  pinMode ( LED_R, OUTPUT);  // to set the OUTPUT mode of pin number 13.  
  pinMode ( LED_G, OUTPUT);  // to set the OUTPUT mode of pin number 7.  
}  

void loop ()  
{ 
  int i;
  pixy.ccc.getBlocks();
  
  if(pixy.ccc.numBlocks) {
    Serial.print("Detected ");
    Serial.println(pixy.ccc.numBlocks);
    
    for (i=0; i<pixy.ccc.numBlocks; i++)
    {
      Serial.print("  block ");
      Serial.print(i);
      Serial.print(": ");
      pixy.ccc.blocks[i].print();
    }
    
    if(pixy.ccc.blocks[i].m_signature == 3 ) {
      digitalWrite (LED_R, HIGH); 
    } 
    if ( pixy.ccc.blocks[i].m_signature == 1) {
      digitalWrite (LED_G, HIGH);
    }
  } else {
    digitalWrite (LED_R, LOW); 
    digitalWrite (LED_G, LOW); 
  }
} 
