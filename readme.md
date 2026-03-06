# helloword_foc_copy
>我...

>从来没有觉得玩电机快乐过。

## 仓库介绍

本仓库复刻了稚晖君在helloword键盘项目中使用的foc无刷电机驱动器

1、重绘PCB，以最小系统实现驱动器全功能

2、代码移植，把原版STM32F4的代码移植到STM32F103C8T6上，以KEIL开发，后续支持CLION

3、提供具体实例：

- 3205电机例程
- 机械硬盘电机驱动例程

项目亮点：个人认为这是最容易入门无刷驱动的一集了，简单的硬件，简单的代码，足以驱动市面上99%的小功率无刷电机，

## 文件夹介绍

- 0、hardware：原理图及pcb

- examples：开发过程中的例程，大部分已验证。

- software：源码，能用，但屎山。

- hardware：硬件原理图及pcb（空）

- images：图

## 环境介绍

- KEIL：5.24.1（尽量用5.38以上，cpp环境想自己配置的参考：https://zhuanlan.zhihu.com/p/670162318）
- CubeMx：6.9.1及以上
- 立创EDA标准版
- VOFA+：使用方法看我教程https://zhuanlan.zhihu.com/p/690064154


*****
*****

## 参考：

https://github.com/peng-zhihui/HelloWord-Keyboard

https://github.com/ToanTech/DengFOC_Lib

https://github.com/xiaocainiao11111/vofa_for_stm32

# *make by xiaocainiao* 
