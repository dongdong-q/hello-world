#define _reg(a) *(volatile unsigned int *)a
#define _reg_byte(a) *(volatile unsigned char *)a

#define GPFCON _reg(0x56000050)
#define GPFDAT _reg(0x56000054)
#define GPGCON _reg(0x56000060)
#define GPGDAT _reg(0x56000064)
#define GPHCON _reg(0x56000070)
#define GPHDAT _reg(0x56000074)
#define GPHUP  _reg(0x56000078)
#define ULCON0 _reg(0x50000000)
#define UBRDIV0 _reg(0x50000028)
#define UCON0 _reg(0x50000004)
#define UTRSTAT0 _reg(0x50000010)
#define UTXH0 _reg_byte(0x50000020)
#define URXH0 _reg_byte(0x50000024)

