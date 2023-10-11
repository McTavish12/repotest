const int numLed              = 4;
const int leds[numLed]        = {6, 9, 10, 11};

const int numButton           = 2;
const int buttons[numButton]  = {2, 13};

int state[numButton]          = {0, 0};
int lastState[numButton]      = {0, 0};
int flag[numButton]           = {0, 0};


void setup()
{
  for(int i = 0; i < numLed; i++)
  {
    pinMode(leds[i], OUTPUT);
  }

  for(int i = 0; i < numButton; i++)
  {
    pinMode(buttons[i], INPUT);
  }
  Serial.begin(9600);
}

void loop()
{
  for(int i = 0; i < numButton; i ++)
  {
    state[i] = digitalRead(buttons[i]);

    if(state[i] != lastState[i])
    {
      if(state[i] == 1)
      {
        flag[i] = 1;
        Serial.print(flag[1]);
        Serial.print("  --  ");
        Serial.println(flag[2]);
      }
      else
      {
        flag[i] = 0;
        Serial.print(flag[1]);
        Serial.print("  --  ");
        Serial.println(flag[2]);
      }
    }
    lastState[i] = state[i];
  }
}

