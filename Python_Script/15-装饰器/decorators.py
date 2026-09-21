# -*- coding: utf-8 -*-
"""
第 15 章：装饰器 decorator
============================
装饰器是一个"函数加工厂"：在不修改原函数代码的前提下，
  给它套上额外的能力（比如计时、日志、权限校验、缓存）。

它建立在前面三个概念之上：
  1. 函数是一等公民（第 12 章）：函数可被作为参数、被返回。
  2. 闭包（第 12 章）：内层函数记住外层变量。
  3. @ 语法糖（本章）：把装饰器"戴"到函数头上。

按"从笨办法到优雅写法"的顺序讲，你会彻底看穿它的原理。
================================================================
"""

# =====================================================================
# 一、需求：想给函数加"计时"，但不改函数本身
# =====================================================================
import time

def slow_func():
    total = 0
    for i in range(1000000):
        total += i
    return total

# 笨办法 1：直接塞进函数里——侵入性强，每个函数都要改
# 笨办法 2：写个"包装函数"包它一下：
def timed_slow(func):
    start = time.time()
    result = func()               # 在中间调用原函数
    print(f"耗时 {time.time() - start:.4f} 秒")
    return result

print("笨办法调用：")
result = timed_slow(slow_func)

# =====================================================================
# 二、升级：写一个"返回包装函数"的工厂（这就是装饰器的雏形）
# =====================================================================
def timer(func):                  # 接收"要被加工的函数"
    def wrapper():                # 内层：真正的"新函数"
        start = time.time()
        result = func()           # 调用原函数
        print(f"耗时 {time.time() - start:.4f} 秒")
        return result
    return wrapper                # 返回包装后的函数

wrapped = timer(slow_func)        # 得到包装函数
print("工厂版调用：")
wrapped()

# =====================================================================
# 三、用 @ 语法糖：把"装饰"动作变得优雅
# =====================================================================
"""
@timer 写在函数定义上方，等价于 slow_func = timer(slow_func)：
  从这一刻起，slow_func 这个名字就指向"包装后的新函数"了。
"""
@timer
def fast_func():
    return sum(range(500000))

print("语法糖版调用：")
fast_func()

# =====================================================================
# 四、装饰"带参数"的函数：wrapper 用 *args, **kwargs 透传
# =====================================================================
def timer2(func):
    def wrapper(*args, **kwargs):     # 接收任意参数，原样传给原函数
        start = time.time()
        result = func(*args, **kwargs)
        print(f"{func.__name__} 耗时 {time.time() - start:.4f} 秒")
        return result
    return wrapper

@timer2
def add(a, b):
    return a + b

print("带参装饰：", add(3, 4))

# =====================================================================
# 五、装饰器也能"带自己的参数"（三层嵌套）
# =====================================================================
"""
如果装饰器本身要带配置（如"重复运行 n 次"），就再包一层：
  repeat(n) 先接收配置，返回真正的装饰器。
"""
def repeat(n):
    def decorator(func):
        def wrapper(*args, **kwargs):
            for _ in range(n):          # 循环执行 n 次
                func(*args, **kwargs)
        return wrapper
    return decorator

@repeat(3)                                # 让 say_hi 执行 3 次
def say_hi():
    print("你好")

say_hi()

# =====================================================================
# 六、两个重要细节：保留函数元信息，以及装饰器的叠加
# =====================================================================
"""
细节 1：装饰后，函数名等信息会变成 wrapper 的，可用 functools.wraps 修复。
细节 2：多个装饰器可以从上到下叠加，执行顺序是"由外向内包装"。
"""
import functools

def debug(func):
    @functools.wraps(func)         # wraps 把原函数的 __name__ 等元信息复制过来
    def wrapper(*args, **kwargs):
        print(f"调用 {func.__name__}({args}, {kwargs})")
        return func(*args, **kwargs)
    return wrapper

@debug
def greet(name):
    """这是问候函数"""
    return f"你好，{name}"

print(greet("小明"))
print("函数名/文档被保留：", greet.__name__, greet.__doc__)   # greet / 这是问候函数

# 装饰器叠加示例：
def bold(func):
    @functools.wraps(func)
    def wrapper(*args, **kwargs):
        return "<b>" + func(*args, **kwargs) + "</b>"
    return wrapper

def italic(func):
    @functools.wraps(func)
    def wrapper(*args, **kwargs):
        return "<i>" + func(*args, **kwargs) + "</i>"
    return wrapper

@bold
@italic                    # italic 先包，bold 再包（从下往上）
def text():
    return "hello"

print(text())              # <b><i>hello</i></b>

# =====================================================================
# 七、经典内置装饰器：@property、@staticmethod（第 22 章详解，先留个名）
# =====================================================================
"""
Python 里有些装饰器是官方提供的，会在面向对象一章用到：
  - @property       : 把方法伪装成属性。
  - @staticmethod   : 静态方法。
  - @classmethod    : 类方法。
  这里不展开，见第 22 章。
"""

# =====================================================================
# 本章小结 + 预告
# =====================================================================
"""
小结：
  1. 装饰器 = 接收函数、返回"包装后新函数"的高阶函数。
  2. @decorator 等价于 func = decorator(func)。
  3. 带参装饰器要三层嵌套；透传参数用 *args/**kwargs。
  4. 用 functools.wraps 保留元信息；多个装饰器从下往上叠加。

预告：下一章回到数据结构（进阶用法）——栈、队列、嵌套、del、排序技巧，
  把列表等容器的"高级操作"补齐。
"""