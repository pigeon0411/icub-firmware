 /****************************************************
 *  						     *
 *                                                   *
 *                                                   *
 *  Written by Marco Maggiali                        *
 *  <marco.maggiali@iit.it>                          *
 ****************************************************/
 
#include <stdio.h>
#include <string.h>
#include "stm32l4xx_hal.h"
#include "usbd_cdc_if.h"
#include "usbd_def.h"
#include "usb_parser.h"



void usbParser(uint8_t * RecMsg)
{
    uint8_t RecMsgLen=strlen(RecMsg);
    uint8_t i=0;
    uint8_t value=0;
	//  if (3<=RecMsgLen)
	  {
		  // for (i=0;i<=(RecMsgLen-3);)
	      for (i=0;i<=(RecMsgLen);)
		  {
			  //i_value=i;

			  switch (RecMsg[i])
			  {
				  case 'L':   //Left EyeBrows
				  {
					value=  (RecMsg[i+2]-'0')+ 10*  (RecMsg[i+1]-'0'); //it should be convert in hex
					while(USBD_BUSY==CDC_Transmit_FS(&RecMsg[i], 3));
					i=i+3;
				  }
				  break;
				  case 'I':   //SWITCH ON ALL THE LEDS
				  {
					//
					while(USBD_BUSY==CDC_Transmit_FS(&RecMsg[i], 1)); //it should be convert in hex
					i=i+1;
				  }
				  break;
				  case 'M':   //Mouth
				  {
					value=  (RecMsg[i+2]-'0')+ 10*  (RecMsg[i+1]-'0'); //it should be convert in hex
					while(USBD_BUSY==CDC_Transmit_FS(&RecMsg[i], 3));
					i=i+3;
				  }
				  break;
				  case 'S':  //eyelids
				  {
					value=  (RecMsg[i+2]-'0')+ 10*  (RecMsg[i+1]-'0');  //it should be convert in hex
					while(USBD_BUSY==CDC_Transmit_FS(&RecMsg[i], 3));
					i=i+3;
				  }
				  break;
				  case 'R':  //Right EyeBrows
 				  {
					value=  (RecMsg[i+2]-'0')+ 10*  (RecMsg[i+1]-'0'); //it should be convert in hex
					while(USBD_BUSY==CDC_Transmit_FS(&RecMsg[i], 3));
					i=i+3;
				  }
				  break;
				  case 'Z':   //SWITCH OFF ALL THE LEDS
				  {
					// SWITCH ON ALL THE LEDS
					while(USBD_BUSY==CDC_Transmit_FS(&RecMsg[i], 1));
					i=i+1;
				  }
				  break;
				  case 'X':   //cancel current command string
				  {
					// SWITCH ON ALL THE LEDS
					while(USBD_BUSY==CDC_Transmit_FS(&RecMsg[i], 1));
					i=i+1;
				  }
			      break;
				  default:
				  {
					  i=i+1;
				  }
			      break;
			  }

		  }
		  for (i=0;i<(30);i++)
		  {
			  RecMsg[i]='\0'; //clean of the buffer
		  }
	  } 
}



