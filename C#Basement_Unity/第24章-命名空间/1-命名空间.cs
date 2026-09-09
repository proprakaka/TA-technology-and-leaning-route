//=========================================================
// 第24章 C# 命名空间 (Namespace)
//=========================================================
//命名空间 namespace：把代码分门别类，避免不同来源的类名冲突。
//语法：namespace 名字 { ... }
//使用别处的命名空间用 using。

using System;

//方式一：定义一个命名空间（命名空间里可以再嵌套命名空间）。
namespace FirstSpace
{
    class Apple
    {
        public void Show()
        {
            Console.WriteLine("来自 FirstSpace 的苹果");
        }
    }

    //嵌套命名空间：通过 . 隔开层级。
    namespace NestedSpace
    {
        class Banana
        {
            public void Show()
            {
                Console.WriteLine("来自 FirstSpace.NestedSpace 的香蕉");
            }
        }
    }
}

//方式二：两个不同的命名空间可以有"同名类"，互不冲突。
namespace SecondSpace
{
    class Apple
    {
        public void Show()
        {
            Console.WriteLine("来自 SecondSpace 的苹果");
        }
    }
}

namespace ProgramSpace
{
    class Program
    {
        static void Main()
        {
            //-----------------------------------------------------
            // 1. 用 命名空间.类名 的方式，全限定名字来访问。
            //-----------------------------------------------------
            FirstSpace.Apple apple1 = new FirstSpace.Apple();
            apple1.Show();

            SecondSpace.Apple apple2 = new SecondSpace.Apple();
            apple2.Show();

            //-----------------------------------------------------
            // 2. 用 using 引入命名空间后，可以直接用类名；有同名类时必须写全限定名。
            //-----------------------------------------------------
            FirstSpace.NestedSpace.Banana banana = new FirstSpace.NestedSpace.Banana();
            banana.Show();

            //-----------------------------------------------------
            // 3. using 别名：给一个长命名空间/类起简称。
            //-----------------------------------------------------
            //（C# 里 using 别名通常写在文件顶部 using 区，这里用全限定名演示）
            Console.WriteLine("命名空间学习完毕。");

            Console.ReadKey();
        }
    }
}

/*
【小结】
  · namespace 用来组织代码、避免命名冲突；
  · 用 using 引入命名空间，或使用完全限定名(命名空间.类名)访问；
  · 命名空间可以嵌套；不同命名空间可以有同名类；
  · using 还支持写别名：using 别名 = 命名空间/类型;（还有 using static 引入静态成员）。
*/