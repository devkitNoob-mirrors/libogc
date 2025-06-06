#ifndef __LIBOGC_CONSOLE_H__
#define __LIBOGC_CONSOLE_H__

/*!
 * \file console.h
 * \brief Console subsystem
 *
 */

#include "gx_struct.h"

/* macros to support old function names */
#define console_init     CON_Init
#define SYS_ConsoleInit  CON_InitEx

#define CONSOLE_ESC(x) "\x1b[" #x
#define CONSOLE_RESET   CONSOLE_ESC(0m)
#define CONSOLE_BLACK   CONSOLE_ESC(30m)
#define CONSOLE_RED     CONSOLE_ESC(31;1m)
#define CONSOLE_GREEN   CONSOLE_ESC(32;1m)
#define CONSOLE_YELLOW  CONSOLE_ESC(33;1m)
#define CONSOLE_BLUE    CONSOLE_ESC(34;1m)
#define CONSOLE_MAGENTA CONSOLE_ESC(35;1m)
#define CONSOLE_CYAN    CONSOLE_ESC(36;1m)
#define CONSOLE_WHITE   CONSOLE_ESC(37;1m)

#define CONSOLE_COLOR_BLACK   0
#define CONSOLE_COLOR_RED     1
#define CONSOLE_COLOR_GREEN   2
#define CONSOLE_COLOR_YELLOW  3
#define CONSOLE_COLOR_BLUE    4
#define CONSOLE_COLOR_MAGENTA 5
#define CONSOLE_COLOR_CYAN    6
#define CONSOLE_COLOR_WHITE   7

#ifdef __cplusplus
	extern "C" {
#endif

/*!
 * \fn CON_Init(void *framebuffer,int xstart,int ystart,int xres,int yres,int stride)
 * \brief Initializes the console subsystem with given parameters
 *
 * \param[in] framebuffer pointer to the framebuffer used for drawing the characters
 * \param[in] xstart,ystart start position of the console output in pixel
 * \param[in] xres,yres size of the console in pixel
 * \param[in] stride size of one line of the framebuffer in bytes
 *
 * \return none
 */
void CON_Init(void *framebuffer,int xstart,int ystart,int xres,int yres,int stride);

/*!
 * \fn s32 CON_InitEx(GXRModeObj *rmode, s32 conXOrigin,s32 conYOrigin,s32 conWidth,s32 conHeight)
 * \brief Initialize stdout console
 * \param[in] rmode pointer to the video/render mode configuration
 * \param[in] conXOrigin starting pixel in X direction of the console output on the external framebuffer
 * \param[in] conYOrigin starting pixel in Y direction of the console output on the external framebuffer
 * \param[in] conWidth width of the console output 'window' to be drawn
 * \param[in] conHeight height of the console output 'window' to be drawn
 *
 * \return 0 on success, <0 on error
 */
s32 CON_InitEx(GXRModeObj *rmode, s32 conXOrigin,s32 conYOrigin,s32 conWidth,s32 conHeight);

/*!
 * \fn CON_GetMetrics(int *cols, int *rows)
 * \brief retrieve the columns and rows of the current console
 *
 * \param[out] cols,rows number of columns and rows of the current console
 *
 * \return none
 */
void CON_GetMetrics(int *cols, int *rows);

/*!
 * \fn CON_GetPosition(int *col, int *row)
 * \brief retrieve the current cursor position of the current console
 *
 * \param[out] col,row current cursor position
 *
 * \return none
 */
void CON_GetPosition(int *cols, int *rows);

/*!
 * \fn CON_EnableGecko(int channel, int safe)
 * \brief Enable or disable the USB gecko console.
 *
 * \param[in] channel EXI channel, or -1 �to disable the gecko console
 * \param[in] safe If true, use safe mode (wait for peer)
 *
 * \return none
 */
void CON_EnableGecko(int channel,int safe);

#ifdef __cplusplus
	}
#endif

#endif
