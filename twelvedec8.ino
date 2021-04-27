
int wb=12;
int m0_ = 5; //right
int m5_ = 6; //left
int m0 = 9; //right
int m5 = 10; //left
int led=12;
int a0 = A0; //right
int a1 = A1;
int a2 = A2;
int a3 = A3;
int a4 = A4;
int a5 = A5; //left
void setup() {
  // put your setup code here, to run once:
  pinMode(m0, OUTPUT);
  pinMode(m5, OUTPUT);
  pinMode(a0, INPUT);
  pinMode(a1, INPUT);
  pinMode(a2, INPUT);
  pinMode(a3, INPUT);
  pinMode(a4, INPUT);
  pinMode(a5, INPUT);
   pinMode(led,OUTPUT);
  Serial.begin(9600);
  if (digitalRead(a0) == HIGH || digitalRead(a1) == HIGH  || digitalRead(a2) == HIGH  || digitalRead(a3) == HIGH  || digitalRead(a4) == HIGH  || digitalRead(a5) == HIGH )
  { delay(3000);
  }
}
void loop() {
  int w;
  static int uturn = 0, right = 0, left = 0, leftofstraight = 0, rightofstraight = 0, ennd = 0, i, contnue, straight, j;
  static char a[100];
  int d = 5;
  // put your main code here, to run repeatedly:
  while (ennd == 0)
  { //continue
    if (digitalRead(a5) == 1 &&  digitalRead(a4) == 1 && digitalRead(a3) == 0 && digitalRead(a2) == 0 && digitalRead(a1) == 1 && digitalRead(a0) == 1 && uturn == 0 && right == 0 && left == 0 && leftofstraight == 0 && rightofstraight == 0 && ennd == 0)
    { analogWrite(m0, 200); //right
      digitalWrite(m5, HIGH); //left
    }
    //continue=going left now turn right
    else if ((digitalRead(a5) == 1 && digitalRead(a4) == 1 && digitalRead(a3) == 1 && digitalRead(a2) == 0 && digitalRead(a1) == 1 && digitalRead(a0) == 1 || digitalRead(a4) == 1 && digitalRead(a3) == 1 && digitalRead(a2) == 0 && digitalRead(a1) == 0) && uturn == 0 && right == 0 && left == 0 && leftofstraight == 0 && rightofstraight == 0 && ennd == 0)
    { analogWrite(m0, 90); //right
      digitalWrite(m5,HIGH); //left
    }
    //continue=going right now turn left
    else if ((digitalRead(a5) == 1 && digitalRead(a4) == 1 && digitalRead(a3) == 0 && digitalRead(a2) == 1 && digitalRead(a1) == 1 && digitalRead(a1) == 1 || digitalRead(a4) == 0 && digitalRead(a3) == 0 && digitalRead(a2) == 1 && digitalRead(a1) == 1) && uturn == 0 && right == 0 && left == 0 && leftofstraight == 0 && rightofstraight == 0 && ennd == 0)
    { analogWrite(m0, 200); //right
      analogWrite(m5, 114); //left
    }
    else if (uturn == 0 && right == 0 && left == 0 && leftofstraight == 0 && rightofstraight == 0 && ennd == 0)
    {//left turn
      if ((digitalRead(a5) == 0 && digitalRead(a4) == 0 && digitalRead(a3) == 0 && digitalRead(a2) == 0 && digitalRead(a1) == 0 && digitalRead(a0) == 0) ||( digitalRead(a5) == 0 && digitalRead(a4) == 0 && digitalRead(a3) == 0 && digitalRead(a2) == 0 && digitalRead(a1) == 1 && digitalRead(a0) == 1)||(digitalRead(a5) == 0 && digitalRead(a4) == 0 && digitalRead(a1) == 1 && digitalRead(a0) == 1)||(digitalRead(a5) == 1 && digitalRead(a4) == 0 && digitalRead(a3) == 0 && digitalRead(a2) == 0 && digitalRead(a1) == 0 && digitalRead(a0) == 1)||(digitalRead(a5) == 0 && digitalRead(a0) == 0))
      { left++;
        //extrainch
        analogWrite(m0, 100); //right
        analogWrite(m5, 113); //left
        delay(35);
        digitalWrite(m0, LOW);
        digitalWrite(m5, LOW);
        delay(120);
        break;
        //analogWrite(m0,110);//right
        //analogWrite(m5,0);//left
        //delay(110);
      }
      //right turn
      if ((digitalRead(a5) == 1 && digitalRead(a4) == 1 && digitalRead(a3) == 0 && digitalRead(a2) == 0 && digitalRead(a1) == 0 && digitalRead(a0) ==0) || digitalRead(a3) == 0 && digitalRead(a2) == 0 && digitalRead(a1) == 0||digitalRead(a0)==0&&digitalRead(a1)==0)
      { right++;
        //extrainch
        analogWrite(m0, 100); //right
        analogWrite(m5, 113); //left
        int p=0;
        while(p<6)
        {p++;
        if(digitalRead(a5) == 0 ||digitalRead(a4) == 0)
        {right=0;
        left++;
          }
          delay(10);
          }       
        digitalWrite(m0, LOW);
        digitalWrite(m5, LOW);
        delay(120);
        break;
        // analogWrite(m0,0);//right
        // analogWrite(m5,130);//left
        //delay(100);
      }

      //u turn
      if (digitalRead(a5) == 1 && digitalRead(a4) == 1 && digitalRead(a3) == 1 && digitalRead(a2) == 1 && digitalRead(a1) == 1 && digitalRead(a0) == 1)
      {
      int p=0,r=0;
      while(p<5)
       {p++; 
       //continue
    if (digitalRead(a5) == 1 &&  digitalRead(a4) == 1 && digitalRead(a3) == 0 && digitalRead(a2) == 0 && digitalRead(a1) == 1 && digitalRead(a0) == 1 && uturn == 0 && right == 0 && left == 0 && leftofstraight == 0 && rightofstraight == 0 && ennd == 0)
    { analogWrite(m0, 200); //right
      digitalWrite(m5, HIGH); //left
    }
    //continue=going left now turn right
    else if ((digitalRead(a5) == 1 && digitalRead(a4) == 1 && digitalRead(a3) == 1 && digitalRead(a2) == 0 && digitalRead(a1) == 1 && digitalRead(a0) == 1 || digitalRead(a4) == 1 && digitalRead(a3) == 1 && digitalRead(a2) == 0 && digitalRead(a1) == 0) && uturn == 0 && right == 0 && left == 0 && leftofstraight == 0 && rightofstraight == 0 && ennd == 0)
    { analogWrite(m0, 90); //right
      digitalWrite(m5,HIGH); //left
    }
    //continue=going right now turn left
    else
    {if ((digitalRead(a5) == 1 && digitalRead(a4) == 1 && digitalRead(a3) == 0 && digitalRead(a2) == 1 && digitalRead(a1) == 1 && digitalRead(a1) == 1 || digitalRead(a4) == 0 && digitalRead(a3) == 0 && digitalRead(a2) == 1 && digitalRead(a1) == 1) && uturn == 0 && right == 0 && left == 0 && leftofstraight == 0 && rightofstraight == 0 && ennd == 0)
    { analogWrite(m0, 200); //right
      analogWrite(m5, 114); //left
    }}
        delay(50);
        if (digitalRead(a5) == 1&& digitalRead(a4) == 1 && digitalRead(a3) == 1 && digitalRead(a2) == 1 && digitalRead(a1) == 1&& digitalRead(a0) == 1)
      {       uturn++;
        //extrainch
        digitalWrite(m0, LOW);
        digitalWrite(m5, LOW);
        delay(120);
        break;
        // analogWrite(m0,0);//right
        // analogWrite(m5,130);//left
        //delay(100);     r++;
      }
              else{break;}
      }
      }
    }
    else {
      //straight
      if (digitalRead(a5) == 1&&digitalRead(a0) == 1&&( digitalRead(a3) == 0 || digitalRead(a2) == 0))
      { straight++;
      }
      //else if(digitalRead(a5)==1||(digitalRead(a5)==1&&digitalRead(a4)==1))
      //{left++;
       // }
        // else if(digitalRead(a0)==1||(digitalRead(a0)==1&&digitalRead(a4)==1))
      //{right++;
       //}
      else if (digitalRead(a5) == 0 && digitalRead(a4) == 0 && digitalRead(a3) == 0 && digitalRead(a2) == 0 && digitalRead(a1) == 0 && digitalRead(a0) == 0)
      { ennd++;
      }
      if (left > 0 && ennd == 0)
      { analogWrite(m0,200);
        analogWrite(m5,180);
        //right
        delay(10);
        digitalWrite(m5_,HIGH); //left
        int turn=0;
        delay(10);
       while(turn==0)
       {if(digitalRead(a5) == 1 && digitalRead(a4) == 0 && digitalRead(a3) == 0 && digitalRead(a2) == 1 && digitalRead(a1) == 1&& digitalRead(a0) == 1)
       {turn++;
             
        }
        }
        digitalWrite(m5_, LOW);
        digitalWrite(m0, LOW);
        digitalWrite(m5, LOW);
        delay(330);
        a[i] = 'L';
        Serial.print(i);
       Serial.print(a[i]);
        i++;
        uturn = 0;
        right = 0;
        left = 0;
        ennd = 0;
        straight = 0;
        break;
       
      }
      else if (straight > 0 && ennd == 0)
      { //straight();
        a[i] = 'S';
        Serial.print(i);
       Serial.print(a[i]);
        
        i++;
        uturn = 0;
        right = 0;
        left = 0;
        straight = 0;
        ennd = 0;
        break;
      }
      else if (right > 0 && ennd == 0)
      { digitalWrite(m5,HIGH);
        analogWrite(m0, 120);
        //left
        delay(10);
        analogWrite(m0_,200); //left
        int turn=0;
        delay(10);
       while(turn==0)
       {if(digitalRead(a5) == 1 && digitalRead(a4) == 1 && digitalRead(a3) == 1 && digitalRead(a2) == 0 && digitalRead(a1) == 0 && digitalRead(a0) == 1)
       {turn++;

        }
        }
        digitalWrite(m0_, LOW);
        digitalWrite(m5, LOW);
        digitalWrite(m0, LOW);
        delay(330);
        a[i] = 'R';
         Serial.print(i);
       Serial.print(a[i]);
        i++;
        uturn = 0;
        right = 0;
        left = 0;
        leftofstraight = 0;
        rightofstraight = 0;
        ennd = 0;
        straight = 0;
        break;
 
      }
      else if (uturn > 0 && ennd == 0)
      { digitalWrite(m5,255);
        analogWrite(m0_,230);
        int turn=0;
        delay(200);
        while(turn==0)
       {if(digitalRead(a5) == 1 && digitalRead(a4) == 1 && digitalRead(a3) == 1 && digitalRead(a2) == 1 && digitalRead(a1) == 1 && digitalRead(a0) == 0)
       {turn++;
       digitalWrite(m0_, LOW);
        digitalWrite(m5, LOW);
         
        }
        }
        delay(330);
        //left
        //delay(10);
        // analogWrite(m0_,90);//left
        //delay(830);
        //digitalWrite(m0_,LOW);
        a[i] = 'B';
        i++;
        uturn = 0;
        right = 0;
        left = 0;
        leftofstraight = 0;
        rightofstraight = 0;
        ennd = 0;
        straight = 0;
        break;
           
      }
      //end
      else if (ennd == 1)
      { digitalWrite(m0, LOW);  
        digitalWrite(m5, LOW);
        digitalWrite(led,HIGH);
        break;
      }
    }
  }
  if (ennd == 1)
  { static int m,l;
    for (i = 1; i <= 1; i++)
    {
      static int b, k, i, j;
      static int q;
      l = strlen(a);
      m = l;
      for (j = 0; j < l; j++)
      { if (a[j] == 'B')
        { if (a[j - 1] == 'L' && a[j + 1] == 'R')
          { a[j - 1] = 'B';
            for (k = j; k < l; k++)
            { a[k] = a[k + 2];
            }
            l = l - 2;
          }
          else if (a[j - 1] == 'L' && a[j + 1] == 'S')
          { a[j - 1] = 'R';
            for (k = j; k < l; k++)
            { a[k] = a[k + 2];
            }
            l = l - 2;
          }
          else if (a[j - 1] == 'R' && a[j + 1] == 'L')
          { a[j - 1] = 'B';
            for (k = j; k < l; k++)
            { a[k] = a[k + 2];
            }
            l = l - 2;
          }
          else if (a[j - 1] == 'S' && a[j + 1] == 'L')
          { a[j - 1] = 'R';
            for (k = j; k < l; k++)
            { a[k] = a[k + 2];
            }
            l = l - 2;
          }
          else if (a[j - 1] == 'S' && a[j + 1] == 'S')
          { a[j - 1] = 'B';
            for (k = j; k < l; k++)
            { a[k] = a[k + 2];
            }
            l = l - 2;
          }
          else if (a[j - 1] == 'L' && a[j + 1] == 'L')
          { a[j - 1] = 'S';
            for (k = j; k < l; k++)
            { a[k] = a[k + 2];
            }
            l = l - 2;
          }
          j = j - 2;
        }
      }
    }
    //
    //for(i=0;i<l;i++)
    //{printf("%c",a[i]);
    //}
    i=0;
    delay(5000);
    digitalWrite(led,LOW);
    delay(5000);
    while (i <l)
    { //continue
    if (digitalRead(a5) == 1 &&  digitalRead(a4) == 1 && digitalRead(a3) == 0 && digitalRead(a2) == 0 && digitalRead(a1) == 1 && digitalRead(a0) == 1)
    { analogWrite(m0, 200); //right
      digitalWrite(m5, HIGH); //left
    }
    //continue=going left now turn right
    else if ((digitalRead(a5) == 1 && digitalRead(a4) == 1 && digitalRead(a3) == 1 && digitalRead(a2) == 0 && digitalRead(a1) == 1 && digitalRead(a0) == 1 || digitalRead(a4) == 1 && digitalRead(a3) == 1 && digitalRead(a2) == 0 && digitalRead(a1) == 0))
    { analogWrite(m0, 90); //right
      digitalWrite(m5,HIGH); //left
    }
    //continue=going right now turn left
    else if ((digitalRead(a5) == 1 && digitalRead(a4) == 1 && digitalRead(a3) == 0 && digitalRead(a2) == 1 && digitalRead(a1) == 1 && digitalRead(a1) == 1 || digitalRead(a4) == 0 && digitalRead(a3) == 0 && digitalRead(a2) == 1 && digitalRead(a1) == 1))
    { analogWrite(m0, 200); //right
      analogWrite(m5, 114); //left
    }
      else if (digitalRead(a5) == 0 && digitalRead(a4) == 0 && digitalRead(a3) == 0 && digitalRead(a2) == 0 && digitalRead(a1) == 0 && digitalRead(a0) == 0 || digitalRead(a5) == 0 && digitalRead(a4) == 0 && digitalRead(a3) == 0 && digitalRead(a2) == 0 && digitalRead(a1) == 1&& digitalRead(a0) == 1||digitalRead(a5) == 0 && digitalRead(a4) == 0 && digitalRead(a1) == 1&& digitalRead(a0) == 1||digitalRead(a5) == 1 && digitalRead(a4) == 0 && digitalRead(a3) == 0 && digitalRead(a2) == 0 && digitalRead(a1) == 0 && digitalRead(a0) == 1||digitalRead(a5) == 1 && digitalRead(a4) == 1 && digitalRead(a3) == 0 && digitalRead(a2) == 0 && digitalRead(a1) == 0 && digitalRead(a0) == 0||digitalRead(a3) == 0 && digitalRead(a2) == 0 && digitalRead(a1) == 0||digitalRead(a0)==0&&digitalRead(a1)==0)
      { if (a[i] == 'L')
        {
          //extrainch
        analogWrite(m0, 100); //right
        analogWrite(m5, 113); //left
        delay(35);
        digitalWrite(m0, LOW);
        digitalWrite(m5, LOW);
        delay(120);
        analogWrite(m0,200);
        analogWrite(m5,180);
        //right
        delay(10);
        digitalWrite(m5_,HIGH); //left
        int turn=0;
        delay(10);
       while(turn==0)
       {if(digitalRead(a5) == 1 && digitalRead(a4) == 0 && digitalRead(a3) == 0 && digitalRead(a2) == 1&& digitalRead(a1) == 1 && digitalRead(a0) == 1)
       {turn++;
             
        }
        }
        digitalWrite(m5_, LOW);
        digitalWrite(m0, LOW);
        digitalWrite(m5, LOW);
        delay(250);
          i++;
        }
        else if (a[i] == 'S')
        { i++;
        delay(200);
        }
        else if (a[i] == 'R')
        {//extrainch
        analogWrite(m0, 100); //right
        analogWrite(m5, 113); //left
        delay(35);
        digitalWrite(m0, LOW);
        digitalWrite(m5, LOW);
        delay(120);
          digitalWrite(m5,HIGH);
        analogWrite(m0, 120);
        //left
        delay(10);
        analogWrite(m0_,200); //left
        int turn=0;
        delay(10);
       while(turn==0)
       {if(digitalRead(a5) == 1 && digitalRead(a4) == 1 && digitalRead(a3) == 1 && digitalRead(a2) == 0 && digitalRead(a1) == 0 && digitalRead(a0) == 1)
       {turn++;

        }
        }
        digitalWrite(m0_, LOW);
        digitalWrite(m5, LOW);
        digitalWrite(m0, LOW);
        delay(330);
          i++;
        }
      }
    }
    ennd=2;
  }
  while (ennd < 3 && ennd >= 2)
  { //continue
    if (digitalRead(a5) == 1 &&  digitalRead(a4) == 1 && digitalRead(a3) == 0 && digitalRead(a2) == 0 && digitalRead(a1) == 1 && digitalRead(a0) == 1 )
    { analogWrite(m0, 200); //right
      digitalWrite(m5, HIGH); //left
    }
    //continue=going left now turn right
    else if ((digitalRead(a5) == 1 && digitalRead(a4) == 1 && digitalRead(a3) == 1 && digitalRead(a2) == 0 && digitalRead(a1) == 1 && digitalRead(a0) == 1 || digitalRead(a4) == 1 && digitalRead(a3) == 1 && digitalRead(a2) == 0 && digitalRead(a1) == 0) )
    { analogWrite(m0, 90); //right
      digitalWrite(m5,HIGH); //left
    }
    //continue=going right now turn left
    else if ((digitalRead(a5) == 1 && digitalRead(a4) == 1 && digitalRead(a3) == 0 && digitalRead(a2) == 1 && digitalRead(a1) == 1 && digitalRead(a1) == 1 || digitalRead(a4) == 0 && digitalRead(a3) == 0 && digitalRead(a2) == 1 && digitalRead(a1) == 1))
    { analogWrite(m0, 200); //right
      analogWrite(m5, 114); //left
    }
    else if (digitalRead(a5) == 0 && digitalRead(a4) == 0 && digitalRead(a3) == 0 && digitalRead(a2) == 0 && digitalRead(a1) == 0 && digitalRead(a0) == 0)
    { ennd++;
    digitalWrite(led,HIGH);
      digitalWrite(m0, LOW);
      digitalWrite(m5, LOW);
       delay(3000);
      digitalWrite(led,LOW);
    }

  }
}
