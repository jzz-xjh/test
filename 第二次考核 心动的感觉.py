#————————————————载入库
import turtle as t

#——————————————数据

zb=[[-600,0]]  #坐标数据
ls=[100,400,800,500,200,50]   #长度数据
an=[85,170]   #角度数据

#——————————————子函数定义

def move(x,y):
    t.penup()
    t.goto(x,y)
    t.pendown()

#——————————————主程序

move(zb[0][0],zb[0][1])
t.hideturtle()
t.forward(ls[0])
for i in range(5):
    t.left(an[0])
    t.forward(ls[1])
    t.right(an[1])
    t.forward(ls[2])
    t.left(an[1])
    t.forward(ls[3])
    t.right(an[1])
    t.forward(ls[4])
    t.left(an[1])
    t.forward(ls[4])
    t.right(an[1])
    t.forward(ls[4])
    t.left(an[1])
    t.forward(ls[4])
    t.right(an[1])
    t.forward(ls[0])
    t.left(an[0])
    t.forward(ls[5])
