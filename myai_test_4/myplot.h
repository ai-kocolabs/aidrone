#ifndef _MYPLOT_H_
#define _MYPLOT_H_

#include <SPI.h>
#include <TFT_eSPI.h>

#define DX_MIN (0+20)
#define DX_MAX (160-20)
#define DY_MIN (80-10)
#define DY_MAX (0+10)

void lcdSetup();
void lcdClear(uint32_t color=TFT_BLACK);
void lcdSetPlotArea(double xs[], double ys[], int howMany);
void lcdPlot(double xs[], double ys[], uint32_t color, int howMany);

#endif
