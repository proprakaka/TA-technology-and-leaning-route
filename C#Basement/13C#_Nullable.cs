//=========================================================
// 第14章 C# 可空类型 (Nullable)
//=========================================================
//普通的值类型（如 int）不能为空(null)。可空类型让“值类型”也能表示“没有值”。
//写法：在值类型后加一个问号 ?，例如 int? 表示"可为空的 int"。

using System;

namespace NullableTeaching
{
    class Program
    {
        static void Main()
        {
            //-----------------------------------------------------
            // 1. 声明可空类型：类型? 变量名 = ...
            //-----------------------------------------------------
            int? num1 = null;              // 可空 int，赋值为 null（空）
            int? num2 = 45;                // 可空 int，赋值为 45
            double? num3 = new double?();  // 等价于 null
            double? num4 = 3.14157;
            bool? boolval = new bool?();   // 可空 bool，默认 null

            Console.WriteLine("显示可空变量的值：{0}, {1}, {2}, {3}",
                              num1, num2, num3, num4);
            //上面 num1、num3 是 null，打印出来是空白。

            //-----------------------------------------------------
            // 2. 可空类型的两个核心属性：
            //    HasValue：是否有值（true 表示有值，false 表示 null）
            //    Value   ：取出实际的值（仅在 HasValue 为 true 时才能安全使用）
            //-----------------------------------------------------
            Console.WriteLine("num1.HasValue = {0}", num1.HasValue);   // False
            Console.WriteLine("num2.HasValue = {0}", num2.HasValue);   // True
            if (num2.HasValue)
            {
                Console.WriteLine("num2.Value = {0}", num2.Value);     // 45
            }

            //-----------------------------------------------------
            // 3. 空合并运算符 ?? ：当左侧为 null 时，用右侧的值作为结果。
            //    语法： 可能为空的表达式 ?? 默认值
            //-----------------------------------------------------
            int? maybeNull = null;
            int fallback = maybeNull ?? 54;    // maybeNull 是 null，所以取 54
            int real = (num2 ?? 100);          // num2 是 45，不为 null，所以取 45
            Console.WriteLine("?? 示例：fallback={0}, real={1}", fallback, real);

            Console.ReadKey();
        }
    }
}

/*
【小结】
  · int?  = Nullable<int> 的简写，表示"可为空的整数"；
  · HasValue 判断是否有值，Value 取值；
  · ?? 空合并运算符：左边为 null 时返回右边，常用于给空值一个默认值。
*/