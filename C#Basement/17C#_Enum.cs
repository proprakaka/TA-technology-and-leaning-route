//=========================================================
// 第18章 C# 枚举 (Enum)
//=========================================================
//枚举 enum：给一组“固定的取值”起有意义的名字，让代码更可读。
//比如用 Suit { Club, Diamond, Heart, Spade } 表示扑克牌的四种花色。

using System;

namespace EnumTeaching
{
    //定义一个枚举：enum 枚举名 { 成员1, 成员2, ... }
    //每个成员默认对应一个 int 值，从 0 开始依次 +1。
    enum Days { Sun, Mon, Tue, Wed, Thu, Fri, Sat };
    //  Sun=0, Mon=1, Tue=2, ... Sat=6

    //也可以手动指定每个成员的值：
    enum Direction { North = 1, East = 2, South = 4, West = 8 };

    class Program
    {
        static void Main()
        {
            //-----------------------------------------------------
            // 1. 声明一个枚举变量，赋值时用 枚举名.成员
            //-----------------------------------------------------
            Days today = Days.Wed;
            Console.WriteLine("today = {0}", today);              // 打印成员名 Wed

            //枚举本质是 int，可以转成 int 得到它的数值：
            int dayValue = (int)today;
            Console.WriteLine("today 的数值 = {0}", dayValue);     // 3

            //反过来，int 也能转回枚举：
            Days back = (Days)2;
            Console.WriteLine("数值 2 对应 = {0}", back);          // Tue

            //-----------------------------------------------------
            // 2. 自定义值的枚举：值可以是不连续的。
            //-----------------------------------------------------
            Direction dir = Direction.North | Direction.East;     // 用位或组合(1|2=3)
            Console.WriteLine("组合方向 = {0} (数值 {1})", dir, (int)dir);

            //-----------------------------------------------------
            // 3. 列举枚举的所有成员：Enum.GetNames / 数值用 Enum.GetValues
            //-----------------------------------------------------
            Console.WriteLine("Days 的所有成员：");
            foreach (string name in Enum.GetNames(typeof(Days)))
            {
                Console.WriteLine("  " + name);
            }

            Console.ReadKey();
        }
    }
}

/*
【小结】
  · enum 定义一组有名字的整数常量，默认从 0 递增；
  · 可手动指定值，也可跳过某些值；
  · 枚举 ↔ int 可以互相转换： (int)枚举 或 (枚举)数值；
  · 可用位运算组合枚举（值为 1、2、4、8 这种 2 的幂时）。
*/