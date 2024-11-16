#ifndef _iic_io_H_
#define _iic_io_H_

typedef 	unsigned char	u8;
typedef 	unsigned int	u16;
typedef 	unsigned long	u32;



/* Exported define -----------------------------------------------------------*/
typedef enum {RESET = 0, SET = !RESET} FlagStatus, ITStatus, BitStatus, BitAction;
#define USER_I2C_SCL_PIN 	P30
#define USER_I2C_SDA_PIN 	P31


#define I2C_SCL_H() 		P30 = 1
#define I2C_SCL_L()			P30 = 0

#define I2C_SDA_H()			P31 = 1
#define I2C_SDA_L()			P31 = 0


//#define READ_SDA() 	P10


/* Exported functions ------------------------------------------------------- */


typedef enum
{
	I2C_OK = 0U,
	I2C_BUSY = 1U,
	I2C_TIMEOUT = 3U,
	I2C_ERROR = 4U,
}__I2C_Status_TypeDef;

typedef enum
{
	I2C_ACK = 0U,
	I2C_NACK = 1U,
}__I2C_ACK_TypeDef;

typedef enum
{
	I2C_Transmitter = 0U,
	I2C_Receiver = 1U,
}__I2C_Oper_TypeDef;

typedef enum
{
	I2C_SDA_IN = 0U,
	I2C_SDA_OUT = 1U,
}__I2C_SDAMode_TypeDef;
/*************************************************
Function: User_I2C_Init
Description: config I2C 
*************************************************/
void User_I2C_Init(void);

/*************************************************
Function: delay
Description: 
Input:  Delaycnt - delay cnt
*************************************************/
void delay(unsigned long Delaycnt);

/*************************************************
Function: I2C_SendBytes
Description: I2C SendBytes
*************************************************/
__I2C_Status_TypeDef I2C_SendBytes(unsigned char SlaveAddr, unsigned int RegAddr, unsigned char *TxBuf, unsigned char OperLen, unsigned long Timeout);

/*************************************************
Function: I2C_RecvBytes
Description: I2C SendBytes
*************************************************/
__I2C_Status_TypeDef I2C_RecvBytes(unsigned char SlaveAddr, unsigned char RegAddr, unsigned char *Rxbuf, unsigned char OperLen, unsigned long Timeout);













#endif

