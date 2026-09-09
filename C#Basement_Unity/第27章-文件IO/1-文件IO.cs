//=========================================================
// 第27章 C# 文件 I/O（读写文件）
//=========================================================
//文件 I/O：读写磁盘上的文件。最常用的是 System.IO 命名空间里的类：
//  File / FileInfo   —— 操作文件本身(创建、读取全部内容、删除等)
//  Directory         —— 操作文件夹
//  StreamReader / StreamWriter —— 以"流"的方式逐行读写文本

using System;
using System.IO;     // 文件操作相关的类都在这个命名空间里

namespace FileIO_Teaching
{
    class Program
    {
        static void Main()
        {
            //用一个文件路径做示例（放在程序的当前目录下）。
            string path = "test.txt";

            //-----------------------------------------------------
            // 1. File.WriteAllText：把字符串一次性写入文件（覆盖旧内容，不存在则创建）。
            //-----------------------------------------------------
            File.WriteAllText(path, "第一行：你好，C#！\n第二行：文件读写示例。");

            //-----------------------------------------------------
            // 2. File.ReadAllText：一次性读取整个文件内容。
            //-----------------------------------------------------
            string content = File.ReadAllText(path);
            Console.WriteLine("读取到的全部内容：\n{0}", content);

            //-----------------------------------------------------
            // 3. File.Exists：判断文件是否存在。
            //-----------------------------------------------------
            Console.WriteLine("文件是否存在：{0}", File.Exists(path));

            //-----------------------------------------------------
            // 4. StreamWriter / StreamReader：逐行读写（适合处理较大的文件）。
            //    using(...) 语句会在代码块结束后"自动关闭"文件资源——非常常用！
            //-----------------------------------------------------
            using (StreamWriter writer = new StreamWriter("lines.txt"))
            {
                writer.WriteLine("第 1 行");
                writer.WriteLine("第 2 行");
                writer.WriteLine("第 3 行");
            }   // 离开这里时，writer 会自动 Close()

            using (StreamReader reader = new StreamReader("lines.txt"))
            {
                string line;
                //ReadLine() 每次读一行，读到末尾返回 null 就停止。
                while ((line = reader.ReadLine()) != null)
                {
                    Console.WriteLine("读行：" + line);
                }
            }

            //-----------------------------------------------------
            // 5. Directory：操作文件夹。
            //-----------------------------------------------------
            Directory.CreateDirectory("mydir");              // 新建文件夹
            File.WriteAllText("mydir\\note.txt", "这是文件夹里的文件"); // 在文件夹里写文件
            Console.WriteLine("文件夹是否存在：{0}", Directory.Exists("mydir"));

            //-----------------------------------------------------
            // 6. 文件或文件夹的删除（谨慎操作！这里仅演示用法）。
            //-----------------------------------------------------
            File.Delete("lines.txt");        // 删除文件
            Directory.Delete("mydir", true); // 递归删除文件夹及其内容
            File.Delete(path);
            Console.WriteLine("演示文件已清理。");

            Console.ReadKey();
        }
    }
}

/*
【常用类速查】
  · File.WriteAllText(path, text) —— 覆盖写入整个文件
  · File.ReadAllText(path)         —— 读取整个文件为字符串
  · File.AppendAllText(path, text) —— 在文件末尾追加内容
  · File.Exists(path)              —— 判断文件是否存在
  · File.Delete(path)              —— 删除文件
  · Directory.CreateDirectory      —— 新建文件夹
  · StreamWriter.WriteLine / StreamReader.ReadLine —— 逐行读写
  · 大文件、二进制等更高级的 I/O，可继续学习 FileStream / BinaryReader 等。

【小结】
  · 用 using System.IO; 引入文件相关类型；
  · 读文件用 File.ReadAllText 或 StreamReader；
  · 写文件用 File.WriteAllText / AppendAllText 或 StreamWriter；
  · 用 using(...) 自动释放文件资源，避免忘记关闭。

【恭喜！】学完本章，你已经从"Hello World"一路走到了文件 I/O，
覆盖了菜鸟教程 C# 的全部核心章节。接下来可以动手做小项目巩固（如：学生管理系统、待办清单）。
*/