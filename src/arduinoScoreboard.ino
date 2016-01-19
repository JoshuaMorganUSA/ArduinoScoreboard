
//PWM FET Pins
int led_red = 3;
int led_green = 5;
int led_blue = 6;


//595 Pins
int latchPin = 8;
int clockPin = 12;
int dataPin = 11;

int latch2 = 10;
int clock2 = 9;
int data2 = 7;


//color stuff
int currentred = 0;
int currentgreen = 0;
int currentblue = 0;
int firstrun = 1;



//Input stuff
String inputString = "";
boolean stringComplete = false;

//holds the input parameters
String digit1 = "";
String digit2 = "";
String incolor_red = "";
String incolor_green = "";
String incolor_blue = "";


int leds[] = {led_red, led_green, led_blue};

void parseInput(String instring);
int get7seg(String input);
void writedisplay(int char1, int char2);
void writergb(int red, int green, int blue);


void setup() {
	
	//595 pins
	pinMode(latchPin, OUTPUT);
	pinMode(clockPin, OUTPUT);
	pinMode(dataPin, OUTPUT);
	digitalWrite(clockPin, LOW);

	digitalWrite(latchPin, HIGH);
	
	pinMode(latch2, OUTPUT);
	pinMode(data2, OUTPUT);
	pinMode(clock2, OUTPUT);
	
	
	
	Serial.begin(9600);
	Serial.println("START");
	/*
	digitalWrite(latchPin, LOW);
	shiftOut(dataPin, clockPin, LSBFIRST, data);
	shiftOut(dataPin, clockPin, LSBFIRST, (data >> 8));	
	digitalWrite(latchPin, HIGH);	
	
	
	*/
	
	writedisplay(get7seg(""), get7seg(""));
	
  for(int i = 0; i < 3; i++)
  {
	  pinMode(leds[i], OUTPUT);
	  digitalWrite(leds[i], HIGH);
  }
 
}



