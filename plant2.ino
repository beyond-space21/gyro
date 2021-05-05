#include <DS3231.h>
#include <EEPROM.h>

DS3231  clc(SDA, SCL);
Time T;

String executionDataST;
int executionData[50] =// start.min , end.min , end.second , date , hour
{
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  1, 1, 1, 1, 0, 0, 1, 0, 0, 0,
  5, 2, 3, 4, 0, 0, 5, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  24, 24, 24, 24, 24, 24, 24, 24, 24, 24
};


int m, s, d;

# define S1 2
# define S2 3
# define S3 4
# define S4 5
# define S5 6
# define S6 7
# define S7 8
# define S8 9
# define S9 10
# define S10 11

bool printState = true;

void setup()
{
  Serial.begin(9600);
  clc.begin();

  //  clc.setTime(1, 0, 40);     // Set the time to 12:00:00 (24hr format)


  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(S4, OUTPUT);
  pinMode(S5, OUTPUT);
  pinMode(S6, OUTPUT);
  pinMode(S7, OUTPUT);
  pinMode(S8, OUTPUT);
  pinMode(S9, OUTPUT);
  pinMode(S10, OUTPUT);

  //for (int i = 0 ; i < 50 ; ++i)
  //{
  //    executionDataST[i] = char(executionData[i]);
  //}
  Serial.println(intAtoString(executionData));

}

void loop() {
  T = clc.getTime();

  m = T.min;
  s = T.sec;
  d = T.date;

  if (((T.date == 0) || (T.date == executionData[30])) && ((T.hour == 24) || (T.hour == executionData[40])))
    triger1();

  if (((T.date == 0) || (T.date == executionData[31])) && ((T.hour == 24) || (T.hour == executionData[41])))
    triger2();

  if (((T.date == 0) || (T.date == executionData[32])) && ((T.hour == 24) || (T.hour == executionData[42])))
    triger3();

  if (((T.date == 0) || (T.date == executionData[33])) && ((T.hour == 24) || (T.hour == executionData[43])))
    triger4();

  if (((T.date == 0) || (T.date == executionData[34])) && ((T.hour == 24) || (T.hour == executionData[44])))
    triger5();

  if (((T.date == 0) || (T.date == executionData[35])) && ((T.hour == 24) || (T.hour == executionData[45])))
    triger6();

  if (((T.date == 0) || (T.date == executionData[36])) && ((T.hour == 24) || (T.hour == executionData[46])))
    triger7();

  if (((T.date == 0) || (T.date == executionData[37])) && ((T.hour == 24) || (T.hour == executionData[47])))
    triger8();

  if (((T.date == 0) || (T.date == executionData[38])) && ((T.hour == 24) || (T.hour == executionData[48])))
    triger9();

  printState = false;

  if (((T.date == 0) || (T.date == executionData[39])) && ((T.hour == 24) || (T.hour == executionData[49])))
    triger10();

  printState = true;
  //  Serial.println(clc.getTimeStr());
}


void triger1() {
  if ((m >= executionData[0]) && (m <= executionData[10])) {
    digitalWrite(S1, HIGH);
    _print("S1");
  } else {
    if ((s < executionData[20]) && (m == executionData[10] + 1)) {
      _print("S1");
      digitalWrite(S1, LOW);
    }
  }
}
void triger2() {
  if ((m >= executionData[1]) && (m <= executionData[11])) {
    digitalWrite(S2, HIGH);
    _print("S2");
  } else {
    if ((s < executionData[21]) && (m == executionData[11] + 1)) {
      _print("S2");
      digitalWrite(S2, LOW);
    }
  }
}
void triger3() {
  if ((m >= executionData[2]) && (m <= executionData[12])) {
    digitalWrite(S3, HIGH);
    _print("S3");
  } else {
    if ((s < executionData[22]) && (m == executionData[12] + 1)) {
      _print("S3");
      digitalWrite(S3, LOW);
    }
  }
}
void triger4() {
  if ((m >= executionData[3]) && (m <= executionData[13])) {
    digitalWrite(S4, HIGH);
    _print("S4");
  } else {
    if ((s < executionData[23]) && (m == executionData[13] + 1)) {
      _print("S4");
      digitalWrite(S4, LOW);
    }
  }
}
void triger5() {
  if ((m >= executionData[4]) && (m <= executionData[14])) {
    digitalWrite(S5, HIGH);
    _print("S5");
  } else {
    if ((s < executionData[24]) && (m == executionData[14] + 1)) {
      _print("S5");
      digitalWrite(S5, LOW);
    }
  }
}
void triger6() {
  if ((m >= executionData[5]) && (m <= executionData[15])) {
    digitalWrite(S6, HIGH);
    _print("S6");
  } else {
    if ((s < executionData[25]) && (m == executionData[15] + 1)) {
      _print("S6");
      digitalWrite(S6, LOW);
    }
  }
}
void triger7() {
  if ((m >= executionData[6]) && (m <= executionData[16])) {
    digitalWrite(S7, HIGH);
    _print("S7");
  } else {
    if ((s < executionData[26]) && (m == executionData[16] + 1)) {
      _print("S7");
      digitalWrite(S7, LOW);
    }
  }
}
void triger8() {
  if ((m >= executionData[7]) && (m <= executionData[17])) {
    digitalWrite(S8, HIGH);
    _print("S8");
  } else {
    if ((s < executionData[27]) && (m == executionData[17] + 1)) {
      _print("S8");
      digitalWrite(S8, LOW);
    }
  }
}
void triger9() {
  if ((m >= executionData[8]) && (m <= executionData[18])) {
    digitalWrite(S9, HIGH);
    _print("S9");
  } else {
    if ((s < executionData[28]) && (m == executionData[18] + 1)) {
      _print("S9");
      digitalWrite(S9, LOW);
    }
  }
}
void triger10() {
  if ((m >= executionData[9]) && (m <= executionData[19])) {
    digitalWrite(S10, HIGH);
    _print("S10");
  } else {
    if ((s < executionData[29]) && (m == executionData[19] + 1)) {
      _print("S10");
      digitalWrite(S10, LOW);
    }
  }
}

void _print(String a) {
  //  if(printState){
  //    Serial.print(a);
  //    Serial.print(" | ");
  //  }
  //  else
  //  Serial.println(a);
}

String intAtoString(int a[50]) {
  String b=b+inttoString(a[0]);

  for (int i = 1; i < 50; i++) {
    b = b + "," + inttoString(a[i]);
  }
  return b;
}

String inttoString(int a) {
  String b,e;
  int d = a;
 int g;

  if(d==0)b = d;
  while (d != 0) {
    b = b + (d % 10);
    d=d/10;
  }
  for (int i = b.length()-1; i >=0; i--) {
    e =e+b[i];
  }
  return e;
}
