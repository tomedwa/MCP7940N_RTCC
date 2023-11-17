/*
 **************************************************************
 * MCP7940M.h
 * Author: Tom
 * Date: 17/11/2023
 * AVR Library for the real time clock and calendar chip,
 * MCP7940M. This library uses the Peter Fleury i2cmaster.h
 * interface to drive the i2c comms.
 **************************************************************
 * EXTERNAL FUNCTIONS
 **************************************************************
 * RTC_init() - Initialise the RTC.
 * RTC_set_time() - Set the current time on the RTC.
 * RTC_get_current_time() - Get the current time on the RTC.
 **************************************************************
*/

#ifndef MCP7940M_H_
#define MCP7940M_H_

#define RTC_ADDR	0xDE
#define RTC_READ	1
#define RTC_WRITE	0
#define RTC_OSCILLATOR_ENABLE	0x80
#define RTC_HOURS_REGISTER		0x02
#define RTC_MINUTES_REGISTER	0x01
#define RTC_SECONDS_REGISTER	0x00

// sec tens, sec ones, min tens, min ones, hour tens, hours ones
extern uint8_t RTC_TIME[6]; 

void RTC_init(); 
uint8_t RTC_read_register(uint8_t regAddr);
void RTC_read_multiple_register(uint8_t startAddr, uint8_t* data, uint8_t numOfReads);
void RTC_write_register(uint8_t regAddr, uint8_t data);
void RTC_set_time(uint8_t hour, uint8_t min, uint8_t sec);
void RTC_get_current_time();

// These are not hard to do, I just dont need this yet.
void RTC_set_day(uint8_t day);		// TO DO
void RTC_set_month(uint8_t month);	// TO DO
void RTC_set_year(uint8_t year);	// TO DO

#endif /* MCP7940M_H_ */