# logic-gate-tester-arduino
Logic Gate Tester for Digital Electronics and Logic Design


Performing various types of logic operation we need to use logic gates and in integrated circuit there are more than one gates fabricated in a single IC. Before using gates for various purposes we need to check logic gates including all logic combination considering in Binary (Logic 1 & 0) needs to implement. It is a time consuming task to check all the input combinations, thus the sole purpose of this project to make it automatic to check all the logic .

Objectives: 
i)	To make an automatic system to check logic gates.
ii)	To Display every checking information including all logic combinations.
iii)	To learn about designing PCB & making it by hand. 


Logic gates are the basic building blocks of any digital system. It is an electronic circuit having one or more than one input and only one output. The relationship between the input and the output is based on a certain logic. Based on this, logic gates are named as AND gate, OR gate, NOT gate, NAND gate, NOR gate, EXOR gate and EXNOR gate. 


WorkingPrinciple:
As we know that High Voltage (+5VDC) as a logic HIGH or 1 and Low Voltage (0VDC) as a logic LOW or 0 is used in Binary Calculation. Here a Arduino Mega is used to set various DIGITAL PIN as HIGH(1) LOW(0) combination for 2 input get like HIGH HIGH , LOW HIGH , HIGH LOW , LOW LOW combinations. Then we use another PIN to read the output state of the Gate and compare the output with the predefined LOGIC table previously saved in the ARDUINO MEGA memory Unit. If the conditions matched (all combination) then we can call the Gate as good & the Green LED is being bright for corresponding gate in the IC. If any of the combinational output makes a false result after comparing with Truth Table then the gate will be declared as BAD gate and Red light is being bright for the corresponding number of Gate in the IC. This process is being set with the respective IC number which needs to give from the user interface keyboard & a display also shows the running logic that is being used to check to find out the logic gate as good or bad.


List of Permissible IC for the Project Prototype: (Table 1.1)
IC Number	Name	Number of input	Number of Gate
7400	2-input NAND	2	4
7402	2-input NOR	2	4
7404	NOT	1	6
7408	2-input AND	2	4
7432	2-input OR	2	4
7486	2-input EXOR	2	4
74286	2-input EXNOR	2	4
7411	3-input AND	3	3


List & Cost of component
Name	Rating
Ardunio Mega2560	ATmega2560 microcontroller
Input voltage - 7-12V
54 Digital I/O Pins (14 PWM outputs)
16 Analog Inputs
256k Flash Memory
16Mhz Clock Speed
16*2 LCD Display	Vdd -Vss (0-5VDC)
Imax 3mA
Duty 1/16
16*2 characters
built-in 5*8 alpha numeric character ROM
standard 4bit or 8bit parallel interface
4*4 Key Pad	Cable Length: 3.3 inch
Keypad Width: 2.7 inch
Keypad Length : 3.0inch
Number of keys: 16
Matrix: 4×4
Zif socket (28 pin)
(IC base)	ZIF (zero insertion force) design
contacts: 28
lead pitch 0.1" (100 mil)
an ideal IC test socket
LED
(Green & Red)	Vf= 1.90V
Rated If=10mA
Registor	220ohm, 1k ; 0.5W
Variable Registor 	10K
IC7809	Output Voltage:9V
Peak Current:2.2A
Short Circuit Current:250mA
Transformer (220/12V)	Primary Voltage:220V
Secondary Voltage:12V
Current rating:1A
Plug	220V,10A
PCB Board	
Jumper
Male to male 
Male to female	
Connector	Copper (26G)
Test IC’s 
(Logic Gates)	7804,7808

Conclusion: 
This is a project to check logic gates simply & automatically. The basic principle of checking gates is that every logic has an individual truth table and we set the truth table in memory when we call it through IC number it will check the truth table and give the result of the IC conditions. This project is designed to use in the Digital Electronics and Logic Design Laboratory (a course of EE3114) to make IC checking easily and reduce the time.
 
Future Improvement: 
This project has a lot of possibilities as follows:
1)	Adding 3 input IC’s
2)	The circuit and code can be made more advanced to check other IC’s such as T, D, F flip-flop.
3)	Some modified truth tables to compare any other complete circuits those are made by Logic Gates. 


Report URL: https://www.slideshare.net/JikrulSayeed/logic-gate-tester-for-ics-digital-electronics-and-logic-deisgn-ee3114/ 
