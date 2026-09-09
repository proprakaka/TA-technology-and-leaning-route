//=========================================================
// 第21章 C# 多态 (Polymorphism)
//=========================================================
//多态：同一个调用，随着“实际对象类型”的不同而表现出不同行为。
//主要手段：虚方法 virtual / 重写 override，以及抽象类 abstract。

using System;

namespace PolymorphismTeaching
{
    //---- 基类 ----
    //virtual 关键字：把这个方法声明为"虚方法"，允许子类去"重写"它。
    class Shape
    {
        public virtual void Draw()
        {
            Console.WriteLine("画一个普通的形状");
        }
    }

    //子类用 override 重写父类的虚方法，实现自己的画法。
    class Circle : Shape
    {
        public override void Draw()
        {
            Console.WriteLine("画一个圆形 O");
        }
    }

    class Rectangle : Shape
    {
        public override void Draw()
        {
            Console.WriteLine("画一个矩形 □");
        }
    }

    //---- 抽象类 (abstract) ----
    //抽象类不能直接 new，它的作用是"定义一套规范"，让子类去具体实现。
    abstract class Animal
    {
        //抽象方法：只有声明、没有方法体，子类必须实现(重写)。
        public abstract void Sound();

        //抽象类里也可以有"非抽象"的普通方法。
        public void Sleep()
        {
            Console.WriteLine("睡觉中 Zzz...");
        }
    }

    class Dog : Animal
    {
        public override void Sound()      // 必须实现抽象方法
        {
            Console.WriteLine("狗叫：汪汪！");
        }
    }

    class Cat : Animal
    {
        public override void Sound()
        {
            Console.WriteLine("猫叫：喵喵！");
        }
    }

    class Program
    {
        static void Main()
        {
            //-----------------------------------------------------
            // 关键点：把子类对象赋给"父类类型"的变量，
            // 调用时实际上执行的是"子类重写后"的方法——这就是运行时多态。
            //-----------------------------------------------------
            Shape s1 = new Circle();
            Shape s2 = new Rectangle();
            s1.Draw();        // 实际是 Circle.Draw
            s2.Draw();        // 实际是 Rectangle.Draw

            //抽象类的多态用法：统一的父类引用，调用各自实现。
            Animal[] animals = { new Dog(), new Cat() };
            foreach (Animal a in animals)
            {
                a.Sound();    // 同一个调用，不同对象不同表现
                a.Sleep();    // 普通方法直接调用
            }

            Console.ReadKey();
        }
    }
}

/*
【小结】
  · 虚方法：基类方法加 virtual；子类加 override 重写；
  · 运行时多态：父类引用指向子类对象，调用时走子类的实现；
  · 抽象类：用 abstract 定义；含抽象方法的类是抽象类，不能 new；
  · 抽象方法只有签名没有实现，由派生类 override 强制实现。
*/