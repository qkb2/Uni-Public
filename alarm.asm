;----------------------------- PROGRAM [EN] -----------------------------
;The alarm system (at P1.0) can be set up by changing P1.0 to 0 and shut down by setting P1.0 to 1. 
;Setting up the alarm is done by entering the password (1234) and shutting down the alarm is done by entering it in reverse (4321).
;Code written for 8051 family of microcontrollers.

	ORG 0000h
;----------------------------- Start -----------------------------
Start:
	CLR A
	MOV R0, #4			;Setup 4 numbers to be entered
	MOV R1, #160		;Setup the pointer to string of numbers entered

ScanLoop:
	CALL ScanKeyPad		;Call the key scanner
	CALL Delay			;Call delay for user to react
	SETB P1.7			;Signal to user that they should stop pushing the button
	DEC R0				;One keystroke registered
	INC R1				;Increase the pointer
	CJNE R0, #0, ScanLoop	;Wait for 4 keystrokes to register
	CALL CheckPswd		;Check the password
	JMP Start			;Reset to start
	
;----------------------------- Scan Row -----------------------------
ScanKeyPad:	
	CLR P0.3			;Clear Row3
	CALL IDCode0		;Call scan column subroutine
	SETB P0.3			;Set Row 3
	JB F0, Done  		;If F0 is set, end scan 
						
	;Scan Row2
	CLR P0.2			;Clear Row2
	CALL IDCode1		;Call scan column subroutine
	SETB P0.2			;Set Row 2
	JB F0, Done		 	;If F0 is set, end scan 						

	;Scan Row1
	CLR P0.1			;Clear Row1
	CALL IDCode2		;Call scan column subroutine
	SETB P0.1			;Set Row 1
	JB F0, Done			;If F0 is set, end scan

	;Scan Row0			
	CLR P0.0			;Clear Row0
	CALL IDCode3		;Call scan column subroutine
	SETB P0.0			;Set Row 0
	JB F0, Done			;If F0 is set, end scan 
												
	JMP ScanKeyPad		;Go back to scan Row3
							
Done:		
	CLR F0		        ;Clear F0 flag before exit
	RET
		
;----------------------------- Scan column -----------------------------
IDCode0:	
	JNB P0.4, KeyCode03	;If Col0 Row3 is cleared - key found
	JNB P0.5, KeyCode13	;If Col1 Row3 is cleared - key found
	JNB P0.6, KeyCode23	;If Col2 Row3 is cleared - key found
	RET					

KeyCode03:	
	SETB F0				;Key found - set F0
	MOV @R1, #'3'		;Code for '3'	
	CLR P1.7			;Set Diode 7 to signal that the keystroke was saved
	RET				

KeyCode13:	
	SETB F0				;Key found - set F0
	MOV @R1, #'2'		;Code for '2'	
	CLR P1.7			;Set Diode 7 to signal that the keystroke was saved
	RET				

KeyCode23:	
	SETB F0				;Key found - set F0
	MOV @R1, #'1'		;Code for '1'	
	CLR P1.7			;Set Diode 7 to signal that the keystroke was saved
	RET				

IDCode1:	
	JNB P0.4, KeyCode02	;If Col0 Row2 is cleared - key found
	JNB P0.5, KeyCode12	;If Col1 Row2 is cleared - key found
	JNB P0.6, KeyCode22	;If Col2 Row2 is cleared - key found
	RET					

KeyCode02:	
	SETB F0				;Key found - set F0
	MOV @R1, #'6'		;Code for '6'	
	CLR P1.7			;Set Diode 7 to signal that the keystroke was saved
	RET				

KeyCode12:	
	SETB F0				;Key found - set F0
	MOV @R1, #'5'		;Code for '5'	
	CLR P1.7			;Set Diode 7 to signal that the keystroke was saved
	RET				

KeyCode22:	
	SETB F0				;Key found - set F0
	MOV @R1, #'4'		;Code for '4'	
	CLR P1.7			;Set Diode 7 to signal that the keystroke was saved
	RET				

IDCode2:	
	JNB P0.4, KeyCode01	;If Col0 Row1 is cleared - key found
	JNB P0.5, KeyCode11	;If Col1 Row1 is cleared - key found
	JNB P0.6, KeyCode21	;If Col2 Row1 is cleared - key found
	RET					

KeyCode01:	
	SETB F0				;Key found - set F0
	MOV @R1, #'9'		;Code for '9'	
	CLR P1.7			;Set Diode 7 to signal that the keystroke was saved
	RET				

KeyCode11:	
	SETB F0				;Key found - set F0
	MOV @R1, #'8'		;Code for '8'	
	CLR P1.7			;Set Diode 7 to signal that the keystroke was saved
	RET				

KeyCode21:	
	SETB F0				;Key found - set F0
	MOV @R1, #'7'		;Code for '7'	
	CLR P1.7			;Set Diode 7 to signal that the keystroke was saved
	RET				

IDCode3:	
	JNB P0.4, KeyCode00	;If Col0 Row0 is cleared - key found
	JNB P0.5, KeyCode10	;If Col1 Row0 is cleared - key found
	JNB P0.6, KeyCode20	;If Col2 Row0 is cleared - key found
	RET					

KeyCode00:	
	RET				

KeyCode10:	
	SETB F0				;Key found - set F0
	MOV @R1, #'0'		;Code for '0'
	CLR P1.7			;Set Diode 7 to signal that the keystroke was saved
	RET				

KeyCode20:	
	RET						

;----------------------------- Delay -----------------------------	
Delay:		
	MOV R6, #50			;Standard short delay loop
	DJNZ R6, $
	RET

;----------------------------- Password Check -----------------------------
CheckPswd:
	CLR F0
	MOV R0, #4			;Reset values from start
	MOV R1, #160
	MOV DPTR, #Passw	;Copy values in Passw DB to DPTR

Rpt:
	CLR A
	MOVC A, @A+DPTR		;Move value from DPTR to A
	XRL A, @R1			;Check if A and value at @R1 are equal
	JNZ Fail			;If not, jump to Fail
	INC R1				;Increase pointer to get next value in user string
	INC DPTR			;Increase pointer to get next value in Passw string
	DJNZ R0, Rpt		;If yes, repeat until all values are checked
	JBC F0, Unlock		;If F0 is set, jump to door unlock 
	CLR P1.0			;Activate the alarm (P1.0 = 0: alarm active)
	JMP CheckEnd		;Jump to return

Fail:
	JBC F0, CheckEnd	;If both Passw and RevPassw were tried, jump to return
	SETB F0				;Set F0 to signal that Passw was already checked				
	CLR A
	MOV R0, #4			;Reset values from the start
	MOV R1, #160
	MOV DPTR, #RevPassw	;This time check the reverse password
	JMP Rpt				;Enter the checking subroutine

Unlock:
	SETB P1.0			;Shut down the alarm (P1.0 = 1: alarm shut down)

CheckEnd:
	RET

Passw: 
	DB "1234" 	;Password: 1,2,3,4
	
RevPassw:
	DB "4321" 	;Reverse password: 4, 3, 2, 1
	
	END