void loop() {
	//unsigned int data = 0x8000;
	/*	int data = 0;	
	for(int i = 0; i < 16; i++)
	{

		if(i == 0)
			data = 1;
		else	
			data = 0;
		
		
		digitalWrite(latchPin, LOW);
		//shiftOut(dataPin, clockPin, LSBFIRST, data);
		//shiftOut(dataPin, clockPin, LSBFIRST, (data >> 8));	
		digitalWrite(clockPin, LOW);
		digitalWrite(dataPin, data);
		digitalWrite(clockPin, HIGH);
		//digitalWrite(latchPin, LOW);
		digitalWrite(latchPin, HIGH);
		
		
		if(i == 13 )
		{
			digitalWrite(led_red, HIGH);
			digitalWrite(led_blue, LOW);
			digitalWrite(led_green, LOW);
			
		}
		
		else if(i == 12)
		{
			digitalWrite(led_red, LOW);
			digitalWrite(led_blue, HIGH);
			digitalWrite(led_green, LOW);
		}
		else
		{
			digitalWrite(led_red, HIGH);
			digitalWrite(led_blue, HIGH);
			digitalWrite(led_green, HIGH);			
		}
		
		//Serial.println(i);
		//delay(500);
		
		//data = data >> 1;
	}
	
	*/
	/*
	
	unsigned int data = 0x0004;
	
	digitalWrite(latchPin, LOW);
	shiftOut(dataPin, clockPin, LSBFIRST, data);
	shiftOut(dataPin, clockPin, LSBFIRST, (data >> 8));	
	digitalWrite(latchPin, HIGH);	
	
	digitalWrite(led_red, LOW);
	digitalWrite(led_blue, HIGH);
	digitalWrite(led_green, LOW);
	
	
	delay(500);
	data = 0x0008;
	digitalWrite(latchPin, LOW);
	shiftOut(dataPin, clockPin, LSBFIRST, data);
	shiftOut(dataPin, clockPin, LSBFIRST, (data >> 8));	
	digitalWrite(latchPin, HIGH);		
	
	digitalWrite(led_green, LOW);
	digitalWrite(led_blue, LOW);
	for(int i = 255; i >= 0; i--)
	{
		analogWrite(led_red, i);
		delay(2);
	}
	delay(50);
	*/
	/*
	int incomingByte = 0;
	if(Serial.available() > 0)
	{
		incomingByte = Serial.read();
		
		Serial.print("I received: ");
		Serial.println(incomingByte, DEC);
	}	
	*/
	
	
	if(stringComplete)
	{	
		
		int redval = incolor_red.toInt();
		int greenval = incolor_green.toInt();
		int blueval = incolor_blue.toInt();
		
		writergb(redval, greenval, blueval);
		writedisplay(get7seg(digit1), get7seg(digit2));
		
		//Serial.println(inputString);
		inputString = "";
		stringComplete = false;
	}
	
	
	/*
	if(firstrun)
	{
		for(int i = 0; i < 30; i++)
			delay(1000);
		firstrun = 0;
	}
	
	*/
	/*
	
	int lastred = 255;
	int lastgreen = 255;
	int lastblue = 255;
	
	for(int i = 0; i<10;i++)
	{
		
			int redval = random(0, 255);
			int greenval = random(0,255);
			int blueval = 255 - redval - greenval;
			if(blueval < 0)
				blueval = 0;
			if(blueval > 255)
				blueval = 255;
			
			
			
	
		for(int j = 0; j< 10; j++)
		{
			
			writergb(map(j, 0, 9, lastred, redval),map(j, 0, 9, lastgreen, greenval),map(j, 00, 9, lastblue, blueval));
			//analogWrite(led_green, );
			//analogWrite(led_blue, );
			
			//writergb(155,155,155);
			String tens = String(i);
			String ones = String(j);
			writedisplay(get7seg(tens), get7seg(ones));
			delay(300);
			
		}
		
		lastred = redval;
		lastgreen = greenval;
		lastblue = blueval;
		
	
			
	}
	*/
	

	
	
	/*
	digitalWrite(led_red, LOW);
	digitalWrite(led_green,LOW);
	digitalWrite(led_blue, LOW);
	delay(500);
	writedisplay(get7seg("8"),get7seg(""));
	
	for(int i = 0; i<256; i++)
	{
		analogWrite(led_blue,i);
		if(i > 128)
		{
			int val = map(255 - i, 255-128, 0, 0, 255);
			analogWrite(led_red, val);
			analogWrite(led_green, val);
		}
		delay(1);
	}
	
	for(int i = 255; i >=0; i--)
	{
		analogWrite(led_red, i);
		analogWrite(led_green,i);
		delayMicroseconds(50);
	}
	
	
	delay(1000);
	
	
	*/
	/*
	int data = 0xFFFF;
	digitalWrite(latchPin, LOW);
	shiftOut(dataPin, clockPin, LSBFIRST, data);
	shiftOut(dataPin, clockPin, LSBFIRST, (data >> 8));	
	digitalWrite(latchPin, HIGH);	
	
	delay(1000);
	
	data = 0x0000;
	digitalWrite(latchPin, LOW);
	shiftOut(dataPin, clockPin, LSBFIRST, data);
	shiftOut(dataPin, clockPin, LSBFIRST, (data >> 8));	
	digitalWrite(latchPin, HIGH);	
	
	delay(1000);
	
	
	*/
	
/*
	writergb(0,0,0);
	writedisplay(get7seg("G"), get7seg("O"));

	for(int i = 0; i < 100; i++)
	{
		writergb(0,0,i);
		delay(4);
	}
	delay(500);
	writergb(0,0,0);
	delay(100);
	writergb(0,0,100);
	writedisplay(get7seg("C"), get7seg("A"));
	delay(700);
	writedisplay(get7seg("A"), get7seg("T"));
	delay(700);
	writedisplay(get7seg("T"), get7seg("S"));
	delay(700);
	writedisplay(get7seg("S"), get7seg(""));
	delay(700);
	writedisplay(get7seg(""), get7seg(""));
	delay(750);
	
	*/
	
}




