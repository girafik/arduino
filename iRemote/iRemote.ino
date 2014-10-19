#include <IRremote.h>
#define irPin 11

#define btnTop1		0x8061F738
#define btnTop2		0x80617738
#define btnUp1		0x80617758
#define btnUp2		0x8061F758
#define btnLeft1	0x8061F75A
#define btnLeft2	0x8061775A
#define btnRight1	0x8061F75B
#define btnRight2	0x8061775B
#define btnDown1	0x8061F759
#define btnDown2	0x80617759
#define btnOK1		0x8061F75C
#define btnOK2		0x8061775C
#define btnMenu		0x8061F754
#define btnHome		0x80617771
#define btnBack		0x8061F783
#define btnPrev		0x8061771F
#define btnPlay1	0x8061F72C
#define btnPlay2	0x8061772C
#define btnNext		0x8061771E
#define btnLess		0x80617711
#define btnMore		0x8061F710
#define btnMute		0x8061770D

IRrecv irrecv(irPin);
decode_results results;

 
void setup() {
   Serial.begin(9600);
   irrecv.enableIRIn();
   Mouse.begin();
   Keyboard.begin();
}
 
void loop() {
	if (irrecv.decode(&results)) {
		switch (results.value) {
		    case btnTop1:
		    case btnTop2:
				Keyboard.press(KEY_F12);
				delay(100);
  				Keyboard.releaseAll();
				break;
		    case btnUp1:
		    case btnUp2:				
				Mouse.move(0, -10, 0);
				break;
			case btnDown1:
		    case btnDown2:				
				Mouse.move(0, 10, 0);
				break;
			case btnLeft1:
		    case btnLeft2:				
				Mouse.move(-10, 0, 0);
				break;
			case btnRight1:
		    case btnRight2:				
				Mouse.move(10, 0, 0);
				break;
			case btnOK1:
			case btnOK2:
				Mouse.press();
				delay(100);
				Mouse.release();
				break;
			case btnPlay1:
			case btnPlay2:
				Keyboard.press(' ');
				delay(100);
  				Keyboard.releaseAll();
		    default:
		      	Serial.print("0x");
				Serial.println(results.value, HEX);
		}
		irrecv.resume();
	}
}