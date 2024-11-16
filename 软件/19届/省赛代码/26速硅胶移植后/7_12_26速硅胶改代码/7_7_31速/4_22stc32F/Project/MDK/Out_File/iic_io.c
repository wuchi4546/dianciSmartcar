#include "headfile.h"


/*************************************************
Function: User_I2C_Init
Description: config I2C 
*************************************************/
void User_I2C_Init(void)
{
	I2C_SCL_H();
	I2C_SDA_H();
}

/*************************************************
Function: I2C_GenerateStart
Description: 
*************************************************/
static void I2C_GenerateStart(void)
{
	
    I2C_SDA_H();
    I2C_SCL_H();
    delay_us(5);
    I2C_SDA_L();
    delay_us(5);
    I2C_SCL_L();
    delay_us(5);
}

/*************************************************
Function: I2C_GenerateStop
Description: 
*************************************************/
static void I2C_GenerateStop(void)
{
	  I2C_SCL_L();  
    I2C_SDA_L();  
    delay_us(5);  
	  I2C_SCL_H(); 
    delay_us(5); 
	  I2C_SDA_H();  
    delay_us(5); 
}


/*************************************************
Function: I2C_GenerateAck
Description: 
*************************************************/
static void I2C_GenerateAck(__I2C_ACK_TypeDef ack)
{
    if(ack == I2C_NACK) 
	{
        I2C_SDA_H();
	}
    else
	{
        I2C_SDA_L();
	}
	
    delay_us(5);		
    I2C_SCL_H();
    delay_us(5);
    I2C_SCL_L();
}

/*************************************************
Function: I2C_RecvAck
Description: 
*************************************************/
static __I2C_ACK_TypeDef I2C_RecvAck(unsigned long Timeout)
{
	unsigned long timeout = 0;
    __I2C_ACK_TypeDef ackStatus;
	
	I2C_SDA_H();
	 
    delay_us(5);
	I2C_SCL_H();
    delay_us(5);
	
	while(1)
	{
		ackStatus = (USER_I2C_SDA_PIN == 0) ? I2C_ACK : I2C_NACK;
		if(ackStatus == I2C_ACK)
		{
			break;
		}
		
		if((timeout++) > Timeout)
		{
			ackStatus = I2C_NACK;
			break;
		}
	}

    I2C_SCL_L();
    delay_us(5);
    return ackStatus;  
}


/*************************************************
Function: I2C_SendByte
Description: 
*************************************************/
static __I2C_ACK_TypeDef I2C_SendByte(u8 tdata, u32 Timeout)
{
    u32 i;
	
    I2C_SCL_L();
	
    for (i = 0; i < 8; i++)      
    {
        if((tdata << i)&0x80)
        {
            I2C_SDA_H();
        }
        else 
        {
            I2C_SDA_L();
        }
        
        I2C_SCL_H();               
        delay_us(5);             
        I2C_SCL_L();    
        delay_us(5);   
    }

    return I2C_RecvAck(Timeout);
}


/*************************************************
Function: I2C_RecvByte
Description: 
*************************************************/
static u8 I2C_RecvByte(void)
{
    u32 i;
    u32 tdata = 0; 
	  u32 BitStatus = 0;
    
    I2C_SDA_H();
	 
    delay_us(5);
    for (i = 0; i < 8; i++)
    {  
        tdata <<= 1;
        I2C_SCL_H(); 
        delay_us(5); 
		
        BitStatus = (USER_I2C_SDA_PIN == 1) ? 1 : 0;
        tdata |= BitStatus;     
		
        I2C_SCL_L();
        delay_us(5);
    }
	
    return tdata;
}





/*************************************************
Function: I2C_DummyWrite
Description: I2C DummyWrite
*************************************************/
static __I2C_Status_TypeDef I2C_DummyWrite(u8 SlaveAddr, u8 RegAddr, u32 Timeout)
{
	/* Generate Start Sign */
	I2C_GenerateStart();
	
	/* Send Slave Address */
	if(I2C_SendByte((SlaveAddr<<1) | I2C_Transmitter, Timeout) != I2C_ACK)
	{
		I2C_GenerateStop();
		return I2C_ERROR;
	}

	if(I2C_SendByte(RegAddr , Timeout) != I2C_ACK)
	{
		I2C_GenerateStop();
		return I2C_ERROR;
	}
	

	return I2C_OK;
}

/*************************************************
Function: I2C_SendBytes
Description: I2C SendBytes
*************************************************/
__I2C_Status_TypeDef I2C_SendBytes(u8 SlaveAddr, u16 RegAddr, u8 *TxBuf, u8 OperLen, u32 Timeout)
{
	u8 i = 0;
	
	/* Dummy Write */
	if(I2C_DummyWrite(SlaveAddr, RegAddr, Timeout) != I2C_OK)
	{
		I2C_GenerateStop();
		return I2C_ERROR;
	}

	/* Generate Start Sign */
	I2C_GenerateStart();

	/* Send Slave Address */
	if(I2C_SendByte((SlaveAddr<<1) | I2C_Transmitter, Timeout) != I2C_ACK)
	{
		I2C_GenerateStop();
		return I2C_ERROR;
	}
	
	/* Send Data */
	for(i = 0; i < OperLen; i++)
	{
		if(I2C_SendByte(TxBuf[i], Timeout) != I2C_ACK)
		{
			I2C_GenerateStop();
			return I2C_ERROR;
		}
	}

	/* Generate Stop Sign */
	I2C_GenerateStop();
	
	return I2C_OK;
}


/*************************************************
Function: I2C_RecvBytes
Description: I2C SendBytes
*************************************************/
__I2C_Status_TypeDef I2C_RecvBytes(u8 SlaveAddr, u8 RegAddr, u8 *Rxbuf, u8 OperLen, u32 Timeout)
{
	u8 i = 0;
	
	/* Dummy Write */
	if(I2C_DummyWrite(SlaveAddr, RegAddr, Timeout) != I2C_OK)
	{
		I2C_GenerateStop();
		return I2C_ERROR;
	}

	/* Generate Start Sign */
	I2C_GenerateStart();
	
	/* Send Slave Address */
	if(I2C_SendByte((SlaveAddr<<1) | I2C_Receiver, Timeout) != I2C_ACK)
	{
		I2C_GenerateStop();
		return I2C_ERROR;
	}
	
	/* Receive Data */
	for(i = 0; i < OperLen - 1; i++)
	{
		Rxbuf[i] = I2C_RecvByte();
		I2C_GenerateAck(I2C_ACK);
	}

	Rxbuf[OperLen - 1] = I2C_RecvByte();
	I2C_GenerateAck(I2C_NACK);
	
	/* Generate Stop Sign */
	I2C_GenerateStop();
	
	return I2C_OK;
}



