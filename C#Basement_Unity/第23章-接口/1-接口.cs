//=========================================================
// 第23章 C# 接口 (Interface)
//=========================================================
//接口 interface：定义一组"方法签名"作为契约，不写具体实现。
//类"实现"接口时，必须把接口里的所有成员都实现出来。
//接口用于实现 C# 缺失的“多继承”能力：一个类可以实现多个接口。

using System;

namespace InterfaceTeaching
{
    //定义一个接口：接口成员默认就是 public，所以不需要(也不能)写访问修饰符。
    interface IPaintCost
    {
        int GetCost(int area);     // 接口方法只有签名，没有方法体
    }

    //还可以定义多个接口：
    interface IShape
    {
        double GetArea();
    }

    //一个类可以实现"多个"接口（用逗号隔开），这弥补了类的单继承限制。
    class Rectangle : IShape, IPaintCost
    {
        private double length;
        private double width;

        public Rectangle(double l, double w)
        {
            length = l;
            width = w;
        }

        //实现 IShape 接口的方法
        public double GetArea()
        {
            return length * width;
        }

        //实现 IPaintCost 接口的方法（这里用了 int 强转，参数是面积）
        public int GetCost(int area)
        {
            return area * 70;    // 每单位面积 70 元
        }
    }

    //接口也可以“继承”接口：
    interface IAdvanced : IShape
    {
        double GetPerimeter();   // 新增一个方法
    }

    class Square : IAdvanced
    {
        private double side;
        public Square(double s) { side = s; }

        public double GetArea() { return side * side; }                       // 来自 IShape
        public double GetPerimeter() { return side * 4; }                     // 来自 IAdvanced
    }

    class Program
    {
        static void Main()
        {
            Rectangle r = new Rectangle(4.0, 5.0);
            int area = (int)r.GetArea();
            Console.WriteLine("面积 = {0}", area);
            Console.WriteLine("刷漆成本 = {0} 元", r.GetCost(area));

            Square sq = new Square(3.0);
            Console.WriteLine("正方形面积 = {0}，周长 = {1}", sq.GetArea(), sq.GetPerimeter());

            Console.ReadKey();
        }
    }
}

/*
【接口 vs 抽象类】
  · 接口：只定义"能做什么"（方法签名），不提供任何实现；类可实现多个接口；
  · 抽象类：可以包含字段、已实现方法，也能有抽象方法；类只能继承一个抽象类；
  · 接口成员默认 public，接口不能有字段、不能实例化。
*/