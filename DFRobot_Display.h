#ifndef DFROBOT_DISPLAY_H
#define DFROBOT_DISPLAY_H

#include "Arduino.h"
#include "DFRobot_Types.h"
#include "DFRobot_Character.h"
#include "Print.h"

#define DISPLAY_BLACK       0x0000      /*   0,   0,   0 */
#define DISPLAY_NAVY        0x000F      /*   0,   0, 128 */
#define DISPLAY_DARKGREEN   0x03E0      /*   0, 128,   0 */
#define DISPLAY_DARKCYAN    0x03EF      /*   0, 128, 128 */
#define DISPLAY_MAROON      0x7800      /* 128,   0,   0 */
#define DISPLAY_PURPLE      0x780F      /* 128,   0, 128 */
#define DISPLAY_OLIVE       0x7BE0      /* 128, 128,   0 */
#define DISPLAY_LIGHTGREY   0xC618      /* 192, 192, 192 */
#define DISPLAY_DARKGREY    0x7BEF      /* 128, 128, 128 */
#define DISPLAY_BLUE        0x001F      /*   0,   0, 255 */
#define DISPLAY_GREEN       0x07E0      /*   0, 255,   0 */
#define DISPLAY_CYAN        0x07FF      /*   0, 255, 255 */
#define DISPLAY_RED         0xF800      /* 255,   0,   0 */
#define DISPLAY_MAGENTA     0xF81F      /* 255,   0, 255 */
#define DISPLAY_YELLOW      0xFFE0      /* 255, 255,   0 */
#define DISPLAY_WHITE       0xFFFF      /* 255, 255, 255 */
#define DISPLAY_ORANGE      0xFD20      /* 255, 165,   0 */
#define DISPLAY_GREENYELLOW 0xAFE5      /* 173, 255,  47 */
#define DISPLAY_PINK        0xF81F

#define swap_int16(a, b) { int16_t t = a; a = b; b = t; }


class DFRobot_Display : public Print
{
  public:
    DFRobot_Display(uint16_t width, uint16_t height);
    
    virtual void        drawPixel(int16_t x, int16_t y, uint16_t color) = 0;
    virtual void        fillScreen(uint16_t color) = 0;
    
    virtual void        drawVLine(int16_t x, int16_t y, int16_t height, uint16_t color);
    virtual void        drawHLine(int16_t x, int16_t y, int16_t width, uint16_t color);
    virtual void        drawRect(int16_t x, int16_t y, int16_t width, int16_t height, 
                                        uint16_t color);
    virtual void        fillRect(int16_t x, int16_t y, int16_t width, int16_t height, 
                                            uint16_t color);
    virtual void        drawLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1, 
                                        uint16_t color);
    virtual void        drawCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color);
    virtual void        fillCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color);
    virtual void        drawTriangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1, 
                                            int16_t x2, int16_t y2, uint16_t color);
    virtual void        fillTriangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1, 
                                                int16_t x2, int16_t y2, uint16_t color);
    virtual void        drawRoundRect(int16_t x0, int16_t y0, int16_t w, int16_t h,
		                                  int16_t radius, uint16_t color);
    virtual void        fillRoundRect(int16_t x0, int16_t y0, int16_t w, int16_t h,
		                                      int16_t radius, uint16_t color);

    virtual int16_t     setRotaion(eROTATION ratotion);
    virtual void        drawBuffer_24(int16_t x, int16_t y, uint8_t *pBuf, uint16_t count);
    virtual void        drawBuffer_16(int16_t x, int16_t y, uint16_t *pBuf, uint16_t count);

	int32_t             readN(Stream * s, uint8_t* pBuf, int32_t length);
	int16_t             drawBmp(Stream *s, int16_t x, int16_t y);
    size_t              write(uint8_t ch);
    size_t              write(const uint8_t* pCh, size_t size);
		
    eROTATION    getRotation(void);
    void         setTextColor(uint16_t color);
    int16_t      getTextColor(void);
    void         setTextSize(uint8_t size);
    uint8_t      getTextSize(void);
    int16_t      getWidth(void);
    int16_t      getHeight(void);
    void         setCursor(uint16_t x, uint16_t y);
    void         getCursor(int16_t* pX, int16_t* pY);
    eSHAPE       getDisplayShape(void);
    uint16_t     getDisplayRadius(void);
    void         setOrign(uint16_t x, uint16_t y);
    void         supportChineseFont(void);

  protected:
    int16_t        width, height, rawWidth, rawHeight;
    int16_t        textColor;
    uint16_t       textSize;
    eROTATION      eRotation;
    eSHAPE         eShape;
    int16_t        cursorX, cursorY;
    uint16_t       displayRadius;
    
    pfCharacterFont_t		pfCharacterFont;

    int16_t      limitVLine(int16_t& x, int16_t& y, int16_t& h);
    int16_t      limitHLine(int16_t& x, int16_t& y, int16_t& w);
    int16_t      limitPixel(int16_t& x, int16_t & y);
    void         setDisplayShape(eSHAPE eShape);

    void         fillCircleHelper(int16_t x0, int16_t y0, int16_t r,
		                              uint8_t part, int16_t offset, uint16_t color);
    void         circleHelper(int16_t x0, int16_t y0,
			                        int16_t r, uint8_t part, uint16_t color);
    int16_t      drawText(int16_t* pX, int16_t* pY, const char* ch);

  private:
    int16_t      printfX, printfY;
};

#endif


