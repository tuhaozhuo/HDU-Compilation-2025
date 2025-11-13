
sample.o:	file format mach-o arm64

Disassembly of section __TEXT,__text:

0000000000000000 <ltmp0>:
       0: d10043ff     	sub	sp, sp, #0x10
       4: b9000fff     	str	wzr, [sp, #0xc]
       8: 52800088     	mov	w8, #0x4                ; =4
       c: b9000be8     	str	w8, [sp, #0x8]
      10: b9400be8     	ldr	w8, [sp, #0x8]
      14: 71000108     	subs	w8, w8, #0x0
      18: 1a9f17e8     	cset	w8, eq
      1c: 370000c8     	tbnz	w8, #0x0, 0x34 <ltmp0+0x34>
      20: 14000001     	b	0x24 <ltmp0+0x24>
      24: b9400be8     	ldr	w8, [sp, #0x8]
      28: 11001108     	add	w8, w8, #0x4
      2c: b9000be8     	str	w8, [sp, #0x8]
      30: 14000005     	b	0x44 <ltmp0+0x44>
      34: b9400be8     	ldr	w8, [sp, #0x8]
      38: 531e7508     	lsl	w8, w8, #2
      3c: b9000be8     	str	w8, [sp, #0x8]
      40: 14000001     	b	0x44 <ltmp0+0x44>
      44: 52800000     	mov	w0, #0x0                ; =0
      48: 910043ff     	add	sp, sp, #0x10
      4c: d65f03c0     	ret
