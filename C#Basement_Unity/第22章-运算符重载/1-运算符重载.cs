//=========================================================
// 第22章 C# 运算符重载 (Operator Overloading)
//=========================================================
//运算符重载：给自定义类型(如自己写的类/结构体)定义"运算符"的行为。
//例如让两个 Box 对象能用 + 直接相加。语法：static 返回类型 operator 运算符(参数)

using System;

namespace OperatorOverloadingTeaching
{
    //一个"盒子"结构体：有长、宽、高。
    struct Box
    {
        public double length;
        public double width;
        public double height;

        public Box(double l, double w, double h)
        {
            length = l;
            width = w;
            height = h;
        }

        //计算体积
        public double GetVolume()
        {
            return length * width * height;
        }

        //-----------------------------------------------------
        // 重载 + 运算符：两个箱子的"对应边相加"得到一个新箱子。
        // 语法：public static 返回类型 operator +(左操作数, 右操作数)
        //-----------------------------------------------------
        public static Box operator +(Box a, Box b)
        {
            Box c = new Box();
            c.length = a.length + b.length;
            c.width = a.width + b.width;
            c.height = a.height + b.height;
            return c;
        }

        //重载 == 运算符：比较两个箱子体积是否相等。
        //注意：C# 要求 == 和 != 必须成对重载。（同时也建议重写 Equals/GetHashCode）
        public static bool operator ==(Box a, Box b)
        {
            return a.GetVolume() == b.GetVolume();
        }

        public static bool operator !=(Box a, Box b)
        {
            return a.GetVolume() != b.GetVolume();
        }
    }

    class Program
    {
        static void Main()
        {
            Box box1 = new Box(2.0, 2.0, 2.0);   // 体积 8
            Box box2 = new Box(3.0, 3.0, 3.0);   // 体积 27
            Box box3 = new Box(1.0, 2.0, 4.0);   // 体积 8

            //调用重载的 + ：box1 + box2
            Box sum = box1 + box2;
            Console.WriteLine("sum 的体积 = {0}", sum.GetVolume());   // (5,5,5) = 125

            //调用重载的 == 与 !=
            Console.WriteLine("box1 == box3 ? {0}", box1 == box3);   // 体积都是8 → true
            Console.WriteLine("box1 != box2 ? {0}", box1 != box2);   // true

            Console.ReadKey();
        }
    }
}

/*
【小结】
  · 运算符重载语法：public static 返回类型 operator 运算符(参数) { ... }
  · 可以重载 + - * / == != 等，让自定义类型支持运算符运算；
  · 可重载运算符有限制：如 [] 、赋值 = 等不能重载；
  · == 与 != 必须成对重载。
*/