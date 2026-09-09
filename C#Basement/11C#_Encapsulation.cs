//=========================================================
// 第12章 C# 封装 (Encapsulation)
//=========================================================
//封装：把数据和操作数据的方法“捆绑”在一起，并控制外部能否访问。
//它通过“访问修饰符”来实现"该公开的公开、该隐藏的隐藏"。

using System;

namespace EncapsulationTeaching
{
    //Rectangle 把“数据(长、宽)”和“行为(计算面积等)”封装在一起。
    class Rectangle
    {
        //成员变量使用 internal 修饰：表示“同一个程序集(项目)”内可以访问。
        //internal 是 C# 里"处在同一程序集"的公开级别。
        internal double length;
        internal double width;

        //计算面积的方法：这里不需要参数，直接使用成员变量。
        internal double GetArea()
        {
            return length * width;
        }

        internal void Display()
        {
            Console.WriteLine("长度：{0}", length);
            Console.WriteLine("宽度：{0}", width);
            Console.WriteLine("面积：{0}", GetArea());
        }
    }

    class ExecuteRectangle
    {
        static void Main()
        {
            Rectangle r = new Rectangle();
            r.length = 4.5;      // 直接给成员变量赋值
            r.width = 3.5;

            r.Display();
            Console.ReadKey();
        }
    }
}

/*
【封装的核心：访问修饰符 (Access Modifiers)】
C# 提供 5 种访问级别，关键字和含义如下：

  public           公开：任何代码都能访问。
  private          私有：只能在“当前类内部”访问。（类成员的默认级别，不加修饰符就是 private）
  protected        受保护：只能在“当前类及其子类(继承类)”中访问。
  internal         内部：只能在“同一个程序集(项目)”内访问。（类本体的默认级别）
  protected internal  受保护内部：当前程序集内 + 子类，取两者并集。

【为什么要封装？】
  1. 隐藏内部实现细节，只暴露必要的接口，使用更简单；
  2. 保护数据不被外部随意篡改（配合属性/方法做访问控制）；
  3. 便于维护：内部改动不影响外部使用者。

【关于“属性(Property)”的一个预告】
  通常我们不会像上面那样直接 public 暴露字段，而是用 get/set 属性来控制读写，
  这一进阶封装方式会在第19章“类”里详细讲解。
*/