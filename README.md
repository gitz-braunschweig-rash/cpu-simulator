# cpu-simulator
education cpu simulator

Opcode

0x0 0000 add r1, r2, r_tartet
0x1 0001 sub r1, r2, r_tartet
0x2 0010 mul r1, r2, r_tartet
0x3 0011 div r1, r2, r_tartet
0x4 0100 load r, address
0x5 0101 store r, address
0x6 0110 add_register_first_half r1 value
0x7 0111 add_register_second_half r1 value
0x8 1000 push r
0x9 1001 pop r
0xA 1010 jump_fixed
0xB 1011 jump_register
0xC 1100 branch_on_equal r1,r2,r_target
0xD 1101 set_stack_pointer
0xE 1110 load_register address r1, into r2
0xF 1111 store_register value r1, into address r2


components

programm counter
status register
stack pointer
ram 
registers
