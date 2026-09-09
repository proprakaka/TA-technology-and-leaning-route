//=========================================================
// 第09章 C# 运算符 (Operators)
//=========================================================
//运算符用于对“操作数”进行计算，是语言表达能力的核心。
//C# 的运算符分为：算术、关系、逻辑、位、赋值、其他 六大类。

using System;

namespace OperatorsTeaching
{
    class Program
    {
        static void Main()
        {
            //-----------------------------------------------------
            // 1. 算术运算符： +  -  *  /  %  ++  --
            //    % 是“取余(取模)”；++ 自增1；-- 自减1。
            //-----------------------------------------------------
            int a = 21, b = 10;
            Console.WriteLine("a={0}, b={1}", a, b);
            Console.WriteLine("a + b = {0}", a + b);   // 加
            Console.WriteLine("a - b = {0}", a - b);   // 减
            Console.WriteLine("a * b = {0}", a * b);   // 乘
            Console.WriteLine("a / b = {0}", a / b);   // 整数相除，结果仍是整数(向下取整)
            Console.WriteLine("a % b = {0}", a % b);   // 取余：21 % 10 = 1
            int c = 5;
            c++;                       // 等价于 c = c + 1
            Console.WriteLine("c++ 后 = {0}", c);
            c--;                       // 等价于 c = c - 1
            Console.WriteLine("c-- 后 = {0}", c);

            //-----------------------------------------------------
            // 2. 关系运算符： ==  !=  >  <  >=  <=
            //    结果总是 bool 类型（true / false）。
            //-----------------------------------------------------
            Console.WriteLine("a == b ? {0}", a == b);   // 等于
            Console.WriteLine("a != b ? {0}", a != b);   // 不等于
            Console.WriteLine("a > b  ? {0}", a > b);    // 大于
            Console.WriteLine("a < b  ? {0}", a < b);    // 小于

            //-----------------------------------------------------
            // 3. 逻辑运算符： &&(与)  ||(或)  !(非)，操作数都是 bool。
            //    &&：两边都为 true 才为 true；||：只要一边为 true 就为 true。
            //-----------------------------------------------------
            bool x = true, y = false;
            Console.WriteLine("x && y = {0}", x && y);   // true AND false = false
            Console.WriteLine("x || y = {0}", x || y);   // true OR false  = true
            Console.WriteLine("!x     = {0}", !x);       // NOT true = false

            //-----------------------------------------------------
            // 4. 位运算符： &  |  ^  ~  <<  >>（对二进制位操作）
            //    ^ 异或：位不同为1，相同为0；~ 取反；<< 左移；>> 右移。
            //-----------------------------------------------------
            int m = 60;     // 二进制 0011 1100
            int n = 13;     // 二进制 0000 1101
            Console.WriteLine("m & n  = {0}", m & n);    // 按位与：0000 1100 = 12
            Console.WriteLine("m | n  = {0}", m | n);    // 按位或：0011 1101 = 61
            Console.WriteLine("m ^ n  = {0}", m ^ n);    // 异或  ：0011 0001 = 49
            Console.WriteLine("m << 2 = {0}", m << 2);   // 左移2位：相当于 ×4 = 240
            Console.WriteLine("m >> 2 = {0}", m >> 2);   // 右移2位：相当于 ÷4 = 15

            //-----------------------------------------------------
            // 5. 赋值运算符： =  +=  -=  *=  /=  %= 等
            //    a += b 等价于 a = a + b。
            //-----------------------------------------------------
            int v = 10;
            v += 5;    // v = v + 5
            v %= 3;    // v = v % 3
            Console.WriteLine("v 依次 +=5, %=3 后 = {0}", v);

            //-----------------------------------------------------
            // 6. 其他常用运算符
            //    sizeof  获取类型字节大小
            //    typeof  获取类型的 System.Type 对象
            //    is      判断对象是否属于某类型
            //    as      尝试做类型转换（失败返回 null）
            //    ?:      三元条件运算符
            //-----------------------------------------------------
            Console.WriteLine("sizeof(int) = {0}", sizeof(int));
            Console.WriteLine("typeof(int) = {0}", typeof(int));
            object obj = "hello";
            Console.WriteLine("obj is string ? {0}", obj is string);   // true
            string s = obj as string;                                  // 转成 string
            Console.WriteLine("obj as string -> {0}", s);

            //三元运算符： 条件 ? 真值 : 假值
            int score = 75;
            string level = score >= 60 ? "及格" : "不及格";
            Console.WriteLine("score={0}, 结论={1}", score, level);

            Console.ReadKey();
        }
    }
}

/*
【运算符优先级（从高到低，同类从左到右）】
  后缀/一元  ++ --  ! ~
  乘除取余   *  /  %
  加减       +  -
  移位       <<  >>
  关系       <  >  <=  >=
  相等       ==  !=
  位与       &
  位异或     ^
  位或       |
  逻辑与     &&
  逻辑或     ||
  三元       ?:
  赋值       = += -= 等（优先级最低，从右到左）
  记不住也没关系——用括号 () 显式分组，永远最清晰。
*/