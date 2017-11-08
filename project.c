#include "project.h"

#ifdef DEBUG
void
__error__(char *pcFilename, uint32_t ui32Line)
{
}
#endif
//=============================================================================================//
//	Jacob Clark
//	10/6/2016
//	Embedded Systems 
//
//  Main C File: This CAN code is functional with 7 receive and transmit objects.
//=============================================================================================//



int  main(void) {
	
	setupHardware();
	SysCtlDelay(SysCtlClockGet()/3);
	
	
//	labFinal();
	labFinalReceive();
 	//transmitAndReceive();
}	

void transmitAndReceive() {
	initReceiver();
	uint8_t data[4];
	uint8_t msgSelect;
	
	while(1) {
		
		printf("Enter 1-7 to send a message, or 0 to display data.\n");		
		msgSelect = getchar();
		
	if(msgSelect==0){
		displayData();	
	}	
	if(1 <= msgSelect && 7 >= msgSelect ) {
	data[0] = 0;
	data[1] = 0;
	data[2] = 128; 
	data[3] = 128;		
		
	printf("sending message\n");
	CAN_Transmit(data, msgSelect);
	
	data[0] = 0;
	data[1] = 128;
	data[2] = 0; 
	data[3] = 128;
		}
	}	
}
void labFinalReceive(){
	initReceiver();
	while(1){
	if(MsgData[1][0] >= 128)
			GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, 0xF);
		else 
			GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, 0x0);
		if(MsgData[1][1] >= 128)
			GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2, 0xF);
		else 
			GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2, 0x0);
		if(MsgData[1][2] >= 128)
			GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, 0xF);
		else 
			GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, 0x0);		
	}	
}


void labFinal(){
	
	uint8_t data[4];

	while(1){	
		data[0] = ADCReadChan()/8; 
		data[1] = ADCReadChan2()/8;
		data[2] = ADCReadChan3()/8;	
		data[3] = 0;
		
		CAN_Transmit(data, 2);
		
		SysCtlDelay(SysCtlClockGet()/3);
		
		
	}	
}



void setupHardware(){
		ClockSetup();
		
		GPIO_Setup();
		UartSetup();
	  CAN_Init();
		SetupADC();
		printf("Debugging interface initialized...\n");
		printf("GPIO ports initialized...\n");
		printf("Clock settings initialized...\n\n");
		printf("Set-up Complete.\n\n");
}


void displayData(){
		printf("MsgData[0] received message 1:\tByte 1: %d\tByte 2: %d\tByte 3: %d\t Byte 4: %d\n", MsgData[0][0], MsgData[0][1], MsgData[0][2], MsgData[0][3]);
		printf("MsgData[1] received message 1:\tByte 1: %d\tByte 2: %d\tByte 3: %d\t Byte 4: %d\n", MsgData[1][0], MsgData[1][1], MsgData[1][2], MsgData[1][3]);
		printf("MsgData[2] received message 1:\tByte 1: %d\tByte 2: %d\tByte 3: %d\t Byte 4: %d\n", MsgData[2][0], MsgData[2][1], MsgData[2][2], MsgData[2][3]);
		printf("MsgData[3] received message 1:\tByte 1: %d\tByte 2: %d\tByte 3: %d\t Byte 4: %d\n", MsgData[3][0], MsgData[3][1], MsgData[3][2], MsgData[3][3]);	
		printf("MsgData[4] received message 1:\tByte 1: %d\tByte 2: %d\tByte 3: %d\t Byte 4: %d\n", MsgData[4][0], MsgData[4][1], MsgData[4][2], MsgData[4][3]);
		printf("MsgData[5] received message 1:\tByte 1: %d\tByte 2: %d\tByte 3: %d\t Byte 4: %d\n", MsgData[5][0], MsgData[5][1], MsgData[5][2], MsgData[5][3]);
		printf("MsgData[6] received message 1:\tByte 1: %d\tByte 2: %d\tByte 3: %d\t Byte 4: %d\n", MsgData[6][0], MsgData[6][1], MsgData[6][2], MsgData[6][3]);
}



	// Enable the PWM0 peripheral

	
	// Check if the peripheral access is enabled.
	