#include <std_types.h>

extern uint32 _estack;
extern uint32 _sidata;
extern uint32 _sdata;
extern uint32 _edata;
extern uint32 _sbss;
extern uint32 _ebss;

int main(void);

void Default_Handler(void)
{
    while(1);
}

void Reset_Handler(void)
{

  uint32 *psrc = &_sidata;
  uint32 *pdst = &_sdata;

  while(pdst < &_edata)
  {
    *pdst = *psrc;
    ++psrc;
    ++pdst;
  }

  pdst = &_sbss;
  while(pdst < &_ebss)
  {
    *pdst = 0;
    ++pdst;
  }

  main();

  while(1);
}


uint32 vector_table[] __attribute__ ((section(".isr_vector"))) =
{
  (uint32)&_estack,
  (uint32)&Reset_Handler,
  (uint32)&Default_Handler,
  (uint32)&Default_Handler,
  (uint32)&Default_Handler,
  (uint32)&Default_Handler,
  (uint32)&Default_Handler,
  0,
  0,
  0,
  0,
  (uint32)&Default_Handler,
  (uint32)&Default_Handler,
  0,
  (uint32)&Default_Handler,
  (uint32)&Default_Handler,
  (uint32)&Default_Handler,
  (uint32)&Default_Handler,
  (uint32)&Default_Handler,
  (uint32)&Default_Handler,
  (uint32)&Default_Handler,
  (uint32)&Default_Handler,
  (uint32)&Default_Handler,
  (uint32)&Default_Handler,
  (uint32)&Default_Handler,
  (uint32)&Default_Handler,
  (uint32)&Default_Handler,
  (uint32)&Default_Handler,
  (uint32)&Default_Handler,
  (uint32)&Default_Handler,
  (uint32)&Default_Handler,
  (uint32)&Default_Handler,
  (uint32)&Default_Handler,
  (uint32)&Default_Handler,
  (uint32)&Default_Handler,
  (uint32)&Default_Handler,
  (uint32)&Default_Handler,
  (uint32)&Default_Handler,
  (uint32)&Default_Handler,
  (uint32)&Default_Handler,
  (uint32)&Default_Handler,
  (uint32)&Default_Handler,
  (uint32)&Default_Handler,
  (uint32)&Default_Handler,
  (uint32)&Default_Handler,
  (uint32)&Default_Handler,
  (uint32)&Default_Handler,
  (uint32)&Default_Handler,
  (uint32)&Default_Handler,
  (uint32)&Default_Handler,
  (uint32)&Default_Handler,
  (uint32)&Default_Handler,
  (uint32)&Default_Handler,
  (uint32)&Default_Handler,
  (uint32)&Default_Handler,
  (uint32)&Default_Handler,
  (uint32)&Default_Handler,
  (uint32)&Default_Handler,
  (uint32)&Default_Handler,
  (uint32)&Default_Handler,
  (uint32)&Default_Handler,
  (uint32)&Default_Handler,
  (uint32)&Default_Handler,
  (uint32)&Default_Handler,
  (uint32)&Default_Handler,
  (uint32)&Default_Handler,
  (uint32)&Default_Handler,
  (uint32)&Default_Handler,
  (uint32)&Default_Handler,
  (uint32)&Default_Handler,
  (uint32)&Default_Handler,
  (uint32)&Default_Handler,
  (uint32)&Default_Handler,
  (uint32)&Default_Handler,
  (uint32)&Default_Handler,
  (uint32)&Default_Handler,
  (uint32)&Default_Handler,
  (uint32)&Default_Handler,
  (uint32)&Default_Handler,
  (uint32)&Default_Handler,
  (uint32)&Default_Handler,
  (uint32)&Default_Handler,
  (uint32)&Default_Handler,
  (uint32)&Default_Handler,
  (uint32)&Default_Handler,
  (uint32)&Default_Handler,
  (uint32)&Default_Handler,
  (uint32)&Default_Handler,
  (uint32)&Default_Handler,
  (uint32)&Default_Handler,
  (uint32)&Default_Handler,
  (uint32)&Default_Handler,
  (uint32)&Default_Handler,
  (uint32)&Default_Handler,
  (uint32)&Default_Handler,
  0,
  (uint32)&Default_Handler,
  (uint32)&Default_Handler
};


