/* 
 * File:   app_sdcard_write.h
 * Author: Eryk Zagorski
 *
 * Created on November 23, 2018, 9:26 PM
 */

#ifndef APP_SDCARD_WRITE_H
#define	APP_SDCARD_WRITE_H

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "system_config.h"
#include "system_definitions.h"

#ifdef	__cplusplus
extern "C" {
#endif

    
#define MAX_SD_CARD_WRITE_BUFFER_SIZE 16
    
typedef enum{
 
APP_SDCARD_WRITE_STATE_CARD_MOUNT,
APP_SDCARD_WRITE_STATE_CARD_CURRENT_DRIVE_SET,
APP_SDCARD_WRITE_STATE_READ_FILE_SIZE,           
APP_SDCARD_WRITE_STATE_ERROR,
APP_SDCARD_WRITE_STATE_CARD_WRITE

} APP_SDCARD_WRITE_STATES;

typedef struct{
    uint8_t buffer[MAX_SD_CARD_WRITE_BUFFER_SIZE];
    uint16_t nElements;
}APP_SDCARD_WRITE_DATA_PARSER;

typedef struct{
    APP_SDCARD_WRITE_STATES state;
    SYS_FS_HANDLE fileHandle;
    int32_t fileSize;
    int32_t currentFilePosition;
    APP_SDCARD_WRITE_DATA_PARSER dataParser;
}APP_SDCARD_WRITE_DATA;


void APP_SDCARD_WRITE_Tasks(void);

void APP_SDCARD_WRITE_Initialize(void);

static bool APP_SDCARD_WIRTE_Write_SDCard(
    const DRV_HANDLE handle,
    uint8_t* const pBuffer,
    const uint16_t bytesToWrite,
    uint16_t*const pNumBytesWrote
);



#ifdef	__cplusplus
}
#endif

#endif	/* APP_SDCARD_WRITE_H */

