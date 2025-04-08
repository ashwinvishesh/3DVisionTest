
#ifndef _IREMITTER_H_
#define _IREMITTER_H_

//FREERUN NUMBERS
#define FRAME_DURATION  (800000) 
#define FRAME_PAN       (20)

// ACER NUMBERS
// #define FRAME_DURATION  (8300)  //6000
// #define FRAME_PAN       (12500) //12000

// ODYSSEY NUMBERS
// Frame exposure duration in half-microseconds (@16MHz)
// #define FRAME_DURATION  (14000)   // 7 ms shutter open duration  tried 3         10000
// Time between sync trigger and start of IR token (same units)
// #define FRAME_PAN       (16000)  // 8 ms delay  1,2,3,4,5,6                      16000

// ODYSSEY 120 NUMBERS
// #define FRAME_DURATION  (18000)
// #define FRAME_PAN       (14000)

// INT1, pin 2 on "Arduino Pro Micro"
#define SYNCIN          1
#define PIN_SYNCIN      PIND

#define LED_IR          0
#define DDR_LED_IR      DDRD
#define PORT_LED_IR     PORTD
#define LED_EYE         0
#define DDR_LED_EYE     DDRB
#define PORT_LED_EYE    PORTB

#define PORT_LCD        PORTB
#define LCD_LEFT	    5
#define LCD_RIGHT       6

#define EYE_RIGHT 0
#define EYE_LEFT  1

typedef enum {
	SYNCMODE_NONE     = 0,
	SYNCMODE_DRIVER   = 1, // }
	SYNCMODE_EXTERNAL = 2, // } Can be used as masks
	SYNCMODE_COMBINED = 3,
	SYNCMODE_FREERUN  = 4
} SyncMode_t;

SyncMode_t IR_SyncMode;

void IR_Init(void);
void IR_Update(uint32_t curTime);
void IR_SetSyncMode(SyncMode_t mode);
void IR_SwapEyes(uint8_t swap);

void IR_SetEye(uint8_t eye);
void IR_StartFrame(void);
//void IR_EndFrame(void);

#endif /* _IREMITTER_H_ */
