#include "ets_sys.h"
#include "driver/uart.h"
#include "osapi.h"
#include "at.h"

#define delayms(x) os_delay_us(x*1000);
extern uint8_t at_wifiMode;
extern at_mdStateType mdState;

void user_init(void)
{
  uart_init(BIT_RATE_115200, BIT_RATE_115200);
  //Set GPIO2 to output mode
  PIN_FUNC_SELECT(PERIPHS_IO_MUX_GPIO2_U, FUNC_GPIO2);
  //Set GPIO2 low
  gpio_output_set(0, BIT2, BIT2, 0);
  at_wifiMode = wifi_get_opmode();
  os_printf("\r\nready!!!\r\n");
  uart0_sendStr("\r\nAT modify by Azazel Fool\r\n");
  at_init();
  delayms(1000);

  //at_setupCmdCwjap(99,"=@HOME,boomakung");
  //delayms(1000);
  uart0_sendStr("Setting MUX to 1:");
  at_setupCmdCipmux(15, "=1");
  delayms(1000);
  //at_queryCmdCipmux(15);
  //delayms(1000);
  uart0_sendStr("Starting TCP server: Listening on port 9999\r\n");
 
  at_setupCmdCipserver(16, "=1,9999");
 
 

}
