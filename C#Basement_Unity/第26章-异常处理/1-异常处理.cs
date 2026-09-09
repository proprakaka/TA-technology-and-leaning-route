//=========================================================
// 第26章 C# 异常处理 (Exception Handling)
//=========================================================
//异常：程序运行中发生的"错误"(如除以0、文件不存在、类型转换失败)。
//用 try/catch/finally 来捕获并处理异常，避免程序直接崩溃。

using System;

namespace ExceptionTeaching
{
    class Program
    {
        static void Main()
        {
            //-----------------------------------------------------
            // 1. try/catch：把可能出错的代码放进 try，出错后跳进 catch 处理。
            //-----------------------------------------------------
            try
            {
                int a = 10;
                int b = 0;
                int c = a / b;      // 除以 0，会抛出异常
                Console.WriteLine("结果：{0}", c);   // 这行不会执行
            }
            catch (Exception e)     // e 是捕获到的异常对象
            {
                Console.WriteLine("捕获到异常：{0}", e.Message);  // e.Message 是异常描述
            }

            //-----------------------------------------------------
            // 2. 捕获不同类型的异常：多个 catch，越具体的靠前。
            //-----------------------------------------------------
            try
            {
                int[] arr = { 1, 2, 3 };
                Console.WriteLine(arr[10]);      // 越界访问，会抛异常
            }
            catch (IndexOutOfRangeException e)   // 专门捕获"下标越界"
            {
                Console.WriteLine("下标越界：{0}", e.Message);
            }
            catch (Exception e)                  // 兜底捕获其它所有异常
            {
                Console.WriteLine("其它异常：{0}", e.Message);
            }

            //-----------------------------------------------------
            // 3. finally：无论是否发生异常，finally 里的代码都会执行。
            //    常用于释放资源（关闭文件、断开连接等）。
            //-----------------------------------------------------
            try
            {
                Console.WriteLine("进入 try");
                throw new Exception("主动抛出的异常");   // throw：主动抛出一个异常
            }
            catch (Exception e)
            {
                Console.WriteLine("catch：{0}", e.Message);
            }
            finally
            {
                Console.WriteLine("finally：无论如何都会执行");
            }

            //-----------------------------------------------------
            // 4. 自定义异常：继承 Exception，构造时把信息传给基类。
            //-----------------------------------------------------
            try
            {
                ValidateAge(-5);
            }
            catch (InvalidAgeException e)
            {
                Console.WriteLine("自定义异常被捕获：{0}", e.Message);
            }

            Console.ReadKey();
        }

        //一个会抛自定义异常的方法：年龄不能为负数。
        static void ValidateAge(int age)
        {
            if (age < 0)
            {
                throw new InvalidAgeException("年龄不能为负数！");
            }
            Console.WriteLine("年龄合法：{0}", age);
        }
    }

    //自定义异常类：继承 Exception，: base(message) 把错误信息传给基类。
    class InvalidAgeException : Exception
    {
        public InvalidAgeException(string message) : base(message)
        {
        }
    }
}

/*
【常见内置异常（继承自 System.Exception）】
  DivideByZeroException   除以零
  IndexOutOfRangeException 数组/集合下标越界
  NullReferenceException   对 null 对象调用成员
  FormatException          格式转换错误(如 int.Parse("abc"))
  FileNotFoundException    文件未找到(见下一章)
  可用 catch(Exception e) 统一捕获；打印 e.Message 了解原因。

【小结】
  · try 包住可能出错的代码；catch 处理异常；finally 兜底执行；
  · throw 主动抛异常；catch(具体类型) 可精确匹配；
  · 可自定义异常：继承 Exception。
*/