#include "types.h"

void WriteLCD(u8 byte);
void CmdLCD(u8 cmd);
void InitLCD(void);
void CharLCD(u8 asciiVal);
void SetCursor(u8 lineNo,u8 pos);
void StrLCD(s8 *str);
void U32LCD(u32 num);
void S32LCD(s32 num);
void F32LCD(f32 fNum,u32 nDP);
void BuildCGRAM(u8 *p);
u8 switch_pressed(void);
