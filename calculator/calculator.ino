#include <Keypad.h>

int add(int num1, int num2);
int subtract(int num1, int num2);
int divide(int num1, int num2);
int multiply(int num1, int num2);

void(* resetFunc) (void) = 0;

const byte ROWS = 4;
const byte COLS = 4;

char hexaKeys[ROWS][COLS] = {
  {'1','2','3','+'},
  {'4','5','6','-'},
  {'7','8','9','/'},
  {'^','0','#','*'}
};

byte rowPins[ROWS] = {9, 8, 7, 6};
byte colPins[COLS] = {5, 4, 3, 2,};

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

int num1 = 0;
int num2 = 0;
int sum = 0;
char oper = '-';

char number[10];
char number2[10];

int i = 0;

int step = 1;


void setup() {
  Serial.begin(9600);
}

void loop() {
  char customKey = customKeypad.getKey();

  if(customKey == '^')
  {
    resetFunc();
  }

  if(step == 1 && customKey != NO_KEY)
  {
    if(customKey >= '0' && customKey <= '9')
    {
      number[i] = customKey;
      Serial.println(number[i]);
      i++;
      customKey = NO_KEY;
    }
    else if(customKey == '#')
    {
      i = 0;
      step++;
      customKey = NO_KEY;
      Serial.println("Step has been incremented");
    }
  }

  if(step == 2 && customKey != NO_KEY)
  {
    switch(customKey)
    {
      case '+':
        oper = customKey;
        Serial.println("Operator has been set to: +");
        step++;
        break;
      
      case '-':
        oper = customKey;
        Serial.println("Operator has been set to: -");
        step++;
        break;

      case '*':
        oper = customKey;
        Serial.println("Operator has been set to: *");
        step++;
        break;

      case '/':
        oper = customKey;
        Serial.println("Operator has been set to: /");
        step++;
        break;
      
      case '^':
        oper = customKey;
        Serial.println("Operator has been set to: ^");
        step++;
        break;

      default:
        Serial.println("Incorrect input!");
    }
  }

  if(step == 3 && customKey != NO_KEY)
  {
    if(customKey >= '0' && customKey <= '9')
    {
      number2[i] = customKey;
      Serial.println(number2[i]);
      i++;
      customKey = NO_KEY;
    }
    else if(customKey == '#')
    {
      i = 0;
      step++;
      customKey = NO_KEY;
      Serial.println("Step has been incremented");
    }
  }

  if(step == 4)
  {
    num1 = atoi(number);
    num2 = atoi(number2);

    switch(oper)
    {
      case '+':
        sum = add(num1,num2);
        step++;
        break;

      case '-':
        sum = subtract(num1,num2);
        step++;
        break;

      case '*':
        sum = multiply(num1,num2);
        step++;
        break;

      case '/':
        sum = divide(num1,num2);
        step++;
        break;
    }
  }

  if(step == 5)
  {
    Serial.println(sum);
  }

}

int add(int num1, int num2)
{
  return num1 + num2;
}

int subtract(int num1, int num2)
{
  return num1 - num2;
}

int divide(int num1, int num2)
{
  return num1 / num2;
}

int multiply(int num1, int num2)
{
  return num1 * num2;
}



