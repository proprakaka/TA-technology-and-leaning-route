//=========================================================
// 第16章 C# 字符串 (String)
//=========================================================
//字符串 string 是"不可变"的文本类型，C# 提供了大量处理字符串的现成方法。

using System;

namespace StringTeaching
{
    class Program
    {
        static void Main()
        {
            //-----------------------------------------------------
            // 1. 常用属性/方法（都是"实例方法"，用 字符串.方法() 调用）
            //-----------------------------------------------------
            string s = "Hello, C# World";

            Console.WriteLine("长度 Length：{0}", s.Length);              // 字符串长度

            Console.WriteLine("转大写 ToUpper：{0}", s.ToUpper());        // 全部大写
            Console.WriteLine("转小写 ToLower：{0}", s.ToLower());        // 全部小写

            Console.WriteLine("是否包含 Contains(\"C#\")：{0}", s.Contains("C#"));   // 子串是否存在
            Console.WriteLine("IndexOf(\"World\")：{0}", s.IndexOf("World"));         // 子串首次出现的下标
            Console.WriteLine("Substring：{0}", s.Substring(0, 5));        // 截取 [0,5) 的字符
            Console.WriteLine("Replace：{0}", s.Replace("World", "C# 教程")); // 替换子串
            Console.WriteLine("Trim：'{0}'", "  hi  ".Trim());             // 去掉首尾空白

            //分割字符串 Split：按某个字符拆成数组
            string csv = "苹果,香蕉,橘子";
            string[] fruits = csv.Split(',');        // 按逗号拆分
            Console.WriteLine("Split 拆分结果：{0} | {1} | {2}", fruits[0], fruits[1], fruits[2]);

            //-----------------------------------------------------
            // 2. 字符串拼接
            //-----------------------------------------------------
            string a = "你好";
            string b = "世界";
            string c1 = a + b;                       // 用 + 号拼接
            string c2 = string.Concat(a, b);         // 用 Concat 拼接
            Console.WriteLine("拼接：{0} / {1}", c1, c2);

            //比较两个字符串是否相同：Compare / Equals（字符串比较区分大小写）
            Console.WriteLine("a.Equals(b) = {0}", a.Equals(b));   // false

            //-----------------------------------------------------
            // 3. 字符串格式化：Format 与 插值($)
            //-----------------------------------------------------
            string formatted = string.Format("姓名：{0}，年龄：{1}", "小明", 18);
            Console.WriteLine(formatted);

            string name = "小红";
            int age = 20;
            string interpolated = $"姓名：{name}，年龄：{age}";   // $ 插值写法
            Console.WriteLine(interpolated);

            //-----------------------------------------------------
            // 4. 空字符串判断：IsNullOrEmpty / IsNullOrWhiteSpace
            //-----------------------------------------------------
            string empty = "";
            Console.WriteLine("IsNullOrEmpty(empty) = {0}", string.IsNullOrEmpty(empty));

            Console.ReadKey();
        }
    }
}

/*
【小结】
  · string 不可变：任何"修改"操作都会返回一个新字符串，原字符串不变；
  · 常用：Length、ToUpper/ToLower、Contains、IndexOf、Substring、Replace、Split、Trim；
  · 拼接：+ 或 string.Concat；比较：Equals / Compare；
  · 格式化：string.Format("{0}...") 或 $"{变量} 插值"；
  · 逐字字符串 @"..." 已在第05章讲过。
*/