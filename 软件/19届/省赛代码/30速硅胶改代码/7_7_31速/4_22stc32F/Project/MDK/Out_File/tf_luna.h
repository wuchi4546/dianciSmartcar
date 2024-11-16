#ifndef _tf_luna_H_
#define _tf_luna_H_




	 
/* Register list */
#define REG_ADDR_DIST             0x00
#define REG_ADDR_AMP              0x02
#define REG_ADDR_TEMP             0x04
#define REG_ADDR_TICK             0x06
#define REG_ADDR_ERROR            0x08
#define REG_ADDR_VERSION          0x0A
#define REG_ADDR_SN               0x10
#define REG_ADDR_SAVE             0x20
#define REG_ADDR_REBOOT           0x21
#define REG_ADDR_DEV_ADDR         0x22
#define REG_ADDR_MODE             0x23
#define REG_ADDR_TRIG             0x24
#define REG_ADDR_ENABLE           0x25
#define REG_ADDR_FPS              0x26
#define REG_ADDR_LOW_POWER        0x28
#define REG_ADDR_RESTORE_DEFAULT  0x29
#define REG_ADDR_AMP_THR          0x2A
#define REG_ADDR_DUMMY_DIST       0x2C
#define REG_ADDR_MIN_DIST         0x2E
#define REG_ADDR_MAX_DIST         0x30	 

typedef struct {
	unsigned char Address;
  int distance;
  int strength;
  int temp;
} TF;


int LunaReadDist(TF* lidar);
int LunaReadAmp(TF* lidar);
int LunaReadTemp(TF* lidar);
	 

extern TF Lidar1;





#endif

