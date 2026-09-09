//=========================================================
// 第17章 C# 结构体 (Struct)
//=========================================================
//结构体 struct 和类 class 很像（都能装数据和放方法），
//但有一个关键区别：struct 是"值类型"，class 是"引用类型"。

using System;

namespace StructTeaching
{
    //定义一个结构体：关键字 struct + 名字。
    //结构体适合表示"轻量的小数据对象"，比如一个点、一个颜色、一笔订单明细。
    struct Point
    {
        //成员变量
        public int X;
        public int Y;

        //结构体里也可以定义方法
        public void Display()
        {
            Console.WriteLine("Point 坐标：({0}, {1})", X, Y);
        }
    }

    //再来一个结构体，演示"带构造函数的结构体"。
    struct Rectangle
    {
        public double length;
        public double width;

        //结构体的构造函数：必须给"所有字段"都赋值。
        //构造函数的名字与结构体同名，没有返回类型。
        public Rectangle(double l, double w)
        {
            length = l;
            width = w;
        }

        public double GetArea()
        {
            return length * width;
        }
    }

    class Program
    {
        static void Main()
        {
            //使用结构体：和类一样 new 出来（也可以不 new，先给字段赋值再用）。
            Point p = new Point();
            p.X = 3;
            p.Y = 4;
            p.Display();

            //带构造函数的结构体：创建时直接传入参数。
            Rectangle rect = new Rectangle(4.5, 2.0);
            Console.WriteLine("矩形面积 = {0}", rect.GetArea());

            //-----------------------------------------------------
            // 演示 struct 与 class 的“值类型 vs 引用类型”区别：
            // 结构体赋值是"拷贝一份"，改其中一个不影响另一个。
            //-----------------------------------------------------
            Point p1 = new Point();
            p1.X = 1;
            Point p2 = p1;      // p2 复制了 p1 的值（各自独立）
            p2.X = 99;          // 改 p2 不影响 p1
            Console.WriteLine("p1.X = {0}, p2.X = {1}", p1.X, p2.X);   // 1 和 99

            Console.ReadKey();
        }
    }
}

/*
【struct 与 class 的区别】
  1. struct 是值类型，class 是引用类型；
  2. struct 不能继承其它 struct/class，也不能被继承（但可以实现接口）；
  3. struct 赋值会复制整个数据，class 赋值只复制"引用"（指向同一对象）；
  4. struct 中不能写"无参构造函数"（C#10 起允许，但传统上只能写带参构造函数）；
  5. struct 适合轻量数据，class 适合复杂对象。

【this 关键字（预告）】
  在方法里可以用 this 表示"当前对象/当前结构体本身"，第19章会详细讲。
*/