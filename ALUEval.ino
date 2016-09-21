/*
 ALU Evaluation program
 Read digital inputs, prints the result to the serial monitor  
*/

// digital pin name:
const int ID1 = 2;
const int ID2 = 3;
const int ID3 = 4;
const int ID4 = 5;

const int IM1 = 6;
const int IM2 = 7;
const int IM3 = 8;
const int IM4 = 9;

const int IS0 = 10;
const int IS1 = 11;
const int IS2 = 12;

const int O1 = 14;
const int O2 = 15;
const int O3 = 16;
const int O4 = 17;

const int OC = 18;

int incomingByte = 0;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);

  // make the pins input:
  pinMode(O1, INPUT);
  pinMode(O2, INPUT);
  pinMode(O3, INPUT);
  pinMode(O4, INPUT);
  pinMode(OC, INPUT);

  // make the pins output:
  pinMode(ID1, OUTPUT);
  pinMode(ID2, OUTPUT);
  pinMode(ID3, OUTPUT);
  pinMode(ID4, OUTPUT);

  pinMode(IM1, OUTPUT);
  pinMode(IM2, OUTPUT);
  pinMode(IM3, OUTPUT);
  pinMode(IM4, OUTPUT);

  pinMode(IS0, OUTPUT);
  pinMode(IS1, OUTPUT);
  pinMode(IS2, OUTPUT); 
}

// the loop routine runs over and over again forever:
void loop() {

  Serial.println("Select ALU mode.");
  Serial.println("A:ADD");
  Serial.println("B:SUB");
  Serial.println("C:AND");
  Serial.println("D:OR");
  Serial.println("E:NOT");
  Serial.println("");
  Serial.println("");

  int hoge = 0;
  while (hoge == 0) {    
    if (Serial.available() > 0) { 
      incomingByte = Serial.read();
      
      switch (incomingByte) {
        
      case 'A':
        // select signal
        digitalWrite(IS0, LOW);
        digitalWrite(IS1, LOW);
        digitalWrite(IS2, LOW);
        Serial.println("Start ADD");
        Serial.println("");
        calc();
        hoge = 1;
        break;

      case 'B':
        // select signal
        digitalWrite(IS0, HIGH);
        digitalWrite(IS1, LOW);
        digitalWrite(IS2, LOW);
        Serial.println("Start SUB");
        Serial.println("");
        calc();
        hoge = 1;
        break;   

      case 'C':
        // select signal
        digitalWrite(IS0, LOW);
        digitalWrite(IS1, HIGH);
        digitalWrite(IS2, LOW);
        Serial.println("Start AND");
        Serial.println("");
        calc();
        hoge = 1;
        break;

      case 'D':
        // select signal
        digitalWrite(IS0, HIGH);
        digitalWrite(IS1, HIGH);
        digitalWrite(IS2, LOW);
        Serial.println("Start OR");
        Serial.println("");
        calc();
        hoge = 1;
        break;   

      case 'E':
        // select signal
        digitalWrite(IS0, LOW);
        digitalWrite(IS1, LOW);
        digitalWrite(IS2, HIGH);
        Serial.println("Start NOT");
        Serial.println("");
        calc();
        hoge = 1;
        break;
      
      }   
    }
  }

}


void calc() {

  int Odata[4] = {0, 0, 0, 0};
  int Carry = 0;   

  for (int i=0; i <=1; i++) {
    digitalWrite(ID4, i);

    for (int j=0; j <=1; j++) {
      digitalWrite(ID3, j);

      for (int k=0; k <=1; k++) {
        digitalWrite(ID2, k);

        for (int l=0; l <=1; l++) {
          digitalWrite(ID1, l);

          for (int m=0; m <=1; m++) {
            digitalWrite(IM4, m);

            for (int n=0; n <=1; n++) {
              digitalWrite(IM3, n);

              for (int o=0; o <=1; o++) {
                digitalWrite(IM2, o);

                for (int p=0; p <=1; p++) {
                  digitalWrite(IM1, p);
                  delay(100);
                  
                  // output data
                  Odata[0] = digitalRead(O1);
                  Odata[1] = digitalRead(O2);
                  Odata[2] = digitalRead(O3);
                  Odata[3] = digitalRead(O4);
                  Carry = digitalRead(OC);

                  // print out the states:
                  Serial.println("Input data are shown as below:");
                  Serial.print("[");
                  Serial.print(i);
                  Serial.print(", ");
                  Serial.print(j);
                  Serial.print(", ");
                  Serial.print(k);
                  Serial.print(", ");
                  Serial.print(l);
                  Serial.println("]");
                  Serial.println("");

                  Serial.println("Im data are shown as below:");
                  Serial.print("[");
                  Serial.print(m);
                  Serial.print(", ");
                  Serial.print(n);
                  Serial.print(", ");
                  Serial.print(o);
                  Serial.print(", ");
                  Serial.print(p);
                  Serial.println("]");
                  Serial.println("");

                  Serial.println("Output data are shown as below:");
                  Serial.print("[");
                  Serial.print(Odata[3]);
                  Serial.print(", ");
                  Serial.print(Odata[2]);
                  Serial.print(", ");
                  Serial.print(Odata[1]);
                  Serial.print(", ");
                  Serial.print(Odata[0]);
                  Serial.println("]");
                  Serial.println("");

                  Serial.println("Output carry signal is shown as below:");
                  Serial.print("[");
                  Serial.print(Carry);
                  Serial.println("]");
                  Serial.println("");
                  Serial.println("");
                  
                  delay(100);
                }
              }
            }
          }
        }
      }  
    }
  }

}





