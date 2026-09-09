//=========================================================
// 第19章 C# 类（上）—— 类的定义、构造函数、析构函数
//=========================================================
//类是 C# 面向对象的核心：把“数据(字段)”和“行为(方法)”封装在一起。
//本章分上下两部分：上篇讲定义和构造函数，下篇讲属性与静态成员。

using System;

namespace ClassTeaching
{
    //定义一个类 Student（学生）。
    class Student
    {
        //---- 字段（成员变量）----
        public string name;     // 姓名
        public int age;         // 年龄

        //---- 构造函数 (Constructor) ----
        //特点：名字必须与类名完全相同，且“没有返回类型”。
        //作用：在创建对象(new)时自动执行，用来初始化对象。

        //默认(无参)构造函数：不写参数。如果你一个构造函数都没写，编译器会自动生成一个。
        public Student()
        {
            name = "未命名";
            age = 0;
            Console.WriteLine("调用了无参构造函数");
        }

        //带参构造函数：创建对象时传入姓名和年龄。
        //一个类可以有多个构造函数（这叫"构造函数重载"，靠参数数量/类型区分）。
        public Student(string n, int a)
        {
            name = n;
            age = a;
            Console.WriteLine("调用了带参构造函数");
        }

        //---- 析构函数 (Destructor) ----
        //写法：类名前加 ~。它没有参数、没有返回值，也不能被显式调用，
        //在对象被垃圾回收(GC)时由系统自动调用，用于释放资源。实际少用，了解即可。
        ~Student()
        {
            Console.WriteLine("Student 对象被回收：{0}", name);
        }

        //---- 普通方法 ----
        public void Introduce()
        {
            Console.WriteLine("我叫 {0}，今年 {1} 岁。", name, age);
        }
    }

    class Program
    {
        static void Main()
        {
            Student s1 = new Student();            // 走无参构造函数
            s1.Introduce();

            Student s2 = new Student("小明", 18);  // 走带参构造函数
            s2.Introduce();

            Console.ReadKey();
        }
    }
}

/*
【小结】
  · 类 = 字段 + 方法，用 new 创建对象；
  · 构造函数：与类同名、无返回类型，new 时自动执行，可重载（多个）；
  · 析构函数：~类名，GC 回收时调用，极少手写；
  · next：下篇讲属性(Property)与静态成员(static)。
*/