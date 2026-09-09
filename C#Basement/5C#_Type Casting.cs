//=========================================================
// 第06章 C# 类型转换 (Type Conversion)
//=========================================================
//类型转换，就是把一种类型的数据“变成”另一种类型。
//C# 里的类型转换主要分两大类：隐式转换 和 显式转换。

using System;

namespace TypeConversionTeaching
{
    class Program
    {
        static void Main()
        {
            //-----------------------------------------------------
            // 1. 隐式转换（Implicit Conversion）
            //    由编译器“自动”完成，无需写额外代码。
            //    前提：目标类型比源类型“更大、更安全”，不会丢失数据。
            //    例如：int → long → float → double（小数类之间从小精度到大精度）。
            //-----------------------------------------------------
            int a = 100;
            long b = a;        // int 自动转 long（安全）
            double c = b;      // long 自动转 double（安全）
            Console.WriteLine("隐式转换：a={0}, b={1}, c={2}", a, b, c);

            //-----------------------------------------------------
            // 2. 显式转换（强制类型转换 / Explicit Conversion）
            //    当"大→小"或可能丢失数据时，编译器不会自动转，需要你明确写出。
            //    语法：在变量前加 (目标类型)。
            //-----------------------------------------------------
            double d = 5673.74;
            int i;
            i = (int)d;        // 强制把 double 转成 int，小数部分会被“截断”
            Console.WriteLine("显式转换：(int)5673.74 = {0}", i);

            //-----------------------------------------------------
            // 3. 使用 Convert 类做转换
            //    System.Convert 提供了一整套转换方法，比强制转换更“显式直观”。
            //    常用：ToInt32, ToDouble, ToString, ToBoolean 等。
            //-----------------------------------------------------
            int i2 = 75;
            float f2 = 53.005f;      // 数字后加 f/F 表示这是一个 float 字面量
            double d2 = 2345.7652;
            bool bo = true;          // bool 只有 true / false 两个取值

            Console.WriteLine(i2.ToString());    // 调用对象的 ToString() 转成字符串
            Console.WriteLine(f2.ToString());
            Console.WriteLine(d2.ToString());
            Console.WriteLine(bo.ToString());

            //Convert 系列会在"类型能转"时正常返回，不能转时抛异常（后面异常处理章节会讲）。
            double d3 = 3.14159;
            int i3 = Convert.ToInt32(d3);        // 四舍五入(银行家舍入)后取整
            string s3 = Convert.ToString(123);   // 数字转字符串
            Console.WriteLine("Convert.ToInt32(3.14159) = {0}, 123转字符串 = {1}", i3, s3);

            //-----------------------------------------------------
            // 4. Parse 与 TryParse：把“字符串”转成数值（这在读取用户输入时非常常用）
            //    int.Parse(字符串) 会在转换失败时抛异常；
            //    int.TryParse(字符串, out 变量) 则返回 true/false，不会抛异常，更安全。
            //-----------------------------------------------------
            string numStr = "123";
            int parsed = int.Parse(numStr);       // "123" → 123
            Console.WriteLine("int.Parse(\"123\") = {0}", parsed);

            int result;
            bool ok = int.TryParse("abc", out result);  // "abc" 不能转 int，返回 false
            Console.WriteLine("TryParse(\"abc\") 是否成功：{0}，结果：{1}", ok, result);

            Console.ReadKey();
        }
    }
}

/*
【小结】
  · 隐式转换：小→大、自动进行，如 int→long；
  · 显式转换(强转)：大→小，需写 (类型)，如 (int)double；
  · Convert 类：提供 ToInt32/ToDouble/ToString 等一系列转换方法；
  · Parse/TryParse：把字符串转成数值，TryParse 更安全；
  · 装箱/拆箱（值类型 ↔ object）已经在第05章讲过了。
*/