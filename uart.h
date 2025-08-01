#include "types.h"

void InitUART0 (void); /* Initialize Serial Interface       */ 
void UART0_Tx(char );  
char UART0_Rx(void);
void UART0_Str(char *);
void UART0_Int(unsigned int);
