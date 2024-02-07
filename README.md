# MCP7940M_RTCC
Library for the MCP7940M Real time clock and calendar.

NOTE: The alarm functionality does not use the RTCC or interrupts. 
It is not hard to implement, but I dont need this functionality at 
the moment so I did alarm time matching a different lazy way.

## Getting Started
Basic example of initialising the RTCC, setting up the time, alarm time, day, and date.

```
i2c_init();
RTC_init();
RTC_set_time(0x00, 0x09, 0x30); /* Current time = 9:30am */
RTC_alarm_enable_disable(RTC_ALARM_ENABLED);
RTC_set_alarm_time(0x00, 0x06, 0x00; /* Alarm time = 6:00am */
RTC_set_date(0x07, RTC_FEBRUARY, 0x24); /* Date is 7th Feb, 2024 (note: RTC_FEBRUARY = 0x02 in .h file) */
RTC_set_weekday(RTC_WEDNESDAY); /* note: RTC_WEDNESDAY = 0x03 in .h file */

while(1) {
  RTC_update_current_time();

  if (RTC_check_alarm_match() == RTC_ALARM_ACTIVE) {
    **Handle alarm match logic**
  }
}
```
There is much more functionality than this, but this is the basics of how the library works.
