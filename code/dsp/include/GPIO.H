/*
 * gpio.h
 *
 *  Created on: 2013-9-22
 *      Author: Administrator
 */

#ifndef GPIO_H_
#define GPIO_H_
#include "types.h"
/*-----------------------------------------------------------------------------
// Register Structure & Defines   I/O ¹¦Ŝʨ׃
//-----------------------------------------------------------------------------
 *
 */
typedef struct
{
   volatile uint32 DIR;
   volatile uint32 OUT_DATA;
   volatile uint32 SET_DATA;
   volatile uint32 CLR_DATA;
   volatile uint32 IN_DATA;
   volatile uint32 SET_RIS_TRIG;
   volatile uint32 CLR_RIS_TRIG;
   volatile uint32 SET_FAL_TRIG;
   volatile uint32 CLR_FAL_TRIG;
   volatile uint32 IRQ_STAT;
} gpio_regs_t;
#define RIS_TRIG 0
#define FAL_TRIG 1
// define all the available gpio peripherals for the processor.
#define GPIOBINTEN               ((uint32*)GPIO_BINTEN)
#define GPIO_BANK01              ((gpio_regs_t *)GPIO_BANK01_BASE)
#define GPIO_BANK23              ((gpio_regs_t *)GPIO_BANK23_BASE)
#define GPIO_BANK45              ((gpio_regs_t *)GPIO_BANK45_BASE)
#define GPIO_BANK67              ((gpio_regs_t *)GPIO_BANK67_BASE)
#define GPIO_BANK8_              ((gpio_regs_t *)GPIO_BANK8_BASE)

//-----------------------------------------------------------------------------
// Public Defines and Macros
//-----------------------------------------------------------------------------
#define GPIO_BANK0            (0)
#define GPIO_BANK1            (1)
#define GPIO_BANK2            (2)
#define GPIO_BANK3            (3)
#define GPIO_BANK4            (4)
#define GPIO_BANK5            (5)
#define GPIO_BANK6            (6)
#define GPIO_BANK7            (7)
#define GPIO_BANK8            (8)
#define MAX_GPIO_BANK_NUM     (9)

#define GPIO_PIN0             (0)
#define GPIO_PIN1             (1)
#define GPIO_PIN2             (2)
#define GPIO_PIN3             (3)
#define GPIO_PIN4             (4)
#define GPIO_PIN5             (5)
#define GPIO_PIN6             (6)
#define GPIO_PIN7             (7)
#define GPIO_PIN8             (8)
#define GPIO_PIN9             (9)
#define GPIO_PIN10            (10)
#define GPIO_PIN11            (11)
#define GPIO_PIN12            (12)
#define GPIO_PIN13            (13)
#define GPIO_PIN14            (14)
#define GPIO_PIN15            (15)
#define MAX_GPIO_PIN_NUM      (16)

#define GPIO_OUTPUT           (0)
#define GPIO_INPUT            (1)

#define OUTPUT_LOW            (0)
#define OUTPUT_HIGH           (1)

//-----------------------------------------------------------------------------
// Public Function Prototypes
//-----------------------------------------------------------------------------
uint32 GPIO_setDir(uint32 in_bank, uint8 in_pin_num, uint8 in_dir);
uint32 GPIO_getInput(uint32 in_bank, uint8 in_pin_num, uint8 *gpio_val);
uint32 GPIO_setOutput(uint32 in_bank, uint8 in_pin_num, uint8 in_val);

extern void GPIO_toggleLoop(uint8 in_bank, uint8 in_pin, uint8 in_dir ,uint8 in_pins_value);

extern void AdStartIoIinit(void);


/**GPIO¹ܽƀ�*/
class GPIO{
public:
/**
 * »򈠇PIO¹ܽŵ膽ֵ
 *
 * @param pin    GPIO¹ܽÍ
 *
 * @return 0: µ膽µˍ
 *				 1: ¸ߵ膽
 *
 */
int16 Read(int32 PIN);
/**
 * ʨ׃GPIOµ膽
 *
 * @param pin    GPIO¹ܽÍ
 * @param value  0: µ͵膽
 *               1: ¸ߵ膽
 *
 * @return 0: ³ɹ¦
 *         Ǥ̻: ʧ°ڍ
 */
 int16 Write(int32 PIN,int16 value);
};

#endif /* GPIO_H_ */
