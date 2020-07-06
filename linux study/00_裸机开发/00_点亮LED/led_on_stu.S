/* light LED1 LED2 LED4
write GPFCON[9:8]=0X01 , ADR=0X56000050 -> configure GPF4 as output
write GPFCON[11:10]=0X01 -> configure GPF5 as output
write GPFCON[13:12]=0X01 -> configure GPF6 as output

write GFPDAT[6:4]=0X0 , 0x56000054 -> configure GPF4 GPF5 GPF6 as low voltage
*/

.text
.global _start

_start:

   ldr r1,=0x56000050
   ldr r0,[r1] /* GPFCON -> r0 */
   orr r0,#0x1500 /* GPFCON[13:8]=0X010101 */
   ldr r2,=0xD5FF
   and r0,r2 /* GPFCON[13:8]=0X010101 */
   str r0,[r1] /* r0 -> GPFCON */

   ldr r0,=0x56000054
   ldr r1,[r0] /* GPFDAT ->r1 */
   /* bic r1, #0x70  GFPDAT[6:4]=0X0 */
   ldr r1,=0x30 /* GFPDAT[5:4]=0X0 */
   str r1,[r0] /* r1 ->GPFDAT */

halt:
    b halt



















