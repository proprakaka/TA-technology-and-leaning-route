//=========================================================
// 第19章 C# 类（下）—— 属性 (Property) 与 静态成员 (static)
//=========================================================
//上篇讲了用 public 字段直接暴露数据，但这样外部可以随意篡改。
//“属性”用 get/set 来安全地读写字段，是封装的高级形式。

using System;

namespace ClassPropertyTeaching
{
    class Student
    {
        //私有字段：外部无法直接访问（这就是"隐藏数据"）。
        private string _name;
        private int _age;

        //---- 属性 (Property) ----
        //语法：访问修饰符 类型 属性名 { get { ... } set { ... } }
        //get 控制“读取”，set 控制“写入”；value 是 set 时外部传入的值（关键字）。
        public string Name
        {
            get { return _name; }              // 读取：返回私有字段
            set { _name = value; }             // 写入：value 是赋值时右边的值
        }

        public int Age
        {
            get { return _age; }
            set
            {
                //在 set 里可以做“合法性校验”，阻止非法值进入。
                if (value >= 0 && value <= 150)
                    _age = value;
                else
                    _age = 0;   // 非法年龄当作 0
            }
        }

        //---- 自动实现的属性 (Auto-Property) ----
        //如果 get/set 内部没有额外逻辑，可以简写成一行，编译器会自动生成幕后字段。
        public string Grade { get; set; }        // 读写都公开
        public string School { get; private set; } = "示例中学"; // 只能在类内部 set

        //---- 静态成员 (static) ----
        //static 成员属于"类本身"，而非某个对象，通过 类名.成员 访问。
        public static int TotalCount = 0;        // 静态字段：统计学生总数

        public Student()
        {
            TotalCount++;                        // 每 new 一个就 +1
        }

        public static void ShowCount()           // 静态方法：只能访问静态成员
        {
            Console.WriteLine("当前学生总数：{0}", TotalCount);
        }
    }

    class Program
    {
        static void Main()
        {
            Student a = new Student();
            a.Name = "小明";      // 触发 set，value = "小明"
            a.Age = 18;           // 合法
            a.Grade = "三年级";
            Console.WriteLine("{0}, {1} 岁, {2}", a.Name, a.Age, a.Grade);
            Console.WriteLine("学校：{0}", a.School);   // 只能读，不能从外部改

            Student b = new Student();
            b.Name = "小红";
            b.Age = 200;          // 非法年龄，会被 set 纠正成 0
            Console.WriteLine("{0}, {1} 岁", b.Name, b.Age);

            //静态成员用 类名.成员 访问，不需要 new 对象。
            Student.ShowCount();

            Console.ReadKey();
        }
    }
}

/*
【小结】
  · 属性 = get(读) + set(写)，内部可加校验，用 value 关键字接住写入值；
  · 自动属性：public 类型 名字 { get; set; } 一行搞定；
  · 可控制访问级别，如 { get; private set; } 只读属性；
  · static 成员属于类本身，用 类名.成员 访问，静态方法里不能直接用实例字段。
*/