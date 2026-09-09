# C# 代码式基础教程（对应菜鸟教程）

本目录是一套「代码 + 注释」形式的 C# 入门教程，章节与 [菜鸟教程 C# 教程](https://www.runoob.com/csharp/csharp-tutorial.html) 对齐，从「Hello World」一路讲到「文件 I/O」。

## 学习方法

1. 建议**按章节顺序**逐章阅读，每章对应一个文件夹；
2. 每个 `.cs` 文件都是**可运行**的完整程序，注释是教学重点；
3. 凡是「这一章第一次出现、前面没讲过」的语法，都会在它**首次出现时用注释说明**；
4. 建议把每章代码复制到 VS.NET / VS Code / 在线工具里**动手运行**，再改一改数值观察变化；
5. 学习阶段建议关闭代码补齐(Copilot/IntelliCode)和 CodeLens，以获得纯学习体验。

## 章节目录

| 章节 | 文件夹 | 内容 | 主要文件 |
| --- | --- | --- | --- |
| 01 | 第01章-简介 | 认识 C# 与 .NET | 1-CSharp简介.cs |
| 02 | 第02章-环境 | 环境搭建与编译运行 | 1-CSharp环境.cs |
| 03 | 第03章-程序结构 | 程序结构、Hello World | 1-程序结构-HelloWorld.cs |
| 04 | 第04章-基本语法 | 类、成员、实例化 | 1-基本语法-Rectangle.cs |
| 05 | 第05章-数据类型 | 值类型 / 引用类型 / sizeof | 1-值类型一览.cs、2-引用类型与sizeof.cs |
| 06 | 第06章-类型转换 | 隐式/显式转换、Convert、Parse | 1-类型转换.cs |
| 07 | 第07章-变量 | 变量声明、初始化、var、键盘输入 | 1-变量.cs |
| 08 | 第08章-常量 | const、readonly、字面常量 | 1-常量.cs |
| 09 | 第09章-运算符 | 算术/关系/逻辑/位/赋值/其它 | 1-运算符.cs |
| 10 | 第10章-判断 | if / else if / switch / 三元 | 1-判断.cs |
| 11 | 第11章-循环 | while / for / foreach / break / continue | 1-循环.cs |
| 12 | 第12章-封装 | 访问修饰符 | 1-封装.cs |
| 13 | 第13章-方法 | 方法、递归、ref / out | 1-方法.cs |
| 14 | 第14章-可空类型 | int?、HasValue、?? | 1-可空类型.cs |
| 15 | 第15章-数组 | 一维/二维/交错数组、Array 工具 | 1-数组.cs |
| 16 | 第16章-字符串 | Length、Substring、Split、Format | 1-字符串.cs |
| 17 | 第17章-结构体 | struct、值类型语义 | 1-结构体.cs |
| 18 | 第18章-枚举 | enum、自定义值 | 1-枚举.cs |
| 19 | 第19章-类 | 构造/析构函数、属性、静态成员 | 1-类与构造函数.cs、2-属性与静态成员.cs |
| 20 | 第20章-继承 | 基类/派生类、protected、base | 1-继承.cs |
| 21 | 第21章-多态 | virtual / override / abstract | 1-多态.cs |
| 22 | 第22章-运算符重载 | operator 重载 | 1-运算符重载.cs |
| 23 | 第23章-接口 | interface、多接口实现 | 1-接口.cs |
| 24 | 第24章-命名空间 | namespace、嵌套、using | 1-命名空间.cs |
| 25 | 第25章-预处理指令 | #if / #region / #warning | 1-预处理指令.cs |
| 26 | 第26章-异常处理 | try/catch/finally、throw、自定义异常 | 1-异常处理.cs |
| 27 | 第27章-文件IO | File、StreamReader/Writer、Directory | 1-文件IO.cs |

## 原有的入门文件

原目录下的 `1C#_HelloWolrd.cs`、`2C#_BaseSentence.cs`、`3C#_ValueTypes.cs`、`4C#_MoreContexts.cs` 已按内容归并到对应章节并增强注释：

- `1C#_HelloWolrd.cs` → 第03章-程序结构（修正拼写 `Wolrd` → `World`）
- `2C#_BaseSentence.cs` → 第04章-基本语法（移除重复的 `using System;`，修正 `calss` → `class`）
- `3C#_ValueTypes.cs` → 第05章-数据类型/1-值类型一览.cs
- `4C#_MoreContexts.cs`（原为空）→ 第05章-数据类型/2-引用类型与sizeof.cs