
int redled = D3;
int blueled = D4;
int greenled = D5;

void LED_Off();
int ledToggle(String command);


void setup() 
{
    pinMode(redled, OUTPUT);
    pinMode(blueled, OUTPUT);
    pinMode(greenled, OUTPUT);
    
    Particle.function("led", ledToggle);
}

void loop() {

}

void LED_Off()
{
    digitalWrite(redled, LOW);
    digitalWrite(blueled, LOW);
    digitalWrite(greenled, LOW);
}

int ledToggle(String command)
{
    LED_Off();
    Particle.publish("Toggle_LED", command);
    
    if (command == "redled")
    {
        digitalWrite(redled, HIGH);
        return 1;
    }
    else if (command == "blueled")
    {
        digitalWrite(blueled, HIGH);
        return 1;
    }
    else if (command == "greenled")
    {
        digitalWrite(greenled, HIGH);
        return 1;
    }
    else
    {
        return -1;
    }
}

