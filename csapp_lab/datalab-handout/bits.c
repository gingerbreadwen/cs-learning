/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
//1
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
  return ~((~x)&(~y))&(~(x&y)); // using mogan law
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
  // min_val 100000 32bits
  // max_val 011111 32bits
  return 1 << 31;

}
//2
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x) {
  // max bits 01111111
  // 11111111 去除
 return (!((~(x+1))^x))&(!!((x+1)^0x0));
}
/* 
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) {
  int mask = 0xAA+(0xAA<<8);
  mask = mask + (mask<<16);
  // int mask = 0xAAAAAAAA;
  return !((mask&x)^mask);
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  return ~x+1;
}
//3
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
  // 分位处理 0x30 0b00110000 0x39 0b00110101
  // 处理前26位
  int cond1,cond2,cond3,a,b,c,last_4;
  a = x>>6;
  cond1 = !(a^0x0);
  // 处理27~28位
  b = x>>4;
  cond2=!(b^0b11);
  // 处理最后四位
  last_4 = x&0xF;
  c = last_4+(~0xA+1); //l-9<0 1
  cond3 = c>>31; // 首位为1
  return cond1&cond2&cond3;
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
  // x->mask 0x0,!0x0 1111111(!0x0)/0000000(0x0)
  int mask = (!!x) <<31 >>31;
  return (mask&y)|(~mask&z);
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
  // cond1 x y 异号
  // cond2 x,y 同号
  int cond1,cond2;
  int sign = 1<<31;
  int signx = !(sign&x);// 负号输出0 正号输出1
  int signy = !(sign&y);
  int samesign = !(signx^signy); // 同号1异号0
  int diff = ~x +y+1;// x-y

  cond1 = (!signx)&(signy); // x+ y- 0 x- y+ 1 异号情况   
  cond2 = samesign&!(diff&sign); // 同号情况
  return cond1|cond2;
}
//4
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNeg(int x) {
  // 区分0 0000000000 与 非0 1111111111 逻辑右移
  int negx = ~x+1;
  return ((negx|x)>>31)+1;
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) {
  // 最多需要多少位来表示
  //  x == 0 -> 1
  //  x >0 -> 1+hignbit
  //  x <0 -> 
  int bit_16,bit_8,bit_4,bit_2,bit_1,bit_0;
  int flag = x>>31;
  x = ((~flag)&x) |(flag&(~x)); // get the highest bits 
  
  bit_16 = !!(x>>16)<<4; // 如果高16位非0 输出16 否则输出 0
  x = x >> bit_16;
  bit_8 = !!(x>>8)<<3; // 如果高8位非0 输出8 否则输出 0
  x = x >> bit_8;
  bit_4 = !!(x>>4)<<2; // 如果高4位非0 输出4 否则输出 0
  x = x >> bit_4;
  bit_2 = !!(x>>2)<<1; // 如果高2位非0 输出2 否则输出 0
  x = x >> bit_2;
  bit_1 = !!(x>>1); // 如果高1位非0 输出1 否则输出 0
  x = x >> bit_1;
  bit_0 = x; // 如果本位非0 则输出1 否则输出 0
  return bit_16+bit_8+bit_4+bit_2+bit_1+bit_0+1;//加上符号位

  


  return bit_16+bit_8+bit_4+bit_2+bit_1+bit_0;
}
//float
// -1
/* 
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatScale2(unsigned uf) {
  // 计算浮点数的两倍
  // 拿到sign位 exp位 frac位
  // 1 先拿到符号位 最后一位
  unsigned s = (uf >> 31)&(0x1);
  // 2 右移23位拿到指数位 获取指数位各个位置的值,去除最高位
  unsigned expr = (uf >> 23)&(0xFF);
  // 3 直接取23位 获取 分数位 去除前面所有位数
  unsigned frac = (uf & 0x7FFFFF);
  // 不同的浮点部分分情况输出
  // 浮点为0的情况
  if (expr == 0 && frac == 0)
  {
    return uf;
  }
  //infinity or not a number 浮点为无穷大或者NaN
  if (expr==0xFF)
  {
    return uf;
  }
  // denormalize
  if (expr == 0)
  {
    //M 0.xxxxxx <1
    // E = 1-127
    frac <<=1;
    return (s<<31)|frac;
  }
  // normalize
  expr++;// 扩大两倍？
  // E =expr -127
  return(s<<31)|(expr<<23)|frac;
}
/* 
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int floatFloat2Int(unsigned uf) {
  // 浮点数转整型数
  // 1 先拿到符号位 最后一位
  unsigned s = (uf >> 31)&(0x1);
  // 2 右移23位拿到指数位 获取指数位各个位置的值,去除最高位
  unsigned expr = (uf >> 23)&(0xFF);
  // 3 直接取23位 获取 分数位 去除前面所有位数
  unsigned frac = (uf & 0x7FFFFF);

  // 浮点数表达为0
  if (expr==0&&frac==0)
  {
    return 0;
  }
  // 浮点数表达为最大值inf
  if (expr==0xFF)
  {
    return 1<<31;
  }
  // 浮点数表达为非正规化
  if (expr==0)
  {
    // M 0.1111<1
    // E 1-127=-126
    return 0;

  }

  // 浮点数表达为正规化
  int E = expr - 127;
  frac = frac | (1<<23);
  
  
  
  
  return 2;
}
/* 
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 * 
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while 
 *   Max ops: 30 
 *   Rating: 4
 */
unsigned floatPower2(int x) {
    return 2;
}