//Runs between "void loop" executions. Special interrupt Arduino function
void serialEvent() {
	while (Serial.available()) {
		// get the new byte:
		char inChar = (char)Serial.read();
		// add it to the inputString:
		inputString += inChar;
		// if the incoming character is a newline, set a flag
		// so the main loop can do something about it:
		if (inChar == '!') {
			parseInput(inputString);
			stringComplete = true;
		}
	}
}


//Parses the input string for the various parameters
void parseInput(String instring)
{
	//Clear the existing parameters
	digit1 = "";
	digit2 = "";
	incolor_red = "";
	incolor_green = "";
	incolor_blue = "";
	
	int i = 0;
	//Get the first character 
	while(i < instring.length())
	{
		char currentChar = instring[i];
		i++;
		if(currentChar == ',')
			break;
		else
			digit1 += currentChar;
		
	}
	
	//Get the second Character	
	while(i < instring.length())
	{
		char currentChar = instring[i];
		i++;
		if(currentChar == ',')
			break;
		else
			digit2 += currentChar;
	
	}
	
	//Get the red value
	while(i < instring.length())
	{
		char currentChar = instring[i];
		i++;
		if(currentChar == ',')
			break;
		else
			incolor_red += currentChar;

	}
	
	//Get the green value
	while(i < instring.length())
	{
		char currentChar = instring[i];
		i++;
		if(currentChar == ',')
			break;
		else
			incolor_green += currentChar;
	}
	
	//Get the blue value
	while(i < instring.length())
	{
		char currentChar = instring[i];
		i++;
		if(currentChar == ',')
			break;
		else
			incolor_blue += currentChar;
	}
	
}


int get7seg(String input)
{
	if		(input == "0" || input == "O")
		return 0x7E;
	else if	(input == "1")
		return 0x30;
	else if	(input == "2")
		return 0x6D;
	else if (input == "3")
		return 0x79;
	else if (input == "4")
		return 0x33;
	else if (input == "5" || input == "S")
		return 0x5B;
	else if (input == "6")
		return 0x5F;
	else if (input == "7")
		return 0x70;
	else if (input == "8")
		return 0x7F;
	else if (input == "9")
		return 0x7B;
	else if (input == "A")
		return 0b1110111;
	else if (input == "C")
		return 0b1001110;	
	else if (input == "F")
		return 0b1000111;
	else if (input == "G")
		return 0b1011111;
	else if (input == "T")
		return 0b0001111;
	else if (input == "")
		return 0x00;
}



void writedisplay(int char1, int char2)
{
	
	//Each char1, char2 int has a leading 0
	//Shift things around so that data holds
	//16 bits of data. The 2 lsb's are unused
	//and are set to 0; 
	int data = (char1 << 9) | (char2 << 1);
	
	
	int redvalue = currentred;
	int greenvalue = currentgreen;
	int bluevalue = currentblue;
	writergb(0,0,0);
	delay(1);
	digitalWrite(latchPin, LOW);
	shiftOut(dataPin, clockPin, LSBFIRST, data);
	shiftOut(dataPin, clockPin, LSBFIRST, (data >> 8));	
	digitalWrite(latchPin, HIGH);
	writergb(redvalue, greenvalue, bluevalue);

		
		
		/*
	digitalWrite(latchPin, LOW);
	digitalWrite(latch2, LOW);
	shiftOut(dataPin, clockPin, LSBFIRST, (char1 << 1 ));
	shiftOut(data2, clock2, LSBFIRST, (char2 << 1));
	digitalWrite(latchPin, HIGH);
	digitalWrite(latch2, HIGH);
	
	*/
}


void writergb(int red, int green, int blue)
{
	
	currentred = red;
	currentgreen = green;
	currentblue = blue;
	analogWrite(led_red,red);
	analogWrite(led_blue, blue);
	analogWrite(led_green, green);
}