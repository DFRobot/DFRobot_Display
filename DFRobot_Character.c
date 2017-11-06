#include "DFRobot_Character.h"


int16_t DFRobot_Character_getCharacter(uint8_t *pCh, uint8_t* pBuf, uint8_t* pWidth, uint8_t* pHeight)
{
  uint8_t        var1 = 0;
  if(*pCh < 0x20) {
    if(*pCh > 0x06 && *pCh < 0x0e) {
      *pWidth = 6; *pHeight = 8;
      return 1;
    } else {
      return DISPLAY_ERR_PARAM;
    }
  //utf-8 code
  } else if(*pCh < 0x80) {
	  for(var1 = 0; var1 < 6; var1 ++) {
#ifdef __AVR__
      pBuf[var1] = pgm_read_byte(&table_character_6_8[*pCh - 0x20][var1]);
#else
      pBuf[var1] = table_character_6_8[*pCh - 0x20][var1];
#endif
	  }
	  *pWidth = 6; *pHeight = 8;
	  return 1;
  } else {
    return DISPLAY_ERR_PARAM;
  }
}


