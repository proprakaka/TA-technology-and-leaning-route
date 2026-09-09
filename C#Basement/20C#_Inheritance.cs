//=========================================================
// 第20章 C# 继承 (Inheritance)
//=========================================================
//继承：让一个"派生类(子类)"获得"基类(父类)"的成员，实现代码复用。
//语法：class 子类 : 基类

using System;

namespace InheritanceTeaching
{
    //---- 基类（父类）----
    //Shape 提供一个通用的"形状"抽象：有 width、height，和 SetSize 方法。
    class Shape
    {
        protected double width;      // protected：本类和子类可见
        protected double height;

        public void SetSize(double w, double h)
        {
            width = w;
            height = h;
        }
    }

    //---- 派生类（子类）----
    //Rectangle 继承 Shape，自动拥有 width、height 和 SetSize。
    //记住：一个类只能继承"一个"直接基类（单继承），但可实现多个接口(第23章)。
    class Rectangle : Shape
    {
        public double GetArea()
        {
            return width * height;   // 直接使用从基类继承的 protected 字段
        }
    }

    //再写一个子类，演示用 base 关键字调用基类构造函数。
    class Animal
    {
        public string Name { get; set; }

        //基类构造函数
        public Animal(string n)
        {
            Name = n;
        }

        public void Eat()
        {
            Console.WriteLine("{0} 正在吃东西", Name);
        }
    }

    class Dog : Animal
    {
        public string Breed { get; set; }

        //子类构造函数：用 base("名字") 调用基类的构造函数。
        //base 关键字：代表"基类"，用来调用基类的成员(构造/方法等)。
        public Dog(string n, string breed) : base(n)
        {
            Breed = breed;
        }

        public void Bark()
        {
            Console.WriteLine("{0}({1}) 汪汪叫！", Name, Breed);
        }
    }

    class Program
    {
        static void Main()
        {
            //使用继承自 Shape 的成员
            Rectangle rect = new Rectangle();
            rect.SetSize(4.5, 3.5);          // SetSize 是父类的方法
            Console.WriteLine("Rectangle 面积 = {0}", rect.GetArea());

            //使用 base 调用基类构造函数的例子
            Dog dog = new Dog("旺财", "金毛");
            dog.Eat();          // Eat 是父类的方法
            dog.Bark();         // Bark 是子类自己的方法

            Console.ReadKey();
        }
    }
}

/*
【小结】
  · 继承语法：class 子类 : 基类，子类自动拥有基类的 public/protected 成员；
  · protected：允许子类访问，但外部不可访问；
  · base：在子类里调用基类的构造函数或方法；
  · C# 是单继承，但可用接口(第23章)实现"多继承"的效果。
*/