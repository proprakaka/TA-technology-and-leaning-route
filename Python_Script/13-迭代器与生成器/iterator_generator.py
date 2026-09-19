# -*- coding: utf-8 -*-
"""
第 13 章：迭代器与生成器
==========================
这一章揭开 for 循环的"内幕"：为什么 for 能遍历列表、字符串、字典……
其实 for 一直在和一个叫"迭代器(iterator)"的东西打交道。

先建立一条概念链：
  可迭代对象(iterable)  --iter()-->  迭代器(iterator)  --next()-->  逐个产出元素
================================================================
"""

# =====================================================================
# 一、可迭代对象 iterable 与迭代器 iterator
# =====================================================================
"""
【原理】两个易混概念：
  - 可迭代对象（iterable）：能被 for 遍历的东西（列表、字符串、字典、集合、
    元组、range 等）。它的标志是：能被 iter() 拿到一个迭代器。
  - 迭代器（iterator）：维护"遍历到哪了"的游标，用 next() 逐个吐出元素，
    吐完后再 next() 会抛 StopIteration 异常。

  for 循环的底层三步曲：
      it = iter(可迭代对象)      # 1. 拿到迭代器
      while True:
          try: x = next(it)       # 2. 不断 next()
          except StopIteration:   # 3. 吐完了就结束
              break
          处理 x
"""
nums = [1, 2, 3]
it = iter(nums)            # 把列表变成迭代器
print(next(it))            # 1
print(next(it))            # 2
print(next(it))            # 3
# print(next(it))          # 报错 StopIteration：没有下一个了

# list 本身不是迭代器（每次 iter 都从头开始）：
a = [1, 2, 3]
b = iter(a)
print(b is a)              # False（列表不是迭代器）

# =====================================================================
# 二、自定义迭代器：类里实现 __iter__ 与 __next__（面熟即可，第22章讲类）
# =====================================================================
class Countdown:                 # 一个"倒数"迭代器
    def __init__(self, start):
        self.current = start
    def __iter__(self):
        return self              # 迭代器返回它自己
    def __next__(self):
        if self.current < 0:
            raise StopIteration  # 完了就抛这个，通知 for 停止
        val = self.current
        self.current -= 1
        return val

for n in Countdown(3):           # 因为实现了上述两个方法，可以被 for 遍历
    print(n)                     # 3 2 1 0

# =====================================================================
# 三、生成器 generator：用 yield 轻松造迭代器
# =====================================================================
"""
【原理】生成器是一种"特殊的迭代器"，但写起来不用实现类。
  只要函数里出现 yield，这个函数就不再是普通函数，而是"生成器函数"：
  调用它不会立即执行，而是返回一个生成器对象。

  yield 的魔法："产出一个值，并在此处暂停"，下次 next() 时从暂停点继续。
  好处：值是一个一个"现算现给"的，不用一次全存在内存里（省内存）。
"""
def countdown(n):
    while n >= 0:
        yield n        # 产出一个值，然后暂停，等下次 next()
        n -= 1

gen = countdown(3)
print(gen)             # <generator object ...>
print(next(gen))       # 3（执行到 yield 3，暂停）
print(next(gen))       # 2（从暂停点继续）
print(next(gen))       # 1
print(next(gen))       # 0
# print(next(gen))     # 再 next 会抛 StopIteration

# 生成器可直接被 for 遍历（for 内部自动处理 StopIteration）：
for n in countdown(3):
    print(n)           # 3 2 1 0

# =====================================================================
# 四、生成器为什么省内存（懒加载）
# =====================================================================
"""
  对比：list(range(1000000)) 会立刻在内存建 100 万个元素；
       而生成器按需一个一个产，内存占用极小。
"""
import sys

big_list = [x for x in range(1000)]       # 列表：一次性造好
big_gen = (x for x in range(1000))        # 生成器表达式：懒加载（第11章提过）

print(type(big_list), type(big_gen))      # list / generator
print(sys.getsizeof(big_list))            # 列表占用较大
print(sys.getsizeof(big_gen))             # 生成器占用极小

# =====================================================================
# 五、生成器表达式（第 11 章埋的伏笔在这里解开）
# =====================================================================
gen_expr = (x * x for x in range(5))
print(gen_expr)             # <generator object ...>
print(list(gen_expr))       # [0, 1, 4, 9, 16]（转列表一次性消费）

# 生成器是"一次性"的，用光就没了：
g2 = (x for x in range(3))
print(list(g2))             # [0, 1, 2]
print(list(g2))             # []（已经空了！）

"""
【易错点】生成器只能遍历一次。想重复遍历，要么重新创建生成器，
  要么一开始就用列表装好结果。
"""

# =====================================================================
# 六、yield 的另一面：也能"接收"从外部送进来的值（进阶，了解即可）
# =====================================================================
def echo():
    while True:
        received = yield          # 先暂停，等在 send
        print("收到：", received)

g = echo()
next(g)                    # 先启动生成器、执行到 yield 处
g.send("hello")            # 把 "hello" 送进 yield，赋给 received
g.send("world")
g.close()                  # 关闭生成器

# =====================================================================
# 本章小结 + 预告
# =====================================================================
"""
小结：
  1. 可迭代对象能用 iter() 得到迭代器；迭代器用 next() 依次产出，靠 StopIteration 结束。
  2. 生成器 = 用 yield 写的迭代器；yield 是"产出并暂停"。
  3. 生成器懒加载、省内存、只能遍历一次。

预告：下一章讲 **with 与上下文管理器**——file 打开后总得记得关闭，
  with 就是为了自动"善后"而生的语法，它背后靠的是 __enter__/__exit__。
"""